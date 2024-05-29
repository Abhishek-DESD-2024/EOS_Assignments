//2. Create a thread to sort given array of "n" integers using bubble sort. 
//Main thread should print the result after sorting is completed.
//Hint: struct array { int *arr; int size; }
//Pass struct address to thread function (via arg4 of pthread_create()).
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
struct array{

	int *arr;
	int size;
}arr_t;

void *bubble_sort(void *param){

	struct array *ptr = (struct array*)param;

	int temp,i,j,*sort;
	ptr->arr[ptr->size];

	for(i=0;i<ptr->size-1;i++){

		for(j=0;ptr->size-1-j;j++){

			if(ptr->arr[j] > ptr->arr[j+1]){

				temp = ptr->arr[j];
				ptr->arr[j] = ptr->arr[j+1];
				ptr->arr[j+1] = temp;

			}
		}
	}
	sort = (int*)malloc(sizeof(ptr->arr));
	sort = ptr->arr;
	return sort;
}

int main(){

	struct array ptr;
	int ret,i,j;

	printf("enter size of array :\n");
	scanf("%d",&ptr.size);

	ptr.arr[ptr.size];

	printf("enter the size of array having %d size : \n",ptr.size);

	for(i=0;i<ptr.size;i++)
		scanf("%d",&ptr.arr[i]);

	printf("entered array is : \n");
	for(j=0;j<ptr.size;j++)
		printf("%4d",ptr.arr[j]);
	printf("\n");

	pthread_t t1;

	ret = pthread_create(&t1,NULL,bubble_sort,&ptr);

	printf("main thread is waiting for sorted elements to return..\n");

	pthread_join(t1,NULL);

	printf("after bubble sort : \n");

	for(i=0;i<ptr.size;i++)
		printf("%4d",ptr.arr[i]);
		printf("\n");

	return 0;
}
