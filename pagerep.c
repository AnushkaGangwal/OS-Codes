#include <stdio.h>
int pages[20],frame[5],f,n;

void initialise()
{
	int i;
	for(i=0;i<f;i++)
		frame[i]=-1;
}

void fifo()
{
	int i,j,k,l=0,hit,fault=0;
	initialise();
	printf("FIRST IN FIRST OUT\n");
	printf("PAGE\tFRAME\n");
	for(i=0;i<n;i++)
	{
		hit=0;
		printf("%d\t",pages[i]);
		for(j=0;j<f;j++)
		{
			if(frame[j]==pages[i])
			{
				printf("HIT");
				hit=1;
			}
		}
		if(hit==0)
		{
			frame[l]=pages[i];
			l=(l+1)%f;
			fault++;
			for(k=0;k<f;k++)
				printf("%d ",frame[k]);
		}
		printf("\n");
	}
	printf("Number of page faults = %d\n",fault);
}

int findlru(int time[5])
{
	int i,least=time[0],pos=0;
	for(i=0;i<f;i++)
	{
		if(time[i]<least)
		{
			least=time[i];
			pos=i;
		}
	}
	return pos;
}

void lru()
{
	int i,j,hit,flag,counter=0,time[5],fault=0,pos,k;
	initialise();
	printf("LEAST RECENTLY USED\n");
	printf("PAGE\tFRAME\n");
	for(i=0;i<n;i++)
	{
		hit=flag=0;
		printf("%d\t",pages[i]);
		for(j=0;j<f;j++)
		{
			if(frame[j]==pages[i])
			{
				counter++;
				time[j]=counter;
				hit=1;
				flag=1;
				printf("HIT");
				break;
			}
		}
		if(hit==0)
		{
			for(j=0;j<f;j++)
			{
				if(frame[j]==-1)
				{
					frame[j]=pages[i];
					counter++;
					time[j]=counter;
					flag=1;
					fault++;
					for(k=0;k<f;k++)
						printf("%d ",frame[k]);
					break;
				}
			}
		}
		if(flag==0)
		{
			pos=findlru(time);
			frame[pos]=pages[i];
			counter++;
			time[pos]=counter;
			fault++;
			for(k=0;k<f;k++)
				printf("%d ",frame[k]);
		}
		printf("\n");
	}
	printf("Number of page faults = %d\n",fault);
}

int findOpt(int i)
{
	int j,k,time[5],max,pos=0,exist=0;
	for(k=0;k<f;k++)
	{
		for(j=i+1;j<n;j++)
		{
			if(frame[k]==pages[j])
			{
				time[k]=j;
				exist=1;
				break;
			}
		}
		if(exist==0)
		{
			time[k]=999;
		}
	}
	max=time[0];
	for(j=0;j<f;j++)
	{
		if(time[j]>max)
		{
			max=time[j];
			pos=j;
		}
	}
	return pos;
}

void optimal()
{
	int i,j,hit,flag,fault=0,k,pos;
	initialise();
	printf("OPTIMAL\n");
	printf("PAGE\tFRAME\n");
	for(i=0;i<n;i++)
	{
		hit=flag=0;
		printf("%d\t",pages[i]);
		for(j=0;j<f;j++)
		{
			if(frame[j]==pages[i])
			{
				hit=1;
				flag=1;
				printf("HIT");
				break;
			}
		}
		if(hit==0)
		{
			for(j=0;j<f;j++)
			{
				if(frame[j]==-1)
				{
					frame[j]=pages[i];
					flag=1;
					fault++;
					for(k=0;k<f;k++)
						printf("%d ",frame[k]);
					break;
				}
			}
		}
		if(flag==0)
		{
			pos=findOpt(i);
			frame[pos]=pages[i];
			fault++;
			for(k=0;k<f;k++)
				printf("%d ",frame[k]);
		}
		printf("\n");
	}
	printf("Number of page faults = %d\n",fault);
}

void main()
{
	int i,j;
	printf("Enter the frame size:\n");
	scanf("%d",&f);
	printf("Enter the number of pages:\n");
	scanf("%d",&n);
	printf("Enter the pages:\n");
	for(i=0;i<n;i++)
		scanf("%d",&pages[i]);
	//fifo();
	//lru();
	optimal();
}