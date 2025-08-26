import socket

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind(("127.0.0.1", 12345))
server_socket.listen(1)

print("TCP chat server started....(type 'exit' to quit)")
conn, address = server_socket.accept()
print(f"Connected with {address}")

while True:
    data = conn.recv(1024).decode()
    if not data:
        break
    print(f"Client: {data}")

    if data.lower() == "exit":
        print("Client ended the chat.")
        break

    reply = input("You: ")
    conn.send(reply.encode())

    if reply.lower() == "exit":
        print("Server ended the chat.")
        break

conn.close()
server_socket.close()
