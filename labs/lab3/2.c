#include<stdio.h>

int main(void){
	int m,n,remainder;
	printf("Enter two integers: ");
	scanf("%d%d",&m,&n);
	if(m==0){
		printf("Greatest common divsora: %d\n",n);
	}
	else if(n==0){
		printf("Greatest common divsorb: %d\n",m);
	}
	else {

		while(n>0){
			remainder=m%n;
			m=n;
			n=remainder;
		
		}
		printf("Greatest common divsor: %d\n",m);

			


	}	
	

return 0;
}
