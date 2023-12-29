

cardData_p1 = []
cardData_p2 = []

def build_lists():
	for line in lines:
		str_p1 = line[line.index(':') + 2 : line.index('|')]
		str_p2 = line[line.index('|') + 2 : ]
		num_series_p1 = [int(j) for j in str_p1.split()]
		num_series_p2 = [int(j) for j in str_p2.split()]
		cardData_p1.append(num_series_p1)
		cardData_p2.append(num_series_p2)
		# print(num_series_p1)

def comparelists(nbs_p1, nbs_p2):
	nbr = 0
	for p1_element in nbs_p1:
		# if p1_element == "":
				# print("no nbr")
				# continue
		for p2_element in nbs_p2:
			if p1_element == p2_element:
				nbr =  nbr + 1
	return nbr
			
File = open("puzzle", "r")
lines = File.readlines()
exce_card_amount = []
cardslen = len(lines)

build_lists()

for line in lines:
	exce_card_amount.append(1)

k = 0
totalnum = 0
i = 0
for i in range(len(lines)):
	additions = comparelists(cardData_p1[i], cardData_p2[i])

	for j in range(exce_card_amount[i]):
		while k < additions:
			exce_card_amount[i + k + 1] += 1
			k = k + 1
		k  = 0
	
i = 0
while i < len((exce_card_amount)):
     totalnum += exce_card_amount[i]
     i = i + 1

print(totalnum)
File.close()
