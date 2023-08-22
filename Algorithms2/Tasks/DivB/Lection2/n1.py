array = []
while (n := int(input())) != 0:
    array.append(n)
max = 0
for i in range(len(array)):
    if array[i] > max:
        max = array[i]
counter = 0
for i in range(len(array)):
    if array[i] == max:
        counter += 1
print(counter)