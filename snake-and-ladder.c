#include<stdio.h>
//Regular text
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Regular bold text
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

void printnum_ladder(int num)
{
    printf(MAG " %3d " WHT, num);
}
void printnum_snake(int num)
{
    if (num == 99 || num == 85 || num == 68)
        printf(BRED " %3d " WHT, num);
    else
        printf(RED " %3d " WHT, num);
}

void display(int arr[][10])
{
    for (int i = 9; i>=0; i--)
    {
        
        if(i%2 != 0){
        for (int j = 9; j >= 0; j--)
        {
            for (int j = 9; j >= 0; j--)
            {
                int x = arr[i][j];
                if (x == 8 || x == 12 || x == 30 || x == 21 || x == 45 || x == 40 || x == 80 || x == 82 || x == 98 || x == 57 || x == 63 || x == 71 || x == 90 || x == 41)
                    printnum_ladder(x);
                else if (x == 99 || x == 83 || x == 78 || x == 62 || x == 59 || x == 42 || x == 38 || x == 22 || x == 19 || x == 2 || x == 55 || x == 66 || x == 76 || x == 85 || x == 32 || x == 50 || x == 52 || x == 68)
                    printnum_snake(x);
                else
                    printf(" %3d ", x);
            }
            printf("\n\n");
        }
        printf("\n\n");
        }
        else{
        for (int j = 0; j<10; j++)
        {
            for (int j = 0; j < 10; j++)
            {
                int x = arr[i][j];
                if (x == 8 || x == 12 || x == 30 || x == 21 || x == 45 || x == 40 || x == 80 || x == 82 || x == 98 || x == 57 || x == 63 || x == 71 || x == 90 || x == 41)
                    printnum_ladder(x);
                else if (x == 99 || x == 83 || x == 78 || x == 62 || x == 59 || x == 42 || x == 38 || x == 22 || x == 19 || x == 2 || x == 55 || x == 66 || x == 76 || x == 85 || x == 32 || x == 50 || x == 52 || x == 68)
                    printnum_snake(x);
                else
                    printf(" %3d ", x);
            }
            printf("\n\n");
        }
        printf("\n\n");
        }
        
    }
    
    
}

int main() 
{
    int arr[10][10],k = 1;
    for (int i = 0; i < 100; i++)
    {
        *(*arr + i) = k++; 
    }
    printf("\n\n");
    display(arr);
    printf("\n");
    
    
    
    return 0;
}
