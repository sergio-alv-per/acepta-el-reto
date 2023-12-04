ultimo = "0"
num_ultimo = 0

for i in range(72948572,129485729, 3):
    j = 3
    digito = f"{i:04}"[-j-1]

    if digito == ultimo:
        num_ultimo += 1
    else:
        print(ultimo, num_ultimo)
        ultimo = digito
        num_ultimo = 1