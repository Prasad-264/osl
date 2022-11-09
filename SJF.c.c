#include<stdio.h>

int main() {
	int AT[10], BT[10], temp[10];
	int i, small, cnt = 0, t, limit;
	double wait_time = 0, turnaround_time = 0, end;
	float avg_wt, avg_tat;
	printf("\nEnter the total number of Processor: ");
	scanf("%d", &limit);
	printf("\nEnter Details of %d Processes\n", limit);
	
	//Taking input
	for(i = 0; i < limit; i++) {
		printf("\nEnter Arrival Time of P%d : ", i+1);
		scanf("%d", &AT[i]);
		printf("Enter Burst Time of P%d : ", i+1);
		scanf("%d", &BT[i]);
		temp[i] = BT[i];
	}
	
	// Printing Table
	int j;
	printf("\nProcess   Arrival Time   Burst Time\n");
	for(j = 0; j < limit; j++) {
		printf("   P%d         %d              %d    \n", j+1, AT[j], BT[j]);
	}
	
	// shortest Job First Algorithm
	BT[9] = 9999;
	for(t = 0; cnt != limit; t++) {
		small = 9;
		for(i = 0; i < limit; i++) {
			if(AT[i] <= t && BT[i] < BT[small] && BT[i] > 0) {
				small = i;
		 	}
		}
		BT[small]--;
		if(BT[small] == 0) {
			cnt++;
			end = t + 1;
			wait_time = wait_time + end - AT[small] - temp[small];
			turnaround_time = turnaround_time + end - AT[small];
		}
	}
	
	// Printing Average TAT and WT 
	avg_wt = wait_time / limit;
	avg_tat = turnaround_time / limit;
	printf("\nAverage Waiting Time: %lf", avg_wt);
	printf("\nAverage Turnaround Time: %lf \n", avg_tat);
	return 0;
}
