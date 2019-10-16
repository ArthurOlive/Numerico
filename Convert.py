def convertBinDec(base):
    num = input("Digite o numero binario: ")
    tam = len(num) - 1
    dec = 0
    if (base > 10 and base <= 32):
        dec = int(num, base)
    else:
        for i in num:
            dec += base ** tam * int(i)
            tam -= 1
    print(dec)

def convertDecBin(base):
    num = input("Digite o numero decimal: ")
    n = int(num)
    #Pega cada caractere começando da esquerda para direita
    binario = ""
    while(n >= 1):
        pog = (n % base)
        n = int((n - pog) / base)
        if (pog <= 9):
            binario += str(pog)
        else: 
            pog -= 10
            binario += chr(65 + pog)
    
    pos = len(binario) - 1
    for _ in range(len(binario)):
        print(binario[pos], end="")
        pos -= 1

if __name__ == "__main__":
    print("1 - Converte de decimal uma base qualquer;")
    print("2 - Converte de uma base qualquer para decimal;")
    esc = int(input("Escolha: "))

    if (esc == 1):
        base = int(input("Digite a base para converter: "))
        convertDecBin(base)
    elif(esc == 2):
        base = int(input("Digite a base para converter: "))
        convertBinDec(base)
    else:
        print("Opção invalida!")