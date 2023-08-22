s = int(input())
n_array = list(map(int, input().split()))
n = n_array[0]
n_array = n_array[1:]
m_array = list(map(int, input().split()))
m = m_array[0]
m_array = m_array[1:]
k_array = list(map(int, input().split()))
k = k_array[0]
k_array = k_array[1:]
n_array = sorted([(n_array[i], i) for i in range(n)])
m_array = sorted([(m_array[i], i) for i in range(m)])
k_array = sorted([(k_array[i], i) for i in range(k)])
res_array = (n, m, k)
for i in range(n):
    l = k - 1
    for j in range(m):
        while l >= 0 and k_array[l][0] + n_array[i][0] + m_array[j][0] > s:
            l -= 1
        l_tmp = l
        while l_tmp >= 0 and k_array[l_tmp][0] + n_array[i][0] + m_array[j][0] == s:
            if res_array > (n_array[i][1], m_array[j][1], k_array[l_tmp][1]):
                res_array = (n_array[i][1], m_array[j][1], k_array[l_tmp][1])
            l_tmp -= 1
if res_array == (n, m, k):
    print(-1)
else:
    print(str(res_array).replace('(', '').replace(')', '').replace(',', ''))