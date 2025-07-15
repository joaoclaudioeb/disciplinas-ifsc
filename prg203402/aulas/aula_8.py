# ==========================================
# Função 1 – Exe. quanto ao uso de Docstring
# ==========================================
def parOuImpar(x):
    """Função que checa se um número é ímpar ou par"""
    
    if (x % 2 == 0):
        print(x,"é par")
    else:
        print(x,"é ímpar")

# ==========================================
# Função 2 – Função recursiva
# ==========================================
# def fatorial(numero):
#     if numero == 0:  
#         return 1
#     else:
#         return numero * fatorial(numero - 1)
    
# ==========================================
# Função 3 – Funções concatenadas
# ==========================================

def fatorial(numero):
    """ Alguma explicação """
    
    # Etapa para validar o valor passado
    if not isinstance(numero, int):
        raise TypeError("Desculpa, 'numero' precisa ser do tipo int.")
    if numero < 0:
        raise ValueError("Desculpa, 'numero' precisa ser igual ou maior a zero.")
    # Uso de uma função recursiva posteriormente a validação
    # dos valores passados
    def fatorial_interno(numero):
        if numero <= 1:
            return 1
        return numero * fatorial_interno(numero - 1)
    
    print("o fatorial de" + str(numero) + "é" + str(fatorial_interno(numero)))

# ==========================================
# Programa principal
# ==========================================

# ==========================================
# Uso da função 1
# ==========================================
# print(parOuImpar.__doc__) 
# parOuImpar(7)

# ==========================================
# Uso da função 2
# ==========================================
# print(fatorial(3))

# ==========================================
# Uso da função 3
# ==========================================
print(fatorial.__doc__)
fatorial(4)

