from itertools import combinations

combinaciones = [[]]

for long in range(1, 9):
    comb_para_long = []

    indices = set(range(long))

    for k in range(long//2+1):
        comb_para_long += [(c, tuple(indices.difference(c))) for c in combinations(indices, k)]
    
    combinaciones.append(comb_para_long)

print(str(combinaciones).replace("[", "{").replace("]", "}").replace("(", "{").replace(")", "}"))