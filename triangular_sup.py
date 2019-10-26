def op1(mat):
    i = 0
    j = 0
    while (i < len(mat)):
        if (mat[i][i] == 0):
            k = 0 
            while(k < len(mat)):
                if(mat[k][i] != 0 and mat[i][k] != 0): #se a linha k tiver o elemento i != 0 este é candidato a substituição
                    copyLine = mat[i]
                    mat[i] = mat[k]
                    mat[k] = copyLine
                    k += 1
                else: 
                    k += 1
        i += 1
    return mat

def op2(mat):
    i = 0
    j = 0
    while(i < len(mat)):
        if (mat[i][i] != 0 ):
            j = 0
            while(j < len(mat)):
                if (j > i):
                    z = 0
                    if (mat[j][i] != 0 and mat[j][i] > 0):
                        k = (mat[j][i] / mat[i][i])
                        while (z < len(mat)):
                            mat[j][z] = -1 * k * mat[i][z] + mat[j][z] #zera o valor 
                            z += 1
                    elif(mat[j][i] != 0):
                        k = -1 * (mat[j][i] / mat[i][i])
                        while (z < len(mat)):
                            mat[j][z] = k * mat[i][z] + mat[j][z] #zera o valor 
                            z += 1
                j += 1
            i += 1
        else:
            j = 0
            while(j < len(mat)):
                if (j > i):
                    z = 0
                    if (mat[j][i] != 0 and mat[j][i] > 0):
                        while (z < len(mat)):
                            mat[j][z] = -1 * mat[i][z] + mat[j][z] #zera o valor 
                            z += 1
                    elif(mat[j][i] != 0):
                        while (z < len(mat)):
                            mat[j][z] = 1 * mat[i][z] + mat[j][z] #zera o valor 
                            z += 1
                j += 1
    return mat

def LU(mat):
    print("antes: ")
    for i in mat:
        print(i)

    print("depois da op1: ")
    mat = op1(mat)
    print("----------------------")
    for i in range(n):
        print(mat[i])
    print("----------------------")

    mat = op2(mat)
    print("----------------------")
    for i in range(n):
        print(mat[i])
    print("----------------------")

    return mat

if __name__ == "__main__":
    n = int(input("Digite o tamanho da matriz: "))

    mat = []
    mat_ant = []
    line = []
    line2 = []
    resp = [] #resultado do sistema
    solucao = []


    #Recebe a matriz
    i = 0
    j = 0
    while (i < n): 
        j = 0
        while(j < n):
            val = float(input("Digite o valor dos coeficiente : "))
            line.append(val)
            line2.append(val)
            j += 1
        mat.append(line)
        mat_ant.append(line2)
        line = [0]
        line2 = []
        solucao.append(line)
        line = []
        val = float(input("Digite o resultado da primeira equalção "))
        line.append(val)
        resp.append(line)
        line = []
        i += 1
    
    for i in range(n):
        print(mat[i], " * ", solucao[i], " = ", resp[i])

    mat_lu = LU(mat)

    i = n-1
    while(i >= 0):
        j = n-1
        desc = 0
        while(j > i):
            desc += solucao[i][0] * mat_lu[i][j] 
            j -= 1
        solucao[i][0] = (resp[i][0] - desc) / mat_lu[i][i]
        i -= 1
    
    print("solução: ")
    print("----------------------")
    for i in range(n):
        print(mat_lu[i], " * ", solucao[i], " = ", resp[i])
    print("----------------------")