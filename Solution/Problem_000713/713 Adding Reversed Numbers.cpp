testCase = int(input())
while testCase:
    testCase-=1
    a,b = map(int,input().split())
    strA = str(a)[::-1]
    strB = str(b)[::-1]
    a = int(strA)
    b = int(strB)
    a = a + b 
    strA = str(a)[::-1]
    print(int(strA))
