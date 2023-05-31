#include<stdio.h>
#include<omp.h>
#define size (int)1e8
int i;
int arr[size];
int main(){
	omp_set_num_threads(4);
#pragma omp for
for(i=0;i<size;i++)
	arr[i]=1;
int sum=0;
double t1,t2;
t1 = omp_get_wtime();
for (i=0;i<size;i++)
	sum+=arr[i];
t2 = omp_get_wtime();
printf("%d\n",sum);
printf("%g\n",t2-t1);
}

