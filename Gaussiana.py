def op1(mat, resp):
    i = 0
    j = 0
    while (i < len(mat)):
        if (mat[i][i] == 0):
            k = 0 
            while(k < len(mat)):
                if(mat[k][i] != 0 and mat[i][k] != 0): #se a linha k tiver o elemento i != 0 este é candidato a substituição
                    copyLine = mat[i]
                    copyresp = resp[i]
                    mat[i] = mat[k]
                    resp[i] = resp[k]
                    mat[k] = copyLine
                    resp[k] = copyresp
                    k += 1
                else: 
                    k += 1
        i += 1
    return mat

def op2(mat, resp):
    i = 0
    j = 0
    epoca = 0
    while(i < len(mat)):
        if (mat[i][i] != 0 ):
            j = 0
            while(j < len(mat)):
                if (j > i):
                    z = 0
                    if (mat[j][i] != 0 and mat[j][i] > 0):
                        k = (mat[j][i] / mat[i][i])
                        resp[j][0] =  round(-1 * k * resp[i][0] + resp[j][0], 2)
                        while (z < len(mat)):
                            mat[j][z] = round(-1 * k * mat[i][z] + mat[j][z], 2) #zera o valor 
                            z += 1
                    elif(mat[j][i] != 0):
                        k = -1 * (mat[j][i] / mat[i][i])
                        resp[j][0] =  round(k * resp[i][0] + resp[j][0], 2)
                        while (z < len(mat)):
                            mat[j][z] =  round(k * mat[i][z] + mat[j][z], 2) #zera o valor 
                            z += 1
                j += 1
            i += 1
        elif(epoca < len(mat) * 2):
            j = 0
            while(j < len(mat)):
                if (j > i):
                    z = 0
                    if (mat[j][i] != 0 and mat[j][i] > 0):
                        resp[j][0] =  round(-1 * resp[i][0] + resp[j][0],2)
                        while (z < len(mat)):
                            mat[j][z] =  round(-1 * mat[i][z] + mat[j][z],2) #zera o valor 
                            z += 1
                    elif(mat[j][i] != 0):
                        resp[j][0] =  round(1 * k * resp[i][0] + resp[j][0], 2)
                        while (z < len(mat)):
                            mat[j][z] =  round(1 * mat[i][z] + mat[j][z],2) #zera o valor 
                            z += 1
                j += 1
            epoca += 1
        else: 
            print("Matriz nao possui solução")
            i = len(mat)
            print("----------------------")
            for i in range(n):
                print(mat[i])
            print("----------------------")
            return 0
    return mat

def LU(mat, resp):
    print("antes: ")
    for i in mat:
        print(i)

    print("depois da op1: ")
    mat = op1(mat, resp)
    print("----------------------")
    for i in range(n):
        print(mat[i], " = ", resp[i])
    print("----------------------")
    mat = op2(mat, resp)
    if (mat):
        print("----------------------")
        for i in range(n):
            print(mat[i])
        print("----------------------")
    else:
        return 0

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
    
    mat_lu = LU(mat, resp)

    if(mat_lu):
        i = n-1
        while(i >= 0):
            j = n-1
            desc = 0
            while(j > i):
                desc += solucao[j][0] * mat_lu[i][j] 
                j -= 1
            solucao[i][0] = round((resp[i][0] - desc) / mat_lu[i][i], 2)
            i -= 1
        
        print("solução: ")
        print("----------------------")
        for i in range(n):
            print(mat_lu[i], " * ", solucao[i], " = ", resp[i])
        print("----------------------")