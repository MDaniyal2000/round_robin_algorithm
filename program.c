#include<stdio.h>

int main()
{
	int n;
	printf("Enter number of processes: \t");
	scanf("%d", &n);

	int burst_time[n];
	int temp[n];
	int track[n];
	int wait[n];
	int turn[n];

	int i;
	for(i = 0; i < n; i++)
	{
		printf("Enter burst time for process %d: ", i);
		int a;
		scanf("%d", &a);
		burst_time[i] = a;
		temp[i] = a;
		track[i] = 0;	
	}

	int t_span;
	printf("Enter time span: ");
	scanf("%d", &t_span);

	printf("Time span: %d", t_span);

	int flag = 1;
	int time = 0; 

	while(flag == 1)
	{
		int f;
		for(f=0; f<n; f++)
		{
			if(temp[f] > 0)
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
			
				if(temp[f] >= 3)
				{
					temp[f] -= t_span;
					time += t_span;
				}

				if(temp[f] == 0)
				{
					if(track[f] == 0)
					{
						wait[f]=(time-3);
						track[f]=1;
					}
				}

		}
		
	}

	int c;
	for(c=0; c<n; c++)
	{
		turn[c] = wait[c] + burst_time[c];
		printf("Process %d \n", c);
		printf("Burst Time %d \n", burst_time[c]);
		printf("Wait Time %d \n", wait[c]);
		printf("Turn Around Time %d \n\n", turn[c]);
	}
}
