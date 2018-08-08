#include <stdio.h>


struct node
{
	int index;
	int burst_time;
	int wait_time;
	int turn_around_time;
};

int main(int argc, char const *argv[])
{
	int n, i, j;
	struct node process_list[10];
	printf("Enter number of processes[max 10]: ");
	scanf("%d", &n);

	// Collect burst time
	for(i=0; i<n; i++)
	{
		printf("Process %d: ", i+1);
		scanf("%d", &process_list[i].burst_time);
		process_list[i].index = i;
	}

	// Order process
	struct node temp;
	for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < (n - 1 - i); j++)
        {
            if (process_list[j].burst_time > process_list[j + 1].burst_time)
            {
                temp = process_list[j];
                process_list[j] = process_list[j + 1];
                process_list[j + 1] = temp;
            } 
        }
    }

    // Calculate waiting time
    process_list[0].wait_time = 0;
    process_list[0].turn_around_time = process_list[0].burst_time;
    for(i = 1; i < n; i++) 
    {
    	process_list[i].wait_time = process_list[i-1].wait_time + process_list[i-1].burst_time;
    	process_list[i].turn_around_time = process_list[i].wait_time + process_list[i].burst_time;

    }

    // Display time
    printf("\nProcess\t\tBurst time\tWaiting time\t\tTurnaround Time");
	for(i=0;i<n;i++)
	{
		printf("\n%d \t\t%d \t\t%d \t\t\t%d", process_list[i].index + 1, process_list[i].burst_time, process_list[i].wait_time, process_list[i].turn_around_time);
	}
	return 0;
}