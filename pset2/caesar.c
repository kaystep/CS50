 #include <cs50.h>
 #include <ctype.h>
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>



int main(int argc, string argv[])



{
//Make sure only two arguments are taken at the command line   
    if (argc != 2 || argv[1] == NULL)
    {
        printf("Usage: ./caesar <key>\n");
        return 1;
    }


    //Convert Argv into an integer for the key    
    int k = atoi(argv[1]); 
    if (k < 0)
    {
        printf("the key must be greater than 0\n");
        return 1;
    }
    
    else
    {
//Get a string input from the user
printf("plaintext: ");
string s = GetString();

printf("ciphertext: ");
    //as long as i is less than the strlen of s, iterate through this for loop
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //if the submitted text is upper case convert it to an alphabetical index and cypher it by the key submitted   
        if isupper(s[i])
        {
            printf("%c", (s[i] - 'A'+ k)%26 +'A'); 
        }
        
        //if the submitted text is lower case convert it to an alphabetical index and cypher it by the key submitted
        else if islower(s[i])
        {
            printf("%c", (s[i] - 'a' + k)%26 + 'a');
        }
        
        //print spaces when the submission is not upper or lower case
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
    return 0;
    }
}