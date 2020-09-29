import math
while True:
        x = int(input())
        if x == 0:
            break
        y = str(math.factorial(x))
        a = list( 0 for x in range(0, 10))
        for ch in y:
            a[int(ch)]+=1
        print(str(x)+'! --')
        print('   ', end='')
        print('(0)'+'{0: >5}'.format(str(a[0]))+'{0: >4}'.format(' ')+'(1)'+'{0: >5}'.format(str(a[1]))+'{0: >4}'.format(' ')+'(2)'+'{0: >5}'.format(str(a[2]))+'{0: >4}'.format(' ')+'(3)'+'{0: >5}'.format(str(a[3]))+'{0: >4}'.format(' ')+'(4)'+'{0: >5}'.format(str(a[4])))
        print('   ', end='')
        print('(5)'+'{0: >5}'.format(str(a[5]))+'{0: >4}'.format(' ')+'(6)'+'{0: >5}'.format(str(a[6]))+'{0: >4}'.format(' ')+'(7)'+'{0: >5}'.format(str(a[7]))+'{0: >4}'.format(' ')+'(8)'+'{0: >5}'.format(str(a[8]))+'{0: >4}'.format(' ')+'(9)'+'{0: >5}'.format(str(a[9])))
