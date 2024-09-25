import csv
import sys

def main():
    # Check for correct command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py <database.csv> <sequence.txt>")

    # Read database file into a variable
    database_file, sequence_file = sys.argv[1], sys.argv[2]
    database = {}
    with open(database_file, 'r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            name = row.pop('name')
            database[name] = row

    # Read DNA sequence file into a variable
    with open(sequence_file, 'r') as file:
        dna_sequence = file.read()

    # Find longest match of each STR in DNA sequence
    matches = {}
    for name, profiles in database.items():
        matches[name] = {}
        for str_type, repeat_count in profiles.items():
            matches[name][str_type] = longest_match(dna_sequence, str_type)
    
    # Check database for matching profiles
    for name, match in matches.items():
        if all(match[str_type] == int(repeat_count) for str_type, repeat_count in database[name].items()):
            print(name)
            break
    else:
        print("No match")

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length - subsequence_length + 1):
        if sequence[i:i + subsequence_length] == subsequence:
            current_count = 1
            # Look for consecutive repeats
            while (i + subsequence_length + subsequence_length <= sequence_length and
                   sequence[i + subsequence_length:i + subsequence_length * 2] == subsequence):
                current_count += 1
                i += subsequence_length
            longest_run = max(longest_run, current_count)
    
    return longest_run

if __name__ == "__main__":
    main()