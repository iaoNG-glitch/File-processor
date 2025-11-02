#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

#define FIFO_CLNT_TO_SVR "fifo_c2s"
#define FIFO_SVR_TO_CLNT "fifo_s2c"
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <mode>\n", argv[0]);
        exit(1);
    }

    char *input_file = argv[1];
    char *mode = argv[2];

    FILE *fp = fopen(input_file, "r");
    if (!fp) {
        perror("파일 열기 실패");
        exit(1);
    }

    mkfifo(FIFO_CLNT_TO_SVR, 0666);
    mkfifo(FIFO_SVR_TO_CLNT, 0666);

    int fd_out = open(FIFO_CLNT_TO_SVR, O_WRONLY);
    int fd_in = open(FIFO_SVR_TO_CLNT, O_RDONLY);

    write(fd_out, mode, strlen(mode) + 1);

    char line[BUF_SIZE];
    char result[BUF_SIZE];
    int line_num = 0;
    clock_t start = clock();

    while (fgets(line, sizeof(line), fp)) {
        line_num++;
        printf("%d번째 줄 전송...\n", line_num);
        write(fd_out, line, strlen(line) + 1);
        memset(result, 0, BUF_SIZE);
        read(fd_in, result, BUF_SIZE);
        printf("%d번째 줄 결과 수신: %s\n", line_num, result);
    }

    write(fd_out, "END", 4);

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n=== 처리 통계 ===\n");
    printf("처리 모드: %s\n", mode);
    printf("처리한 줄 수: %d줄\n", line_num);
    printf("소요 시간: %.2f초\n", time_spent);

    fclose(fp);
    close(fd_in);
    close(fd_out);
    return 0;
}
