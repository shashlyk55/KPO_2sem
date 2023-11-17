#include<iostream>
#include"Call.h"
using namespace Call;
using namespace std;

void main() {
	int a = 1, b = 2, c = 3, d = 4;
	/*cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	cout << "d = ";
	cin >> d;*/

	 int res = sum1(1, 2, 3);
	cout << "mul = " << mul(a, b, c) << endl;
	cout << "sum2 = " << sum2(a, b, c, d) << endl;
}