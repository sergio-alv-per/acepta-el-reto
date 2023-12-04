
def factors(x):
    f = []
    for i in range(1, x):
        if x % i == 0:
            f.append(i)
    return f

print("{", end="")
for i in range(1, 201):
    factores = [str(x) for x in factors(i)]
    print("{" + ", ".join(factores) + "},")

print("}")

