import socket

client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_address = ("127.0.0.1", 12345)

print("UDP chat client started...(type 'exit' to quit)")

while True:
    msg = input("You: ")
    client_socket.sendto(msg.encode(), server_address)

    if msg.lower() == "exit":
        print("You ended the chat")
        break

    data, _ = client_socket.recvfrom(1024)
    reply = data.decode()
    print(f"Server: {reply}")

    if reply.lower() == "exit":
        print("Server ended the chat.")
        break

client_socket.close()
