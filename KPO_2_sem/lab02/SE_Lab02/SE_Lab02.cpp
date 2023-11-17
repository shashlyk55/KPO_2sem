#include<iostream>
using namespace std;

int mul(int& x, int& y) {
	return(x * y);
}

int (*pfun)(int&, int&);

void main() {
	//X= 9+n, Y= 10+n, Z= 11+n, S= 1.0+n
	bool tr = true;
	bool fal = false;

	char ch1 = 'l';
	char ch2 = 'л';

	wchar_t wch1 = L's';
	wchar_t wch2 = L'с';
	
	short a = 21;	//21(10)=0001 0101(2)=15(16)
	short b = -21;  //-21(10)=1001 0101(2 пр)=1110 1010(2 об)=1110 1011(2 доп)=EB(16)

	short max = 0x7fff;	
	short min = 0x8000;

	unsigned short uns_max = 0xffff;  
	unsigned short uns_min = 0x0000;

	int n = 22;		//22(10)=0001 0110(2)=16
	int c = -22;	//-22(10)=1001 0110(2 пр)=1110 1001(2 об)=1110 1010(2 доп)=EA(16)
	
	int i_max = 0x7fffffff;	
	int i_min = 0x80000000;	
	
	unsigned int uni_max = 0xFFFFFFFF;
	unsigned int uni_min = 0x00000000;

	long k = 23;	//23(10)=0001 0111(2)=17
	long j = -23;	//-23(10)=1001 0111(2 пр)=1110 1000(2 об)=1110 1001(2 доп)=E9(16)

	long lmax = 0x7fffffff;
	long lmin = 0x80000000;

	unsigned long unl_max = 0xffffffff;
	unsigned long unl_min = 0x00000000;

	float fmax = 13.0;		
	float fmin = -13.0;

	char l = 'l';
	wchar_t s = 's';
	short sh = 10;
	int i = 20;
	float f = 5.0;
	double d = 7.0;

	char* pc = &l;
	wchar_t* pw = &s;
	short* ps = &sh;
	int* pi = &i;
	float* pf = &f;
	double* pd = &d;
	
	pc += 3;
	pw += 3;
	ps += 3;
	pi += 3;
	pf += 3;
	pd += 3;

	int inf = i / 0;
	int ninf = -i / 0;
	int ind = sqrt(b);

	pfun = mul;
	int res = mul(n, c);

}