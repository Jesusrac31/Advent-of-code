from collections import defaultdict
import sys

def read_data():
    data = defaultdict(list)
    with open("input.in") as f:
        for i in f:
            i = i.strip()
            i = i.split("-")
            data[i[0]].append(i[1])
            data[i[1]].append(i[0])
    return data

def cuenta(data, nodo_init, bloqueados = set()):
    if nodo_init == "end":
        return 1
    if nodo_init in bloqueados:
        return 0
    sol = 0
    if (ord(nodo_init[0]) > 91):
        bloqueados.add(nodo_init)
    for i in data[nodo_init]:
        sol += cuenta(data, i, bloqueados)
    if (ord(nodo_init[0]) > 91):
        bloqueados.remove(nodo_init)
    return sol



def cuenta_rep(visited = False, repeated=".."):
    # print(nodo_init_rep)
    # print(bloqueados_rep)
    # print(visited)
    # print("--------------")
    if nodo_init_rep[-1] == "end":
        return 1
    if nodo_init_rep[-1] in bloqueados_rep:
        if visited or nodo_init_rep[-1] == "start":
            return 0
        else:
            visited = True
            repeated = nodo_init_rep[-1]
    sol = 0
    if (ord(nodo_init_rep[-1][0]) > 91 and nodo_init_rep[-1] != repeated):
        bloqueados_rep.add(nodo_init_rep[-1])
    for i in data_rep[nodo_init_rep[-1]]:
        nodo_init_rep.append(i)
        sol += cuenta_rep(visited, repeated)
        nodo_init_rep.pop()
    if (ord(nodo_init_rep[-1][0]) > 91 and nodo_init_rep[-1] != repeated):
        bloqueados_rep.remove(nodo_init_rep[-1])
    return sol


def solve_p1():
    data = read_data()
    for i in data:
        print(i, "-->", data[i])

    sol = cuenta(data, "start")
    return sol

def solve_p2():
    global data_rep
    global bloqueados_rep
    global nodo_init_rep

    data_rep = read_data()
    bloqueados_rep = set()
    nodo_init_rep = ["start"]
    sol = cuenta_rep()

    return sol

if __name__ == "__main__":
    print(solve_p1())
    print("--------------------------")
    print(solve_p2())