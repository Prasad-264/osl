#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void bubblesort(int a[], int n);
void selectionsort(int a[], int n);

int main() {
	int a[10], n, i;
	pid_t id;
	printf("Enter the number of elements : ");
	scanf("%d", &n);
	printf("\nEnter the elements : ");
	for(i=0; i<n; i++) scanf("%d", &a[i]);
	id = fork();
	switch(id) {
		case -1 : printf("\nError in Fork");
				  break;	
		case 0 : printf("\nChild process ID : %d",getpid());
				 printf("\nMy Parent Process ID : %d",getppid());
			 	 bubblesort(a, n);
			 	 printf("\n");
			 	 sleep(5);			 				
			 	 printf("\nI am Orphan.");
			 	 printf("\nMy parent ID is : %d",getppid());			 
				 break;
		default : printf("\nParent process ID : %d",getpid());
			  	 selectionsort(a, n);			  
			  	 printf("\n");		 			 
			  	 sleep(2);
				 break;			  			 			 
	}
	return 0;
}

void bubblesort(int a[], int n) {
	int i, j, temp;
	for(i=0; i<n; i++) {
		for(j=0; j<n-1; j++) {
		   	if(a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
		    }
		}
	}
	printf("\nAscending order : ");
	for(i=0; i<n; i++) printf("%d ", a[i]);
}

void selectionsort(int a[], int n) {
	int i, j, min, temp;
	for(i=0; i<n; i++) {
	   	min = i;	   
		for(j=i+1; j<n; j++) {
			if(a[j] > a[min]) min=j;
		}
	   	temp = a[i];
	   	a[i] = a[min];
	   	a[min] = temp;	   
	}
	printf("\nDescending order : ");
	for(i=0;i<n;i++) printf("%d ", a[i]);
}

