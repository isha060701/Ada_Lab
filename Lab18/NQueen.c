#include <stdio.h>
int board[10][10];
int isSafe(int board[][10],int i,int j,int n)
{
    for(int row=0;row<i;row++)
    {
        if(board[row][j]==1)
        {
            return 0;
        }
    }
    
    int x=i;
    int y=j;
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
            return 0;
        }
        x--;
        y--;
    }
    x=i;
    y=j;
    while(x>=0 && y<n)
    {
        if(board[x][y]==1)
        {
            return 0;
        }
        x--;
        y++;
    }
    return 1;
}
int solveNQueen(int board[][10],int i, int n)
{
    if(i==n)
    {
        return 1;
    }
    for(int j=0;j<n;j++)
    {
        if(isSafe(board,i,j,n))
        {
            board[i][j]=1;
            int nextQueenPossible= solveNQueen(board,i+1,n);
            if(nextQueenPossible==1)
            {
              return 1;
            }
            board[i][j]=0;
        }
        
    }
    return 0;
}
int main()
{
    int n;
    printf("Enter the number of queens:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            board[i][j]=0;
        }
    }
    int val=solveNQueen(board,0,n);
    if(val)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==1)
                {
                    printf("Q ");
                }
                else
                {
                    printf("_ ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
