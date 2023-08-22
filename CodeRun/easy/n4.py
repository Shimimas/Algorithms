n, m = tuple(map(int, input().split()))
n_array = sorted(list(map(int, input().split())))
m_array = sorted(list(map(int, input().split())), reverse=True)
profit = 0
for i in range(min(n, m)):
    if m_array[i] < n_array[i]:
        break
    else:
        profit += m_array[i] - n_array[i]
print(profit)