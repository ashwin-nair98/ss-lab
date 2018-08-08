#include <stdio.h>


struct node
{
	int burst_time;
	int wait_time;
	int turn_around_time;
	int exec_time_left;
};

int main(int argc, char const *argv[])
{
	int n, i, j, slice, update;
	struct node process_list[10];
	printf("Enter number of processes[max 10]: ");
	scanf("%d", &n);
	printf("Enter time slice: ");
	scanf("%d", &slice);

	// Collect burst time
	printf("Enter burst time: ");
	for(i=0; i<n; i++)
	{
		printf("Process %d: ", i+1);
		scanf("%d", &process_list[i].burst_time);
		process_list[i].exec_time_left = process_list[i].burst_time;
		process_list[i].wait_time = 0;
	}
	
	// Burst time
	int total_burst_time = 0, counter_burst_time = 0;
	for( i = 0; i < n; i++)
		total_burst_time += process_list[i].burst_time;

	i=-1;
	int counter = 0;
	while(total_burst_time > counter_burst_time)
	{
		i = (i+1) % n;
		if(process_list[i].exec_time_left < 1) 
			continue;
		else if(process_list[i].exec_time_left <= slice)
		{
			// Process ends here
			for(j = 0; j < n; j++)
			{
				if(process_list[j].exec_time_left < 1 || i==j)
					continue;
				else
				{
					process_list[j].wait_time += process_list[i].exec_time_left;
				}
			}
			process_list[i].turn_around_time = process_list[i].wait_time + process_list[i].burst_time;
			counter_burst_time += process_list[i].exec_time_left;
			process_list[i].exec_time_left = 0;

		}
		else
		{
			// Process executes for time slice and then continues
			for(j = 0; j < n; j++)
			{
				if(process_list[j].exec_time_left < 1 || i==j)
					continue;
				else
					process_list[j].wait_time += slice;
			}
			process_list[i].exec_time_left -= slice;
			counter_burst_time += slice;

		}
		
	}



	printf("\nProcess\t\tBurst time\tWaiting time\t\tTurnaround Time");
	for(i=0;i<n;i++)
	{
		printf("\n%d \t\t%d \t\t%d \t\t\t%d", i + 1, process_list[i].burst_time, process_list[i].wait_time, process_list[i].turn_around_time);
	}

	return 0;
}