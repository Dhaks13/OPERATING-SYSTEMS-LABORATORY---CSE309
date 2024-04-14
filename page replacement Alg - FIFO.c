//page replacement Alg - FIFO

#include<stdio.h>

int n;

int check(int arr[], int val)
{
	for(int i=0; i<n; i++)
	{
		if(arr[i]==val)
		{
			return 1;
		}
	}
	return 0;
}

void printFrame(int arr[])
{
	printf("Fault Frame: ");
	for(int i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}


int pr_fifo(int str[], int size)
{
	int arr[n];
	for(int i=0; i<n; i++)
	{
		arr[i]=-1;
	}
	int faults=0,j=0;
	for(int i=0; i<size; i++)
	{
		if(check(arr,str[i]))
		{
			continue;
		}
		if(j==n)
		{
			j=0;
		}	
		arr[j++]=str[i];
		++faults;
		printFrame(arr);
	}
	return faults;

}

int main()
{
	int size;
	printf("Enter the size of stream:");
	scanf("%d",&size);
	int stream[size];
	printf("Enter the values:");	
	for(int i=0; i<size; i++)
		scanf("%d",&stream[i]);
	printf("Enter the no. of frame:");
	scanf("%d",&n);
	int res=pr_fifo(stream,size);
	printf("Num. of Page Faults: %d\n",res);
	return 0; 
}
