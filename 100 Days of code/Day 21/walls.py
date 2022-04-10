from turtle import Turtle

POSITIONS = [(-320, -320), (-320, 320), (320, -320), (320, 320), (-320, -320)]

class Wall:

    def __init__(self):
        self.walls = []
        self.create_walls()

    def create_walls(self):
        for position in POSITIONS:
            self.add_wall(position)

    def add_wall(self, position):
        new_wall = Turtle("square")
        new_wall.color("white")
        new_wall.penup()
        new_wall.goto(position)
        self.walls.append(new_wall)
