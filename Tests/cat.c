#include <cs50.h>
#include <stdio.h>

//Prototype funcions
int get_n(void);
void meow(int num);

int main(void)
{
    //Get a number from the user
    int n = get_n();

    meow(n);
}

int get_n(void)
{
    //Get user input
    int n;
    do
    {
        n = get_int("What is n? ");
    }
    while(n < 0);
    return n;
}

void meow(int num)
{
    //Meow a set number of times
    for (int i = 0; i < num; i++)
    {
        printf("meow\n");
    }
}
