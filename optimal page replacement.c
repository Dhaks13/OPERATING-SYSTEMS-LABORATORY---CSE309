//optimal page replacement


#include<stdio.h>

int n;
int size;

int check(int arr[], int val, int str[])
{
	int index=0;
	int max=0,flag=0;
	for(int i=0; i<n; i++)
	{
		if(arr[i]==str[val])
		{
			return -1;
		}
	}
	for(int i=0; i<n; i++)
	{
		if(arr[i]==-1)
			return i;
		flag=0;
		for(int j=val; j<size; j++)
		{
			if(arr[i]==str[j])
			{
				flag=1;
				if(j>max)
				{
					max=j;
					index=i;
				}
			}
		}
		if(flag==0)
			return i;
	}
	return index;
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


int pr_opt(int str[])
{
	int arr[n];
	for(int i=0; i<n; i++)
	{
		arr[i]=-1;
	}
	int faults=0,j;
	for(int i=0; i<size; i++)
	{
		j=check(arr,i,str);
		if(j==-1)
		{
			continue;
		}	
		arr[j]=str[i];
		++faults;
		printFrame(arr);
	}
	return faults;

}

int main()
{
	printf("Enter the size of stream:");
	scanf("%d",&size);
	int stream[size];
	printf("Enter the values:");	
	for(int i=0; i<size; i++)
		scanf("%d",&stream[i]);
	printf("Enter the no. of frame:");
	scanf("%d",&n);
	int res=pr_opt(stream);
	printf("Num. of Page Faults: %d\n",res);
	return 0; 
}
