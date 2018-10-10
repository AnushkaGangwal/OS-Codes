#include <stdio.h>
int n,at[10],bt[10],ind[10];
int ct[10],tat[10],wt[10],temp;

void display()
{
	int i;
	ct[0]=at[0]+bt[0];
    tat[0]=ct[0]-at[0];
    wt[0]=tat[0]-bt[0];
    for(i=1;i<n;i++)
    {
        ct[i]=ct[i-1]+bt[i];
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d",ind[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
}

void fcfs()
{
	int i,j;
	for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(at[j]>at[j+1])
            {
                temp=ind[j];
                ind[j]=ind[j+1];
                ind[j+1]=temp;
                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
            }
        }
    }
}

void sjf()
{
	int i,j,time=0,min,k;
	fcfs();
    time+=bt[0];
    for(i=1;i<n;i++)
    {
        k=i;
        min=bt[i];
        for(j=i+1;j<n;j++)
        {
            if(time>=at[j] && bt[j]<min)
            {
                min=bt[j];
                k=j;
            }
        }
        time+=bt[k];
        temp=ind[i];
        ind[i]=ind[k];
        ind[k]=temp;
        temp=at[i];
        at[i]=at[k];
        at[k]=temp;
        temp=bt[i];
        bt[i]=bt[k];
        bt[k]=temp;
    }
    display();
}

void priority()
{
    int i,j,time=0,min,k,prio[10];
    printf("Enter priority of each process:\n");
    for(i=0;i<n;i++)
        scanf("%d",&prio[i]);
    fcfs();
    time+=bt[0];
    for(i=1;i<n;i++)
    {
        k=i;
        min=prio[i];
        for(j=i+1;j<n;j++)
        {
            if(time>=at[j] && prio[j]<min)
            {
                min=prio[j];
                k=j;
            }
        }
        time+=bt[k];
        temp=ind[i];
        ind[i]=ind[k];
        ind[k]=temp;
        temp=at[i];
        at[i]=at[k];
        at[k]=temp;
        temp=bt[i];
        bt[i]=bt[k];
        bt[k]=temp;
    }
    display();
}

void main()
{
	int i;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("For each process, enter Arrival Time and Burst Time:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&at[i],&bt[i]);
        ind[i]=i+1;
    }
    //fcfs();
    //display();
    //sjf();
    rr();
    //priority();
}