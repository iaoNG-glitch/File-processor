#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO_CLNT_TO_SVR "fifo_c2s"
#define FIFO_SVR_TO_CLNT "fifo_s2c"
#define BUF_SIZE 1024

void process_line(const char *mode, const char *input, char *output) {
    if (strcmp(mode, "count") == 0) {
        int chars = strlen(input);
        int words = 0;
        int in_word = 0;
        for (int i = 0; input[i]; i++) {
            if (isspace(input[i])) {
                in_word = 0;
            } else if (!in_word) {
                in_word = 1;
                words++;
            }
        }
        sprintf(output, "%d chars, %d words", chars - 1, words);
    }
    else if (strcmp(mode, "upper") == 0) {
        for (int i = 0; input[i]; i++)
            output[i] = toupper(input[i]);
        output[strlen(input)] = '\0';
    }
    else if (strcmp(mode, "lower") == 0) {
        for (int i = 0; input[i]; i++)
            output[i] = tolower(input[i]);
        output[strlen(input)] = '\0';
    }
    else if (strcmp(mode, "reverse") == 0) {
        int len = strlen(input);
        for (int i = 0; i < len; i++)
            output[i] = input[len - i - 2];
        output[len - 1] = '\0';
    }
}

int main() {
    char buffer[BUF_SIZE];
    char result[BUF_SIZE];
    char mode[BUF_SIZE];
    int line_num = 0;

    mkfifo(FIFO_CLNT_TO_SVR, 0666);
    mkfifo(FIFO_SVR_TO_CLNT, 0666);

    int fd_in = open(FIFO_CLNT_TO_SVR, O_RDONLY);
    int fd_out = open(FIFO_SVR_TO_CLNT, O_WRONLY);

    read(fd_in, mode, BUF_SIZE);

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        int n = read(fd_in, buffer, BUF_SIZE);
        if (n <= 0) continue;
        if (strncmp(buffer, "END", 3) == 0) break;

        line_num++;
        printf("%d번째 줄 처리 중...\n", line_num);

        process_line(mode, buffer, result);

        char send_buf[BUF_SIZE];
        if (strcmp(mode, "count") == 0)
            sprintf(send_buf, "Line %d: %s", line_num, result);
        else
            sprintf(send_buf, "%s", result);

        write(fd_out, send_buf, strlen(send_buf) + 1);
    }

    close(fd_in);
    close(fd_out);
    unlink(FIFO_CLNT_TO_SVR);
    unlink(FIFO_SVR_TO_CLNT);
    return 0;
}
