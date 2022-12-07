import turtle
import random

t = turtle.Turtle()
t1 = turtle.Turtle()
t2 = turtle.Turtle()
t3 = turtle.Turtle()
tu = turtle
#window
tu.screensize(100, 100, 'black')
#pen 1
t.pensize(2)
t.shape("circle")
t.pencolor("white")
t.speed(5)
#pen 2
t1.pensize(2)
t1.shape("circle")
t1.pencolor("white")
t1.speed(5)
#pen 3
t2.pensize(2)
t2.shape("circle")
t2.pencolor("white")
t2.speed(5)
#pen 4
t3.pensize(2)
t3.shape("circle")
t3.pencolor("white")
t3.speed(5)

#the outline

t.penup()
t1.penup()
t1.sety(-100)
t.sety(100)
t1.pendown()
t.pendown()
t.forward(400)
t.setpos(-400, 100)
t1.forward(400)
t1.setpos(-400, -100)
t2.penup()
t3.penup()
t2.backward(200)
t3.forward(200)
t3.pendown()
t2.pendown()
t2.setpos(-200, -400)
t3.setpos(200, -400)
t3.setpos(200, 400)
t2.setpos(-200, 400)
tu.done()