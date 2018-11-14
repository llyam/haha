/*************************************************************************
	> File Name:send_response.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年09月30日 星期日 16时32分51秒
 ************************************************************************/

#include <stdio.h>

int send(int socket, int rq) {
    if (send(sockfd, &rq, sizeof(rq), 0) <= 0) {
        perror("error sending rq");
        return -1;
    }
    return 0;
}
