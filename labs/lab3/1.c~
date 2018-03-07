#include<stdio.h>

int Max(int a, int b){
	if(a>b)
		return a;
	return b;
}

int Min(int a, int b){
	if (a<b)
		return a;
	return b;
}

int main(void){

	int a,b,c,d,big,small;
	printf("Enter four integers:");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	big=Max(a,Max(b,Max(c,d)));
	small=Min(a,Min(b,Min(c,d)));
	printf("The largest is: %d\n",big);
	printf("The smallest is: %d\n",small);

	return 0;
}



