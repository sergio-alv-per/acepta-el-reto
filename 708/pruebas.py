for n in range(10000):
    s = 0
    for i in range(n+1):
        if i%3==0:
            for d in range(1, 15):
                if i%(10**d) == (10**d - 2):
                    s += 1
    
    if s != sum((n + 10**d + 2)//(3*10**d) for d in range(1, 15)):
        print(f"{n} | {s} | {sum((n + 10**d + 2)//(3*10**d) for d in range(1, 15))}")
        break

    
