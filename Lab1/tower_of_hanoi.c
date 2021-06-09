#include <stdio.h>
#include <stdlib.h>
void towerOfHanoi(int n, char from_rod,char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("\nMove disk 1 from rod %c to %c rod ",from_rod,to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("\nMove disk 1 from rod %c to %c rod ",from_rod,to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
 
int main()
{
    int n ; 
    printf("Enter the number of rings\n");
    scanf("%d",&n);
    towerOfHanoi(n, 'A', 'C', 'B'); 
    return 0;
}
  
