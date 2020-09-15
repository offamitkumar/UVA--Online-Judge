while True:
    try:
        a = list(map(int , input().split()))
        a.pop()
        x = len(a)
        ans = -10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
        for i in range(0 , x):
            for j in range(i,x):
                temp = 1
                for k in range(i,j+1):
                    temp *= a[k]
                ans = max(ans , temp)
        print(ans)
    except EOFError:
        break
