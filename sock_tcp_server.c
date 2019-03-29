#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int
main()
{
 int sock0;
 struct sockaddr_in addr;
 struct sockaddr_in client;
 int len;
 int sock;

 /* Create a  tcp sock */
 sock0= socket(AF_INET, SOCK_STREAM, 0);

  /* Setting sock */
 addr.sin_family = AF_INET;       /* IPv4 */
 addr.sin_port = htons(12345);   /* port: 12345 */
 addr.sin_addr.s_addr = INADDR_ANY;

 /* assigns ip and port */
 bind(sock0, (struct sockaddr *)&addr, sizeof(addr));

 /* socket to enter listening state*/
 listen(sock0, 5);

 /* Accept client to connet from listen sock */
 len = sizeof(client); 
 sock = accept(sock0, (struct sockaddr *)&client, &len); 

 /* send data */
 write(sock, "HELLO", 5);

 /* close listen sock */
 close(sock);

 /* close client sock */
 close(sock0);

 return 0;
}
