#include<stdlib.h>
#include<stdio.h>
#include<omp.h>
#include<time.h>
#include <math.h>


int main() {
	int points = 10000000;
	int i;
	double sum = 0.0;
	double x_point, y_point;
#pragma omp parallel private(i,x_point,y_point)num_threads(8)
	{
		

#pragma omp for reduction(+:sum) 
	for (i = 0; i<points; i++) {
		x_point = double(rand() % 100) / (100.0);
		y_point = double(rand() % 100) / (100.0);
		if (pow(x_point-.5,2) + pow(y_point-.5,2) <= .25)
		{
			sum++;
		}
	}

	}
  printf( "PI = %lf" , (sum / points) * 4.0);
}