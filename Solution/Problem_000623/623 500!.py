import math
while True:
    try:
        x = int(input())
        print(str(x)+"!")
        print(math.factorial(x))
    except EOFError:
        break
