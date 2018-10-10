#include<stdio.h>
int main()
{
 	int i,j,sum=0,n;
 	int d[20];
 	int disk;
 	int temp,max;
 	int dloc;
 	printf("Enter number of locations:");
	scanf("%d",&n);
 	printf("Enter starting position of head[max:200]: ");
 	scanf("%d",&disk);
 	printf("Enter elements of disk queue[max:200]: ");
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&d[i]);
 	}
 	d[n]=disk;
	for(i=0;i<=n;i++)
 	{
  		for(j=i;j<=n;j++)
  		{
   	 		if(d[i]>d[j])
    			{
    				temp=d[i];
    				d[i]=d[j];
    				d[j]=temp;
    			}
  		}
 	}
 	max=d[n];
 	printf("Order of execution:\n");
 	for(i=0;i<n;i++)
 	{
 		if(disk==d[i])
		{
			dloc=i;
			break;
		}
 	}
 	for(i=dloc;i>=0;i--)
 	{
 		printf("%d -->",d[i]);
 	}
 	for(i=n;i>dloc;i--)
 	{
 		printf("%d-->",d[i]);
 	}
 	sum=disk+max;
 	printf("\nDistance Travelled %d",sum);
 	return 0;
}
