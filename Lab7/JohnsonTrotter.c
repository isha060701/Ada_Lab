#include <stdlib.h>
#include <stdio.h>
int lr=1;
int rl=0;
int fact(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
        res = res * i;
    return res;
}
int mobile_pos(int a[],int n,int mobile)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==mobile)
        {
            return i;
        }
    }
}
int largest_mobile(int a[],int dir[],int n)
{
    int mobile=0;
    for(int i=0;i<n;i++)
    {
        if(dir[a[i]-1]==rl && i!=0)
        {
            if(a[i]>a[i-1] && a[i]>mobile)
            {
                mobile=a[i];
            }
        }
       if(dir[a[i]-1]==lr && i!=n-1)
       {
           if(a[i]>a[i+1] && a[i]>mobile)
           {
              mobile=a[i];
           }
       }
    }
       if (mobile == 0)
        {
            return 0;
        }
       else
        {
            return mobile;
        }
}
void perm(int a[],int dir[],int n)
{
    int mobile=largest_mobile(a,dir,n);
    int pos=mobile_pos(a,n,mobile);
    if(dir[a[pos]-1]==rl)
    {
        int temp=a[pos];
        a[pos]=a[pos-1];
        a[pos-1]=temp;
    }
    else if(dir[a[pos]-1]==lr)
    {
        int temp=a[pos];
        a[pos]=a[pos+1];
        a[pos+1]=temp;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>mobile)
        {
            if(dir[a[i]-1]==lr)
            {
                dir[a[i]-1]=rl;
            }
            else if(dir[a[i]-1]==rl)
            {
                dir[a[i]-1]=lr;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int a[n];
    int dir[n];
    for(int i=0;i<n;i++)
    {
        a[i]=i+1;
        dir[i]=0;
        printf("%d ",a[i]);
    }
    printf("\n");
    for(int i=1;i<fact(n);i++)
    {
        perm(a,dir,n);
    }
    return 0;
}
