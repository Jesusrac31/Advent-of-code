def read_data():
    data = []
    with open("input.in") as f:
        for i in f:
            i = i[:-1]
            data.append(i)
    return data

def solve_p1():
    data = read_data()
    symbol = {")":3, "]":57, "}":1197, ">":25137}
    sintax_error = 0
    for i in data:
        expected = []
        for j in i:
            if (j == ")"):
                if (expected[-1] != "("):
                    sintax_error += symbol[j]
                    break
                expected.pop()
            elif (j == "]"):
                if (expected[-1] != "["):
                    sintax_error += symbol[j]
                    break
                expected.pop()
            elif (j == "}"):
                if (expected[-1] != "{"):
                    sintax_error += symbol[j]
                    break
                expected.pop()
            elif (j == ">"):
                if (expected[-1] != "<"):
                    sintax_error += symbol[j]
                    break
                expected.pop()
            else:
                expected.append(j)
                
    return sintax_error


def solve_p2():
    data = read_data()
    symbol = {"(":1, "[":2, "{":3, "<":4}
    sol = []
    for i in data:
        expected = []
        for j in i:
            if (j == ")"):
                if (expected[-1] != "("):
                    expected.clear()
                    break
                expected.pop()
            elif (j == "]"):
                if (expected[-1] != "["):
                    expected.clear()
                    break
                expected.pop()
            elif (j == "}"):
                if (expected[-1] != "{"):
                    expected.clear()
                    break
                expected.pop()
            elif (j == ">"):
                if (expected[-1] != "<"):
                    expected.clear()
                    break
                expected.pop()
            else:
                expected.append(j)
        if (len(expected) != 0):
            print(expected)
            sol.append(0)
            expected.reverse()
            for j in expected:
                sol[-1]*=5
                sol[-1]+=symbol[j]
    sol.sort()
    print(sol)
    return sol[len(sol)//2]
if __name__ == "__main__":

    print(solve_p1())
    print("--------------------------")
    print(solve_p2())