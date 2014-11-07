#include <stdio.h>
#include <math.h>

float f(float x)
{
	float yy;

	yy = x*x*x + 4*x*x -10;
	return yy;
}

float g(float x)
{
	float gg;

	gg = x - x*x*x - 4*x*x + 10;
	return gg;
}

void Erfen(float a,float b,int N,float tol)
{
	int i = 0;
	float p,fa,fp;

	fa = f(a);
	for(i = 0; i < N; i++) {
		p = (a + b)/2;
		fp = f(p);
		if((fp == 0) | ((b - a)/2) < tol)
			break;
		if(fa * fp < 0)
			b = p;
		else a = p;
	}
	printf("Answer: %f\nLoop: %d\n",p,i);
}

void Diedai(float _p0,int N,float tol)
{
	int i = 0;
	float p,p0;

	while(i < N) {
		p = g(p0);
		if(abs(p - p0) < tol)
			break;
		i++;
		p0 = p;
	}
	printf("Answer: %f\n Loop: %d\n",p,i);
}

int main()
{
	Erfen(1.0,2.0,20,0.000005);
	Diedai(1.01,200,0.000005);
	return 0;
}
