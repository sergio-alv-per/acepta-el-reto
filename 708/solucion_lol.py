import argparse

SUMAS_1 = [0, 45, 900, 13500, 180000, 2250000, 27000000, 315000000, 3600000000, 40500000000, 450000000000, 4950000000000, 54000000000000, 585000000000000, 6300000000000000]
SUMAS_3 = [[0, 18, 306, 4509, 60012, 750015, 9000018, 105000021, 1200000024, 13500000027, 150000000030, 1650000000033, 18000000000036, 195000000000039, 2100000000000042, 22500000000000045],
 [0, 12, 294, 4491, 59988, 749985, 8999982, 104999979, 1199999976, 13499999973, 149999999970, 1649999999967, 17999999999964, 194999999999961, 2099999999999958, 22499999999999955],
[0, 15, 300, 4500, 60000, 750000, 9000000, 105000000, 1200000000, 13500000000, 150000000000, 1650000000000, 18000000000000, 195000000000000, 2100000000000000, 22500000000000000]]

p = argparse.ArgumentParser()

p.add_argument("inicio", type=int)
p.add_argument("final", type=int)

args = p.parse_args()

a = args.inicio
b = args.final


def sum_digits_mult_3_1_to_n(n):
    n = n - n%3
    d = len(str(n))-1
    msd = int(str(n)[0])

    if n < 100:
        return sum([sum(map(int,str(i))) for i in range(n+1) if i%3 == 0])

    term_1 = 0
    for i in range(1, msd+1):
        if (-(i-1))%3 == 0:
            term_1 += (i-1)*(int("3"*d)+1)
        else:
            term_1 += (i-1)*(int("3"*d))
        
        term_1 += SUMAS_3[(1-i)%3][d]
    
    term_2 = msd*(n%10**d + 3 - (-msd)%3)//3

    if (-msd)%3 == 0:
        term_2 += sum_digits_mult_3_1_to_n(n%10**d)
    elif (-msd)%3 == 1:
        term_2 += sum_digits_mult_3_plus1_1_to_n(n%10**d)
    else:
        term_2 += sum_digits_mult_3_plus2_1_to_n(n%10**d)
    
    return term_1 + term_2


def sum_digits_mult_3_plus1_1_to_n(n):
    if n < 10:
        return sum([sum(map(int,str(i))) for i in range(n+1) if i%3 == 1])
    else:
        n = n - (n-1)%3
        return sum_digits_mult_3_1_to_n(n) + (n+3)//3 - 9*(sum((n + 2*10**d + 1)//(3*10**d) for d in range(1, 15)))

def sum_digits_mult_3_plus2_1_to_n(n):
    if n < 100:
        return sum([sum(map(int,str(i))) for i in range(n+1) if i%3 == 2])
    else:
        n = n - (n-2)%3
        return sum_digits_mult_3_1_to_n(n) + 2*((n+3)//3) - 9*(sum((n + 2*10**d + 1)//(3*10**d) for d in range(1, 15)) + sum((n + 10**d + 2)//(3*10**d) for d in range(1, 15)))

print(sum_digits_mult_3_1_to_n(b) - sum_digits_mult_3_1_to_n(a-1))
