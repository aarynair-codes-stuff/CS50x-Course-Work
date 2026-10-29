from cs50 import get_string


def get_letters(letters, inp_text):
    # Initialise the variables
    total = 0
    text_len = len(inp_text)

    # Converts text to lowercase
    lower_text = inp_text.lower()

    # Loops though text counting letters
    for i in range(0, text_len):
        for j in range(0, 26):
            if letters[j] == lower_text[i]:
                total += 1

    return total


def get_words(inp_text):
    # Initialise the variables
    total = 1
    text_len = len(inp_text)

    # Counts the number of words based on spaces
    for i in range(0, text_len):
        if inp_text[i] == ' ':
            total += 1

    return total


def get_sentences(inp_text):
    # Initialise the variables
    total = 0
    text_len = len(inp_text)

    # Counts the number of sentences based on punctuation
    for i in range(0, text_len):
        if inp_text[i] == '.' or inp_text[i] == '!' or inp_text[i] == '?':
            total += 1

    return total


def C_L_index(letters, words, sentences):
    # Calculates letters and sentences per 100 words
    l_per_100 = (letters / words) * 100
    s_per_100 = (sentences / words) * 100

    # Calculates reading index and grade
    index = 0.0588 * l_per_100 - 0.296 * s_per_100 - 15.8
    grade = round(index)

    return grade


def grade_output(grade):
    if grade >= 16:
        print("Grade 16+")

    elif grade < 1:
        print("Before Grade 1")

    else:
        print("Grade ", grade)


lowercase_letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                     'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

# Prompt the user for some text
text = get_string("Text: ")

# Count the number of letters, words, and sentences in the text
letter_count = get_letters(lowercase_letters, text)
word_count = get_words(text)
sentence_count = get_sentences(text)

# Compute the Coleman-Liau index
grade = C_L_index(letter_count, word_count, sentence_count)

# Print the grade level
grade_output(grade)
