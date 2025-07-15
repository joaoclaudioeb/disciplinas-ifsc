# ==========================================
# Função 1 – Mostrar o menu "void"
# ==========================================
def exibir_menu():
    print("==============================")
    print("   Conversor de Temperatura   ")
    print("==============================")
    print("Escolha uma opção:")
    print("1 - Celsius para Fahrenheit")
    print("2 - Fahrenheit para Celsius")
    print("3 - Help")
    print("==============================")

# ==========================================
# Função 2 – Fazer a conversão (com return)
# ==========================================
def converter_temperatura(v: float, o: int) -> float | None:
    if o == 1:
        return (v * 9/5) + 32  # Celsius para Fahrenheit
    elif o == 2:
        return (v - 32) * 5/9  # Fahrenheit para Celsius
    else:
        return None                # Inválido


# ==========================================
# Programa principal
# ==========================================
while 1:
    exibir_menu()

    try:
        opcao = int(input("Digite sua opção (1/2/3): "))
    except ValueError:
        print("Opção inválida. Tente novamente.\n")
        continue

    if opcao == 3:
        print("Programa encerrado. Até mais!")
        break

    if opcao not in [1, 2]:
        print("Opção inválida. Tente novamente.\n")
        continue

    try:
        valor = float(input("Digite o valor da temperatura: "))
    except ValueError:
        print("Valor inválido. Tente novamente.\n")
        continue

    # Faz a conversão
    resultado = converter_temperatura(valor, opcao)

    # Exibe o resultado
    if opcao == 1:
        print(f"\n{valor}°C equivalem a {resultado:.2f}°F\n")
    else:
        print(f"\n{valor}°F equivalem a {resultado:.2f}°C\n")
