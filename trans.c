/*
Tharindu Rusira (u1011765)

Abstract transfer function for unsigned subtraction of intervals (x,y) where x,y are 4-bit integers 
The subtraction operation is defined by [x1,x2]-[y1,y2] = [x1-y2,x2-y1]
https://en.wikipedia.org/wiki/Interval_arithmetic#Simple_arithmetic

Since 4-bit integers are used, 0<x,y<15 and we are required to wrap around underflows(negetive values), overflows will not occur because the subtracted result is always less than or equal to 15. 

*/

#include <stdio.h>
int a,b;

void sub(int x1,int x2, int y1,int y2){
// let's do a quick sanity check to make sure we are getting 4-bit unsigned integers
if(x1<0 || x1>15 || x2<0 || x2>15 || y1<0 || y1>15 || y2<0 || y2>15){printf("bad input...\n");return;}

	a = x1 - y2;
	b = x2 - y1;

	if(a>=0 && a<16 && b>=0 && b <16){
		a=a; b=b;
	}
	if(a<0){
		a=0; //rounding to 0, closest value in the range [0,15]
	}
	if(b<0 || b<a){
		b=15; //rounding to 15, closest value in the range [0,15]
	}
/* If a, the lower bound underflows, eg. (-2,5), we approximate the lowerbound to 0, which gives us the interval (0,5)*/
/* If b, the upper bound underflows or less than a valid lowerbound, eg. (2,-1),  we approximate the upper bound to 15, which gives us the interval (2,15) */
	
}



int main(void){

	sub(1,2,3,4);
	printf("(%d,%d)-(%d,%d)=(%d,%d)",x1,x2,y1,y2,a,b);

return 0;
}
