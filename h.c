/*************************************************************************
	> File Name:m.c
	> Author: shenyuchi
	> Mail: 1349334667@qq.com
	> Created Time:2018年11月25日 星期日 14时19分13秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include<errno.h>
#include<sys/socket.h>
#include<signal.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<unistd.h>
#include<netdb.h>
#define SERV_PORT 8000
int df[100000] = {0};
void sys_err(const char *ptr, int num) {
    perror(ptr);
    exit(num);
}
typedef struct Node {
    char **data;
    int length, head, tail, count;
    pthread_mutex_t mutex;
    pthread_cond_t is_empty;
    pthread_cond_t is_full;
}Node;

Node *init() {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = (char **)malloc(sizeof(char *) * 50);
    p->head = 0;
    p->tail = -1;
    p->length = 0;
    p->count = 0;
    pthread_mutex_init(&p->mutex, NULL);
    pthread_cond_init(&p->is_full, NULL);
    pthread_cond_init(&p->is_empty, NULL);
    return p;
}

void push(char *str, Node *p) {
    while (1) {
        if (pthread_mutex_lock(&p->mutex) != 0) continue ;
        while (p->count >= 100) pthread_cond_wait(&p->is_full, &p->mutex);
        char *bu, *ch, *outer = NULL, pq[5][30];
        int i = 0, sum;
        strcpy(bu, str);
        ch = strtok_r(bu, ":", &outer);
        while (ch != NULL) {
            strcpy(pq[i++], ch);
            ch = strtok_r(NULL, ":", &outer);
        }
        sum = (atoi(pq[0]) + atoi(pq[1]));
        printf("%d\n", sum);
        if (df[sum] != 0) {
            printf("%s 重复！\n", str);
        } else {
            df[sum] = 1;
            p->tail++;
            p->data[p->tail] = (char *)malloc(sizeof(char) * strlen(str));
            strcpy(p->data[p->tail], str);
            p->count += 1;
        }
        pthread_cond_signal(&p->is_empty);
        if (pthread_mutex_unlock(&p->mutex) != 0) return ;
        return ;
    }
}

void *func(void *arg) {
    signal(SIGPIPE,SIG_IGN);
    //printf("%lld:", pthread_self());
    char *q[30], *ch;
    char *outer_ptr = NULL;
    int i, accefd;
    Node *p = (Node *) arg;
    while (1) {
        if (pthread_mutex_lock(&p->mutex) != 0) {
            sleep(1); 
            continue;    
        }
        while (p->count == 0) pthread_cond_wait(&p->is_empty, &p->mutex);
        while (p->head <= p->tail) {
            i = 0;
            //printf("%s\n", p->data[p->head]);
            char ha[30];
            strcpy(ha, p->data[p->head]);
            ch = strtok_r(ha, ":", &outer_ptr);
            while(ch != NULL) {
                q[i++] = ch;
                ch = strtok_r(NULL, ":", &outer_ptr);
            }
            struct sockaddr_in server;
            int sockfd = socket(AF_INET, SOCK_STREAM, 0);
            int port = atoi(q[1]), accefd;
            char *ip = q[0];
            //printf("%d---%s\n", port, q[0]);
            bzero(&server, sizeof(server));
            server.sin_family = AF_INET;
            server.sin_port = htons(port);
            server.sin_addr.s_addr = inet_addr(ip);
            if ((accefd = connect(sockfd, (struct sockaddr *)&server, sizeof(server))) < 0) { 
                printf("%s  |\n-------------------------------no\n", p->data[p->head]);
            } else {
                printf("%s  |\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^yes\n", p->data[p->head]);
        char aa[4096] = {0}, bb[200] = {0}, buf[4096], iip[100];
        pid_t pid = fork();
            if (pid == -1) {
                printf("pid wrong!\n");
            } else if (pid == 0) {
        strcpy(iip, inet_ntoa(server.sin_addr));
        printf("%s\n", iip);
        int nx = strlen(iip);   
        mkdir(iip, 0775);
        int leng;
        while(1) {
            leng = recv(sockfd, buf, 4096, 0);
            //printf("recv%s\n", buf);
            if (leng == 0)
            {
                printf("Opposite have close the socket.\n"); 
                break; //表示文件已经读到了结尾,也意味着客户端关闭了socket
            }
            if(leng == -1 && errno == EINTR)
                continue;           
            if(leng == -1 ) {
                printf("NO\n");
                break; //表示出现了严重的错误*/
            }
            int n = buf[0] - '0';
            strncpy(bb, iip, nx);
            bb[nx] = '/';
            strncpy(bb + nx + 1, buf + 1, n);
            strncpy(aa, buf + 1 + n, strlen(buf + 1 + n));
            FILE *fd;
            fd = fopen(bb, "a+");
            fwrite(aa , sizeof(char), strlen(aa), fd);
            memset(buf, 0x00, sizeof(buf));
            memset(bb, 0x00, sizeof(bb));
            memset(aa, 0x00, sizeof(aa));
            fclose(fd);
        } 
            exit(EXIT_SUCCESS);
            }
            }
            p->head++;
            if (df[atoi(q[1]) + atoi(q[0])] == 1) df[atoi(q[1]) + atoi(q[0])] = 0;
            close(sockfd);
        }
        p->count -= 1;
        pthread_cond_signal(&p->is_full);
        if (pthread_mutex_unlock(&p->mutex) != 0) continue;
    }
}

void clear(Node *node) {
    free(node->data);
    free(node);
    return ;
}

int main(int argc, char **argv) {
    int sockfd, accefd, ret;
    struct sockaddr_in seraddr, cliaddr;
    socklen_t len;
    
    bzero(&seraddr, sizeof(seraddr));
    bzero(&cliaddr, sizeof(cliaddr));
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {sys_err("socket", -1);}
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(SERV_PORT);
    seraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    //bind
    if (bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr)) < 0) {
        sys_err("ind", -2);
    }
    //listen
    if (listen(sockfd, 128) < 0) {sys_err("listen", -3);}
    char aa[4096] = {0}, bb[200] = {0};  
    pthread_t thr[5];
    Node *node[5];
    for (int i = 0; i < 5; i++) {
        node[i] = init();
    }
    for (int i = 0; i < 5; i++) {
        pthread_create(&thr[i], NULL, func, (void *)node[i]);
    }
    int leng, h = 0;
    while (1) {
        if ((accefd = accept(sockfd, (struct sockaddr *)&cliaddr, &len)) < 0) {
            printf("NO\n");
        }
        char buf[4096];
        while (1) {
            leng = recv(accefd, buf, 4096, 0);
            if (leng == 0) {
                printf("已读完\n");
                break;
            }
            if (h >= 5) h = 0;
            printf("-- --\npush:%d %s\n-- --\n", h, buf);
            push(buf, node[h]);
            h++;
            memset(buf, 0, sizeof(buf));
        }
        //close(accefd);
    }
    for (int i = 0 ; i < 5; i++) {
        pthread_mutex_destroy(&node[i]->mutex);
        pthread_cond_destroy(&node[i]->is_full);
        pthread_cond_destroy(&node[i]->is_empty);
        free(node[i]->data);
        free(node[i]);
    }
    close(sockfd);
    return 0;
}
