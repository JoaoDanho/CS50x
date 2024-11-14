# Uses get_int from CS50; if not in the CS50 environment, use input() and int() instead
from cs50 import get_int

# Prompt the user for the pyramid's height until a valid value is provided.
while True:
    height = get_int("Height: ")
    if height >= 1 and height <= 8:
        break

# Generate the pyramid
for i in range(1, height + 1):

    # Calculate how many spaces and hashes are needed for each row
    spaces = height - i
    hashes = i
    print(" " * spaces + "#" * hashes)
