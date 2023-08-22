def add_el(el):
    heap.append(el)
    i = len(heap) - 1
    while i > 0 and heap[(i - 1) // 2] < heap[i]:
        heap[(i - 1) // 2], heap[i] =  heap[i], heap[(i - 1) // 2]
        i = (i - 1) // 2

def extract(n):
    tmp = heap[0]
    heap[0] = heap[n - 1]
    heap[n - 1] = tmp
    i = 0
    while i * 2 + 2 < n - 1:
        if heap[i * 2 + 1] > heap[i] or heap[i * 2 + 2] > heap[i]:
            if heap[i * 2 + 1] > heap[i * 2 + 2]:
                heap[i], heap[i * 2 + 1] = heap[i * 2 + 1], heap[i]
                i = i * 2 + 1
            else:
                heap[i], heap[i * 2 + 2] = heap[i * 2 + 2], heap[i]
                i = i * 2 + 2
        else:
            break
    if i * 2 + 1 < n - 1 and heap[i] < heap[i * 2 + 1]:
        heap[i], heap[i * 2 + 1] = heap[i * 2 + 1], heap[i]

n = int(input())
n_array = list(map(int, input().split()))
heap = []
for el in n_array:
    add_el(el)
for n in range(n, 0, -1):
    extract(n)
print(' '.join(map(str, heap)))