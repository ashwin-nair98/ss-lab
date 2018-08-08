#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n, wait_time[10], burst_time[10], turn_around_time[10], i, j;
	printf("Enter number of processes [max 10]:");
	scanf("%d", &n);

	// Collect burst time requirement of each process
	printf("Enter the burst time of each process:\n");
	for (i = 0; i < n; i++)
	{
		printf("Process %d: ", i+1);
		scanf("%d", &burst_time[i]);
	}

	// Calculate waiting time
	wait_time[0] = 0;
	for(i=1;i<n;i++)
	{
		wait_time[i] = 0;
		for(j=0;j<i;j++)
			wait_time[i] += burst_time[j];
	}

	// Calculate turn around time
	for(i=0;i<n;i++) 
	{
		turn_around_time[i] = burst_time[i] + wait_time[i];
	}

	printf("\nProcess\t\tBurst time\tWaiting time\t\tTurnaround Time");
	for(i=0;i<n;i++)
	{
		printf("\n%d \t\t%d \t\t%d \t\t\t%d", i+1, burst_time[i], wait_time[i], turn_around_time[i]);
	}
	return 0;
}