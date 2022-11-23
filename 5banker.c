#include <stdio.h>
int main()
{
      int n, m, i, j, k, y,alloc[20][20],max[20][20],avail[50],ind=0; 

      printf("\nEnter the no of Proceses:");
      scanf("%d",&n);

    printf("\nEnter the no of Resources:");
    scanf("%d",&m);

    printf("\nEnter the Allocation Matrix:");
    for (i = 0; i < n; i++) 
    {
       for (j = 0; j < m; j++)
    {
       scanf("%d",&alloc[i][j]);
    }
    }

    printf("\nEnter the Max Matrix:");
    for (i = 0; i < n; i++) 
    {
       for (j = 0; j < m; j++)
       {
       scanf("%d",&max[i][j]);
       }
 }

    printf("\nEnter the Available Matrix");
    for(i=0;i<m;i++)
    {
 scanf("%d",&avail[i]);
    }
 int finish[n], safesequence[n],work[m],need[n][m];
//calculating NEED matrix

   for (i = 0; i < n; i++) 
 {
    for (j = 0; j < m; j++)
    {
     need[i][j] = max[i][j] - alloc[i][j];
    }
 }

   printf("\nNEED matrix ");
   for (i = 0; i < n; i++) 
 {
    printf("\n");
      for (j = 0; j < m; j++)
      {
      printf(" %d ",need[i][j]);
      }
 }

 for(i=0;i<m;i++)
 {
    work[i]=avail[i];
 }
 for (i = 0; i < n; i++) 
 {
     finish[i] = 0; //finish of particular process is false

 }
 for (k = 0; k < n; k++) 
 {
     for (i = 0; i < n; i++) 
     {
       if (finish[i] == 0) 
       {
        int flag = 0;

    for (j = 0; j < m; j++) 
   {
    if (need[i][j] > work[j])
   {
     flag = 1;
     break;
   }
   }
   if (flag == 0) {
     safesequence[ind++] = i;

     for (y = 0; y < m; y++)
     {
     work[y] += alloc[i][y];
     }
 finish[i] = 1;
 }
 }
 }
 }

 printf("\nFollowing is the SAFE Sequence\n");
 for (i = 0; i <n ; i++)
 printf(" P%d ", safesequence[i]);
}

/*
allocation matrix
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

Max requirement matrix 
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

*/