
def comparelists(win_nbs, crd_nbs):
    nbr = 0
    for win_element in win_nbs:
        if win_element == "":
                print("no nbr")
                continue
        for crd_element in crd_nbs:
            crd_element = crd_element.strip("\n")
            if win_element == crd_element:
                print("winning list " + win_element + "  matching in card " + crd_element)
                if nbr >= 1:
                    nbr *= 2
                else:
                    nbr = 1
    print(nbr)
    return nbr
            
File = open("puzzle", "r")
totalnbr = 0

while(1):
    line = File.readline()
    if len(line) == 0:
        break
    x = line.split('|')
    card_nbrs = x[1].split(" ") 
    winning_str = x[0].split(":")
    winning_nbrs = winning_str[1].split(" ")
    print(winning_nbrs)
    print(card_nbrs)
    totalnbr += comparelists(winning_nbrs, card_nbrs)
    print(totalnbr)
File.close()
