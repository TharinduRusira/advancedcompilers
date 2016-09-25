#include "interval.h"
interval interval::operator-(const interval &y){
	int a,b;
	// we do the subtraction this-y
	a = lo-y.hi;
	b = hi - y.lo;
	/*
	 * We are rounding the values that are outside our abstract domain [-32,31] so that there will be no undefined behavior
	 */
	if(a<MIN){a=(MAX+1) - a%(MAX+1);}
	if(b>MAX){b=MIN + b%(-1*MIN);}
	//if a>b after wrapping around, return TOP
	if(b<a){return top();}
	return interval(a,b) ;
}

