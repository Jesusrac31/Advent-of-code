def read_data():
    data = []
    with open("input.in") as f:
        for i in f:
            i = i[:-1]
            data.append([])
            for j in i:
                data[-1].append(int(j))
    return data

def update(data, j, k):
    coords = [(j-1, k-1),
              (j-1, k),
              (j-1, k+1),
              (j, k-1),
              (j, k+1),
              (j+1, k-1),
              (j+1, k),
              (j+1, k+1),
             ]
    print(j,k)
    print(updated)
    if not((j, k) in updated):
        print("Updating...")
        updated.append((j, k))
        for i in coords:
            if (i[0]>=0 and i[0] < len(data) and i[1]>= 0 and i[1]<len(data[0])):
                data[i[0]][i[1]]+=1
                if data[i[0]][i[1]] > 9:
                    update(data, i[0], i[1])
    else:
        print(j,k)
    return data
def solve_p1():
    global updated
    updated = []
    data = read_data()
    N = 100
    test = 2
    sol = 0
    for i in range(N):
        print(i)
        updated.clear()
        for j in range(len(data)):
            for k in range(len(data[j])):
                data[j][k]+=1
                if (data[j][k]>9):
                    print("Ramificación")
                    data = update(data, j, k)
        for j in range(len(data)):
            for k in range(len(data[j])):
                if (data[j][k]>9):
                    data[j][k] = 0
                    sol+=1
        if i == test-1:
            for j in data:
                print(j)

    return sol

def solve_p2():
    global updated
    updated = []
    data = read_data()
    N = 1000
    test = 2
    sol_ant = 0
    sol = 0
    for i in range(N):
        print(i)
        updated.clear()
        for j in range(len(data)):
            for k in range(len(data[j])):
                data[j][k]+=1
                if (data[j][k]>9):
                    print("Ramificación")
                    data = update(data, j, k)
        for j in range(len(data)):
            for k in range(len(data[j])):
                if (data[j][k]>9):
                    data[j][k] = 0
                    sol+=1
        
        if i == test-1:
            for j in data:
                print(j)
        if (sol-sol_ant >= len(data)*len(data[0])): 
            print(i+1)
            for j in data:
                print(j)
            sol = i
            break
        sol_ant = sol

    return sol+1
if __name__ == "__main__":

    print(solve_p1())
    print("--------------------------")
    print(solve_p2())