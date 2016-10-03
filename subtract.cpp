#include "interval.h"
interval interval::operator-(const interval &y){
	int a,b;
	// we do the subtraction this-y
	a = lo-y.hi;
	b = hi - y.lo;
	/*
	 * We are rounding the intervals that are outside our abstract domain [-32,31] so that there will be no undefined behavior
	 */
	if(a<MIN && b> MAX){a= a + RANGE; b= b-RANGE;}
	else if(a<MIN && b<MIN){a= a+RANGE;b=b+RANGE;}
	else if(a>MAX && b>MAX){a=a-RANGE;b=b-RANGE;}
	else if((a<MIN && b<MAX && b>MIN)||(b>MAX && a>MIN && a<MAX)){return top();}
   	if(b<a){return top();}
	return interval(a,b) ;
}

