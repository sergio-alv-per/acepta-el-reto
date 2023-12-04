import argparse

p = argparse.ArgumentParser()
p.add_argument("n", type=int)

n = p.parse_args().n

s = [0, 0, 0,]
for i in range(1, n+1):
    s[i%3] += sum(map(int, str(i)))

print(s)