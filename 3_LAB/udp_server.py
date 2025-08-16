import socket

server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.bind(("127.0.0.1", 12345))

print("UDP chat server started....(type 'exit' to quit)")

while True:
    data, address = server_socket.recvfrom(1024)
    msg = data.decode()
    print(f"Client: {msg}")

    if msg.lower() == "exit":
        print("Client ended the chat.")
        break

    reply = input("You: ")
    server_socket.sendto(reply.encode(), address)

    if reply.lower() == "exit":
        print("Server ended the chat.")
        break

server_socket.close()
