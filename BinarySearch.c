#include <sys/types.h> 
#include <sys/wait.h> 
#include <stdio.h>    
#include <stdlib.h>    
#include <unistd.h> 
 
void binarysearch(long int [10], int n);

void main(int argc, char *argv[],char *envp[]) {
	int i, n = 0;
	long a[10];
	for(i=1; argv[i]!=NULL; i++) {		
		a[i] = strtol(argv[i], NULL, 10);
		n++;
	}
	printf("\n");	
	printf("\nIn second child process. Process id is :  %d", getpid());
	printf("\nMy parent's process id is : %d", getppid());
	binarysearch(a,n);
}

void binarysearch(long int a[10],int n) {
	int i = 0, j = n-1, mid , c = -1, temp;
	printf("\nEnter the number to search : ");
	scanf("%d", &temp);
	printf("\nIn Binary Search Program\n");
	while(i<=j && a[mid]!=temp) {
	   mid = (i+j) >> 1;
	   if(temp == a[mid]) c = 1;  
	   if(temp > a[mid]) i = mid+1;
	   else j = mid-1;
	}
	if(c == -1) printf("The given number %d is not found.",temp);
	else printf("The given number %d is found ",temp);
}


