#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <stdlib.h>
#include <unistd.h>


void search(char *path, char* name, long inode){
    struct dirent *dp;
    DIR *dirp = opendir(path);
    int i=0;
    if (dirp == NULL) {
        perror("Couldn't open the directory");
        exit(1);
    }
    printf("%s ---- ", name);
    while ((dp = readdir(dirp)) != NULL){
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0 && dp->d_ino==inode){
            if(i>0) printf(", ");
            printf("%s",dp->d_name);
            i++;
        }
    }
    printf("\n");
    closedir(dirp);
}

int main(){
    DIR* dirp;
    struct dirent* dp;
    int len;
    dirp = opendir("./tmp");
    chdir("./tmp");
    if (dirp == NULL) {
		perror("Couldn't open the directory");
		exit(1);
    }
    printf("File ---- Hard Links\n");
    while ((dp = readdir(dirp)) != NULL) {
        struct stat st;

        if(stat(dp->d_name, &st) < 0){
            perror("stat");
			continue;
        }
        if ( strcmp(dp->d_name, ".") && strcmp(dp->d_name, "..") && !S_ISDIR(st.st_mode)){
            if(st.st_nlink > 1){
                search(".", dp->d_name, dp->d_ino);
            }
        }


    }
    (void)closedir(dirp);
    return 0;
}
