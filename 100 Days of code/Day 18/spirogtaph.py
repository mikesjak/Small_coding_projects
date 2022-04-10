import turtle as t
import random

t.colormode(255)
tim = t.Turtle()


def randomcolor():
    r = random.randint(0, 255)
    g = random.randint(0, 255)
    b = random.randint(0, 255)
    random_color = (r, g, b)
    return random_color


tim.penup()
tim.hideturtle()
tim.setheading(225)
tim.forward(350)
tim.setheading(0)

for dot_count in range(1, 101):
    tim.dot(20, randomcolor())
    tim.forward(50)

    if dot_count % 10 == 0:
        tim.setheading(90)
        tim.forward(50)
        tim.setheading(180)
        tim.forward(500)
        tim.setheading(0)

screen = t.Screen()
screen.exitonclick()
