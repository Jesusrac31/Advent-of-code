def read_data():
    data = []
    with open("input.in") as f:
        for i in f:
            i = i[:-1]
            data.append([10]+[int(j) for j in i])
            data[-1].append(10)
    data.insert(0, [10 for i in range(len(data[-1]))])
    data.append([10 for i in range(len(data[0]))])
    return data

def solve_p1():
    data = read_data()
    bajos = []
    for i in range(1, len(data)-1):
        for j in range(1, len(data[0])-1):
            if (data[i][j]<data[i+1][j] and data[i][j]<data[i-1][j] and data[i][j]<data[i][j+1] and data[i][j]<data[i][j-1]):
                bajos.append(data[i][j]+1)
    return sum(bajos)


def matriz2pos(a, b):
    return a*long+b

def pos2matriz(a):
    return (a//long, a-(a//long)*long)

def dfs(node):
    a, b = pos2matriz(node)
    if (mapa[a][b] >= 9 or node in bloqueados):
        return 0
    
    sol = 1
    bloqueados.append(node)
    sol += dfs(matriz2pos(a+1, b))
    sol += dfs(matriz2pos(a-1, b))
    sol += dfs(matriz2pos(a, b+1))
    sol += dfs(matriz2pos(a, b-1))
    return sol

def solve_p2():
    global mapa
    mapa = read_data()

    global long
    global bloqueados
    long = len(mapa[0])
    bloqueados = []

    sol = []
    for i in range(len(mapa)*len(mapa[0])):
        if not(i in bloqueados):
            sol.append(dfs(i))
    res = 1
    for i in sorted(sol)[-3:]:
        res*=i

    return res
if __name__ == "__main__":

    print(solve_p1())
    print("--------------------------")
    print(solve_p2())