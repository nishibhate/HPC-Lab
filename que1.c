#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

int linearSearch(int* A, int n, int x);

int main(){

	int number=5, i =0, find;
	int* Arr;

	printf("Enter number : ");
	scanf("%d", &number);
	Arr = (int *)malloc( number * sizeof(int));

	printf("Enter array elements : \n");
	for(i=0; i<number; i++){
		scanf("%d",&Arr[i]);
	}
    
    printf("Enter element to be searched : ");
	scanf("%d", &find);
	

   
	int index = linearSearch(Arr, number, find);
    
	
	if(index == -1){
		printf("Not found");
	}
	else
		printf("Found at %d\n", index);

	
	
	return 0;

}


int linearSearch(int* A, int n, int x){
	
	int found = -1;

 void omp_set_num_threads()
 {
 	int num_threads=4;
	 }	
	#pragma omp parallel for
	for(int i =0; i< n; i++){
		if(A[i] == x)
			
			found = i+1;
		printf("THREAD ID %d works for iteration %d \n",omp_get_thread_num(),n);
	}
	
	return found;
}
