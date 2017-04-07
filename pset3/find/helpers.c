/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
 //binary search on values[] of size n, searching for value
bool search(int value, int values[], int n)
{
    
    int left = 0;
    int right = n-1;
    int mid;
    
    while (left <= right)
    {   
    mid = ((left + right) / 2);
    
    if (values[mid] == value)
    {
        return true;
    }
    
    else if (values[mid] > value)
    {
       right = mid - 1; 
    }
    
    else if (values[mid] < value)
    {
       left = mid + 1;
    }
   
        
    }
    
    return false;
    
}
       



/**
 * Sorts array of n values.
 */

 
 
void sort(int values[], int n)
{
    int i, j;
    int temp;
    for (i = 0; i < (n - 1); i++) 
    {
       
        //perform the swaps
        for (j = 0; j < n-1-i; j++)
        {
            if (values[j] > values[j + 1])
            {
                temp=values[j];
                values[j]=values[j+1];
                values[j+1]=temp;
            }
        }
        
       
        
    }
}