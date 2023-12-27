import socket
import time
import struct
import random

def generate_random_data():
    current_values = [random.uniform(1.0, 2.0) for _ in range(20)]
    voltage_values = [random.uniform(1.0, 2.0) for _ in range(20)]
    return current_values, voltage_values

def send_data():
    host = '192.168.1.11'  
    port = 1234 


    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((host, port))

    print(f"Connected to {host}:{port}")

    while True:
        currents, voltages = generate_random_data()


        for i in range(10):
            current_bytes = struct.pack('d', currents[i])
            voltage_bytes = struct.pack('d', voltages[i])

            client_socket.sendall(current_bytes)
            client_socket.sendall(voltage_bytes)

        time.sleep(1) 

    client_socket.close()

if __name__ == "__main__":
    send_data()

