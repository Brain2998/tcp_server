FROM gcc:4.9
RUN mkdir -p /tcp_server
COPY . /tcp_server
WORKDIR /tcp_server
RUN gcc -o tcp_server server.c
CMD ["./tcp_server", "0.0.0.0", "42749"]