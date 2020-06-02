l = [0]*5005
l[0] = 0
l[1] = 1
for i in range(2,5001):
    l[i] = l[i-1]+l[i-2]
while True:
    try:
        x = int(input())
        print(f"The Fibonacci number for {x} is {l[x]}")
    except EOFError:
        break
