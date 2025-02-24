import mouse
import keyboard
import time
import pyautogui
import pyscreeze

it = time.time()
keyboard.send("windows+2")
time.sleep(0.5)

i = 0
while True:
    s = f"{i:04}"
    for c in s:
        keyboard.write(c, 0.02)
    img = pyscreeze.screenshot()
    r, g, b = img.getpixel((1090, 603))
    if (r, g, b) != (80, 125, 187):
        s1 = f"{(i - 4):04}"
        keyboard.send("windows+2")
        print(s1)
        break
print(time.time() - it)
