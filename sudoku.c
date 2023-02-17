
#include <stdio.h>
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

    int ans[9][9];
    answer(*ar,*ans);
    
   return 0;
}