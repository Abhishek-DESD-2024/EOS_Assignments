#include<stdio.h>

void selection_sort(int *arr){

	int i,j,temp;
		printf("after sort : \n");
	for(i = 0;i<10;i++){

		for(j = i+1;j<10;j++){

			if(arr[i] > arr[j]){

					temp = arr[i];//temp = 56
					arr[i] = arr[j];//arr[i] = 24
					arr[j] =temp;//arr[j] 56
			}
		}
	}

	//for(i=0;i<10;i++)
		//printf("%4d",arr[i]);


}

int main(){
	int arr[10] = {56,24,57,49,98,36,72,51,10,9};
	
	printf("before sort : ");
	for(int i = 0;i<10;i++){

		printf("%4d",arr[i]);
	}

	selection_sort(arr);
	
	  printf("after sort : ");
      for(int i = 0;i<10;i++){
 
         printf("%4d",arr[i]);
  }


	return 0;
}
