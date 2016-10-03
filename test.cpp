#include "interval.h"
using namespace std;

int main(void){
//test cases

interval i1(-32,-32); interval i2(-32,-31);
interval i3(-31,-31); interval i4(0,0);
interval i5(-31,30); interval i6(-32,2);
interval i7(0,30); interval i8(-32,1);
interval i9(1,1); interval i10(-32,31);
cout << "Interval operator-"<<endl;
//operator- test cases
cout << i1<< "-"<< i8 << "="<< i1.operator-(i8) << endl;
cout << i2<< "-"<< i10 << "="<< i2.operator-(i10) << endl;
cout << i1<< "-"<< i9 << "="<< i1.operator-(i9) << endl;
cout << i7<< "-"<< i1 << "="<< i7.operator-(i1) << endl;
cout << i1<< "-"<< i9 << "="<< i1.operator-(i9) << endl;
cout << i6<< "-"<< i2 << "="<< i6.operator-(i2) << endl;
cout << i7<< "-"<< i8 << "="<< i7.operator-(i8) << endl;

cout << "Interval bitwise-AND"<<endl;
//bitwise-AND test cases
cout << i1 << "&" << i2 << "="<< i1.operator&(i2) << endl;
cout << i3 << "&" << i6 << "="<< i3.operator&(i6) << endl;
cout << i1 << "&" << i3 << "="<< i1.operator&(i3) << endl;
cout << i1 << "&" << i4 << "="<< i1.operator&(i4) << endl;
cout << i6 << "&" << i5 << "="<< i6.operator&(i5) << endl;



return 0;
}
