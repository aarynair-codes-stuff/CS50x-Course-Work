from cs50 import get_int


def get_card_num():
    # Takes credit card number as input from user
    card_num = get_int("Number: ")

    while (card_num <= 0):  # Re-prompts if 0 or negative
        card_num = get_int("Number: ")

    return card_num


def get_length(card_num):
    # Calculates the length of the credit card num using log basse 10
    length = len(str(card_num))
    return length


def get_checksum(card_num, length):
    # Converts card num from int to string
    str_card_num = str(card_num)
    sum_from_second = 0
    sum_from_end = 0
    checksum = 0

    i = length - 2
    while i >= 0:
        digit_char = str_card_num[i]

        # Convert to int
        actual_num = int(digit_char)

        doubled_num = 2 * actual_num

        if doubled_num > 9:
            doubled_num -= 9

        sum_from_second = sum_from_second + doubled_num

        i = i - 2

    j = length - 1
    while j >= 0:
        digit_char = str_card_num[j]

        actual_num = int(digit_char)

        sum_from_end = sum_from_end + actual_num
        j = j - 2

    # Returns checksum from Luhn’s Algorithm
    checksum = sum_from_second + sum_from_end
    return checksum


def get_first_digits(card_num, length):
    # Retrieves the first digits for identification
    initial_digits = card_num // 10 ** (length - 2)
    if initial_digits // 10 == 4:
        return initial_digits // 10
    else:
        return initial_digits


def get_valid(length, checksum, first_digits):
    # Checks if valid length
    if length > 16 or (length < 15 and length != 13):
        print("INVALID")
    else:
        # Checks if valid checksum
        if checksum % 10 != 0:
            print("INVALID")
        else:
            # Checks if valid combination of length and first digits
            if first_digits == 4 and (length == 13 or length == 16):
                print("VISA")
            elif length == 15 and (first_digits == 34 or first_digits == 37):
                print("AMEX")
            elif length == 16 and (first_digits == 51 or first_digits == 52 or first_digits == 53 or first_digits == 54 or first_digits == 55):
                print("MASTERCARD")
            else:
                print("INVALID")


# Declares all variables by calling respective functions
card_num = get_card_num()
length = get_length(card_num)
checksum = get_checksum(card_num, length)
first_digits = get_first_digits(card_num, length)

print(card_num)
print(length)
print(checksum)
print(first_digits)

# Checks if variables are valid
get_valid(length, checksum, first_digits)
