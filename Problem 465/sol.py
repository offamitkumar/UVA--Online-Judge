while True:
    try:
        inp = str(input())
        values = inp.split()
        print(values[0] , end=" ")
        print(values[1] , end=" ")
        print(values[2])
        #print(int(values[0]),end=" ")
        #print(values[1],end=" ")
        #print(int(values[2]))
        INT_MAX=2147483647
        if int(values[0])>INT_MAX:
            print("first number too big")
        if int(values[2])>INT_MAX:
            print("second number too big")
        if values[1]=='+' and int(values[0])+int(values[2])>INT_MAX:
            print("result too big")
        elif values[1]=='*' and int(values[0])*int(values[2])>INT_MAX:
            print("result too big")
    except EOFError:
        break

