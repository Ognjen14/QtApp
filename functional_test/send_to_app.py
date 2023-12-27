import socket
import time
import struct
import random

def generate_random_data():
    cooler_current = [random.uniform(1.0, 5.0) for _ in range(20)]
    cooler_voltage = [random.uniform(1.0, 5.0) for _ in range(20)]
    detector_current = [random.uniform(1.0, 5.0) for _ in range(20)]
    detector_voltage = [random.uniform(1.0, 5.0) for _ in range(20)]
    return cooler_current, cooler_voltage, detector_current, detector_voltage

def send_data():
    host = '192.168.1.11'
    port = 1234

    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((host, port))

    print(f"Connected to {host}:{port}")

    while True:
        cooler_current, cooler_voltage, detector_current, detector_voltage = generate_random_data()

        for i in range(10):
            cooler_current_bytes = struct.pack('d', cooler_current[i])
            cooler_voltage_bytes = struct.pack('d', cooler_voltage[i])
            detector_current_bytes = struct.pack('d', detector_current[i])
            detector_voltage_bytes = struct.pack('d', detector_voltage[i])

            client_socket.sendall(cooler_current_bytes)
            client_socket.sendall(cooler_voltage_bytes)
            client_socket.sendall(detector_current_bytes)
            client_socket.sendall(detector_voltage_bytes)

        time.sleep(1)

    client_socket.close()

if __name__ == "__main__":
    send_data()

