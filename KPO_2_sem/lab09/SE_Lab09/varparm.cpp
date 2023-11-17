#include<iostream>
#include"varparm.h"
using namespace std;


int Varparm::ivarparm(int a,...) {
	int* p = &a;
	int mul = 1;
	for (int i = 1; i <= a; i++) {
		mul *= p[i];
	}
	return mul;
}

int Varparm::svarparm(short a,...) {
	int* p = (int*)(&a);
	int max = 1;
	for (int i = 2; i < a; i++) {
		if (p[max] < p[i]) {
			max = i;
		}
	};
	return p[max];
}

double Varparm::fvarparm(float x,...) {
	double* p = (double*)(&x + 1);
	int k = 0;
	double sum = x;
	while (p[k] != (double)FLT_MAX) {
		sum += p[k++];
	}
	return sum;
}

double Varparm::dvarparm(double x,...) {
	double sum = 0;
	double* p = (double*)(&x);
	int k = 0;
	while (p[k] != (double)DBL_MAX) {
		sum += p[k++];
	}
	return sum;
}