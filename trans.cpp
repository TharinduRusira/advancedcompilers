/*
Tharindu Rusira (u1011765)

Abstract transfer functions for 5-bit signed interval subtraction and 
*/

#include <iostream>
#include <assert.h>
using namespace std;

class interval{

	// 5-bit signed integers [-16,15]
	int lo,hi;

	public:
	static interval subtract(interval,interval);
	static interval bitwise_and(interval,interval);

};


interval interval::subtract(interval x, interval y){
	// let's do a quick sanity check to make sure we are getting 5-bit unsigned integers
	assert(x.lo>=-16 || x.lo<=15 || x.hi>=-16 || x.hi<=15 || y.lo>=-16 || y.lo<=15 || y.hi>=-16 || y.hi<=15 || x.lo<x.hi || y.lo<y.hi);
	int a,b;
	interval result;
	// we do the subtraction y-x
	a = y.lo-x.hi;
	b = x.lo - y.hi;

	/*
	 * We are rounding the values that are outside our abstract domain [-16,15] so that there will be no undefined behavior
	 */

	if(a<-16){a=16- a%16;}
	if(b>15){b=-16-b%16;}
	//if a>b after rounding, the resulting interval is invalid
	assert(a<=b);

	result.lo = a;
	result.hi = b;
	cout << "(%d,%d)-(%d,%d)=(%d,%d)\n" << y.lo,y.hi,x.lo,x.hi,a,b;
	return result;
}

interval interval::bitwise_and(interval x, interval y){

	assert(x.lo>=-16 || x.lo<=15 || x.hi>=-16 || x.hi<=15 || y.lo>=-16 || y.lo<=15 || y.hi>=-16 || y.hi<=15 || x.lo<x.hi || y.lo<y.hi);
	interval result;



return result;
}








int main(void){
//test cases
	

return 0;
}
