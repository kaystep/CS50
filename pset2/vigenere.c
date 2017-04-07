#include <cs50.h>
 #include <ctype.h>
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>



int main(int argc, string argv[])



{
    //Make sure only two arguments are taken at the command line   
    if (argc != 2)
    {
        printf("You must submit just one key string\n");
        return 1;
    }
    //Ensure that the key given only contains alphabetical characters
    for (int i = 0, n =strlen(argv[1]); i < n; i++)
    if (!isalpha(argv[1][i]))
    {
        printf("Your key must only contain alphabetical characters\n");
        return 1;
    }

//Get a string input from the user
printf("plaintext: ");

//get Plain text to decipher
string s = GetString();
//Set the key = to the user input
char *key = (argv[1]); 

//Position counter for the ciphertext
int k = 0;
printf("ciphertext: ");

    //as long as j is less than the strlen of s, iterate through this for loop
    for (int j = 0, n = strlen(s); j < n; j++)
    {
        k = k % strlen(key);
        //if the submitted text is upper case convert it to an alphabetical index and cypher it by the key submitted   
        if isupper(s[j])
        
        {
            printf("%c", (((s[j] - 'A') + (key[k] -'A'))%26 +'A')); 
            k++;
        }
        //if the submitted text is lower case convert it to an alphabetical index and cypher it by the key submitted
        else if islower(s[j])
        {
            printf("%c", (((s[j] - 'a') + (tolower(key[k]) - 'a'))%26 + 'a'));
            k++;
        }
        
       
            
        
        //print whatever the character is when the submission is not upper or lower case
        else
        {
            printf("%c", s[j]);
        }
    
    }
    
    printf("\n");

    return 0;
    
}