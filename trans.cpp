/*
Tharindu Rusira (u1011765)

Abstract transfer functions for 5-bit signed interval subtraction and bitwise AND
*/

#include <iostream>
#include <assert.h>
using namespace std;

class interval{

	public:
	// 5-bit signed integers [-16,15]
	int lo,hi;

	static interval subtract(interval,interval);
	static interval bitwise_and(interval,interval);
	interval(int x,int y);

};

interval::interval(int x,int y){
	lo = x;
	hi = y;

} 
interval interval::subtract(interval x, interval y){
	// let's do a quick sanity check to make sure we are getting 5-bit unsigned integers
	assert((x.lo>=-16 || x.lo<=15 || x.hi>=-16 || x.hi<=15 || y.lo>=-16 || y.lo<=15 || y.hi>=-16 || y.hi<=15 || x.lo<x.hi || y.lo<y.hi));
	int a,b;
	// we do the subtraction y-x
	a = y.lo-x.hi;
	b = y.hi - x.lo;

	/*
	 * We are rounding the values that are outside our abstract domain [-16,15] so that there will be no undefined behavior
	 */

	if(a<-16){a=16- a%16;}
	if(b>15){b=-16-b%16;}
	//if a>b after wrapping around, return TOP
	if(b<a){a=-16;b=15;}

	cout << "(" << y.lo<< ","<< y.hi << ")-("<<x.lo<<","<<x.hi<<")=("<<a<<","<<b<<")"<<endl;
	return interval(a,b);
}

interval interval::bitwise_and(interval x, interval y){

	assert((x.lo>=-16 || x.lo<=15 || x.hi>=-16 || x.hi<=15 || y.lo>=-16 || y.lo<=15 || y.hi>=-16 || y.hi<=15 || x.lo<x.hi || y.lo<y.hi));
	int a,b;
	if(x.hi<0 &&  y.hi<0) {a=-16;b=-1;} // both intervals are in the negative range (leading bit is 1)
	else if(x.lo>=0 && y.hi>=0) {a=0;b=15;} // both intervals are in the positive range (leading bit is 0)
	else {a=-16;b=15;} //defaulting to TOP

	cout << "(" << x.lo<< ","<< x.hi << ")&("<<y.lo<<","<<y.hi<<")=("<<a<<","<<b<<")"<<endl;

	return interval(a,b);
}


int main(void){
//test cases

interval i1(10,12); interval i2(0,7);
interval i3(-10,-5); interval i4(-15,0);
interval i5(-12,15);

//subtract test cases
//interval::subtract(i2,i1);
//interval::subtract(i3,i4);
//interval::subtract(i5,i1);

//bitwise-AND test cases
cout << (-10 & 0);
return 0;
}
