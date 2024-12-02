def solve_p1():
    tot = 0
    with open("input.in") as f:
        for i in f:
            output = i.split(" | ")[1]
            output = output[:-1].split(" ")
            for j in output:
                if len(j) <= 4 or len(j) == 7:
                    tot+=1
    return tot

def comunes(lista):
    elementos = {"a":2, "b":2, "c":2, "d":2, "e":2, "f":2, "g":2}
    for i in range(len(lista)):
        for j in range(len(lista)):
            for k in lista[j]:
                if not(k in lista[i]):
                    elementos[k] = 0
                elif (elementos[k] == 2):
                    elementos[k] = 1
    sol = ""
    for j in [i for i in elementos  if elementos[i] == 1]:
        sol+=j
    return sol

def resta(minuendo, sustraendo):
    sol = ""
    for i in minuendo:
        if not(i in sustraendo):
            sol+=i

    return sol

def ord_str(cadena):
    lista = sorted([i for i in cadena])
    sol = ""
    for i in lista:
        sol+=i
    return sol

def solve_p2():
    sol = 0
    with open("input.in") as f:
        for line in f:
            dic_decode = {}
            set_coded = set()
            dic_input = {}
            num_7seg = []

            output = line.split(" | ")
            for i in output[0].split(" "):
                set_coded.add(ord_str(i))
            for i in output[1][:-1].split(" "):
                num_7seg.append(ord_str(i))

            print(output)
            print(set_coded)

            ### Decoding ###
            set_len5 = []
            set_len6 = []
            for i in set_coded:
                if len(i) == 2:
                    dic_decode[1] = ord_str(i)
                if len(i) == 3:
                    dic_decode[7] = ord_str(i)
                if len(i) == 4:
                    dic_decode[4] = ord_str(i)
                if len(i) == 5:
                    set_len5.append(ord_str(i))
                if len(i) == 6:
                    set_len6.append(ord_str(i))
                if len(i) == 7:
                    dic_decode[8] = ord_str(i)

            dic_input["a"] = resta(dic_decode[7], dic_decode[1])
            dic_input["g"] = comunes(set_len5+[dic_decode[4]])
            dic_input["d"] = resta(resta(comunes(set_len5), dic_input["g"]), dic_input["a"])
            dic_input["c"] = comunes([comunes(set_len6), dic_decode[1]])
            dic_input["f"] = resta(resta(resta(comunes(set_len6), dic_input["a"]), dic_input["d"]), dic_decode[1])
            dic_input["b"] = resta(dic_decode[1],dic_input["c"])
            dic_input["e"] = resta(dic_decode[8],dic_input["a"]+dic_input["g"]+dic_input["d"]+dic_input["b"]+dic_input["f"]+dic_input["c"])

            for i in dic_input:
                print(i, "-->", dic_input[i])

            dic_decode[0]=ord_str(dic_input["a"]+dic_input["b"]+dic_input["c"]+dic_input["d"]+dic_input["e"]+dic_input["f"])
            dic_decode[1]=ord_str(dic_input["b"]+dic_input["c"])
            dic_decode[2]=ord_str(dic_input["a"]+dic_input["b"]+dic_input["d"]+dic_input["e"]+dic_input["g"])
            dic_decode[3]=ord_str(dic_input["a"]+dic_input["b"]+dic_input["c"]+dic_input["d"]+dic_input["g"])
            dic_decode[4]=ord_str(dic_input["b"]+dic_input["c"]+dic_input["f"]+dic_input["g"])
            dic_decode[5]=ord_str(dic_input["a"]+dic_input["c"]+dic_input["d"]+dic_input["f"]+dic_input["g"])
            dic_decode[6]=ord_str(dic_input["a"]+dic_input["c"]+dic_input["d"]+dic_input["e"]+dic_input["f"]+dic_input["g"])
            dic_decode[7]=ord_str(dic_input["a"]+dic_input["b"]+dic_input["c"])
            dic_decode[8]=ord_str(dic_input["a"]+dic_input["b"]+dic_input["c"]+dic_input["d"]+dic_input["e"]+dic_input["f"]+dic_input["g"])
            dic_decode[9]=ord_str(dic_input["a"]+dic_input["b"]+dic_input["c"]+dic_input["d"]+dic_input["f"]+dic_input["g"])
            
            print("### NUMS ###")
            for i in dic_decode:
                print(i, "-->", dic_decode[i])

            numero = 0
            for i in num_7seg:
                suma = 0
                for j in dic_decode:
                    if (i == dic_decode[j]):
                        print(i, j)
                        suma = j
                numero += suma
                numero*=10
            numero/=10
            sol+=int(numero)
            print(int(numero))
            print(sol)
            print("### NEXT ###")
    print("### SOLUTION ###")         
    return sol

if __name__ == "__main__":

    print(solve_p1())
    print("--------------------------")
    print(solve_p2())