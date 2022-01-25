from collections import Counter
import csv,math

dataset, cls_count, filename, n, X, P = [], {},input("Enter file name: "), int(input("Enter no. of tuples: ")), input("Enter unknown data sample: ").split(' '), {}

with open(filename) as NB:
    readcsv = csv.reader(NB, delimiter=',')
    col_names = next(readcsv)
    class_var=[]
    for i in readcsv:
        class_var.append(i[-1])
        dataset.append(i)
    class_var=set(class_var)
data=[]

for j in class_var:
    cls_count[j], P[j] = [], 1
for j in dataset:
    cls = j[-1]
    for k in j[:-1]:
        cls_count[cls].append(k)
for i in cls_count:
    cls_count[i] = dict(Counter(cls_count[i]))
data_dict = dict(Counter(dataset))
print('\n',data_dict)
for i in cls_count:
    for j in X:
        P[i] *= cls_count[i][j]/data_dict[i]
    P[i] *= data_dict[i]/n
print("Unknown Sample belongs to class: ", max(P, key=P.get))
