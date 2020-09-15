while True:
    try:
        inputList = list(map(int, input().split()))
        inputList.pop()
        firstTime = True
        prevMin = -1
        bestAns = -1
        prevMax = -1
        for i in inputList:
            if firstTime :
                firstTime = False
                prevMin = i
                prevMax = i
                bestAns = i
                continue
            currentBestMin = min(prevMin * i , min(prevMax * i , i))
            currentBestMax = max(prevMin * i , max(prevMax * i , i))
            bestAns = max(bestAns , currentBestMax)
            prevMin = currentBestMin 
            prevMax = currentBestMax
        print(bestAns)
    except EOFError:
        break
