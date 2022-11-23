#include<stdio.h>
#include<stdlib.h>

int main()
{
    int RQ[100],i,n,TotalHeadmoment =0,initial,count=0;
    printf("Enter the number of requests\n");
    scanf("%d",&n);
    printf("Enter the request sequence\n");
    
    printf("Enter inital head position\n");
    scanf("%d",initial);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&RQ[i]);


    }

    

    //logic

    

    while(count!=0)
    {
        int min =1000,d,index; //min for finding min
        for(i=0;i<n;i++)
        {
            d=abs(RQ[i]-initial);
            if(min>d)
            {
                min=d;
                index=i; //updating index
            }
        }
        TotalHeadmoment=TotalHeadmoment+min;      //seek =min
        initial =RQ[index];
        //1000 is for max
        //you can use any number 
        RQ[index]=1000;
        count++;
          

    }

    printf("Total head movement is %d \n",TotalHeadmoment);
    return 0;

}
