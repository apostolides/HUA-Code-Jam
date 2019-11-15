from string import *

###############################################
# Not my best solution,  needs revisio n.     #
# TODO:                                       #
# 1)Replace file input with input from stdin. #
# 2)Remove unnecessary calculations.          #
###############################################

def main():
    with open("large.in") as file: #small.in
        content = file.readlines()
    content = [x.strip() for x in content]
    line = 0

    totalCases = atoi(content[line])
    line+=1

    for j in range(0,totalCases):
        #Read num of search engines
        engineNum = atoi(content[line])
        line+=1

        engines = []

        #Read search engines
        i = 0
        while i < engineNum:
            engines.append(content[line])
            line+=1
            i+=1

        #Read number of queries
        queriesNum = atoi(content[line])
        line+=1

        queries = []

        #Read queries
        i = 0
        while i < queriesNum:
            queries.append(content[line])
            line+=1
            i+=1

        enginesSeen = i = 0
        switches = 1
        positionSeen = {}
        bestPerm = []
        while i < queriesNum:
            if queries[i] not in positionSeen:
                enginesSeen+=1
                positionSeen[queries[i]] = i
            if enginesSeen==engineNum:
                bestPerm.append(queries[i]);
                switches+=1
                positionSeen = {}
                enginesSeen = 0
            else:
                i+=1
        if switches >= 1 :
            switches-=1
        else:
            switches = 0
        print("Case #{:d}: {:d}".format(j+1,switches))

main()
