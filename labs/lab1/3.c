#include<stdio.h>

int main(void){
	float loan,interest,payment,first,second,third;
	printf("Enter amount of loan: ");
	scanf("%f",&loan);
	printf("Enter inerest rate: ");
	scanf("%f",&interest);
	printf("Enter monthly payment: ");
	scanf("%f",&payment);
	first=loan*(1+(interest/100)/12)-payment;
	printf("Balance remaining after first payment: $%10.2f\n",first);
	second=first*(1+(interest/100)/12)-payment;
	printf("Balance remaining after second payment: $%10.2f\n",second);
	third=second*(1+(interest/100)/12)-payment;
	printf("Balance remaining after third payment: $%10.2f\n",third);
}
