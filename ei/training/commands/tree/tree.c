#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int is_directory_we_want_to_list(const char *parent, char *name) {
    struct stat st_buf;
    if (!strcmp(".", name) || !strcmp("..", name))
        return 0;

    char *path = alloca(strlen(name) + strlen(parent) + 2);
    sprintf(path, "%s/%s", parent, name);
    stat(path, &st_buf);
    return S_ISDIR(st_buf.st_mode);
}

int list(const char *name, int step) {
    DIR *dir = opendir(name);
    struct dirent *ent;

    while (ent = readdir(dir)) {
        char *entry_name = ent->d_name;
//        printf("%*s\n", step, entry_name);

        
        if (is_directory_we_want_to_list(name, entry_name)) {
            // You can consider using alloca instead.
            printf("%*s%s\n", step,"", entry_name);
            char *next = malloc(strlen(name) + strlen(entry_name) + 2);
            sprintf(next, "%s/%s", name, entry_name);
            list(next,step+4);
            free(next);

        }
        else
        {
            if (!strcmp(".", entry_name) || !strcmp("..", entry_name))
                continue;

             printf("%*s%s\n", step,"", entry_name);
        }
    }

    closedir(dir);
}

int main(){
list("/home/vinay/ei/training", 0);
return 0;
}


