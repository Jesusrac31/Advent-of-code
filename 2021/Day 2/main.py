# Parte 1: multiplica x final con y (profundidad) final

movimientos = open('D:/jesus/phiton/Adviento/Adviento/Day 2/movimientos.txt')
x = 0
profundidad = 0
Valores = []

for linea in movimientos:
    Valores.append(linea)
    if linea[0] == 'f': # Mueve para adelante
        x += int(linea[-2])
    elif linea[0] == 'u': # Mueve para arriba (baja profundidad)
        profundidad -= int(linea[-2])
    elif linea[0] == 'd': # Mueve para abajo (sube profundidad)
        profundidad += int(linea[-2])
print(x*profundidad)

# Parte 2: añade eje z y cambia comandos
x = 0
profundidad = 0
z=0

for linea in Valores:
    if linea[0] == 'f': # Mueve para adelante y varía profundidad
        x += int(linea[-2])
        profundidad += int(linea[-2])*z
    elif linea[0] == 'u': # Disminuye eje z
        z -= int(linea[-2])
    elif linea[0] == 'd': # Aumenta eje z
        z += int(linea[-2])
print(x*profundidad)