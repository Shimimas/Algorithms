def add_el(el):
    heap.append(el)
    i = len(heap) - 1
    while i > 0 and heap[(i - 1) // 2] < heap[i]:
        heap[(i - 1) // 2], heap[i] =  heap[i], heap[(i - 1) // 2]
        i = (i - 1) // 2

def extract():
    print(heap[0])
    heap[0] = heap[-1]
    heap.pop()
    i = 0
    while i * 2 + 2 < len(heap):
        if heap[i * 2 + 1] > heap[i] or heap[i * 2 + 2] > heap[i]:
            if heap[i * 2 + 1] > heap[i * 2 + 2]:
                heap[i], heap[i * 2 + 1] = heap[i * 2 + 1], heap[i]
                i = i * 2 + 1
            else:
                heap[i], heap[i * 2 + 2] = heap[i * 2 + 2], heap[i]
                i = i * 2 + 2
        else:
            break
    if i * 2 + 1 < len(heap) and heap[i] < heap[i * 2 + 1]:
        heap[i], heap[i * 2 + 1] = heap[i * 2 + 1], heap[i]


n = int(input())
heap = []
for _ in range(n):
    x = input().split()
    if len(x) == 1:
        extract()
    else:
        add_el(int(x[1]))

