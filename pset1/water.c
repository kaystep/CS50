#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("how many minutes did you shower today\n");
    int n = get_int();
    int bottles = n * 12;
    printf("Wow you used %i bottles of water.\n", bottles);
}