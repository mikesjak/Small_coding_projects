from turtle import Turtle, Screen
import random

is_race_on = False
screen = Screen()
screen.setup(width=600, height=400)
user_bet = screen.textinput(title="Make your bet!", prompt="Which turtle will win the race? Pick a color!")
colors = ["red", "green", "orange", "blue", "yellow", "purple"]
y_positions = [-70, -40, -10, 20, 50, 80]
turtles = []

for turtle_index in range(0, 6):
    new_turtle = Turtle(shape="turtle")
    new_turtle.color(colors[turtle_index])
    new_turtle.penup()
    new_turtle.goto(x=-230, y=y_positions[turtle_index])
    turtles.append(new_turtle)

if user_bet:
    is_race_on = True

while is_race_on:
    for turtle in turtles:
        if turtle.xcor() >= 230:
            is_race_on = False
            winning_color = turtle.color()
            if winning_color == user_bet:
                print(f"You won! The {winning_color} has won the race!")
            else:
                print(f"You lost! The {winning_color} has won the race!")
            break

        rand_distance = random.randint(0, 10)
        turtle.forward(rand_distance)


screen.exitonclick()
