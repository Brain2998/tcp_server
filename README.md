# tcp_server
TCP and on C. UDP is on branch "udp_server"

Run in docker:\
docker build -t server .\
docker run --restart always -p 42749:42749 -d server\
