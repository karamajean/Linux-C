
all: sock_udp_recv sock_udp_send sock_tcp_client sock_tcp_server

sock_udp_recv :sock_udp_recv.c
        cc sock_udp_recv.c -o sock_udp_recv
sock_udp_send :sock_udp_send.c
        cc sock_udp_send.c -o sock_udp_send
sock_tcp_client :sock_tcp_client.c
        cc sock_tcp_client.c -o sock_tcp_client
sock_tcp_server :sock_tcp_server.c
        cc sock_tcp_server.c -o sock_tcp_server

clean:
        rm sock_udp_recv sock_udp_send sock_tcp_client sock_tcp_server
