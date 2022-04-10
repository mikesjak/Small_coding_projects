import pyautogui, time
time.sleep(5)

# You have to define the text you want to spam

file = "Eminem.txt"

f = open("file", "r")
for word in f:
    time.sleep(0.5)
    pyautogui.typewrite(word)
    pyautogui.press("enter")


