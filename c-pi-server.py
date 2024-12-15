import socket 
import subprocess as sp
import threading

ADDR = "127.0.0.1"
PORT = 4450


def server():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind((ADDR, PORT))
    s.listen(5)

    while True:
        conn, addr = s.accept()
        cl = threading.Thread(target=lambda: handler(conn))
        cl.start()


def handler(conn :socket.socket):
    conn.send("hello")
    conn.close()


def main():
    server()


if __name__ == '__main__':
    main()