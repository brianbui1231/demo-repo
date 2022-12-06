import time

Seconds = int(input("Enter a number to countdown from in seconds:\n"))

if Seconds > 0:
    for i in range(Seconds):
        print("")
        print(Seconds)
        time.sleep(1)
        Seconds -= 1
else:
    print("Invalid number")
    x = input("Do you want to try again?\n")
    x.lower()
    if x == "yes" or "y":
        Seconds = int(input("Enter a new number to countdown from in seconds:\n"))
        if Seconds > 0:
            for i in range(Seconds):
                print("")
                print(Seconds)
                time.sleep(1)
                Seconds -= 1
    else:
        print("Thank you for playing!")
