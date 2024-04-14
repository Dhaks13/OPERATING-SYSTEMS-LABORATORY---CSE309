//LRU -page replacement Alg.c 

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


int pr_lru(int str[], int size)
{
	int arr[n];
	for(int i=0; i<n; i++)
	{
		arr[i]=-1;
	}
	int faults=0,j=0;
	for(int i=0; i<size; i++)
	{
		if(j==n)
		{
			j=0;
		}	
		if(check(arr,str[i]))
		{
			j++;
			continue;
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
	int res=pr_lru(stream,size);
	printf("Num. of Page Faults: %d\n",res);
	return 0; 
}
