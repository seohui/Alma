# StrJoin
#
# Greedy approach
# Prove it! 
# assume two min length string 'a' and 'b'
# 1) same depth: 
# 'a' 'x' 'b' 'y' -> ('a' + 'x') + ('b' + 'y')
# == ('a' + 'b') + ('x' + 'y')
#
# 2) diff depth:
# 'a' 'x' 'b' -> ('a' + 'x') + 'b'
# >= ('a' + 'b') + 'x'
# this case is always true!

import sys
import heapq

test_case = int(sys.stdin.readline())

def work():
    n = int(sys.stdin.readline())
    
    heap = list()
    for e in map(int, sys.stdin.readline().rstrip().split()):
        heapq.heappush(heap, e)

    total_time = 0
    while len(heap) != 1:
        first = heapq.heappop(heap)
        second = heapq.heappop(heap)

        total_time += (first + second)
        heapq.heappush(heap, first+second)

    print(total_time)

for _ in range(test_case):
    work()

