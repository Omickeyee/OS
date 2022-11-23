#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#define MAX_SIZE 50
// gcc reverse.c -o reverse
void printArray(int arr[], int size)
{
    printf("Elements in the array are :: ");
    for (int i = 0; i < size; i++) // printing the array
    {
        printf("%d ", arr[i]);
    }
}
void reverse(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}
int main(int argc, char *argv[])
{
    printf("In Child Process with process Id :: %d\n", getpid());
    int arr[MAX_SIZE];   // to store the numbers in from the parent process
    int size = (argc)-1; // number of elements in the array
    for (int i = 1; i <= size; i++)
    {
        arr[i - 1] = atoi(argv[i]); // changing the numbers from char to intergers
    }
    printf("\n");
    printf("After reversing ");
    reverse(arr, size);    // reversing the array
    printArray(arr, size); // printing the array
    printf("\n");
}



/*
omickeyee@omickeyee-HP-Pavilion-Laptop-15-cc1xx:~$ cd practise/practise/2b
omickeyee@omickeyee-HP-Pavilion-Laptop-15-cc1xx:~/practise/practise/2b$ ls 
reverse.c
omickeyee@omickeyee-HP-Pavilion-Laptop-15-cc1xx:~/practise/practise/2b$ gcc reverse.c -o a

omickeyee@omickeyee-HP-Pavilion-Laptop-15-cc1xx:~/practise/practise/2b$ gcc excusve.c -o main
excusve.c: In function ‘main’:
excusve.c:82:9: warning: implicit declaration of function ‘wait’ [-Wimplicit-function-declaration]
   82 |         wait(NULL);
      |         ^~~~
omickeyee@omickeyee-HP-Pavilion-Laptop-15-cc1xx:~/practise/practise/2b$ gcc excusve.c -o main
omickeyee@omickeyee-HP-Pavilion-Laptop-15-cc1xx:~/practise/practise/2b$ ./main

 This is the main process 
 
 Process ID: 413874
 Parent ID: 413874 
Enter the Size of the array :: 3
Enter the elements :: 1 2 3

Elements in the array are :: 1 2 3 

After Sorting Elements in the array are :: 1 2 3 
Forking the current proces :: 

 Inside parent process

 Current proccess ID is: 413874
 Child ID is: 413875

Inside the Child process
In Child Process with process Id :: 413875

After reversing Elements in the array are :: 3 2 1 
-------------- PARENT IS WAITING FOR CHILD TO COMLPETE --------------

 Parent executed successfully 

*/