#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
int
main()
{
 struct sockaddr_in server;
 int sock;
 char buf[32];
 int n;

 /* Create a  tcp sock */
 sock = socket(AF_INET, SOCK_STREAM, 0); /* AF_INET:IPv4 SOCK_STREAM: TCP */

 /* Setting sock */
 server.sin_family = AF_INET;      /* IPv4 */
 server.sin_port = htons(12345);   /* port: 12345 */
 server.sin_addr.s_addr = inet_addr("127.0.0.1");

 /* connect to server */
 connect(sock, (struct sockaddr *)&server, sizeof(server));

 /* read data from server */
 memset(buf, 0, sizeof(buf));
 n = read(sock, buf, sizeof(buf)); 

 printf("recv bytes = %d, mesage = %s\n", n, buf);

 /* close socket */
 close(sock);

 return 0;
}

