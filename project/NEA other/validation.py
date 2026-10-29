def username_validation():
    username_valid = False
    special_characters = "-';/*"
    while username_valid != True:
        count = 0
        inp_username = input("\nEnter your username: ")
        for letter in inp_username:
            for char in special_characters:
                if letter == char:
                    count += 1
                else:
                    pass
        if count > 0:
            print("\nUsername should not contain special characters: - ' ; / *")
        else:
            username_valid = True
            print("\nUsername is valid")


username_validation()



def password_validation():
    password_valid = False
    while password_valid != True:
        inp_password = input("\nEnter your password: ")
        inp_confirm_password = input("\nConfirm your password: ")
        if len(inp_password) <= 35 and len(inp_password) >= 12:
            if inp_password == inp_confirm_password:
                password_valid = True
                print("\nPassword is valid and both passwords match")
            else:
                print("\nPasswords do not match")
        else:
            print("\nPassword should be between 12 and 35 characters")

password_validation()