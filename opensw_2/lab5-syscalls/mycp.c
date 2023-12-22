#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char* argv[]){
    if (argc != 3){
        printf("usage: %s source-file dest-file\n", argv[0]);
        return 0;
    }

    int fd_src, fd_dest;
    fd_src = open(argv[1], O_RDONLY); //source file
    if (fd_src == -1 || fd_dest == -1){
        perror("open source file");
        return 0;
    }
    
    fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC , 0644); // dest file
    if (fd_dest == -1){
        perror("open destination file");
        return 0;
    }

    else {
        char buf[256];
        unsigned long rf, wf;
        while(1){
            rf = read(fd_src, buf, 256);
            if (rf == 0) break;
            wf = write(fd_dest, buf, rf);
            if (rf != wf) {
                perror("Error writing");
                return 0;
            }
        }
    }
   
    printf("File copied successfully from %s to %s\n", argv[1], argv[2]);
    return 0;
    
}