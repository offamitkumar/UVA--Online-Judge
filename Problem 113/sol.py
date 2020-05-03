import math
while True:
    try:
        x = int(input())
        y = int(input())
        print(round(float(y**(1.0/float(x)))))
    except EOFError:
        break
