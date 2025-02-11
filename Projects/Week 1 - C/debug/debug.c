#include <stdio.h>
#include <string.h> // for strcspn
int main(void)
{
    // Declare variables
    char name[100];
    char location[100];

    // Ask for your name and where you live
    printf("What is your name? ");
    fgets(name, sizeof(name), stdin);

    printf("Where do you live? ");
    fgets(location, sizeof(location), stdin);

    // Remove newline characters from input
    name[strcspn(name, "\n")] = '\0';
    location[strcspn(location, "\n")] = '\0';

    // Say hello
    printf("Hello, %s, from %s!\n", name, location);

    return 0;
}