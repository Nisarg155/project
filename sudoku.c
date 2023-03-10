#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#define NORMAL  "\x1b[0m"
#define RED    "\x1b[31m"
#define GREEN  "\x1b[32m"
  int question[27][3]= {{0,0,0},{0,0,6},{0,0,3},
                        {0,0,0},{0,1,0},{4,0,0},
                        {0,4,0},{8,0,0},{0,7,9},
                        {8,0,9},{0,7,0},{0,6,0},
                        {0,6,0},{0,8,0},{0,0,5},
                        {0,5,7},{0,3,0},{8,0,0},
                        {2,0,0},{1,0,9},{0,0,0},
                        {0,0,0},{5,0,3},{0,0,0},
                        {0,0,0},{0,0,0},{6,0,0}};
int answer[9][9];
void disp(int *question,int *answer)
{
    for(int i=1;i<=81;i++)
    {
        int n=*(answer+i-1);
        if(n!=0)
        {
            if(*(question+i-1)!=0)
            printf(GREEN"%d ",n);
            else
            printf(NORMAL"%d ",n);
        }
        else
        printf(RED"%d ",n);
        
        if(i%3==0 && i%9!=0)
        printf(NORMAL"|\t");
        
        if(i%9==0 && i!=81)
        printf("\n");
        
        if(i%27==0 && i!=81)
        printf(NORMAL"_____________________\n");
    }
}
int chek(int *answer,int num,int index)
{
    int row=(index-1)/9;
    int col=index%9;
    for(int i=0;i<9;i++)
    {
    if(*(answer+(row*9+i))==num)
    return 1;
    }
    
    printf("\nprinting col:\n");
    for(int i=0;i<81;i+=9)
    {
        if(*(answer+(col+i))==num)
        return 1;
    }
    
    printf("\nprinting box::\n");
    row-=row%3;
    col-=col%3;
    int ibox=(row*9)+col;
    printf("\n%d\n",ibox);
    for(int i=1;i<=21;)
    {
        if(*(answer+ibox+i-1)==num)
        return 1;
        if(i%3==0)
        i+=6;
        i++;
    }
    return 0;
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
                    pos[num-1][k] = row;
                    pos[num-1][k+1] = col;
                    k+=2;
                }
                
            }
            
        }
        
    }
    
}
int main()
{
    int pos[9][18] = {0};
    for(int i=0;i<81;i++)
    *(*answer+i)=*(*question+i);

    
    disp(*question,*answer);
    printf("\n\n");    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            pos[i][j]=-1;
        }
        
    }
    position(answer,pos);
    
   /* for (int i = 0; i < 9; i++)  //!commented position array
    {
        for (int j = 0; j < 18; j++)
        {
            printf("%d  ",pos[i][j]);
        }
        
        printf("\n");
        
    }*/
    return 0;
}
