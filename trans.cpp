/*
Tharindu Rusira (u1011765)

Abstract transfer function for unsigned subtraction of intervals (x,y) where x,y are 4-bit integers 
The subtraction operation is defined by [x1,x2]-[y1,y2] = [x1-y2,x2-y1]
https://en.wikipedia.org/wiki/Interval_arithmetic#Simple_arithmetic

Since 4-bit integers are used, 0<x,y<15 and we are required to wrap around underflows(negetive values), overflows will not occur because the subtracted result is always less than or equal to 15. 

*/

#include <iostream>
#include <assert.h>


class interval{

	// 5-bit signed integers [-16,15]
	int lo,hi;

	public:
	static interval subtract(interval,interval);
	static interval bitwise_and(interval,interval);

};


void sub(interval x, interval y){
// let's do a quick sanity check to make sure we are getting 5-bit unsigned integers
assert(x.lo>=-16 || x.lo<=15 || x.hi>=-16 || x.hi<=15 || y.lo>=-16 || y.lo<=15 || y.hi>=-16 || y.hi<=15 || x.lo<x.hi || y.lo<y.hi);
	int a,b;
	// we do the subtraction y-x
	a = y.lo-x.hi;
	b = x.lo - y.hi;

	if(a<0){
		a=0; //rounding to 0, closest value in the range [0,15]
	}
	if(b<0 || b<a){
		b=15; //rounding to 15, closest value in the range [0,15]
	}
/* If a, the lower bound underflows, eg. (-2,5), we approximate the lowerbound to 0, which gives us the interval (0,5)*/
/* If b, the upper bound underflows or less than a valid lowerbound, eg. (2,-1),  we approximate the upper bound to 15, which gives us the interval (2,15) */
	printf("(%d,%d)-(%d,%d)=(%d,%d)\n",x1,x2,y1,y2,a,b);
}


void bitwise_and(interval x, interval y){
assert(x.lo>=-16 || x.lo<=15 || x.hi>=-16 || x.hi<=15 || y.lo>=-16 || y.lo<=15 || y.hi>=-16 || y.hi<=15 || x.lo<x.hi || y.lo<y.hi);




}








int main(void){
//test cases
	sub(4,5,1,2);
	sub(1,2,3,4);
	sub(5,6,7,8);

return 0;
}
