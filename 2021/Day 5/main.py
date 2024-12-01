import numpy as np

coordenadas = open('D:/jesus/phiton/Adviento/Adviento/Day 5/coordenadas.txt')

lineas = 500
cords = np.zeros((lineas,2,2))
tablero=np.zeros((990,990))
part=0

for x,linea in enumerate(coordenadas):
    for i in linea:
        if i.isdigit():
            if part==0:
                cords[x,0,0] = cords[x,0,0]*10
                cords[x,0,0] += int(i)
            elif part==1:
                cords[x,0,1] = cords[x,0,1]*10
                cords[x,0,1] += int(i)
            elif part==5:
                cords[x,1,0] = cords[x,1,0]*10
                cords[x,1,0] += int(i)
            elif part==6:
                cords[x,1,1] = cords[x,1,1]*10
                cords[x,1,1] += int(i)
        else:
            part+=1
    part=0

prop_x = 0
prop_y = 0

for i in cords:
    if i[0,0]==i[1,0]:#cord x igual
        for j in range(abs(int(i[0,1]-i[1,1]))+1):
            if i[0,1]<i[1,1]:
                tablero[int(i[0,1]+j),int(i[0,0])]+=1
            else:
                tablero[int(i[1,1]+j),int(i[0,0])]+=1
    elif i[0,1]==i[1,1]:#cord y igual
        for j in range(abs(int(i[0,0]-i[1,0]))+1):
            if i[0,0]<i[1,0]:
                tablero[int(i[0,1]),int(i[0,0]+j)]+=1
            else:
                tablero[int(i[0,1]),int(i[1,0]+j)]+=1
    else: #ambas distintas
        if i[0,0]<i[1,0]:
            prop_x = 1
        else:
            prop_x = -1
        if i[0,1]<i[1,1]:
            prop_y = 1
        else:
            prop_y = -1

        for j in range(abs(int(i[0,0]-i[1,0]))+1):
            tablero[int(i[0,1]+j*prop_y),int(i[0,0]+j*prop_x)]+=1
cont=0

for i in tablero:
    for j in i:
        if j >= 2:
            cont+=1
print(cont)