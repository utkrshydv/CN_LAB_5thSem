import socket
import sys
import threading

BUFFER_SIZE = 1024

if len(sys.argv) != 4:
    print(f"Usage: python {sys.argv[0]} <MY_PORT> <OTHER_IP> <OTHER_PORT>")
    sys.exit(1)

MY_PORT = int(sys.argv[1])
OTHER_IP = sys.argv[2]
OTHER_PORT = int(sys.argv[3])

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(("0.0.0.0", MY_PORT))

stop_flag = False

def receive_messages():
    global stop_flag
    while not stop_flag:
        try:
            data, addr = sock.recvfrom(BUFFER_SIZE)
            msg = data.decode().strip()
            if msg:
                print(f"\nOther: {msg}")
            if msg.lower() == "exit":
                print("Exit message received. Closing.")
                stop_flag = True
                break
            print("> ", end="", flush=True)  # Keep prompt visible
        except:
            break

def send_messages():
    global stop_flag
    while not stop_flag:
        try:
            msg_out = input(">utkarsh:  ")
            sock.sendto(msg_out.encode(), (OTHER_IP, OTHER_PORT))
            if msg_out.lower() == "exit":
                print("Exit message sent. Closing.")
                stop_flag = True
                break
        except:
            break

print(f"My UDP port: {MY_PORT} | Sending to {OTHER_IP}:{OTHER_PORT}")

threading.Thread(target=receive_messages, daemon=True).start()
send_messages()

sock.close()
