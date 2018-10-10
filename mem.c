#include <stdio.h>
int nb,np,b[10],p[10];

void firstfit()
{
	int i,j,count=0,visited[10],process[10],processAlloc[10];
	for(i=0;i<nb;i++)
		visited[i]=0;
	for(i=0;i<np;i++)
		processAlloc[i]=0;
	for(i=0;i<np;i++)
	{
		for(j=0;j<nb;j++)
		{
			if(p[i]<=b[j] && visited[j]==0)
			{
				visited[j]=1;
				process[j]=i;
				processAlloc[i]=1;
				count++;
				break;
			}
		}
	}
	for(i=0;i<nb;i++)
	{
		if(visited[i]==1)
			printf("%d\t\t%d\t%d\t\t\t%d\t\t%d\n",i+1,b[i],process[i]+1,p[process[i]],b[i]-p[process[i]]);
		else
			printf("%d\t\t%d\t---\t\t\t---\t\t%d\n",i+1,b[i],b[i]);
	}
	printf("Number of unallocated processes = %d\n",np-count);
}

void bestfit()
{
	int i,j,temp,count=0,visited[10],process[10],processAlloc[10];
	for(i=0;i<nb;i++)
	{
		for(j=0;j<nb-1;j++)
		{
			if(b[j]>b[j+1])
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	}
	for(i=0;i<nb;i++)
		visited[i]=0;
	for(i=0;i<np;i++)
		processAlloc[i]=0;
	for(i=0;i<np;i++)
	{
		for(j=0;j<nb;j++)
		{
			if(p[i]<=b[j] && visited[j]==0)
			{
				visited[j]=1;
				process[j]=i;
				processAlloc[i]=1;
				count++;
				break;
			}
		}
	}
	for(i=0;i<nb;i++)
	{
		if(visited[i]==1)
			printf("%d\t\t%d\t%d\t\t\t%d\t\t%d\n",i+1,b[i],process[i]+1,p[process[i]],b[i]-p[process[i]]);
		else
			printf("%d\t\t%d\t---\t\t\t---\t\t%d\n",i+1,b[i],b[i]);
	}
	printf("Number of unallocated processes = %d\n",np-count);
}

int worstfit()
{
	int i,j,temp,count=0,visited[10],process[10],processAlloc[10];
	for(i=0;i<nb;i++)
	{
		for(j=0;j<nb-1;j++)
		{
			if(b[j]<b[j+1])
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	}
	for(i=0;i<nb;i++)
		visited[i]=0;
	for(i=0;i<np;i++)
		processAlloc[i]=0;
	for(i=0;i<np;i++)
	{
		for(j=0;j<nb;j++)
		{
			if(p[i]<=b[j] && visited[j]==0)
			{
				visited[j]=1;
				process[j]=i;
				processAlloc[i]=1;
				count++;
				break;
			}
		}
	}
	for(i=0;i<nb;i++)
	{
		if(visited[i]==1)
			printf("%d\t\t%d\t%d\t\t\t%d\t\t%d\n",i+1,b[i],process[i]+1,p[process[i]],b[i]-p[process[i]]);
		else
			printf("%d\t\t%d\t---\t\t\t---\t\t%d\n",i+1,b[i],b[i]);
	}
	printf("Number of unallocated processes = %d\n",np-count);
}

void main()
{
	int i;
	printf("Enter number of blocks: ");
	scanf("%d",&nb);
	printf("Enter size of blocks:\n");
	for(i=0;i<nb;i++)
		scanf("%d",&b[i]);
	printf("Enter number of processes: ");
	scanf("%d",&np);
	printf("Enter size of processes:\n");
	for(i=0;i<nb;i++)
		scanf("%d",&p[i]);
	printf("Block\tBlock Size\tProcess\t\tProcess Size\tFragment\n");
	firstfit();
	bestfit();
	worstfit();
}