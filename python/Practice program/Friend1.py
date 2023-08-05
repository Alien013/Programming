import random
import pyautogui as pg
import time
animal = ('monkey', 'domkey', 'chutiye', 'haarami')
time.sleep(8)
for i in range(200):
    a = random.choice(animal)
    pg.write("You are "+a)

    pg.press('enter')