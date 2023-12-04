import random

N = 200000

print(N)
for _ in range(N):
    a,b = random.sample(range(10**9+1), 2)
    print(min(a,b), max(a,b))