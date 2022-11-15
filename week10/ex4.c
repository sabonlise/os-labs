#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

#define PATH "/mnt/d/os/week10/tmp"

unsigned long inumnode;
char* file;


int selector(const struct dirent *dir) {
    if (strcmp(dir->d_name, "..") != 0 && strcmp(dir->d_name, ".") != 0 && dir->d_ino == inumnode) return 1;
    return 0;
}


int main() {
    DIR *temporary_folder;
    struct dirent *directory;

    temporary_folder = opendir(PATH);
    if (temporary_folder == NULL) return EXIT_FAILURE;

    while((directory = readdir(temporary_folder)) != NULL) {
        struct dirent **name_list = NULL;
        file = directory->d_name;
        inumnode = directory->d_ino;
        int len = scandir(PATH, &name_list, selector, NULL);

        if (len > 1) {
            printf("%s - ", file);
            while (len--) {
                printf("%s ", name_list[len]->d_name);
                free(name_list[len]);
            }
            printf("\n");
        }
        free(name_list);
    }

    closedir(temporary_folder);

    return EXIT_SUCCESS;
}