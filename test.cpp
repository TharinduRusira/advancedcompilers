#include "interval.h"
using namespace std;

int main(void){
//test cases

interval i1(10,12); interval i2(0,7);
interval i3(-10,-5); interval i4(-15,0);
interval i5(-12,15); interval i6(-4,-3);
interval i7(-16,-16); interval i8(-16,-15);
//cout << "Interval operator-"<<endl;
//operator- test cases
cout << i1<< "-"<< i2 << "="<< i1.operator-(i2) << endl;
cout << i3<< "-"<< i4 << "="<< i3.operator-(i4) << endl;
cout << i5<< "-"<< i1 << "="<< i5.operator-(i1) << endl;
cout << i4<< "-"<< i1 << "="<< i4.operator-(i1) << endl;
cout << i5<< "-"<< i6 << "="<< i5.operator-(i6) << endl;
cout << i6<< "-"<< i2 << "="<< i6.operator-(i2) << endl;
cout << i7<< "-"<< i8 << "="<< i7.operator-(i8) << endl;

//cout << "Interval bitwise-AND"<<endl;
//bitwise-AND test cases
cout << i1 << "&" << i2 << "="<< i1.operator&(i2) << endl;
cout << i3 << "&" << i6 << "="<< i3.operator&(i6) << endl;
cout << i1 << "&" << i3 << "="<< i1.operator&(i3) << endl;
cout << i1 << "&" << i4 << "="<< i1.operator&(i4) << endl;
cout << i6 << "&" << i5 << "="<< i6.operator&(i5) << endl;



return 0;
}
