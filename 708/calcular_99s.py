sumas_1 = [0, 45]
sumas_3 = [0, 18, 306]
sumas_3_1 = [0]
sumas_3_2 = [0]

for d in range(2, 15):
    sumas_1.append(sumas_1[d-1]*10 + 45*10**(d-1))

for d in range(3, 16):
    sumas_3.append(sumas_3[d-1] + 3*sumas_1[d-1] + 18*(int("3"*(d-1))+1) + (12+15)*int("3"*(d-1)))

for d, s in enumerate(sumas_3[1:], start=1):
    sumas_3_1.append(s - 6*d)
    sumas_3_2.append(s - 3*d)

print(sumas_1)
print(sumas_3)
print(sumas_3_1)
print(sumas_3_2)

