#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

#define BUFFERSIZE 256

int main(int argc, char *argv[]) {
    if(argc!=2){
        printf("You can only call cpf with one arguments!");
        return 0;
    }

    struct stat sb;
    lstat(argv[1], &sb);

    printf("------------------- %s ------------------------\n", argv[1]);

    printf("File type               : ");

    switch (sb.st_mode & S_IFMT) {
        case S_IFBLK:  printf("Block special file\n");            break;
        case S_IFCHR:  printf("Device\n");        break;
        case S_IFDIR:  printf("Directory\n");               break;
        case S_IFIFO:  printf("FIFO/pipe\n");               break;
        case S_IFLNK:  printf("Symbolic link\n");           break;
        case S_IFREG:  printf("Regular file\n");            break;
        case S_IFSOCK: printf("Socket\n");                  break;
        default:       printf("Unknown?\n");                break;
    }

    printf("Access privileges       : ");
    printf((sb.st_mode & S_IRUSR) ? "r" : "-");
    printf((sb.st_mode & S_IWUSR) ? "w" : "-");
    printf((sb.st_mode & S_IXUSR) ? "x" : "-");
    printf((sb.st_mode & S_IRGRP) ? "r" : "-");
    printf((sb.st_mode & S_IWGRP) ? "w" : "-");
    printf((sb.st_mode & S_IXGRP) ? "x" : "-");
    printf((sb.st_mode & S_IROTH) ? "r" : "-");
    printf((sb.st_mode & S_IWOTH) ? "w" : "-");
    printf((sb.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    printf("inode-Number            : %ld\n", (long) sb.st_ino);
    printf("Device numbers          : dev = %d; rdev = %d\n", sb.st_dev, sb.st_rdev);
    printf("Link count              : %d\n", sb.st_nlink);
    printf("UID                     : %d\n", sb.st_uid);
    printf("GID                     : %d\n", sb.st_gid);
    printf("File size               : %lld\n", sb.st_size);
    printf("Last access             : %s", ctime(&sb.st_atime));
    printf("Last modification       : %s", ctime(&sb.st_mtime));
    printf("Last inode change       : %s", ctime(&sb.st_ctime));

    return 0;
}
