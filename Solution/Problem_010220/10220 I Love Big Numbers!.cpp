import math
while True:
    try :
        x = int(input())
        y = str(math.factorial(x))
        s = 0
        for ch in y:
            s += int(ch)
        print(s)
    except EOFError:
        break
