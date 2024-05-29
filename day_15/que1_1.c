#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *selection_sort(void *param){
	
	int *arr; 

	arr = (int*)param;

	int i,j,temp;
		//printf("after sort : \n");
	for(i = 0;i<10;i++){

		for(j = i+1;j<10;j++){

			if(arr[i] > arr[j]){

					temp = arr[i];//temp = 56
					arr[i] = arr[j];//arr[i] = 24
					arr[j] =temp;//arr[j] 56
			}
		}
	}

	return arr;

	//for(i=0;i<10;i++)
		//printf("%4d",arr[i]);


}

int main(){
	
	int ret;
	pthread_t t1;

	int arr[10] = {56,24,57,49,98,36,72,51,10,9};
	
	ret = pthread_create(&t1,NULL,selection_sort,arr);
	printf("pthread_create return value : %d\n",ret);
	if(ret < 0 ){
		
		perror("pthread_create() failed");
		_exit(1);
	}

	printf("before sort : \n");
	for(int i = 0;i<10;i++){

		printf("%4d",arr[i]);
	}
	printf("\n");

	//selection_sort(arr);

	pthread_join(t1,NULL);
	
	  printf("after sort : \n");
      for(int i = 0;i<10;i++){
 
         printf("%4d",arr[i]);
  }
  printf("\n");


	return 0;
}
