#include <stdio.h>
#define NORMAL  "\x1b[0m"
#define RED    "\x1b[31m"
#define GREEN  "\x1b[32m"
void disp(int *question,int *answer)
{
    for(int i=1;i<=81;i++)
    {
        int n=*(answer+i-1);
        if(n!=0)
        {
            if(*(question+i)!=0)
            printf(GREEN"%d ",n);
            else
            printf(NORMAL"%d ",n);
        }
        else
        printf(NORMAL"%d ",n);
        
        if(i%3==0 && i%9!=0)
        printf(NORMAL"|\t");
        
        if(i%9==0 && i!=81)
        printf("\n");
        
        if(i%27==0 && i!=81)
        printf(NORMAL"_____________________\n");
    }
}
void chek(int *question,int *answer,int index)
{
    int row=(index-1)/9;
    int col=index%9;
    
    printf("\nrow=%d\ncol=%d\nprinting row:\n",row,col);
    for(int i=0;i<9;i++)
    printf("%d ",*(question+(row*9+i)));
    
    printf("\nprinting col:\n");
    for(int i=0;i<81;i+=9)
    printf("%d ",*(question+(col+i)));

    printf("\nprinting box::\n");
    for(int i=0;i<21;i++)
    {
        
    }
    
}
int main()
{
    int question[27][3]={{0,0,0},{0,0,6},{0,0,3},
                         {0,0,0},{0,1,0},{4,0,0},
                         {0,4,0},{8,0,0},{0,7,9},
                         {8,0,9},{0,7,0},{0,6,0},
                         {0,6,0},{0,8,0},{0,0,5},
                         {0,5,7},{0,3,0},{8,0,0},
                         {2,0,0},{1,0,9},{0,0,0},
                         {0,0,0},{5,0,3},{0,0,0},
                         {0,0,0},{0,0,0},{6,0,0}};
    
    int answer[9][9];
    for(int i=0;i<81;i++)
    *(answer+i)=*(*question+i);
    
    int numi[9]={0};
    for(int i=0;i<81;i++)
    numi[*(*question+i)-1];
    
    disp(*question,answer);
    chek(*question,answer,15);
    return 0;
}