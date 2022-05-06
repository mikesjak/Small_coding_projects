import turtle as t
import random

tim = t.Turtle()

colors = ["white","white smoke","dim gray","slate gray","cornflower blue","blue","dodger blue","turquoise","teal","lime green","dark green","lime","gold","peru","deep pink","red","medium violet red","blue violet","indigo"]

def draw_shape(numSides):
    angle = 360 / numSides
    for _ in range(numSides):
        tim.forward(20)
        tim.right(angle)

for i in range(3,100000):
    tim.color(random.choice(colors))
    draw_shape(i)
    