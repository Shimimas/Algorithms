counter = 0
letters = 'ГОД'
for i in letters:
    for h in letters:
        for j in letters:
            for b in letters:
                for f in letters:
                    for l in letters:
                        string = i + h + j + b + f + l
                        if i == 'Г' or i == 'Д':
                            counter += 1
print(counter)
