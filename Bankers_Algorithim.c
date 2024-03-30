//deadlock detection and avoidance

#include <stdio.h>
int main()
{
    int n, m, i, j, k;
    printf("Enter the no of process:");
    scanf("%d",&n);
 
    printf("Enter the no of values: ");
    scanf("%d",&m);
    
    int alloc[n][m];
    int max[n][m];
 
    int avail[m];
    int availc[m]; 
    printf("Enter the value of Available: ");
	for(i=0; i<m; i++){
		scanf("%d",&avail[i]);
		availc[i]=avail[i];
	}

    printf("Enter the value of allocation matrix:\n");
    for(i=0; i<n; i++){
    	printf("For Process %d: ",i+1);
    	for(j=0;j<m; j++){
    		scanf("%d",&alloc[i][j]);
		}
	}
	
	
    printf("Enter the value of Maximum matrix:\n");
    for(i=0; i<n; i++){
    	printf("For Process %d: ",i+1);
    	for(j=0;j<m; j++){
    		scanf("%d",&alloc[i][j]);
	}
    }
	
	printf("\n\nDEADLOCK DETECTION\n");
	 
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
 
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        flag = 1;
                         break;
                    }
                }
 
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
   
      int flag = 1;
       
      for(int i=0;i<n;i++)
    {
      if(f[i]==0)
      {
        flag=0;
         printf("The following system is not safe\n");
        break;
      }
    }
     
      if(flag==1)
    {
      printf("Following is the SAFE Sequence\n");
      for (i = 0; i < n - 1; i++)
        	printf(" P%d ->", ans[i]);
      		printf(" P%d", ans[n - 1]);
    	}
    	printf("\n");
	
	printf("\n\nDEADLOCK AVOIDANCE\n");
	int req[m],pid;
	printf("Enter the process:");
	scanf("%d",&pid);
	printf("Enter the request:");
	for(i=0;i<m;i++){
		scanf("%d",&req[i]);
	}
	flag=0;
	for(i=0;i<m;i++){
		if(pid>n && pid<0){
			flag=-1;
			break;
		}
		if(req[i] > need[pid-1][i]){
			flag=1;
		}
		if(req[i] > availc[i])
		{
			flag=1;
		}
	}
	if(flag==-1){
		printf("Invalid Request!\n");	
	}
	else if(flag==1)
	{
		printf("Request cannont be granted!\n");
	}
	else
	{
		printf("Request can be granted!\n");
	}
    	printf("\n");
    	return (0);

}
