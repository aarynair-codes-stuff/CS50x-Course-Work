import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    shares = db.execute("SELECT * FROM shares WHERE user_id = ?", session["user_id"])
    value = db.execute("SELECT SUM(current_price) FROM shares WHERE user_id = ?",
                       session["user_id"])
    sum_value = value[0]["SUM(current_price)"]
    rows = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
    cash = rows[0]["cash"]

    if type(sum_value) != int:
        sum_value = 0

    return render_template("index.html", shares=shares, cash=cash, sum=sum_value + cash)

# Before implementing buy and sell, implement two tables, one named stocks with attributes (share id, stock name string, total stock quantity int, current stock price float, foreign key user id)
# Another named transactions with attributes (transaction id, stock name, transaction stock quantity, transaction amount (can be sell or buy), sale type ('buy' or 'sell'), date and time of sale, foreign key user id)

# When implementing buy and sell, add a SQL query which updates the stock quantity and price for stocks table and one which records the transaction in the transactions table
# Records from the stocks table will be used for display on the index page

# CREATE TABLE users (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, username TEXT NOT NULL, hash TEXT NOT NULL, cash NUMERIC NOT NULL DEFAULT 10000.00);
# CREATE TABLE shares (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, stock_name TEXT NOT NULL, quantity INT NOT NULL, current_price NUMERIC NOT NULL, user_id int, CONSTRAINT fk_user FOREIGN KEY (user_id) REFERENCES users(id));
# CREATE TABLE transactions (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, transaction_stock_name TEXT NOT NULL, transaction_quantity INT NOT NULL, transaction_amount NUMERIC NOT NULL, transaction_type TEXT NOT NULL, transaction_datetime DATETIME DEFAULT CURRENT_TIMESTAMP, user_id int, CONSTRAINT fk_user FOREIGN KEY (user_id) REFERENCES users(id));


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        stockName = request.form.get("symbol")
        try:
            quantity = int(request.form.get("shares"))
        except ValueError:
            return apology("must provide valid quantity", 400)
        stockInfo = lookup(stockName)
        rows = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        cash = rows[0]["cash"]

        # Ensure username was submitted
        if not stockName or stockName.isalnum() == False:
            return apology("must provide stock name", 400)

        # Ensure password was submitted
        elif not stockInfo:
            return apology("stock not found", 400)

        elif not quantity > 0 or type(quantity) != int:
            return apology("must provide valid quantity", 400)

        # Hash password
        price = stockInfo["price"] * quantity

        if price > cash:
            return apology("insufficient funds", 400)

        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash - price, session["user_id"])

        db.execute("INSERT INTO transactions (transaction_stock_name, transaction_quantity, transaction_amount, transaction_type, user_id) VALUES (?, ?, ?, 'Buy', ?)",
                   stockName, quantity, price, session["user_id"])

        # Insert data into database
        try:
            db.execute("INSERT INTO shares (stock_name, quantity, current_price, user_id) VALUES (?, ?, ?, ?)",
                       stockName, quantity, price, session["user_id"])
        except ValueError:
            # If stock has already been purchased
            previous_quantity = db.execute(
                "SELECT quantity FROM shares WHERE stock_name = ? AND user_id = ?", stockName, session["user_id"])
            if not previous_quantity:
                x = 0
            else:
                x = previous_quantity[0]["quantity"]
            quantity = quantity + x
            price = stockInfo["price"] * quantity
            db.execute("UPDATE shares SET quantity = ?, current_price = ? WHERE stock_name = ? AND user_id = ?",
                       quantity, price, stockName, session["user_id"])

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("buy.html")


@app.route("/cash", methods=["GET", "POST"])
@login_required
def cash():
    """Add Cash"""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        amount = int(request.form.get("amount"))
        rows = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        cash = rows[0]["cash"]

        # Ensure username was submitted
        if not amount:
            return apology("must provide amount", 403)

        elif not amount > 0 or type(amount) != int:
            return apology("must provide valid amount", 403)

        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash + amount, session["user_id"])

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("cash.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    history = db.execute("SELECT * FROM transactions WHERE user_id = ?", session["user_id"])

    return render_template("history.html", history=history)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        stock = request.form.get("symbol")
        # Ensure username was submitted
        if not stock or stock.isalnum() == False:
            return apology("must provide valid stock", 400)

        stockInfo = lookup(stock)

        if not stockInfo:
            return apology("no info found", 400)

        return render_template("quoted.html", info=stockInfo)

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        cpassword = request.form.get("confirmation")

        # Ensure username was submitted
        if not username:
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not password:
            return apology("must provide password", 400)

        elif not cpassword:
            return apology("must provide password", 400)

        elif password != cpassword:
            return apology("passwords do not match", 400)

        # Hash password
        hashedPassword = generate_password_hash(password)

        # Insert credentials into database
        try:
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hashedPassword)
        except ValueError:
            # Query database for username
            return apology("username already exists", 400)

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        stockName = request.form.get("symbol")
        quantity = int(request.form.get("shares"))
        stockInfo = lookup(stockName)
        rows = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        cash = rows[0]["cash"]

        # Ensure username was submitted
        if not stockName or stockName.isalnum() == False:
            return apology("must provide stock name", 400)

        # Ensure password was submitted
        elif not stockInfo:
            return apology("stock not found", 400)

        rows = db.execute("SELECT * FROM shares WHERE stock_name = ? AND user_id = ?",
                          stockName, session["user_id"])

        # Ensure username exists and password is correct
        if len(rows) != 1:
            return apology("no stocks of that name owned", 400)

        elif not quantity > 0 or type(quantity) != int or quantity > rows[0]["quantity"]:
            return apology("must provide valid quantity", 400)

        # Hash password
        price = stockInfo["price"] * quantity

        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash + price, session["user_id"])

        db.execute("INSERT INTO transactions (transaction_stock_name, transaction_quantity, transaction_amount, transaction_type, user_id) VALUES (?, ?, ?, 'Sell', ?)",
                   stockName, quantity, price, session["user_id"])

        previous_quantity = db.execute(
            "SELECT quantity FROM shares WHERE stock_name = ? AND user_id = ?", stockName, session["user_id"])
        quantity = previous_quantity[0]["quantity"] - quantity
        price = stockInfo["price"] * quantity
        db.execute("UPDATE shares SET quantity = ?, current_price = ? WHERE stock_name = ? AND user_id = ?",
                   quantity, price, stockName, session["user_id"])

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        stocks = db.execute("SELECT stock_name FROM shares WHERE user_id = ?", session["user_id"])
        return render_template("sell.html", stocks=stocks)
