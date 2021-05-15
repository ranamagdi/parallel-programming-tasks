#include<stdlib.h>
#include<stdio.h>
#include<omp.h>
#include<time.h>
#define N 100
#define chunksize 50

int main() {
	int a[N], id, j, chunk, target_val;
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		a[i] = rand() % N + 1;
	}
	chunk = chunksize;
	printf("please enter the target value from range 1 to 100  \n");
	scanf_s("%d", &target_val);

#pragma omp parallel private(j,id)
	{
	id = omp_get_thread_num();
#pragma omp for schedule(dynamic,chunk)
	for (int i = 0; i < N; i++) {
		if (a[i] == target_val)
		{
			printf("found the target in array index number %d by thread %d \n ",i, id);
		
		}
		
	}
	

	}

}

