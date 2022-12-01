import random
import time
dices = int(input("Enter amount of dices:\n"))
numDice = int(input("Enter the max amount number a dice should have:\n"))
def rollDice(x, y):
    c = input("Enter anything to roll or enter q to quit:\n")
    dice1 = 1
    total = 0
    while c != 'q':
        if y <= 9 and y > 0:
            for i in range(x):
                print("Rolling...")
                time.sleep(1)
                print("Rolling...")
                time.sleep(.5)
                randomNum = random.randint(0, y)
                print(f'Dice {dice1}: {randomNum}')
                total += randomNum
                dice1 += 1
        else:
            print("You entered a number that isn't possible for a die:\n")
            y = int(input("Enter a new number:\n"))
        c = input("Enter anything to roll or enter q to quit:\n")
    print("Your total is: ", total)
    return 
rollDice(dices, numDice)
    

