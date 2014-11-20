#include <stdio.h>
#include <math.h>

#define MAX 100

void input_XY(float *x,float *y,int n)
{
	int i;

	printf("Please input X:\n");
	for(i = 1; i <= n+1; i++) {
		scanf("%f",&x[i]);
	}

	printf("Please input Y:\n");
	for(i = 1; i <= n+1; i++){
		scanf("%f",&y[i]);
	}
}

float NewTon(float *x,float *y,int n)
{
	int i,j;

	for(j =	1; j <= n; j++){
		for(i = n+1; i >= j+1;i--) {
			y[i] = (y[i] - y[i-1])/(x[i] - x[i-j]);
		}
	}
	return y[n+1];
}

int main()
{
	int i,j;
	int n;
	float x[MAX],y[MAX];
	float xx,yy;

	printf("Please input Jieshu n: ");
	scanf("%d",&n);
	
	printf("Please input xx: ");
	scanf("%f",&xx);

	input_XY(x,y,n);
	yy = NewTon(x,y,n);

	for(j = n; j >= 1; j--)
		yy = y[j] + (xx - x[j])*yy;
	printf("yy: %f\n",yy);
}

