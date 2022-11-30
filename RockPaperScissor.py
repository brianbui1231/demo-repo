import random
yourChoice = input("Enter your choice: Rock, Paper, or Scissor:\n")
enemy = ['rock', 'paper', 'scissor']
computer1 = random.choice(enemy) 
def winChoice(player, computer):
    player.lower()
    computer.lower()
    if player == computer:
        print("You Tied!\n")
    else:
        if player == "rock" and computer == "scissor":
            print("You Won!\n")
        if player == "scissor" and computer == "rock":
            print("You Lost!\n")
        if player == "paper" and computer == "rock":
            print("You Won!\n")
        if player == "paper" and computer == "scissor":
            print("You Lost!\n")
        if player == "scissor" and computer == "paper":
            print("You Won!\n")
        if player == "rock" and computer == "paper":
            print("You Lost!\n")
winChoice(yourChoice, computer1)
c = input("Enter anything to continue, else enter q to quit:\n")

while c != 'q' and yourChoice in enemy:
    yourChoice = input("Enter your choice: Rock, Paper, or Scissor:\n")
    winChoice(yourChoice, computer1)
