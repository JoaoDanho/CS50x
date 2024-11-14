from cs50 import get_string
import re

# Prompt the user for text input
text = get_string("Text: ")

# Initialize counters for letters, words, and sentences
letters = 0
words = 1  # Start at 1 to count the last word without a trailing space
sentences = 0

# Count letters, words, and sentences
for char in text:
    if char.isalpha():
        letters += 1
    elif char == ' ':
        words += 1
    elif char in ['.', '!', '?']:
        sentences += 1

# Calculate L and S as specified in the Coleman-Liau formula
L = (letters / words) * 100
S = (sentences / words) * 100

# Apply the Coleman-Liau formula
index = 0.0588 * L - 0.296 * S - 15.8

# Determine the grade level, rounded to nearest integer
grade = round(index)

# Print the appropriate grade level
if grade >= 16:
    print("Grade 16+")
elif grade < 1:
    print("Before Grade 1")
else:
    print(f"Grade {grade}")
