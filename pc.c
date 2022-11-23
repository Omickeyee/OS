#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<unistd.h>

sem_t empty,full; //synchronization variables
pthread_mutex_t mutex;  //synchronization variables
int buffer[5];

int count=0;


void *producer(void * arg)
{
    long int num;
    num=(long int) arg;
  
  sem_wait(&empty);// it is full so wait //producers is trying to produce data
//producer is allowed to produce data
//producer is waiting for his turn
    pthread_mutex_lock(&mutex);

    //producer is producing a data ;

   buffer[count]=rand()%10;//assign random value
   printf("\n Producer: %ld produced :%d",num+1,buffer[count]);
   count++;
   sleep(1);
   pthread_mutex_unlock(&mutex); //producer have released lock on crirical section

  sem_post(&full); //producer is incrementing full value
  pthread_exit(NULL);



}


void *consumer(void * arg)
{
  long int num;
  num=(long int) arg;
  
  sem_wait(&full);// it is full so wait //consumer is trying to produce data
//consumer is allowed to produce data
//consumer is waiting for his turn
    pthread_mutex_lock(&mutex);

    //consumer is producing a data ;
    count--;

   //buffer[count]=rand()%10;//assign random value // no need of this in consumer
   printf("\n Consumer: %ld consumed :%d",num+1,buffer[count]);
   //count++;
  sleep(1);
   pthread_mutex_unlock(&mutex); //consumer have released lock on crirical section

  sem_post(&empty); //consumer is incrementing full value
  pthread_exit(NULL);
}



int main()
{
  pthread_t p[10],c[10]; //thread variables
  unsigned long int i,j;
    int np,nc; //number of producers and consumers
    
    
    //read no. of producer and no. of consumers
    printf("enter number of producers and number of consumers");
    scanf("%d %d",&np,&nc);
 //initalize semaphore variable 
 sem_init(&empty,0,5); //1-variable,2-0 mean not shared 3-initial value
 sem_init(&full,0,0);
  //initialse  of mutex 
  pthread_mutex_init(&mutex,NULL);

//create producers thread
  for( i=0;i<np;i++)
  {
     pthread_create(&p[i],NULL,producer,(void *)i);

  }
 
  // for(i=0;i<np;i++)
  // {
  //   printf("\n buffer count %d",buffer[i]);
  // }
//create consumer thread
   for(j=0;j<nc;j++)
   {
    pthread_create(&c[j],NULL,consumer,(void *)j);

   }
//  for(i=0;i<nc;i++)
//   {
//     printf("\n buffer count %d", buffer[i]);
//   }
   //join producer thread
   for( i=0;i<np;i++)
    pthread_join(p[i],NULL);

    //join consumer thread
    for( j=0;j<nc;j++)
    pthread_join(c[j],NULL);



    return 0;

}