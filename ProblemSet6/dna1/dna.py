import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py databases/[database].csv sequences/[text].txt")
        return

    # Read database file into a variable
    strs = []
    rows = []
    num_rows = 0
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        strs = reader.fieldnames
        for row in reader:
            rows.append(row)
            num_rows += 1

    # Read DNA sequence file into a variable
    sequence = ""
    with open(sys.argv[2]) as seq:
        sequence = seq.read()

    # Find longest match of each STR in DNA sequence
    str_and_match = {}
    for i in range(1, len(strs)):
        score = longest_match(sequence, strs[i])
        str_and_match[strs[i]] = score

    # Check database for matching profile
    for i in range(0, num_rows):
        count = 0
        for j in range(1, len(strs)):
            if str_and_match[strs[j]] == int(rows[i][strs[j]]):
                count += 1
        if count == len(strs) - 1:
            print(rows[i]["name"])
            break
        elif i == num_rows - 1:
            print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


main()
