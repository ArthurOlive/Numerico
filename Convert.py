def decodifica(base):
    print("Digite o numero da base ", base,": ", end = "")
    num = input()
    tam = len(num) - 1
    dec = 0 #recebe o numero decimal
    if (base > 10 and base <= 32):
        dec = int(num, base) #por falta de um objeto do tipo char é necessario utilizar essa função
    else:
        for i in num:
            dec += base ** tam * int(i) #multiplica a base elevada ao indice que é o numero de caractere menos 1
            tam -= 1                    #e multiplica pelo numero do indice;
    print("O número ", num , " na base ",base, " = ",dec, " na base decimal.")

def codifica(base):
    n = int(input("Digite o numero decimal : "))
    num = n
    #Pega cada caractere começando da esquerda para direita
    cod = ""                       #cod <- ""
    while(n >= 1):                 #enquanto n >= 1
        pog = (n % base)           #    pog <- n % base //recebe o resto da divisão com o numero n para evitar o problema do numero impár
        n = int((n - pog) / base)  #    n <- (n - pog) / base
        if (pog <= 9):             #    se pog <= 9:
            cod += str(pog)        #        cod += pog
        else:                      #    se nao: 
            pog -= 10              #        pog -= 10 //retira o numero 10
            cod += chr(65 + pog)   #        cod == char(65 + pog) //soma A + pog que pode ser qualquer numero
    #O numero resultante esta invertido
    pos = len(cod) - 1             #pos = strlen(cod) - 1
    print("O número ", num, " da base 10 = ", end = "")
    for _ in range(len(cod)):      #para cada letra da string cod faca:
        print(cod[pos], end="")    #    escreva cod[pos]
        pos -= 1                   #    pos -= 1
    print(" na base ", base, ".")

if __name__ == "__main__":
    #Menu para a escolha da operação
    print("1 - Converte de uma base qualquer para decimal;")
    print("2 - Converte de decimal uma base qualquer;")
    esc = int(input("Escolha: "))

    if (esc == 1):
        base = int(input("Digite a base para converter: "))
        decodifica(base)
    elif(esc == 2):
        base = int(input("Digite a base para converter: "))
        codifica(base)
    else:
        print("Opção invalida!")