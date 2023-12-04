import random

for _ in range(1000000):
    a = random.randint(1, 10**15)
    b = random.randint(1, 10**15)

    if a == b:
        b = a + 10000
    
    print(min(a,b), max(a,b))

print(0, 0)