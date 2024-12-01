#Parte 1: Busca la tarjeta ganadora

#Primero pasemos los valores del txt a una variables junto a un sitio donde validarlas

def winner(tarjeta):
    mult = 1
    mult2 = 1
    for i in range(len(tarjeta)):
        for j in range(len(tarjeta[0])):
            mult = mult*tarjeta[i][j]
            mult2 = mult2*tarjeta[j][i]
        if mult == 1 or mult2 == 1:
            return True
    return False

bingo = open('D:/jesus/phiton/Adviento/Adviento/Day 4/bingo.txt')

numeros = [46,12,57,37,14,78,31,71,87,52,64,97,10,35,54,36,27,84,80,94,99,22,0,11,30,44,86,59,66,7,90,21,51,53,92,8,76,41,39,77,42,88,29,24,60,17,68,13,79,67,50,82,25,61,20,16,6,3,81,19,85,9,28,56,75,96,2,26,1,62,33,63,32,73,18,48,43,65,98,5,91,69,47,4,38,23,49,34,55,83,93,45,72,95,40,15,58,74,70,89]

tarjetas = []
validacion = []
tarjeta = []
validación_tarjeta=[]
fila = []
validacion_fila = []

for x,linea in enumerate(bingo):
    tarjeta_ind = 0
    if linea != '\n':
        for i in range(5):
            fila.append(int(linea[i*3:i*3+3]))
            validacion_fila.append(0)
        tarjeta.append(fila.copy())
        fila.clear()
        validación_tarjeta.append(validacion_fila.copy())
        validacion_fila.clear()
    else:
        tarjetas.append(tarjeta.copy())
        tarjeta.clear()
        validacion.append(validación_tarjeta.copy())
        validación_tarjeta.clear()
        tarjeta_ind += 1

ganadora = False
ficha = []
val = []
num = 0

for i in numeros:
    for x,j in enumerate(tarjetas):
        for y,k in enumerate(j):
            for z,l in enumerate(k):
                if l==i:
                    validacion[x][y][z] = 1
        ganadora = winner(validacion[x])
        if ganadora:
            ficha = j
            val = validacion[x]
            num = i
            print(j)
            print(validacion[x])
            print(i)
            print(tarjetas[74])
            print(validacion[74])
            break
    if ganadora:
        break

sum = 0

for x,i in enumerate(val):
    for y,j in enumerate(i):
        if j == 0:
            sum += ficha[x][y]
print(sum*num)