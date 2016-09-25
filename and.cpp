#include "interval.h"
interval interval::operator&(const interval&y){
	int a,b;
	if(hi<0 &&  y.hi<0) {a=MIN;b=-1;} // both intervals are in the negative range (leading bit is 1)
	else if(lo>=0 && y.lo>=0) {a=0;b=MAX;} // both intervals are in the positive range (leading bit is 0)
	else if((hi<0 && y.lo>=0)||(lo>=0 && y.hi<0))
	{
		//result is positive
		a = 0; b=MAX;
		//can we give a more precise answer than [0,MAX]?
	}// if one interval is positive and the other is negative, result will be in positive range
	else {return top();} //defaulting to TOP
	return interval(a,b);
}
