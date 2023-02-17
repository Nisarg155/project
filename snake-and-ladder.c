#include<stdio.h>

void display(int *arr)
{
    for (int i = 100; i>0; i--)
    {
        if(i%10 == 0)
        {
            printf("\n");
        printf("_________________________________________________________________________________");
        printf("\n");
        }
        printf("   %2d  ",i);
        printf("|");

    }
    
    
}

int main() 
{
    int arr[10][10];
    for (int i = 0; i < 100; i++)
    {
        *(*arr + i) = i; 
    }
    display(arr);
    printf("\n");
    
    
    
    return 0;
}