inputFile = open('puzzle', 'r')
lines = inputFile.readlines()

cardData = []
cardInstances = []

def setCardData():
    data = []
    instances = []

    for i in range(len(lines)):
        line = lines[i]
        
        numSeries1 = line[line.index(':') + 2 : line.index('|')]
        numSeries2 = line[line.index('|') + 2 :]

        lineData = []
        lineData.append([int(j) for j in numSeries1.split()])
        lineData.append([int(j) for j in numSeries2.split()])

        data.append(lineData)
        instances.append(1)

    global cardData, cardInstances
    cardData = data
    cardInstances = instances

def cardPoints(card):
    points = 0
    
    winningNrs = card[0]
    cardNrs = card[1]

    for nr1 in winningNrs:
        for nr2 in cardNrs:
            if nr1 == nr2:
                points += 1

    return points

def totalCards():
    setCardData()
    
    for i in range(len(lines)):
        points = cardPoints(cardData[i])

        for j in range(cardInstances[i]):
            for k in range(points):
                cardInstances[i + k + 1] += 1

    nrCards = 0

    for i in range(len(cardInstances)):
        nrCurrCards = cardInstances[i]
        nrCards += nrCurrCards

    return nrCards

print(totalCards())