#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TASKS 5
#define MAX_LEN 25

void taskManager();
void addTask(char tasks[MAX_TASKS][MAX_LEN], int *taskCount);
void viewTask(char tasks[MAX_TASKS][MAX_LEN], int taskCount);
void deleteTask(char tasks[MAX_TASKS][MAX_LEN], int *taskCount);

int main(void)
{
    taskManager();
    return 0;
}

void taskManager()
{
    int option;
    char tasks[MAX_TASKS][MAX_LEN];
    int taskCount = 0;
    bool running = true;

    while (running)
    {
        printf("\n========== TO-DO LIST ==========\n");
        printf("1. Add task\n");
        printf("2. View tasks\n");
        printf("3. Delete task\n");
        printf("4. Quit\n");
        printf("================================\n");
        printf("Choose option: ");
        scanf("%d", &option);

        while (getchar() != '\n');

        switch (option)
        {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                viewTask(tasks, taskCount);
                break;
            case 3:
                deleteTask(tasks, &taskCount);
                break;
            case 4:
                printf("👋 Thank you! Exiting...\n");
                running = false;
                break;
            default:
                printf("⚠️ Invalid option! Please choose 1–4.\n");
        }
    }
}

void addTask(char tasks[MAX_TASKS][MAX_LEN], int *taskCount)
{
    if (*taskCount < MAX_TASKS)
    {
        printf("Enter task: ");
        fgets(tasks[*taskCount], MAX_LEN, stdin);

        size_t len = strlen(tasks[*taskCount]);
        if (len > 0 && tasks[*taskCount][len - 1] == '\n')
            tasks[*taskCount][len - 1] = '\0';

        (*taskCount)++;
        printf("✅ Task added!\n");
    }
    else
    {
        printf("⚠️ Task list is full! (Max %d tasks)\n", MAX_TASKS);
    }
}

void viewTask(char tasks[MAX_TASKS][MAX_LEN], int taskCount)
{
    printf("\n📋 Task list:\n");
    if (taskCount == 0)
    {
        printf("No tasks yet.\n");
    }
    else
    {
        for (int i = 0; i < taskCount; i++)
        {
            printf("%d. %s\n", i + 1, tasks[i]);
        }
    }
}

void deleteTask(char tasks[MAX_TASKS][MAX_LEN], int *taskCount)
{
    if (*taskCount == 0)
    {
        printf("⚠️ No tasks to delete!\n");
        return;
    }

    int num;
    printf("Enter task number to delete: ");
    scanf("%d", &num);
    while (getchar() != '\n');

    if (num < 1 || num > *taskCount)
    {
        printf("⚠️ Invalid task number!\n");
    }
    else
    {
        printf("🗑️ Deleted task %d: %s\n", num, tasks[num - 1]);

        for (int i = num - 1; i < *taskCount - 1; i++)
        {
            strcpy(tasks[i], tasks[i + 1]);
        }
        (*taskCount)--;
    }
}

