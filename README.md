# tcp_server
UDP Server on C. TCP is on branch "master"

Run in docker:\
docker build -t server .\
docker run --restart always -p 42749:42749/udp -d server
