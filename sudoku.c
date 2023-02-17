
#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#define NORMAL  "\x1b[0m"
#define RED    "\x1b[31m"
#define GREEN  "\x1b[32m"
void disp(int *ar)  //? diaplay the output at every step 
{
    for(int i=1;i<=81;i++)
    {
        int n=*(ar+i-1);
        if(n!=0)
        printf(GREEN"%d ",n);
        else
        printf(NORMAL"%d ",n);
        
        if(i%3==0 && i%9!=0)
        printf("|\t");
        
        if(i%9==0 && i!=81)
        printf("\n");
        
        if(i%27==0 && i!=81)
        printf(NORMAL"_____________________\n");
    }
}
void answer(int *ar,int *ans) //? converts ar to answer
{
    for (int i = 0; i < 81; i++)
    {
        *(ans + i) = *(ar + i); 
        
    }
    
}
void position(int (*arr)[9],int (*pos)[18])
{
    int k = 0;
    for (int num = 1; num <10 ; num++)
    {
        k=0;
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (num == arr[row][col])
                {
                    pos[num-1][k++] = row;
                    pos[num-1][k++] = col;

                }
                
            }
            
        }
        
    }
    
}
void for_loop(int )


int main()
{
    int ar[27][3]={{0,0,0},{0,0,6},{0,0,3},
                   {0,0,0},{0,1,0},{4,0,0},
                   {0,4,0},{8,0,0},{0,7,9},
                   {8,0,9},{0,7,0},{0,6,0},
                   {0,6,0},{0,8,0},{0,0,5},
                   {0,5,7},{0,3,0},{8,0,0},
                   {2,0,0},{1,0,9},{0,0,0},
                   {0,0,0},{5,0,3},{0,0,0},
                   {0,0,0},{0,0,0},{6,0,0}};
    disp((*ar));
    printf("\n");
    printf("\n");

    int ans[9][9],pos[9][18] = {0};
     for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            pos[i][j]=-1;
        }
        
    }
    answer(*ar,*ans);
    position(ans,pos);
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            printf("%d  ",pos[i][j]);
        }
        printf("\n");     
    }
    
    
    
   return 0;
}