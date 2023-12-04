import random
import string

nombres = ["Alan","Jacinto","Martinez","Alicia","Jesús","Mirta","Andrea","Josefina","Mónica","Andrés","Juan","Nicolás","Antonia","Juana","Noé","Antonio","Juárez","Noelia","Azul","Julia","Paula","Bartolomé","Julián","Patricio","Belén","Juliana","Renzo","Celeste","Julio","Rodrigo","Edgardo","Leandro","Rodríguez","Felicia","Luis","Romina","Florencia","Luisa","Rosario","Gaspar","Marcelo","Tato","Gerardo","Marcos","Tomás","Giménez","María","Victor","Gonzalo","Mariano","Yayo","Gustavo","Martín","Zulema","Google","Adidas","Mickey","Renault","Lego","Superman","Versace","Disney","Nilo","Quito","París","Paraná","Brasil","Sucre","Mississippi","Argentina","Panamá","Everest","Paraguay","Asunción","Aconcagua","Bolivia","Japón","Marte","Ecuador","Rusia","Tierra","Chile","América","Neptuno","Uruguay","Asia","Saturno","México","Europa","Júpiter","Colombia","Oceanía","España","Cuba","África","Barcelona","Medellín","Nigeria","Dolly","Snoopy","Facebook"]

for caso in range(100):
    n = random.randint(1, 100)
    print(n)
    for i in range(n):
        nombre = random.choice(nombres) + str(i)
        print(nombre, random.randint(1, 10), random.randint(1,10))

print(0)