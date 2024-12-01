#Parte 1: compara elementos de una lista

profundidades = open('D:/jesus/phiton/Adviento/Adviento/Day 1/profundidades.txt')
increases = 0
ant = -1
Valores = []

for linea in profundidades:
    Valores.append(int(linea))
    if ant != -1 and int(linea) > ant:
        increases += 1
    ant = int(linea)
print(increases)

# Parte 2: compara la suma de 3 elementos de una lista con otra suma de 3 elementos

Lista = []
increases_B = 0

for linea in Valores:
    if len(Lista) == 3:
        for i in range(len(Lista)-1):
            Lista[i+1] += linea
        if Lista[0]<Lista[1]:
            increases_B +=1
        Lista.pop(0)
    else: 
        for x,i in enumerate(Lista):
            Lista[x] += linea
    Lista.append(linea)
print(increases_B)