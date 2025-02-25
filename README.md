
Interprocess Communication using Sockets in C
Introduction
This project demonstrates interprocess communication (IPC) using sockets in C. It includes both UNIX domain socket and TCP/IP socket implementations, enabling message exchange between a client and a server.

Concepts Used
1.Sockets: A socket is an endpoint for communication between processes over a network or locally.
2.UNIX Domain Sockets: Used for communication between processes on the same system.
3.TCP/IP Sockets: Used for communication between processes over a network using the Internet Protocol (IP).
4.Blocking I/O: The read() and write() functions block execution until data is available or sent.
5.Loopback Address (127.0.0.1): Used for local testing in TCP sockets.

UNIX Domain Sockets
UNIX domain sockets enable interprocess communication (IPC) within the same machine using a file path instead of an IP address.

Server (unix_server.c)
1.Creates a socket using socket(AF_UNIX, SOCK_STREAM, 0).
2.Binds the socket to a file path (/tmp/chat_socket).
3.Listens for an incoming client connection.
4.Accepts the client connection and enters a communication loop:
5.Reads data from the client.
6.Sends a response back to the client.
7.Closes the connection and removes the socket file.

Client (unix_client.c)
1.Creates a socket using socket(AF_UNIX, SOCK_STREAM, 0).
2.Connects to the server via /tmp/chat_socket.
3.Enters a communication loop:
4.Reads input from the user and sends it to the server.
5.Receives a response from the server and prints it.
6.Closes the connection.

TCP/IP Sockets
TCP/IP sockets enable communication between processes over a network.

Server (tcp_server.c)
1.Creates a socket using socket(AF_INET, SOCK_STREAM, 0).
2.Binds the socket to an IP address (INADDR_ANY) and port (8080).
3.Listens for incoming client connections.
4.Accepts a client connection and enters a communication loop:
5.Reads messages from the client.
6.Sends responses to the client.
7.Closes the connection.

Client (tcp_client.c)
1.Creates a socket using socket(AF_INET, SOCK_STREAM, 0).
2.Connects to the server using IP (127.0.0.1) and port (8080).
3.Enters a communication loop:
4.Reads input from the user and sends it to the server.
5.Receives and prints the server’s response.
6.Closes the connection.

Conclusion
This project demonstrates two types of socket communication:

UNIX domain sockets for IPC within the same machine.
TCP/IP sockets for communication over a network.
It provides a basic chat system and can be extended to support multiple clients, threading, non-blocking I/O, and encryption.







