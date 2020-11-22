#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[]) {
    long long size = 0;
    DIR* d = opendir("./");
    struct dirent* entry = readdir(d);

    printf("Directories: \n");
    while(entry){
        if(entry->d_type == DT_DIR){
            struct stat s;
            char arr[256];

            strcpy(arr, "./");
            stat(strcat(arr, entry->d_name), &s);
            printf("\t%s\n", entry->d_name);
            size += s.st_size;
        }
        entry = readdir(d);
    }

    rewinddir(d);
    entry = readdir(d);

    printf("Files: \n");
    while(entry){
        if(entry->d_type == DT_REG){
            struct stat s;
            char arr[256];

            strcpy(arr, "./");
            stat(strcat(arr, entry->d_name), &s);
            printf("\t%s\n", entry->d_name);
            size += s.st_size;
        }
        entry = readdir(d);
    }

    printf("Total Size: %lld\n", size);


    closedir(d);
    return 0;
}
