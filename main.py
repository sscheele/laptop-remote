import serial
import sys
from pynput.mouse import Button
from pynput.mouse import Controller as MouseController
from pynput.keyboard import Controller as KeyController
from pynput.keyboard import Key
import time
import os

mouse = MouseController()
keyboard = KeyController()
MOUSE_MOVE_AMT = 30 

mappings = {
    "1": "UL",
    "2": "U",
    "3": "UR",
    "4": "L",
    "5": "Click",
    "6": "R",
    "7": "DL",
    "8": "D",
    "9": "DR",
    "VolUp": "VolUp",
    "VolDown": "VolDown",
    "ArrLeft": "ArrLeft",
    "ArrRight": "ArrRight"
}

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: main.py [ttyX]")
        sys.exit(0)
    port = sys.argv[1]
    ard = serial.Serial(port, 115200)

    while True:
        msg = ard.readline().decode().rstrip()
        # print("Received message: ")
        msg = mappings[msg]
        print(msg)
        mouse_mvmt = [0,0]
        if msg == "Click":
            mouse.press(Button.left)
            time.sleep(0.1)
            mouse.release(Button.left)
        elif msg == "ArrLeft":
            keyboard.press(Key.left)
            time.sleep(0.1)
            keyboard.release(Key.left)
        elif msg == "ArrRight":
            keyboard.press(Key.right)
            time.sleep(0.1)
            keyboard.release(Key.right)
        elif msg == "VolDown":
            os.system("amixer -D pulse sset Master 5%-")
        elif msg == "VolUp":
            os.system("amixer -D pulse sset Master 5%+")
        else:
            if msg.startswith("U"):
                mouse_mvmt[1] = -MOUSE_MOVE_AMT
            if msg.startswith("D"):
                mouse_mvmt[1] = MOUSE_MOVE_AMT
            if msg.endswith("L"):
                mouse_mvmt[0] = -MOUSE_MOVE_AMT
            if msg.endswith("R"):
                mouse_mvmt[0] = MOUSE_MOVE_AMT
        print(mouse_mvmt)
        mouse.move(*mouse_mvmt)
