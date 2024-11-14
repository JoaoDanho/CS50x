from cs50 import get_string

# Get credit card number from user
number = get_string("Number: ")

# Function to validate card number using Luhn's algorithm


def luhn_checksum(card_number):
    total = 0
    reverse_digits = card_number[::-1]  # Reverse the card number for easy indexing

    for i, digit in enumerate(reverse_digits):
        n = int(digit)

        # Double every second digit starting from the right
        if i % 2 == 1:
            n *= 2
            if n > 9:
                n -= 9

        total += n

    # Card is valid if total is a multiple of 10
    return total % 10 == 0


# Check if the card number is valid
if luhn_checksum(number):
    # Check for AMEX
    if len(number) == 15 and (number.startswith("34") or number.startswith("37")):
        print("AMEX")
    # Check for MASTERCARD
    elif len(number) == 16 and number.startswith(("51", "52", "53", "54", "55")):
        print("MASTERCARD")
    # Check for VISA
    elif len(number) in [13, 16] and number.startswith("4"):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
