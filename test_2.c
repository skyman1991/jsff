#include <stdio.h>
#include <math.h>

#define MAX 100
#define tol 0.000001

void input_A(float a[][MAX],int m,int n)
{
	int i,j;
	float temp;

	printf("Please input juzhen A:\n");
	for(i = 1; i <= m; i++){
		printf("\nline:%d ",i);
		for(j = 1; j <= n; j++){
			scanf("%f",&temp);
			a[i][j] = temp;
		}
	}
}

void input_b(float *b,int n)
{
	int i;

	printf("Please input Juzhen b:\n");
	for(i = 1;i <= n;i++)
	  scanf("%f",&b[i]);
}

void printJuzhen(float p[][MAX],int m,int n)
{
	int i,j;
	for(i = 1; i <= m; i++){
		for(j = 1; j <= n; j++)
		  printf("%f  ",p[i][j]);
		printf("\n");
	}
}

void LU_division(float a[][MAX],float l[][MAX],float u[][MAX],int n)
{
	int i,j,k,r;
	float s1,s2;

	for(i = 1; i <= n; i++){      //确定U的第一行和L的第一列
		u[1][i] = a[1][i];
		l[i][1] = a[i][1]/u[1][1];
	}
	for(r = 2;r <= n;r++){
		for(i = r;i <= n;i++){
			s1 = 0;
			for(k = 1;k <= r-1;k++){
				s1 = s1 + l[r][k]*u[k][i];
			}
			u[r][i] = a[r][i] - s1;
		}

		for(i = r+1; i <=n; i++){
			s2 = 0;
			for(k = 1;k <= r-1;k++){
				s2 += l[i][k]*u[k][r];
			}
			l[i][r] = (a[i][r] - s2)/u[r][r];
		}
	}
	
	printf("L:\n");
	printJuzhen(l,n,n);
	printf("U:\n");
	printJuzhen(u,n,n);
}

void get_x(float l[][MAX],float u[][MAX],float *b,float *x,int n)
{
	int i,j;
	float s1,s2,t;
	float y[MAX];

	for(i = 1;i <= n;i++){
		s1 = 0;
		for(j = 1;j < i;j++){
			s1 -= l[i][j]*y[j];
		}
		y[i] = (b[i] + s1)/l[i][i];
	}
	for(i = n;i >= 1; i--){
		s2 = 0;
		for(j = n;j > i; j--){
			s2 -= u[i][j]*x[j];
		}
		x[i] = (y[i] + s2)/u[i][i];
	}
	printf("The answer is:\n");
	for(i = 1;i <= n;i++)
	  printf("x[%d]: %f\n",i,x[i]);
}

int main()
{
	int n;
	float A[MAX][MAX],L[MAX][MAX],U[MAX][MAX];
	float b[MAX],x[MAX];
	
	printf("Please input n: ");
	scanf("%d",&n);
	input_A(A,n,n);
	input_b(b,n);
	LU_division(A,L,U,n);
	get_x(L,U,b,x,n);
	return 0;
}
