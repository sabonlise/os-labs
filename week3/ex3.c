#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX_FILES 256
#define MAX_FILE_NAME_LENGTH 64
#define MAX_PATH_SIZE 2048
#define MAX_FILE_DATA 1024
#define MAX_SUBDIRECTORIES_NUMBER 8


struct Directory;
struct File;

struct File {
    int id;
    
    char name[MAX_FILE_NAME_LENGTH];
    size_t size;
    char data[MAX_FILE_DATA];
    
    struct Directory *directory; // The parent directory
};

struct Directory {
    int nf;
    int nd;
    char path[MAX_PATH_SIZE];
    struct File *files[MAX_FILES];
    struct Directory *directories[MAX_SUBDIRECTORIES_NUMBER];
    
};

typedef struct Directory Directory;
typedef struct File File;

// Operations on files
void add_to_file(File *file, const char * content);
void append_to_file(File *file, const char * content);
void pwd_file(File * file);


// Operations on directories
void add_file(File* file, Directory *dir);
void add_dir(Directory *dir1, Directory *dir2); // given to you

// Helper functions
void show_dir(Directory *dir);
void show_file(File *file);
void show_file_detailed(File *file);

int main(){
    
    char content1[] = "int printf(const char * format, ...);";
    char content2[] = "int main(){printf('Hello World');}";
    char content3[] = "//This is a comment in C language";
    char content4[] = "Bourne Again Shell!";
    
    
    Directory home, bin, root, test;
    
    home.nf = 0;
    bin.nf = 0;
    root.nf = 0;
    
    home.nd = 0;
    bin.nd = 0;
    root.nd = 0;
    
    strcpy(home.path, "/home");
    strcpy(bin.path, "/bin");
    strcpy(root.path, "/root");
    
    // Add subdirectories
    add_dir(&bin, &root);
    add_dir(&home, &root);
    
    File bash, ex31, ex32;
    int current_id = 0;
    
    bash.id = ++current_id;
    ex31.id = ++current_id;
    ex32.id = ++current_id;
    
    strcpy(bash.name, "bash");
    strcpy(ex31.name, "ex3_1.c");
    strcpy(ex32.name, "ex3_2.c");
    
    
    add_file(&bash, &bin);
    add_file(&ex31, &home);
    add_file(&ex32, &home);

    add_to_file(&ex31, content1);
    add_to_file(&ex32, content3);
    add_to_file(&bash, content4);
    
    append_to_file(&ex31, content2);
    
    show_dir(&root);
    show_file_detailed(&bash);
    show_file_detailed(&ex31);
    show_file_detailed(&ex32);
    
    pwd_file(&bash);
    pwd_file(&ex31);
    pwd_file(&ex32);
   
    return EXIT_SUCCESS;
}

// Helper functions

// Displays the content of the Directory dir
void show_dir(Directory *dir){
    printf("\nDIRECTORY\n");
    printf(" path: %s\n", dir->path);
    printf(" files:\n");
    printf("    [ ");
    for (int i = 0; i < dir->nf; i++){
        show_file(dir->files[i]);
    }
    printf("]\n");
    printf(" directories:\n");
    printf("    { ");
    
    for (int i = 0; i < dir->nd; i++){
        show_dir(dir->directories[i]);
    }
    printf("}\n");
}

// Prints the name of the File file
void show_file(File *file){
    printf("%s ", file->name);
}

// Shows details of the File file
void show_file_detailed(File *file){
    printf("\nFILE\n");
    printf(" id: %d\n", file->id);
    printf(" name: %s\n", file->name);
    printf(" size: %lu\n", file->size);
    printf(" data:\n");
    printf("    [ %s ]\n", file->data);
}


// Implementation: Operations on files

// Adds the content to the File file
void add_to_file(File *file, const char * content) {
    file->size = strlen(content);
    strncpy(file->data, content, min(MAX_FILE_DATA, strlen(content)));
}

// Appends the content to the File file
void append_to_file(File *file, const char * content) {
    int allowed_characters_limit = min(MAX_FILE_DATA - strlen(content), strlen(content));
    file->size = file->size + allowed_characters_limit;
    strncat(file->data, content, allowed_characters_limit);
}

// Prints the path of the File file
void pwd_file(File * file) {
    printf("%s/%s\n", file->directory->path, file->name);
}


// Implementation: Operations on directories

// Adds the File file to the Directory dir
void add_file(File* file, Directory *dir) {
    dir->files[dir->nf++] = file;
    file->directory = dir;
}

// Given to you
// Adds the subdirectory dir1 to the directory dir2
void add_dir(Directory *dir1, Directory *dir2){
    if (dir1 && dir2){
        char buf[MAX_PATH_SIZE];
        strncpy(buf, dir2->path, min(MAX_PATH_SIZE, strlen(dir2->path)));
        strncat(buf, dir1->path, min(MAX_PATH_SIZE - strlen(dir1->path), strlen(dir1->path)));
        strncpy(dir1->path, buf, min(MAX_PATH_SIZE, strlen(buf)));
        
        dir2->directories[dir2->nd++] = dir1;
        
        memset(buf, 0, MAX_PATH_SIZE);
    }
}
