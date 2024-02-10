#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void listTasks() {
    FILE *file = fopen("~/.local/share/chore/tasks.txt", "r");
    if (file != NULL) {
        printf("Tasks for the day:\n\n");
        char line[100];
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    } 
    else {
        printf("Error opening file for reading\n");
    }
}

void addTasks(char description[], int priority) {
    FILE *file = fopen("~/.local/share/chore/tasks.txt", "a");
    if (file != NULL) {
        fprintf(file, "%s, %d\n", description, priority);
        fclose(file);
    } 
    else {
        printf("Error opening file for writing\n");
    }
}

void removeTasks() {
    // wip
}

void sync() {
    // wip
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("chore -h\n");
        return 1;
    }

    else if (strcmp(argv[1], "-h") == 0) {
        printf("$ chore -h\n\n  -l: list tasks\n  -a: add tasks\n  -x: remove tasks\n  -s: force sync\n");
    }

    else if (strcmp(argv[1], "-l") == 0) {
        listTasks();
    }
    
    else if (strcmp(argv[1], "-a") == 0 && argc > 3) {
        char* description = argv[2];
        int priority = atoi(argv[3]);
        addTasks(description, priority);
    }

    else if (strcmp(argv[1], "-x") == 0) {
        removeTasks();
    }

    else if (strcmp(argv[1], "-s") == 0) {
        sync();
    }

    else {
        printf("Invalid option\n");
        return 1;
    }

    return 0;
}