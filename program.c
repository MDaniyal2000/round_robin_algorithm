#include<stdio.h>

int main()
{
	int n;
	printf("Enter number of processes: \t");
	scanf("%d", &n);

	int burst_time[n];
	int temp_burst_time[n];
	int wait_time[n];
	int turn_around_time[n];

	int i;
	for(i = 0; i < n; i++)
	{
		printf("Enter burst time for process %d: ", i);
		int a;
		scanf("%d", &a);
		burst_time[i] = a;
		temp_burst_time[i] = a;	
	}

	int time_span;
	printf("Enter time span: ");
	scanf("%d", &time_span);

	printf("Time span: %d\n", time_span);

	int flag = 1;
	int time = 0; 

	while(flag == 1)
	{
		int f;
		for(f=0; f<n; f++)
		{
			if(temp_burst_time[f] > 0)
			{
				flag = 1;
				break;
			}
			else
			{	
				flag = 0;
			}
		}


		for(f=0; f<n; f++)
		{
			
			if(temp_burst_time[f] >= time_span)
			{
				temp_burst_time[f] -= time_span;
				if(temp_burst_time[f] == 0)
				{
					wait_time[f] = time;
				}
				time += time_span;
			}
			else if( (temp_burst_time[f] <= (time_span-1)) and (temp_burst_time[f] > 0))
			{
				temp_burst_time[f] = 0;
				wait_time[f] = time;
				time += burst_time[f];
			}
		}
	}

	int c;
	for(c=0; c<n; c++)
	{
		turn_around_time[c] = wait_time[c] + burst_time[c];
		printf("Process %d \n", c);
		printf("Burst Time %d \n", burst_time[c]);
		printf("Wait Time %d \n", wait_time[c]);
		printf("Turn Around Time %d \n\n", turn_around_time[c]);
	}
}
