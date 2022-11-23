//using mutex

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_mutex_t wr,mutex;
int a=10,readcount=0; //readcount keep trackes of no. readers



void * reader(void *arg)
{
 long int num ;
 num =(long int)arg;
pthread_mutex_lock(&mutex); //only one reader is incrementing
  readcount++;
  pthread_mutex_unlock(&mutex);

  if(readcount==1) //if he is first reader then only he will lock the writer
    pthread_mutex_lock(&wr);

  printf("\n reader %ld is in critical section",num);
printf("\nReader %ld is reading data %d",num,a); //num=of writer //a is not incrementing cause he is just reading the data
sleep(1);
pthread_mutex_lock(&mutex);//only one thread
readcount--;//reader try to leave creitical section
pthread_mutex_unlock(&mutex);

if(readcount==0)//unlock the writer
  pthread_mutex_unlock(&wr);

printf("\n reader %ld left critical section",num);


}


void * writer(void * arg)
{
  long int num ;
  num =(long int)arg; //atg is of 8 bytes

  //lock wr variable to enter cs
  pthread_mutex_lock(&wr);

printf("\n writer %ld is in critical section",num);

  printf("\n Writer %ld have written data as %d",num,++a);
  sleep(1);
  //writer relases a lock on wr
  pthread_mutex_unlock(&wr);

printf("\n writer %ld left critical section",num);



}

int main()
{
  pthread_t r[10],w[10];

 long int i,j;
 int nr ,nw;

  //initialize mutex variable
  pthread_mutex_init(&wr,NULL);
  pthread_mutex_init(&mutex,NULL);
 //read input data
 printf("Enter number of reader and writers");
 scanf("%d %d",&nr,&nw);

  //create reader and writer threads
  for(i=0;i<nr;i++)
    pthread_create(&r[i],NULL,reader,(void *)i);
     for(j=0;j<nw;j++)
    pthread_create(&w[j],NULL,writer,(void *)j);

    //join the thread
    for(i=0;i<nr;i++)
    pthread_join(r[i],NULL);

     for(j=0;j<nw;j++)
    pthread_join(w[j],NULL);


  return 0;
}
