n = int(input())
num_set = set([i for i in range(1, n + 1)])
while (s := input()) != "HELP":
    tmp_set = set(map(int, s.split()))
    if input() == "YES":
        num_set &= tmp_set
    else:
        num_set -= tmp_set
res_text = ''
array = sorted(list(num_set))
for el in array:
    res_text += str(el) + ' '
print(res_text)