n = int(input())
array = sorted(list(map(int, input().split())))
array_ans = sorted([array[-4] * array[-3] * array[-2] * array[-1],
                    array[0] * array[-2] * array[-1] * array[-3], 
                    array[0] * array[1] * array[-1] * array[-2], 
                    array[0] * array[1] * array[2] * array[-1],
                    array[0] * array[1] * array[2] * array[3]])
print(array_ans[-1])