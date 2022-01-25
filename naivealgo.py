c1n = 0
c2n = 0
c1 = [0,0,0,0]
c2 = [0,0,0,0]
pc1 = [0,0,0,0]
pc2 = [0,0,0,0]
data = []

f = open("data.csv","r")
d = f.read()
lines = d.split('\n')
for d in lines:
	data.append(d.split(","))

atrb = len(data[0])
for i in range(len(lines)):
	if data[i][atrb-1] == "Yes":
		c1n = c1n + 1
	elif data[i][atrb-1] == "No":
		c2n = c2n +  1
print(c1n)
print(c2n)
pofc1 = c1n/len(lines)
pofc2 = c2n/len(lines)

inp = input("Enter outlook, temperature, humidity, windy \n")
inp_data = inp.split(",")

for i in range(len(lines)):
	for j in range(atrb-1):
		if data[i][j] == inp_data[j]:
			if data[i][atrb-1] == "Yes":
				c1[j] = c1[j] + 1
			else:
				c2[j] = c2[j] + 1

pc1[:] = [x/c1n for x in c1]
pc2[:] = [x/c2n for x in c2]

pxbyc1 = 1
pxbyc2 = 1

for x in pc1:
	pxbyc1 = pxbyc1 * x

for x in pc2:
	pxbyc2 = pxbyc2 * x

pc1byx = pxbyc1 * pofc1
pc2byx = pxbyc2 * pofc2

if pc1byx>pc2byx:
	print("Play = Yes")
else:
	print("Play = No")




