
def comparelists(win_nbs, crd_nbs):
    nbr = 0
    for win_element in win_nbs:
        if win_element == "":
                # print("no nbr")
                continue
        for crd_element in crd_nbs:
            crd_element = crd_element.strip("\n")
            if win_element == crd_element:
                nbr =  nbr + 1
    return nbr
            
File = open("puzzle", "r")
lines = File.readlines()
exce_card_amount = []
cardslen = len(lines)


for line in lines:
     exce_card_amount.append(1)


i = 0
while i < len(lines):
    j = 0
    x = lines[i].split('|')
    card_nbrs = x[1].split(" ") 
    winning_str = x[0].split(":")
    winning_nbrs = winning_str[1].split(" ")
    while j < exce_card_amount[i]:
        add_1_next_n = comparelists(winning_nbrs, card_nbrs)
        k = 0
        while k < add_1_next_n:
            if int(i + k + 1) < cardslen:
                exce_card_amount[i + k + 1] += 1
            k = k + 1
        j = j + 1
    i = i + 1

i = 0
totalnum = 0
while i < len((exce_card_amount)):
     totalnum += exce_card_amount[i]
     i = i + 1
print(totalnum)
File.close()
