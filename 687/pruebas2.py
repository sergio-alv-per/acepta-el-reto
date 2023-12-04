
s = 0
for i in range(1, 546):
    s += sum([int(x) for x in str(i)])

print(s)