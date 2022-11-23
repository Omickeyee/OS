#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

void zombie(){
int p;
p=fork();

if(p==0){
printf("In Child, Child id is %d\n", getpid());
printf("My Parent Id is, %d \n", getppid());

}
else{
sleep(5);
printf("In Parent, Parent id is %d\n", getpid());
printf("My Child Id is, %d\n", p);
}
}

void orphan(){
int p;
p=fork();

if(p==0){
sleep(7);
printf("\nChild is running, Child id is %d\n", getpid());
printf("\nMy parent has id %d\n" , getppid());
}

else{
sleep(3);
printf("\nparent is running, parent id is %d\n", getpid());
printf("\nmy parent has is %d\n", p);
}
}

int main(){
orphan();
}