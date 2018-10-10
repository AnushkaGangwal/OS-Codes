#include <stdio.h>
#include <stdlib.h>
int n,q,head,queue[20],end;

void fcfs()
{
	int i,seek=0;
	for(i=0;i<q;i++)
	{
		seek+=abs(head-queue[i]);
		head=queue[i];
	}
	printf("Seek Time = %d\n",seek);
}

void sstf()
{
	int i,j,seek=0,temp,min;
	for(i=0;i<q;i++)
	{
		min=i;
		for(j=i+1;j<q;j++)
		{
			if(abs(head-queue[j])<abs(head-queue[min]))
				min=j;
		}
		seek+=abs(head-queue[min]);
		head=queue[min];
		temp=queue[i];
		queue[i]=queue[min];
		queue[min]=temp;
	}
	printf("Seek Time = %d\n",seek);
}

void scan(int end)
{
	int i,j,temp,seek=0;
	for(i=0;i<q;i++)
	{
		for(j=0;j<q-1;j++)
		{
			if(queue[j]>queue[j+1])
			{
				temp=queue[j];
				queue[j]=queue[j+1];
				queue[j+1]=temp;
			}
		}
	}
	if(end==0)
	{
		i=0;
		while(head>queue[i])
			++i;
		--i;
		for(j=i;j>=0;j--)
		{
			seek+=abs(head-queue[j]);
			head=queue[j];
			printf("%d\t",head);
		}
		seek+=head;
		head=0;
		for(j=i+1;j<q;j++)
		{
			seek+=abs(head-queue[j]);
			head=queue[j];
			printf("%d\t",head);
		}
	}
	else
	{
		i=q-1;
		while(head<queue[i])
			i--;
		i++;
		for(j=i;j<q;j++)
		{
			seek+=abs(head-queue[j]);
			head=queue[j];
		}
		seek+=end-head;
		head=end;
		for(j=i-1;j>=0;j--)
		{
			seek+=abs(head-queue[j]);
			head=queue[j];
		}
	}
	printf("Seek Time = %d\n",seek);
}

void main()
{
	int i,j;
	printf("Enter the number of cylinders: ");
	scanf("%d",&n);
	printf("Enter the number of queue elements: ");
	scanf("%d",&q);
	printf("Enter the cylinder queue:\n");
	for(i=0;i<q;i++)
		scanf("%d",&queue[i]);
	printf("Enter the disk head: ");
	scanf("%d",&head);
	printf("Enter nearest end: ");
	scanf("%d",&end);
	//fcfs();
	//sstf();
	scan(end);
	//look();
	//cscan();
	//clook();
}