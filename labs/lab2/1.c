#include <stdio.h>

int main(void) {
int a1, a2, a3, a4, b1, b2, b3, b4,c1, c2, c3, c4, d1, d2, d3, d4;
int row1, row2, row3, row4;
int column1, column2, column3, column4;
int diag1, diag2;
printf("Enter the numbers:");

scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", &a1, &a2, &a3, &a4, &b1, &b2, &b3, &b4,&c1, &c2, &c3, &c4,&d1, &d2, &d3, &d4);

row1=a1+a2+a3+a4;
row2=b1+b2+b3+b4;
row3=c1+c2+c3+c4;
row4=d1+d2+d3+d4;
column1=a1+b1+c1+d1;
column2=a2+b2+c2+d2;
column3=a3+b3+c3+d3;
column4=a4+b4+c4+d4;
diag1=a1+b2+c3+d4;
diag2=a4+b3+c2+d1;
printf("%3d%3d%3d%3d\n",a1, a2, a3, a4);
printf("%3d%3d%3d%3d\n",b1, b2, b3, b4);
printf("%3d%3d%3d%3d\n",c1, c2, c3, c4);
printf("%3d%3d%3d%3d\n",d1, d2, d3, d4);
printf("rows sums:");
printf("%3d%3d%3d%3d\n",row1, row2, row3, row4);
printf("column sums:");
printf("%3d%3d%3d%3d\n",column1, column2, column3, column4);
printf("diagonal sums:");
printf("%3d%3d\n",diag1,diag2);
return 0;


}
