a, b = [int(x) for x in input().split(" ")]

while a != 0 and b!= 0:
    s = 0
    for i in range(a, b+1):
        if i%3 == 0:
            s += sum(map(int, str(i)))

    print(s)

    a, b = [int(x) for x in input().split(" ")]