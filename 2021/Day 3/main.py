#Pasa a binario y descubre la cifra mas común en cada caso

tasas = open('D:/jesus/phiton/Adviento/Adviento/Day 3/tasas.txt')
gamma=[]
epsilon=[]

Valores = []

def btod(binario): #Le pasas una lista con el número binario
    decimal = 0
    for x,i in enumerate(binario):
        if i == 1:
            decimal+= 2**(len(binario)-x-1)
    return(decimal)

for linea in tasas:
    Valores.append(linea)

for i in range(12):
    zeros=0 # Veces que sale el 0
    ones=0 # Veces que sale el 1
    for j in range(len(Valores)):
        if Valores[j][i]=='0':
            zeros += 1
        else:
            ones += 1
    if zeros>ones:
        gamma.append(0)
        epsilon.append(1)
    else:
        gamma.append(1)
        epsilon.append(0)

print('gamma: ',btod(gamma))
print('epsilon: ',btod(epsilon))
print('consumo: ',btod(gamma)*btod(epsilon))

# Parte 2: busca el numero con los digitos mas comunes

Valores_restantes = []
Valores_originales = Valores.copy()

O=0
CO=0
Lista=[]

for i in range(12):# calcula O2
    zeros=0 # Veces que sale el 0
    ones=0 # Veces que sale el 1
    for j in range(len(Valores)):
        if Valores[j][i]=='0':
            zeros += 1
        else:
            ones += 1
    if zeros>ones:
        for x,j in enumerate(Valores):
            if j[i]=='0':
                Valores_restantes.append(j)
    else:
        for x,j in enumerate(Valores):
            if j[i]=='1':
                Valores_restantes.append(j)
    Valores=Valores_restantes.copy()
    Valores_restantes.clear()

O=Valores[0]
Valores=Valores_originales.copy()
for i in O[:-1]:
    Lista.append(int(i))
print(Lista)
O=btod(Lista)
print(O)

for i in range(12):# calcula CO2
    if len(Valores) == 1:
        break
    else:
        zeros=0 # Veces que sale el 0
        ones=0 # Veces que sale el 1
        for j in range(len(Valores)):
            if Valores[j][i]=='0':
                zeros += 1
            else:
                ones += 1
        if zeros>ones:
            for x,j in enumerate(Valores):
                if j[i]=='1':
                    Valores_restantes.append(j)
        else:
            for x,j in enumerate(Valores):
                if j[i]=='0':
                    Valores_restantes.append(j)
        Valores=Valores_restantes.copy()
        Valores_restantes.clear()

CO=Valores[0]
Lista.clear()
for i in CO[:-1]:
    Lista.append(int(i))
print(Lista)
CO=btod(Lista)
print(CO)

print(CO*O)