import random

print("300000 300000")

a = [str(x) for x in random.choices(range(10**9, 10**9+1), k=300000)]

print(" ".join(a))