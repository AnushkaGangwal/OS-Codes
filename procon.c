#include <stdio.h>

void main()
{
	int i,n,front,rear,queue[20],choice;
	printf("Enter length of buffer: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		queue[i]=999;
	do
	{
		printf("Enter choice:\n1.Produce\n2.Consume\n3.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: if((rear!=front) || (rear==0 && queue[0]==999))
					{
						printf("Enter item: ");
						scanf("%d",&queue[rear]);
						rear=(rear+1)%n;
					}
					else
						printf("Buffer full, producer please wait.\n");
					break;

			case 2: if(queue[front]==999)
					{
						printf("Buffer empty, consumer please wait.\n");
						front=rear=0;
					}
					else
					{
						printf("%d data is consumed\n",queue[front]);
						queue[front]=999;
						front=(front+1)%n;
					}
					break;

			case 3: break;
		}
	}while(choice!=3);
}