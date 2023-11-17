#include<iostream>
#include"varparm.h"
using namespace std;
using namespace Varparm;

void main() {
	int a = ivarparm(4, 1, 2, 3, 7);
	int b = svarparm(4, 1, 2, 3, 7);
	double c = fvarparm(1.0, 2.0, 3.0, 7.0, FLT_MAX);
	double d = dvarparm(1.0, 2.0, 3.0, 7.0, DBL_MAX);
}