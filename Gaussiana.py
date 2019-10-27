def op1(mat, resp):
    i = 0
    while (i < len(mat)):
        if (mat[i][i] == 0): #se a diagonal principal de determinada linha estiver vazia
            k = 0 
            while(k < len(mat)):
                if(mat[k][i] != 0 and mat[i][k] != 0): #se a linha k tiver o elemento i != 0 este é candidato a substituição
                    copyLine = mat[i] #Copia a linha da matriz dos coeficientes que vai receber a troca
                    copyresp = resp[i]#Copia a linha da matriz dos resultados que vai receber a troca
                    mat[i] = mat[k]  #recebe a linha do indice 
                    resp[i] = resp[k]#recehe a linha do indice
                    mat[k] = copyLine#recebe a linha da copia e sobrescreve a linha de destino
                    resp[k] = copyresp#recebe a linha da copia e sobrescreve a linha de destino
                    k = len(mat) #recebe o valor para fechar o loop
                else: 
                    k += 1 #tenta a proxima linha
        i += 1#testa a proxima linha
    return mat

def op2(mat, resp):
    i = 0
    j = 0
    epoca = 0 #controla o teste para a soma com k = 1
    while(i < len(mat)):
        if (mat[i][i] != 0 ): #se a diagonal principal for diferente de 0
            j = 0
            while(j < len(mat)):
                if (j > i):
                    z = 0
                    if (mat[j][i] != 0 and mat[j][i] > 0):
                        k = (mat[j][i] / mat[i][i]) #recebe o escalar que ira multiplicar a linha
                        resp[j][0] =  round(-1 * k * resp[i][0] + resp[j][0], 2) #altera a matriz dos resultados
                        while (z < len(mat)): #move dentro da linha as colunas
                            mat[j][z] = round(-1 * k * mat[i][z] + mat[j][z], 2) #altera cada valor da linha 
                            z += 1
                    elif(mat[j][i] != 0):
                        k = -1 * (mat[j][i] / mat[i][i])#recebe o escalar que ira multiplicar a linha esse valor é negativo por isso multiplica por -1
                        resp[j][0] =  round(k * resp[i][0] + resp[j][0], 2)#altera a matriz dos resultados
                        while (z < len(mat)):#move dentro da linha as colunas
                            mat[j][z] =  round(k * mat[i][z] + mat[j][z], 2) #altera cada valor da linha
                            z += 1
                j += 1
            i += 1
        elif(epoca < len(mat) * 2): #senao se epoca for meno que 2 vezes o tamanho da matriz 
            j = 0
            while(j < len(mat)): #ira verificar qual linha possui um elemento na coluna i que nao seja 0
                if (j != i): #se nao for a linha da diagonal
                    z = 0
                    if (mat[j][i] != 0 and mat[j][i] > 0):#verifica se existe uma linha que possui o indice da coluna diferente de 0 e se esse é maior que 0
                        resp[j][0] =  round(1 * resp[i][0] + resp[j][0],2) #altera a matriz das respostas com a alteração
                        while (z < len(mat)): #move dentro da linha as colunas
                            mat[j][z] =  round(1 * mat[i][z] + mat[j][z],2) #altera cada valor da linha multiplicando por menos 1
                            z += 1
                    elif(mat[j][i] != 0):#se o valor for negatipo 
                        resp[j][0] =  round(-1  * resp[i][0] + resp[j][0], 2)#altera a matriz das respostas com a alteração
                        while (z < len(mat)):#move dentro da linha as colunas
                            mat[j][z] =  round(-1 * mat[i][z] + mat[j][z],2) #altera cada valor da linha 
                            z += 1
                j += 1
            epoca += 1 
        elif(resp[i][0] != 0): #quando o valor da epoca extrapola a condição o programa diz que o sistema é impossivel, isso ocorre pq uma linha nao possui coeficiente
            #exemplo duas linhas iguais com respostas diferentes de 0 e diferentes
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
    mat = op1(mat, resp)#executa primeiro a operação de troca de linha
    print("----------------------")
    for i in range(n):
        print(mat[i], " = ", resp[i])
    print("----------------------")
    mat = op2(mat, resp)#executa a soma multiplicada por um escalar
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

    mat = [] #recebe as linhas
    mat_ant = []#recebe a matriz escalonada 
    line = []#recebe uma linha da matriz 
    line2 = []#recebe a linha das respostas
    resp = [] #resultado do sistema
    solucao = []#matriz solução


    #Recebe a matriz
    i = 0
    j = 0
    #recebe a matriz dos coeficientes, recebe a matriz das soluções e a matriz dos resultados 
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
    
    mat_lu = LU(mat, resp)#escalona

    if(mat_lu):
        i = n-1#começa da ultima linha
        while(i >= 0):#vai subindo nas linhas
            j = n-1#começa da ultima coluna
            desc = 0#valor inteiro que subtrai o resultado
            while(j > i):#enquanto a coluna nao for a diagonal principal da linha
                desc += solucao[j][0] * mat_lu[i][j] #multiplique pelas soluções ja encontradas e some umas com as outras
                j -= 1
            solucao[i][0] = round((resp[i][0] - desc) / mat_lu[i][i], 2)#subtrai a solução pelos valores ja conhecidos e divide pela diagonal principal da linha
            i -= 1
        
        print("solução: ")
        print("----------------------")
        for i in range(n):
            print(mat_lu[i], " * ", solucao[i], " = ", resp[i])
        print("----------------------")