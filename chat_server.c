#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/file.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 511
#define MAX_SOCK 1024

char *EXIT_STRING = "exit";
char *START_STRING = "Connect to JuJu's chatting \n";

int maxfdp1; //최대 소켓 번호
int user_count = 0; //참가자 수
int chat_count = 0; //총 대화 수
int chat_socket_list[MAX_SOCK]; //참가자 소켓 번호
int listen_sock; //서버 리슨 소켓
char ip_list[MAX_SOCK][20]; //접속 ip

void errquit(char *msg){ perror(msg); exit(1);}

time_t ct;
struct tm tm;

void *thread_function(void *arg){
	int i;
	printf("명령어를 선택하세요. : help, user_count, chat_count, ip_list\n");
	while(1){
		char bufmsg[MAXLINE + 1];
		fprintf(stderr, "\033[1;34m");
		printf("server>"); //커서 출력
		fgets(bufmsg, MAXLINE, stdin); //명령어 입력
		if (!strcmp(bufmsg, "\n")) continue;
		else if (!strcmp(bufmsg, "help\n")){
			printf("help, user_count, chat_count, ip_list\n");
		}else if (!strcmp(bufmsg, "user_count\n")){
			printf("현재 참가자 수 = %d\n", user_count);
		}else if (!strcmp(bufmsg, "chat_count\n")){
			printf("지금까지 오간 대화의 수 = %d\n", chat_count);
		}else if (!strcmp(bufmsg, "ip_list\n")){
			for (i = 0; i < user_count; i++){
				printf("%s\n", ip_list[i]);
			}
		}else{
			printf("없는 명령어 입니다. help를 통해 명령어 목록을 확인하세요.\n");
		}
	}
}


//새로운 참가자
void add_client(int s, struct sockaddr_in *new_client_addr){

	char buf[20];
	inet_ntop(AF_INET, &new_client_addr->sin_addr, buf, sizeof(buf));
	write(1, "\033[0G", 4);
	fprintf(stderr, "\033[33m");
	printf("new member : %s \n", buf);
	chat_socket_list[user_count];
	strcpy(ip_list[user_count], buf);
	user_count++;
}

//나간 참가자
void remove_client(int s){
	close(chat_socket_list[s]);
	if(s != user_count -1){
		chat_socket_list[s] = chat_socket_list[user_count -1];
		strcpy(ip_list[s], ip_list[user_count -1]);
	}

	user_count--;
	ct = time(NULL);
	tm = *localtime(&ct);
	write(1, "\033[0G", 4);
	fprintf(stderr, "\033[33m");
	printf("[%02d:%02d:%02d]", tm.tm_hour, tm.tm_min, tm.tm_sec);
	printf("채팅 참가자 1명 탈퇴. 현재 참가자 수 = %d\n", user_count);
	fprintf(stderr, "\033[34m");//글자색을 녹색으로 변경
	fprintf(stderr, "server>"); //커서 출력
}

//최대 소켓 번호
int getmax() {
		// Minimum 소켓번호는 가정 먼저 생성된 listen_sock
	int max = listen_sock;
	int i;
	for (i = 0; i < user_count; i++){
		if (chat_socket_list[i] > max)
			max = chat_socket_list[i];
	}
	return max;
}

int  tcp_listen(int host, int port, int backlog) {
	
	int sd;
	struct sockaddr_in server_addr;

	sd = socket(AF_INET, SOCK_STREAM, 0);
	if (sd == -1) {
		perror("socket fail");
		exit(1);
	}
	//server_addr 구조체의 내용 세팅
	bzero((char *)&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(host);
	server_addr.sin_port = htons(port);
	if (bind(sd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) { 				perror("bind fail");  exit(1);
	}// 클라이언트로부터 연결요청을 기다
	listen(sd, backlog);
	return sd;
}

int main(int argc, char *argv[]){

	struct sockaddr_in client_addr;
	char buf[MAXLINE + 1];
	int i, j, nbyte, accp_sock, addrlen = sizeof(struct sockaddr_in);
	fd_set read_fds;
	pthread_t a_thread;

	if(argc != 2){
		printf("사용법 : %s port\n", argv[0]);
		exit(1);
	}

	listen_sock = tcp_listen(INADDR_ANY, atoi(argv[1]), 5);
	pthread_create(&a_thread, NULL, thread_function, (void *)NULL);
	while(1){
		FD_ZERO(&read_fds);
		FD_SET(listen_sock, &read_fds);
		for (i = 0; i < user_count; i++)
			FD_SET(chat_socket_list[i], &read_fds);


		maxfdp1 = getmax() + 1;	// maxfdp1 재 계산
		if (select(maxfdp1, &read_fds, NULL, NULL, NULL) < 0)
			errquit("select fail");

		if (FD_ISSET(listen_sock, &read_fds)) {
			accp_sock = accept(listen_sock,(struct sockaddr*)&client_addr, &addrlen);
			if (accp_sock == -1) errquit("accept fail");
			add_client(accp_sock, &client_addr);
			send(accp_sock, START_STRING, strlen(START_STRING), 0);
			ct = time(NULL);
			tm = *localtime(&ct);
			write(1, "\033[0G", 4);
			printf("[%02d:%02d:%02d]", tm.tm_hour, tm.tm_min, tm.tm_sec);
			fprintf(stderr, "\033[33m");//글자색을 노란색으로 변경
			printf("사용자 1명 추가. 현재 참가자 수 = %d\n", user_count);
			fprintf(stderr, "\033[34m");//글자색을 녹색으로 변경
			fprintf(stderr, "server>"); //커서 출력
		}

		// 클라이언트가 보낸 메시지를 모든 클라이언트에게 방송
		for (i = 0; i < user_count; i++) {
			if (FD_ISSET(chat_socket_list[i], &read_fds)) {
				chat_count++;
				nbyte = recv(chat_socket_list[i], buf, MAXLINE, 0);
				if (nbyte <= 0) {
					remove_client(i);
					continue;
				}
				buf[nbyte] = 0;
				if (strstr(buf, EXIT_STRING) != NULL) {
					remove_client(i);
					continue;
				}
				for (j = 0; j < user_count; j++)
					send(chat_socket_list[j], buf, nbyte, 0);
				printf("\033[0G");
				fprintf(stderr, "\033[97m");
				printf("%s", buf);
				fprintf(stderr, "\033[34m");
				fprintf(stderr, "server>");
			}
		}
	}
	return 0;
}


