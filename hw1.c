#include <stdio.h>
#include <stdlib.h>


// Multiply 2 integers and return the results
int multiply(int a, int b){
	return a*b;
}

int main(){

	int arrSize = 0;
	printf("Enter an array size: ");
	scanf("%d", &arrSize);
	//printf("size of arrays %d\n", arrSize); *(DEBUG CODE)*

	//declare and allocate the pointer arrays and set the array size;
	int* arr1 = (int *)malloc(arrSize * sizeof(int));
	int* arr2 = (int *)malloc(arrSize * sizeof(int));

	//print out the address of the first array after allocation.
	printf("allocated array 1 address: %p\n", (void *)arr1);

	//print out the size of the pointer array.
	printf("The size of pointer array1 is: %ld\n", sizeof(arr1));

	//Input content for array 1
	printf("input elements for array 1\n");
	for (int i = 0; i < arrSize; i++){
		printf("enter a number for arr1[%d]:", i);
		scanf("%d", &arr1[i]);
	}

        //Input content for array 2
        printf("input elements for array 2\n");
        for (int i = 0; i < arrSize; i++){
                printf("enter a number for arr2[%d]:", i);
                scanf("%d", &arr2[i]);
        }

	/* (DEBUG PRINT ARRAY STATEMENT)
        for (int i = 0; i < arrSize; i++){
                printf("%d\n", arr2[i]);
        }
	*/

	//Open or create a file to write on
	FILE* arrResult;
	arrResult = fopen("hw1_output.txt", "w");

	if (arrResult == NULL) {
	printf("file failed to open");
	exit(0);
	}

	//Multiply the element of two arrays and check even or odd
	printf("Multiply Start\n");
	for (int i = 0; i <arrSize; i++){
		int multi = multiply(arr2[i], arr1[i]);
		fprintf(arrResult, "arr[%d] * arr[%d] = %d\n\n", i, i, multi);
		if(multi%2==0){
			fprintf(arrResult, "	%d is an even number\n\n", multi);
		}
		else{
			fprintf(arrResult, "	%d is an odd number\n\n", multi);
		}
	}
	printf("Multiply End\n");
	fclose(arrResult);

	FILE* readResult;
	readResult =  fopen("hw1_output.txt", "r");
	//Read the newly formatted file
	char line[100];

	while (fgets(line, sizeof(line), arrResult) != NULL) {
		printf("%s", line);
	}

	printf("end of program\n");
	fclose(arrResult);
	return 0;
}
