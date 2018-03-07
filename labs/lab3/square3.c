#include<stdio.h>

int main(void){
	int i,n,square;
	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in table: ");
	scanf("%d",&n);
	
	i =1;

	for (square=1;i<=n;i++){
		square=i*i;
		printf("%10d%10d\n",i,square);
		
		
	}
	return 0;
}
