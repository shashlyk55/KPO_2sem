#include<iostream>
using namespace std;

float defaultparm(int a, int b, int c, int d, int e, int f = 2, int g = 5) {
	return ((float)(a + b + c + d + e + f + g)) / 7;
}
void main() {
	float a = defaultparm(1, 3, 4, 6, 7);
	float b = defaultparm(1, 3, 4, 6, 7, 9, 8);
}

