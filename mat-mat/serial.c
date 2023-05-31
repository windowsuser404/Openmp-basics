#include<stdio.h>
#include<omp.h>
#include<unistd.h>
#define size 1000
int matA[size][size] ;
int matB[size][size] ;
int matC[size][size] ;
int i,j,k;
void matrix_generator(){
	for(i=0;i<size;i++)
		for(j=0;j<size;j++){
			matA[i][j]=(i+1)*(j+1)-(1+i);
			matB[i][j]=(1+j)*(1+i)-(1+j);
			matC[i][j]=0;
		}
}
int main(){
	matrix_generator();
        float t1,t2;
t1 = omp_get_wtime();
{
                for(i=0;i<size;i++)
                        for(j=0;j<size;j++)
                                for(k=0;k<size;k++)
                                        matC[i][j] += matA[i][k]*matB[k][j];
}
t2 = omp_get_wtime();
printf("Time taken in serial:%g\n",t2-t1);
}

