import serial
import time
import requests

ser = serial.Serial('COM5', 9600)
time.sleep(2)

API_KEY = 'D1WF66PHGSX8LIIQ'
THINGSPEAK_URL = 'https://api.thingspeak.com/update'


def enviar_a_thingspeak(temperatura):
    payload = {
        'api_key': API_KEY,
        'field1': temperatura
    }
    try:
        response = requests.post(THINGSPEAK_URL, data=payload)
        if response.status_code == 200:
            print("Datos enviados a ThingSpeak correctamente")
        else:
            print("Error al enviar datos a ThingSpeak:", response.status_code)
    except Exception as e:
        print("Error de conexión:", e)


while True:
    if ser.in_waiting > 0:
        mensaje = ser.readline().decode('utf-8', errors='ignore').strip()

        try:
            temperatura = float(mensaje)
            print(f"Temperatura actual: {temperatura} °C")

            enviar_a_thingspeak(temperatura)

        except ValueError:
            print("Error: No se pudo convertir el mensaje a un valor numérico")

