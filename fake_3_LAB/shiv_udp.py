import socket
import threading
import sys

running = True


def receive_messages(sock):
    global running
    while running:
        try:
            data, addr = sock.recvfrom(1024)
            message = data.decode()
            print(f"\nPeer: {message}")
            if message.lower() == "exit":
                print("Peer ended the chat.")
                running = False
                break
            print("You: ", end="", flush=True)
        except:
            break


if len(sys.argv) != 5:
    print(
        f"Usage: python {sys.argv[0]} <My_IP> <My_Port> <Peer_IP> <Peer_Port>")
    sys.exit(1)

my_ip = sys.argv[1]
my_port = int(sys.argv[2])
peer_ip = sys.argv[3]
peer_port = int(sys.argv[4])

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((my_ip, my_port))

threading.Thread(target=receive_messages, args=(sock,), daemon=True).start()

print("You: ", end="", flush=True)

while running:
    try:
        msg = input()
        sock.sendto(msg.encode(), (peer_ip, peer_port))
        if msg.lower() == "exit":
            running = False
            break
        print("You: ", end="", flush=True)
    except:
        break

sock.close()
