#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#define MAX_SIZE 10

void sortA(int arr[], int size) // sorting the array using bubble sort in ascending order
{
    for (int i = 0; i < size - 1; i++)
    {
        int j = i + 1;
        for (j; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void printArray(int array[], int size) // function to print the array
{
    printf("Elements in the array are :: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int main()
{
    int array[MAX_SIZE], size; // declared array of integers of MAX_SIZE
    pid_t pid;
    printf("\n This is the main process \n ");
    printf("\n Process ID: %d", getpid());
    printf("\n Parent ID: %d \n", getpid());
    printf("Enter the Size of the array :: "); // taking the size of the array from the user
    scanf("%d", &size);
    printf("Enter the elements :: "); // taking the elements of the array
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("\n");
    printArray(array, size); /// printing the array
    printf("\n");
    sortA(array, size); // sorting the array
    printf("After Sorting ");
    printArray(array, size);
    printf("Forking the current proces :: \n");
    pid = fork();
    if (pid == -1) // if error occurred
    {
        printf("Unfortunately the pid was not born");
    }
    else if (pid == 0) // Inside the child process
    {
        printf("\nInside the Child process\n");
        printf("Current pid is: %d", getpid());
        char *buffer[size + 1];
        buffer[0] = "./reverse"; // name of the file to execute using execv command
        int i;
        for (i = 1; i < size + 1; i++)
        {
            buffer[i] = malloc(10);
            snprintf(buffer[i], 10, "%d", array[i - 1]);
        }
        buffer[i] = NULL;
        execv("./a", buffer);
        printf("Returned from the reversing of the elements using Execv command\n");
    }
    else
    {
        // Inside parent process
        printf("\n Inside parent process\n");
        printf("\n Current proccess ID is: %d", getpid());
        printf("\n Child ID is: %d", pid);
        printf("\n-------------- PARENT IS WAITING FOR CHILD TO COMLPETE --------------");
        wait(NULL);
        printf("\n\n Parent executed successfully \n\n");
    }
    return 0;
}