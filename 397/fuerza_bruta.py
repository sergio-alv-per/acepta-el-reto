res = "{"
for n in range(10**3):
    mod = 0
    for i in range(1, n+1):
        mod = (mod + i%3)%3
    if mod == 0:
        res += "{" + str(n) + ",1},\n"
    else:
        res += "{" + str(n) + ",0},\n"

print(res)
    