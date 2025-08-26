import socket

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = ("127.0.0.1", 12345)

client_socket.connect(server_address)

print("TCP chat client started...(type 'exit' to quit)")

while True:
    msg = input("You: ")
    client_socket.send(msg.encode())

    if msg.lower() == "exit":
        print("You ended the chat")
        break

    reply = client_socket.recv(1024).decode()
    print(f"Server: {reply}")

    if reply.lower() == "exit":
        print("Server ended the chat.")
        break

client_socket.close()
