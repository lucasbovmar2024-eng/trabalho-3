# ex03/folha_pagamento.py

# ========== Código caótico (espaguete) ==========
print("=== Versão caótica ===")
funcionarios = [("Ana", 40, 20), ("Bruno", 45, 18), ("Carla", 38, 22)]
for i in range(3):
    nome, horas, valor_hora = funcionarios[i]
    salario_bruto = horas * valor_hora
    if salario_bruto > 1000:
        imposto = salario_bruto * 0.2
    else:
        imposto = salario_bruto * 0.1
    salario_liquido = salario_bruto - imposto
    print(f"{nome} -> Bruto: {salario_bruto}, Liq: {salario_liquido}")
print("Fim do processamento caótico\n")

# ========== Versão refatorada (alta coesão) ==========
print("=== Versão refatorada ===")

# Função pura: só calcula, sem efeito colateral
def calcular_salario_liquido(horas_trabalhadas, valor_por_hora):
    salario_bruto = horas_trabalhadas * valor_por_hora
    imposto = salario_bruto * 0.2 if salario_bruto > 1000 else salario_bruto * 0.1
    return salario_bruto - imposto

# Procedimento: só imprime, não modifica estado
def imprimir_holerite(nome, salario_liquido):
    print(f"{nome} recebeu R$ {salario_liquido:.2f}")

# Fluxo principal organizado
dados_funcionarios = [("Ana", 40, 20), ("Bruno", 45, 18), ("Carla", 38, 22)]
for nome, horas, valor in dados_funcionarios:
    liquido = calcular_salario_liquido(horas, valor)
    imprimir_holerite(nome, liquido)

print("Fim do processamento estruturado")