# tcp_server
TCP and UDP Server on C. UDP is on branch "udp_server"

Run in docker:
docker build -t server .\
#TCP server\
docker run --restart always -p 42749:42749 -d server\
#UDP server\
docker run --restart always -p 42749:42749\udp -d server
