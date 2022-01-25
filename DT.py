import csv
import math
from collections import Counter

data_list, prob, listHD, independent_var, ind_var, splitting_attr = [], [], [], [], [], []
line_count, HD, HDI, HDII = 0, 0, 0, 0
attributes = ["outlook", "temperature", "humidity", "windy"]
class_var = set()
with open('input2.csv', 'r') as file:
	data = csv.reader(file, delimiter = ',', quotechar = '"')
	for line in data:
		line_count += 1
		class_index = len(line) - 1
		class_var.add(line[class_index])
		data_list.append(line)

class_var = list(class_var)
for i in class_var:
	count = 0
	for j in data_list:
		if(i == j[class_index]):
			count += 1
	prob.append(count/line_count)

for i in prob:
	HD += i*math.log10(1/i)

for i in range(class_index):
	for j in data_list:
		independent_var.append((j[i], j[class_index]))
		ind_var.append(j[i])
	ct1 = Counter(ind_var)
	ct2 = Counter(independent_var)
	HDII = 0
	for key1, val1 in ct1.items():
		HDI = 0
		for key2, val2 in ct2.items():
			if(key1 == key2[0]):
				HDI += (val2/val1)*math.log10(val1/val2)
		HDII += (val1/line_count) * HDI
	listHD.append(HD - HDII)
	ind_var.clear()
	independent_var.clear()

m = max(listHD)
ind = 0
for i in listHD:
	if(i == m):
		break
	ind += 1
	
print("Splitting Atrribute is", attributes[ind])