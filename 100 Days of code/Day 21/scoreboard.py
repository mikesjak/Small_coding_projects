from turtle import Turtle

ALIGNMENT = "center"
FONT = ("Arial", 24, "normal")

class Scoreboard(Turtle):

    def __init__(self):
        super().__init__()
        self.penup()
        self.goto(0, 250)
        self.score = 0
        self.color("white")
        self.hideturtle()
        self.update_score()

    def update_score(self):
        self.write(f"Score: {self.score}", align=ALIGNMENT, font=FONT)

    def add_score(self):
        self.score += 1
        self.clear()
        self.update_score()

    def game_over(self):
        self.clear()
        self.goto(0, 20)
        self.write("GAME OVER", align=ALIGNMENT, font=FONT)
        self.goto(0, -20)
        self.write(f"Final score: {self.score}", align=ALIGNMENT, font=FONT)
