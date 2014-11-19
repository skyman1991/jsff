# include <stdio.h>
# include <math.h>

void main(){
	float m,q,e,w,A[12][12],x0[12],x1[2];
	int i,j,n;
	printf("请输入方程组的阶数(小于等于10)n:\n");
	scanf("%d",&n);
	printf("请输入松弛因子w:\n");
	scanf("%f",&w);
	for(i=1;i<=n;i++)
	{
		printf("请输入增广矩阵的第%d行:\n",i);
	    for(j=1;j<=n+1;j++)
		scanf("%f",&A[i][j]);
		x0[i]=0.0;
	}
	printf("请输入误差限e:\n");
	scanf("%f",&e);
	for(i=1;i<=n;i++)
	{
		m=0.0;
		for(j=1;j<=i-1;j++)
			m=m+A[i][j]*x1[j];
		for(j=i;j<=n;j++)
			m=m+A[i][j]*x0[j];
		x1[i]=(A[i][n+1]-m)*w/A[i][i]+x0[i];
	}
	q=0.0;
	for(i=1;i<=n;i++)
		q=q+fabs(x0[i]-x1[i]);
	while(q>e)
	{
		for(i=1;i<=n;i++)
			x0[i]=x1[i];
		for(i=1;i<=n;i++)
		{
			m=0.0;
			for(j=1;j<=i-1;j++)
				m=m+A[i][j]*x1[j];
			for(j=i;j<=n;j++)
				m=m+A[i][j]*x0[j];
			x1[i]=(A[i][n+1]-m)*w/A[i][i]+x0[i];
		}
		q=0.0;
		for(i=1;i<=n;i++)
            q=q+fabs(x0[i]-x1[i]);
	}
	printf("线性方程组的解为:\n");
	for(i=1;i<=n;i++)
		printf("x[%d]=%f\n",i,x1[i]);
}
