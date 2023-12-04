from collections import Counter

decode = {".-": "A",
          "-...": "B",
          "-.-.": "C",
          "-..": "D",
          ".": "E",
          "..-.": "F",
          "--.": "G",
          "....": "H",
          "..": "I",
          ".---": "J",
          "-.-": "K",
          ".-..": "L",
          "--": "M",
          "-.": "N",
          "---": "O",
          ".--.": "P",
          "--.-": "Q",
          ".-.": "R",
          "...": "S",
          "-": "T",
          "..-": "U",
          "...-": "V",
          ".--": "W",
          "-..-": "X",
          "-.--": "Y",
          "--..": "Z",
          "-.-.--": "!",
          "..--..": "?"}

encode = {v:k for k,v in decode.items()}

def calcular_puntos(codigo):
    espacios_entre_simbolos = len(codigo)-1
    recuentos = Counter(codigo)

    return espacios_entre_simbolos + recuentos["."] + 3*recuentos["-"]


cost = {k: calcular_puntos(v) for k,v in encode.items()}

print("{")
for k,v in cost.items():
    print("{'" + str(k) + "', " + str(v) + "},")
print("};")