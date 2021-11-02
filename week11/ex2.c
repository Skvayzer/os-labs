#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    DIR* dirp;
    struct dirent* dp;
    int len;
    dirp = opendir(".");
//     chdir("./lofsdisk");
    if (dirp == NULL) {
		perror("Couldn't open the directory");
		exit(1);
    }
    while ((dp = readdir(dirp)) != NULL) {
        struct stat st;
        printf("%s\n", dp->d_name);
    }
    (void)closedir(dirp);
    return 0;
}

