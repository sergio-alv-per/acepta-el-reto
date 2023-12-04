mults = [0]*3

d = 5

for i in range(0, 10**d-1 + 1):
    mults[i%3] += 1

print(mults)