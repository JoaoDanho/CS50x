from cs50 import get_float

# Prompt user for a non-negative amount
while True:
    change = get_float("Change owed: ")
    if change >= 0:
        break

# Convert dollars to cents to avoid float precision issues
cents = round(change * 100)

# Initialize the coin counter
coins = 0

# Calculate number of quarters (25$)
coins += cents // 25
cents %= 25

# Calculate number of dimes (10$)
coins += cents // 10
cents %= 10

# Calculate number of nickels (5$)
coins += cents // 5
cents %= 5

# Calculate number of pennies (1$)
coins += cents

# Output the total number of coins
print(coins)
