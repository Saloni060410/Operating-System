// FCFS Process Scheduling

#include <stdio.h>

int main()
{	int n, i;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	
	int bt[n], wt[n], tat[n];
	
	printf("Enter the burst time for each process: \n");
	for (i=0; i<n; i++)
	{	printf("Process %d : ", i);
		scanf("%d", &bt[i]);
	}
	wt[0] = 0;
	tat[0] = bt[0];
	float total_wt=0;
	float total_tat = bt[0];
	
	for (i=1; i<n; i++)
	{	wt[i] = wt[i-1] + bt[i-1];
		tat[i] = wt[i] + bt[i];
		total_wt += wt[i];
		total_tat += tat[i];
	}	
	
	printf("Process\tWaiting Time\tBurst Time\tTurnaround Time\n");
	for (i=0; i<n; i++)
	{	
        printf("P%d\t%d\t%d\t%d\n", i, wt[i], bt[i], tat[i]);
	}
	
	printf("\nAverage waiting time = %.2f\n", (total_wt/n));
	printf("Average turnaround time = %.2f", (total_tat/n));
	return 0;
}