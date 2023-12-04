N = int(input())

while N != 0:
    objetos = []
    for i in range(N):
        entrada = input().split(" ")
        objetos.append((-int(entrada[1]), int(entrada[2]), i, entrada[0]))
    
    objetos.sort()

    print(" ".join(x[3] for x in objetos))
    N = int(input())
