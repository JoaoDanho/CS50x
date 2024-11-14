#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int remaining_cents; // define the variable as int

    do // this prompt asks the usuary to tell how much is the exchange
    {
        remaining_cents = get_int("Troco devido: ");
    }
    while (remaining_cents < 1); // if the exchange is less than 1, the prompt will repeat

    int coins = 0; // create the variable coins as int

    coins += remaining_cents / 25; // exemple: cents = 117, then 117 / 25 = 4
    remaining_cents %= 25;         // 25 * 4 = 100, so remains 17

    // reminder, coins are 4 at the moment, and left 17 cents.
    coins += remaining_cents / 10; // 17 / 10 = 1, so we add that 1 to the other 4 coins.
    remaining_cents %= 10;         // remains 7

    // coins at moment are 5.
    coins += remaining_cents / 5; // repeat the process, here we get 1 coin.
    remaining_cents %= 5;         // remains 3

    // coins at moment 6.
    coins += remaining_cents / 1; // now left 3 cents, 3 / 1 = 3;
    remaining_cents %= 1;         // remains 0

    // 4(25 cent) + 1(10 cent) + 1(5 cent) + 3(1 cent) = 8 coins

    printf("%i\n", coins);
}
