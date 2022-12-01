import random

amountNum = int(input("Enter the amount of numbers for your pin that you want to generate:\n"))
for num in range(amountNum):
    print(random.randint(0, 9), end ='')