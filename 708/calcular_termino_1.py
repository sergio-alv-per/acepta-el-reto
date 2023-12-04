d_treses = [0, 3, 33, 333, 3333, 33333, 333333, 3333333, 33333333, 333333333, 3333333333, 33333333333, 333333333333, 3333333333333, 33333333333333, 333333333333333]

sumas_3 = [
[0, 18, 306, 4509, 60012, 750015, 9000018, 105000021, 1200000024, 13500000027, 150000000030, 1650000000033, 18000000000036, 195000000000039, 2100000000000042, 22500000000000045],
[0, 12, 294, 4491, 59988, 749985, 8999982, 104999979, 1199999976, 13499999973, 149999999970, 1649999999967, 17999999999964, 194999999999961, 2099999999999958, 22499999999999955],
[0, 15, 300, 4500, 60000, 750000, 9000000, 105000000, 1200000000, 13500000000, 150000000000, 1650000000000, 18000000000000, 195000000000000, 2100000000000000, 22500000000000000]
]

def calcular_termino_1(msd, d):
    term_1 = 0

    for i in range(1, msd+1):
        if ((-(i-1))%3) == 0:
            term_1 += (i-1)*(d_treses[d] + 1)
        else:
            term_1 += (i-1)*(d_treses[d])
        
        term_1 += sumas_3[(1-i)%3][d]
    
    return term_1

matriz = [[0]*15]

for i in range(1, 10):
    matriz.append([0])
    for d in range(1, 16):
        matriz[i].append(calcular_termino_1(i, d))

print(",\n".join(str(x) for x in matriz).replace("[", "{").replace("]", "}"))
