//This program takes a person's name and outputs their initials capitalized

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)

{

    //Store the User's name in a string
    string s = get_string();
    
    //Capitalize and print the first Letter of the Person's name
    printf("%c", toupper(s[0]));
   
   //find the space between the first and last name, then print the capitalized letter of the last name
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == ' ')
        {
            printf("%c", toupper(s[i + 1]));
        }
        
        }
    
    printf("\n");
}