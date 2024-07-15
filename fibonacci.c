#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() 
{
    int first = 0, second = 1, next, i, count;
    pid_t pid;
    printf("Enter the number of terms for the Fibonacci sequence: ");
    scanf("%d", &count);

    if (count < 0)
    {
        printf("You entered a negative number. Please enter a non-negative number.\n");
    }
    else
    {
        pid = fork();
        if (pid == 0)
        {
            // Child process
            printf("Child process is generating the Fibonacci sequence:\n");
            if (count > 2)
            {
                count -= 2;
                printf("%d %d ", first, second);
                for (i = 0; i < count; i++)
                {
                    next = first + second;
                    printf("%d ", next);
                    first = second;
                    second = next;
                }
            }
            else
            {
                printf("%d %d", first, second);
            }
            printf("\nChild process ends.\n");
        }
        else
        {
            // Parent process
            printf("Parent process is waiting for the child to complete.\n");
            wait(NULL);
            printf("Parent process ends.\n");
        }
    }
    return 0;
}

