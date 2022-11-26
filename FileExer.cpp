#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/**
 * 111
 * @return
 */
int main() {
    int fd0, record_len, buff_len, cnt;
    char filename[50], f_buff[2000];
    strcpy(filename, "/example.txt");
    fd0 = open(filename, O_RDWR|O_CREAT, 0644);
    if (fd0 < 0) {
        printf("Can't open or create exaple.txt file!\n");
        exit(0);
    }
    buff_len = 20;
    record_len = 10;
    lseek(fd0, 0, SEEK_SET);

    cnt = read(fd0, f_buff, record_len * buff_len);
    cnt = cnt / record_len;
    printf("%s\n", f_buff);
    strcpy(f_buff, "1234567890");
    write(fd0, f_buff, strlen(f_buff));
    write(fd0, "\n\r", 2);
    close(fd0);
    return (0);

}
