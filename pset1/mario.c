#include <cs50.h>
#include <stdio.h>


int main(void)

{
    int height;
    int spaces;
    int hashes;
    int rows;
do
{
    printf("Please enter a number that is greater than 0 but less than 24, this will be how high Mario climbes\n");
    height = get_int();
}
while (height < 0 || height > 23);


// Start with row 1 and sequentially add 1 until the number of rows == height
for (rows = 1; rows <= height; rows++)
{
    //Subtract a space from ech sequential row
    for (spaces = height - rows; spaces > 0; spaces--)
    {
    printf(" ");
    }
    // Add a space to each sequential row
    for (hashes = 1; hashes <= rows + 1; hashes++)
    {
    printf("#");
    }
    //Print a new line to restart the loop
    printf("\n");
}

return 0;


}