#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)

{
    
    float change;
    int quarter;
    int dime;
    int nickel;
    int penny;
    int coins_used;
    
do
{   
    printf("How much changed is owed\n");
    change = get_float();
} while (change < 0 );

    //convert from dollars to cents
    change = round(change * 100);
    
    //initialize the change and numbers of coins used variables
    quarter = 25;
    dime = 10;
    nickel = 5;
    penny = 1;
    coins_used = 0;
//multiple while loops to iterate through the change needed, this could be refactored using module instead   
while ( change >= quarter) {
    change = change - quarter;
    coins_used++;
}
    
while (change >= dime) {
    change = change - dime;
    coins_used++;
}
    
while (change >= nickel) {
    change = change - nickel;
    coins_used++;
}
    
while (change >= penny) {
    change = change - penny;
    coins_used++;
}
    
    
    printf("%i\n", coins_used);
    
}