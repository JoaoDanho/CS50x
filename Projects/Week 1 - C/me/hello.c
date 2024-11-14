#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // define the type and name of my variable, an use the function get_string
    string name = get_string("hello, what is your name?\n");

    // then use printf to the message "hello +(your name)
    printf("hello, %s\n", name);
}
