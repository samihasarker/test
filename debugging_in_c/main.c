#include <stdio.h>
#include <stdlib.h>

int main()
{   int n,i,sum=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    for(i=1;i<n;i++){
        sum=sum+i;
    }
    printf("sum is:%d\n",sum);
    return 0;
}
