#include<stdio.h>

int main(void){
	int m,n,remainder,a,b;
	printf("Enter a fraction: ");
	scanf("%d/%d",&m,&n);
	a=m;
	b=n;
	while(n>0){
		remainder=m%n;
		m=n;
		n=remainder;
		
		}
	printf("In lowest terms: %d/%d\n",a/m,b/m);
	
	

return 0;
}
