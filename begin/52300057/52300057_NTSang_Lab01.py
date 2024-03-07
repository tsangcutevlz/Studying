import re


def sumN(n):
    if n == 0:
        return 0
    else:
        return n + sumN(n-1)


def mSum(A, B):
    result = []
    for i in range(len(A)):
        row = []
        for j in range(len(B[0])):
            row.append(A[i][j] + B[i][j])
        result.append(row)
    return result


def mProp(A, B):
    result = [[0] * len(B[0]) for _ in range(len(A))]
    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len(B)):
                result[i][j] += A[i][k] * B[k][j]
    for row in result:
        print(row)
    
def ithCombine(p,q):
    print("if", p, ", then", q)
def panqCombine(p,q):
    output = ""
    k = q.split()
    output += k[0] + " not "
    output += " ".join(k[1:])
    print(p, "and",output)

def npoqCombine(p,q):
    output = ""
    k = p.split()
    output += k[0] + " not "
    output += " ".join(k[1:])
    print(output, ", or", q)

def ex1():
    print("1a: ", 15*2 + 7*8)
    print("1b: ", 20 - 15 + 15*2)
    print("1c: ", 20 + 30 - 3*15 + 5*(5**2))
    print("1d: ", (4/6 + 2/6) / (5/2 + 1/2))
    print("1e: ", (14/2 + 7))
    print("1f: ", (5*2) / (5 - 20*(3**2) + 30))


def ex2():
    print("2a: 15*2 + 7*8 =", 15*2 + 7*8)
    print("2a: 20 - 15 + 15*2 =", 20 - 15 + 15*2)
    print("2a: 20 + 30 - 3*15 + 5*(5**2) =", 20 + 30 - 3*15 + 5*(5**2))
    print("2a: (4/6 + 2/6) / (5/2 + 1/2) =", (4/6 + 2/6) / (5/2 + 1/2))
    print("2a: (14/2 + 7) =", (14/2 + 7))
    print("2a: (5*2) / (5 - 20*(3**2) + 30) =", (5*2) / (5 - 20*(3**2) + 30))


def ex3():
    print("SumN:", sumN(10))


def ex4():
    s = input("Input your string: ")
    print("4a:", s.replace(" ", ""))
    print("4b:", s.replace(" ", "_"))


def ex5():
    a = input("ex5: ")
    operator = ['+', '-', '%', '/', '%', '^']
    operator_pos = -1
    tempOperator = ""
    for i, charac in enumerate(a):
        if charac in operator:
            operator_pos = i
            tempOperator = charac
    num1 = int(a[:operator_pos])
    num2 = int(a[operator_pos+1:])
    if operator_pos == -1:
        print("Your operator is wrong !!!")
    else:
        if tempOperator == "+":
            print("Output:", int(num1)+int(num2))
        elif tempOperator == "-":
            print("Output:", int(num1)-int(num2))
        elif tempOperator == "*":
            print("Output:", int(num1)*int(num2))
        elif tempOperator == "/":
            if int(num2) != 0:
                print("Output:", int(num1)/int(num2))
            else:
                print("Error: Division by zero !!!!")
        elif tempOperator == "%":
            print("Output:", int(num1) % int(num2))
        elif tempOperator == "^":
            print("Output:", int(num1)**int(num2))
        else:
            print("Your input operator is not true type")


def ex6():
    a = input("ex6: ")
    operator = ['+', '-', '*', '/', '%', '^']
    operator_pos = -1
    tempOperator = ""
    for i, charac in enumerate(a):
        if charac in operator:
            operator_pos = i
            tempOperator = charac
    num1 = int(a[:operator_pos])
    num2 = int(a[operator_pos+1:])
    d = {'+': "output:" + str(int(num1) + int(num2)), '-': "output:" + str(int(num1)-int(num2)), '*': "output:" + str(int(num1)*int(num2)),
         '/': "output:" + str(int(num1)/int(num2)), '%': "output:" + str(int(num1) % int(num2)), '^': "output:" + str(int(num1)**int(num2))}
    print(d[tempOperator])


def ex7():
    print("ex7: ")
    m1 = [[1, 2, 3], [4, 5, 6]]
    m2 = [[5, 6, 4], [2, 3, 1]]
    if len(m1) != len(m2) or len(m1[0]) != len(m2[0]):
        print("Matrix dimension error")
    else:
        print(mSum(m1, m2))


def ex8():
    print("ex8: ")
    m1 = [[1, 2, 3], [4, 5, 6]]
    m2 = [[5, 6], [2, 3], [8, 1]]
    if len(m1[0]) != len(m2):
        print("Matrix dimension error")
    else:
        mProp(m1, m2)


def ex9():
    p = "it rainny"
    q = "i go swimming"
    ithCombine(p,q)
    panqCombine(p,q)
    npoqCombine(p,q)

ex1()
ex2()
ex3()
ex4()
ex5()
ex6()
ex7()
ex8()
ex9()