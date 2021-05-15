#include<stdlib.h>
#include<stdio.h>
#include<omp.h>
const int n = 100;
int main(int argc, char*argv[]) {
	int  thread, id, chunk ,i;
	float a[n], b[n], c[n];
for ( i = 0; i < n; i++) {
			a[i] = b[i] = float(i);
		}
#pragma omp parallel private(i,id)
	{
	thread = omp_get_num_threads();
	id = omp_get_thread_num();

	if (id == 0) {

		printf("Number of threads = %d\n", thread);
		
	}

	printf("thread number %d starting \n ", id);
	for ( i = id*(n/thread); i < (id+1)*(n/thread); i++)
	{
		c[i] = a[i] + b[i];
		printf("thread %d:c[%d]=%f\n",id, i, c[i]);

	}

	}
}