#include <stdio.h>
#include <stdio.h>

#define N 20   //最大迭代次数
#define MAX 100  //最大方程组数

void input_A(float a[][MAX],int n)  //输入矩阵系数A
{
	int i,j;
	
	printf("Please input Juzhen A:\n");
	for(i = 1; i <= n; i++) {
		printf("Line%d: ");
		for(j = 1; j <= n; j++) {
			scanf("%f",&a[i][j]);
		}
		printf("\n");
	}
}

void input_b(float a[MAX],int n) // 输入矩阵b
{
	int i;
	
	printf("Please input Juzhen b:\n");
	for(i = 1; i <= n; i++) {
		scanf("%f",&a[i]);
	}
}

float norm(float *a,float *b,int n)
{
	int i;
	float sum = 0;

	for(i = 0; i < n; i++){
		s += fabs(a[i]-b[i]) * fabs(a[i]-v[i]);
	}

	return sqrt(s);
}

int x1x0(float *x1,float *x0,int n)
{
	int i;

	for(i = 0;i < n; i++) {
		x1[i] = x0[i];
	}

	return 1;
}

int SOR(float a[][MAX],float *b,float _x0[],float tol,float w,int N)  //SOR迭代
{
	int i,j,k;
	float x0[MAX],x1[MAX];

	k = 1;
	
	input_A(a);
	input_b(b);

	while(k <= n) {
		
	}

}
