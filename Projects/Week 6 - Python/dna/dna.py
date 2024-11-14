import csv
import sys

# Main function


def main():
    # Check if the correct number of command-line arguments was provided
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # Read database file into a list of dictionaries
    database = []
    with open(sys.argv[1]) as file:
        # Use DictReader to parse each row as a dictionary
        reader = csv.DictReader(file)
        for row in reader:
            # Convert STR counts from strings to integers
            for key in row.keys():
                if key != "name":  # Skip the "name" field
                    row[key] = int(row[key])
            database.append(row)  # Append each person's data to the database list

    # Read DNA sequence file into a string variable
    with open(sys.argv[2]) as file:
        dna_sequence = file.read().strip()

    # Prepare a dictionary to store the counts of each STR in the DNA sequence
    str_counts = {}
    # Retrieve STR names from the first row of the database (excluding "name")
    str_names = database[0].keys() - {"name"}

    # Find longest match of each STR in DNA sequence
    for str_name in str_names:
        str_counts[str_name] = longest_match(dna_sequence, str_name)

    # Check database for matching profiles
    for person in database:
        # Use 'all' to check if all STR counts match for this person
        match = all(person[str_name] == str_counts[str_name] for str_name in str_names)
        if match:
            print(person["name"])  # Print the matching person's name
            return

    # If no match is found, print "No Match"
    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables to track the longest run
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in the sequence for consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" within the sequence
        # If a match, move substring to next position in sequence
        # Continue moving substring and checking until no more consecutive matches
        while True:
            # Define the start and end of the substring
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring, increase the count
            if sequence[start:end] == subsequence:
                count += 1
            # If no match, exit the inner loop
            else:
                break

        # Update longest run if this run is the longest found so far
        longest_run = max(longest_run, count)

    # Return the longest run found after checking the entire sequence
    return longest_run


main()
