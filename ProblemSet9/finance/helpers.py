import requests

from flask import redirect, render_template, session
from functools import wraps

# Comments

# Comments


def apology(message, code=400):
    """Render message as an apology to user."""
    # Comments
    def escape(s):
        """
        Escape special characters.

        https://github.com/jacebrowning/memegen#special-characters
        """  # Comments
        for old, new in [
            ("-", "--"),  # Comments
            (" ", "-"),  # Comments
            ("_", "__"),
            ("?", "~q"),
            ("%", "~p"),  # Comments
            ("#", "~h"),
            ("/", "~s"),  # Comments
            ('"', "''"),
        ]:
            s = s.replace(old, new)
        return s
    # Comments
    return render_template("apology.html", top=code, bottom=escape(message)), code

# Comments


def login_required(f):
    """
    Decorate routes to require login.

    https://flask.palletsprojects.com/en/latest/patterns/viewdecorators/
    """
    # Comments
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get("user_id") is None:  # Comments
            return redirect("/login")  # Comments
        return f(*args, **kwargs)
    # Comments
    return decorated_function

# Comments


def lookup(symbol):  # Comments
    """Look up quote for symbol."""
    url = f"https://finance.cs50.io/quote?symbol={symbol.upper()}"
    try:  # Comments
        response = requests.get(url)
        response.raise_for_status()  # Raise an error for HTTP error responses
        quote_data = response.json()
        return {
            "name": quote_data["companyName"],  # Comments
            "price": quote_data["latestPrice"],
            "symbol": symbol.upper()  # Comments
        }
    except requests.RequestException as e:
        print(f"Request error: {e}")  # Comments
    except (KeyError, ValueError) as e:  # Comments
        print(f"Data parsing error: {e}")
    return None
# Comments


def usd(value):  # Comments
    """Format value as USD."""
    return f"${value:,.2f}"
# Comments
