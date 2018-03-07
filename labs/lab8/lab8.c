#include <stdio.h>
#include <string.h>
#include <stdlib.h>
float binarysearch(float loan,float int_rate,float months){
	float low = 0;
	float high = loan;
	float principal_out,payment,interest,principal,cent;
	cent= months/100;
	//printf("%f\n",cent);
	for(;;){
		payment = (low+high)/2;
		//printf("%.2f\n",payment);
		principal_out = loan;
		for(int i=0;i< months;i++){
			interest = principal_out*int_rate;
			principal = payment - interest;
			principal_out = principal_out-principal;
			//printf("%.2f %.2f %.2f %.2f\n",principal_out,payment,interest,principal);
		}
		if ((principal_out<=0 && principal_out>=-cent)){
		  printf("Your monthly payment = %.2f\n",payment);
		  return payment;
		  exit(-1);
		}
		else if(principal_out>0){
			low = payment;
		}
		else if(principal_out<-cent){
			high = payment;
		}

	}
}

int main(void){
        float months;
	float loan,int_rate,payment;

	printf("Enter the loan amount: ");
	scanf("%f",&loan);
	printf("Enter the annual interest rate: ");
	scanf("%f",&int_rate);
	int_rate = int_rate/1200;
	printf("Enter the number of months to pay back: ");
	scanf("%f",&months);
	//printf("%f %f %f",loan,int_rate,months);

	payment=binarysearch(loan,int_rate,months);
	printf("Your monthly payment = %.2f\n",payment);
	printf("        principlal_outstanding         payment        interest        principal\n");
	int i=0;
	float interest, total_int=0,principal,p_out,lastpay;
	p_out=loan;

	for(i=1;i<months;i++){
	  
	  interest = p_out*int_rate;
	  total_int += interest;
	  principal = payment - interest;
	  printf("payment No.%d:  %15.2f %15.2f %15.2f %15.2f\n",i,p_out,payment,interest,principal);
	  p_out -= principal;
	 
	}
	interest = p_out*int_rate;
	total_int += interest;
	principal = p_out;
	lastpay=principal+interest;
	printf("payment No.%d:  %15.2f %15.2f %15.2f %15.2f\n",i,p_out,lastpay,interest,principal);
	printf("Total interest paid = %.2f\n",total_int);
	printf("Total principal unpaid= 0.00\n");
}
