from decimal import Decimal
import numpy as np
def recu(x, conFat = 0):
    fat = 1
    if conFat != 0 and x >= 1:
        fat = conFat * x
        return fat
    else:
        for i in range(2, (x + 1)):
            fat *= i
        return fat

n = int(input("Digite o o valor de n: "))
x = int(input("Digite o numero de x: "))
exp = 0

conFat = 1
for i in range(0, n): 
    conFat =  recu(i, conFat)
    copyExp = Decimal((x ** i) / conFat) #Nao consegue conter um numero inferior a x e-324
    exp += copyExp

print("fatorial de ", i, " = ", conFat)
print("O valor da função exponencial e^",x," :", (exp))