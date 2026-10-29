#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompts the user to enter their name
    string name = get_string("What is your name? ");
    // Prints a hello message using the name
    printf("hello, %s\n", name);
}
