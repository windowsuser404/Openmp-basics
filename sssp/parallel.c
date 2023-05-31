// Floyd-Warshall Algorithm in C

#include <stdio.h>
#include <omp.h>
// defining the number of vertices
#define nV 100

#define INF 999
int graph[nV][nV],i, j, k;
void generate_matrix(int graph[][nV]){
	for(i=0;i<nV;i++)
		for(j=0;j<nV;j++){
			if(i!=j)
			graph[i][j]=((7+j))*((3+i))+(3*j)-(5*i);
			else
				graph[i][j]=0;
		}
}

void printMatrix(int matrix[][nV]);

// Implementing floyd warshall algorithm
void floydWarshall(int graph[][nV]) {
int matrix[nV][nV];
#pragma omp parallel private(j)
{
#pragma omp for
  for (i = 0; i < nV; i++)
    for (j = 0; j < nV; j++)
      matrix[i][j] = graph[i][j];
}
  // Adding vertices individually
#pragma omp parallel private(i,j)
{
#pragma omp for
  for (k = 0; k < nV; k++) {
    for (i = 0; i < nV; i++) {
      for (j = 0; j < nV; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
}
  //printMatrix(matrix);
}

void printMatrix(int matrix[][nV]) {
  for (int i = 0; i < nV; i++) {
    for (int j = 0; j < nV; j++) {
      if (matrix[i][j] == INF)
        printf("%4s", "INF");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
float t1,t2;
omp_set_num_threads(4);
  generate_matrix(graph);
t1 = omp_get_wtime();
  floydWarshall(graph);
t2 = omp_get_wtime();
printf("Parallel Time is %g\n",t2-t1);
}
