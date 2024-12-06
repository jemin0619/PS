#직관적이진 않지만, 수학만으로 풀린다.

import math
N = int(input())
a = list(map(int, input().split()))
ret = 0.0
for val in a: ret += 1/val
print(math.ceil(ret))
