from cs50 import get_int


def generate_row(width, height):
    # Creates a string to store the row value
    output = ""

    # Adds the leading spaces
    i = height
    while i > 1:
        output = output + " "
        i -= 1

    # Creates the symmetrical blocks
    blocks = ""
    j = 0
    while j < width:
        blocks = blocks + "#"
        j += 1

    # Joins the spaces, first blocks, gap and second blocks
    output = output + blocks
    output = output + "  "
    output = output + blocks
    print(f"{output}")


def create_pyramid(height):
    # Generates the pyramid line by line
    i = 0
    while i < height:
        generate_row(i + 1, height - i)
        i += 1


# Prompt the user for input
height = get_int("Height: ")

# Re-prompt the user for input
while height > 8 or height < 1:
    height = get_int("Height: ")

create_pyramid(height)
