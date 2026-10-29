#include <stdio.h>

int main(void)
{
    const int n = 3;
    //For each row
    for (int row = 0; row < n; row++)
    {
        //For each column
        for (int col  = 0; col < n; col++)
        {
            //Print one brick
            printf("#");
        }
        printf("\n");
    }

}
