/*
Tharindu Rusira (u1011765)

Abstract transfer function for unsigned subtraction of intervals (x,y) where x,y are 4-bit integers 
The subtraction operation is defined by [x1,x2]-[y1,y2] = [x1-y2,x2-y1]
https://en.wikipedia.org/wiki/Interval_arithmetic#Simple_arithmetic

Since 4-bit integers are used, 0<x,y<15 and we are required to wrap around underflows(negetive values), overflows will not occur because the subtracted result is always less than or equal to 15. 
We can shift bits to keep the last 4 bits and chop the rest of the bit string to address this issue.
*/

#include <stdio.h>
int a,b;

void sub(int x1,int x2, int y1,int y2){
	a = x1 - y2;
	b = x2 - y1;

	if(a>=0 && a<16 && b>=0 && b <16){
		a=a; b=b;
	}
	if(a<0){
		a=0; //rounding to 0, closest value in the range [0,15]
	}
	if(b<0){
		b=0; //rounding to 0, closest value in the range [0,15]
	}
	
}



int main(void){

	sub(1,2,3,4);
	printf("a=%d\tb=%d\n",a,b);

return 0;
}
