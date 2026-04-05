# ex05/estoque.py

def aplicar_desconto(estoque, percentual):
    """Subtrai percentual de cada item (modifica a lista original)"""
    for i in range(len(estoque)):
        estoque[i] = estoque[i] * (1 - percentual / 100)

# Programa principal
estoque_original = [100.0, 200.0, 50.0, 300.0]
print("Antes do desconto:", estoque_original)

aplicar_desconto(estoque_original, 10)
print("Depois do desconto:", estoque_original)

# Análise exigida:
# Python utiliza call-by-sharing (passagem por objeto). A variável 'estoque' dentro
# da função referencia o mesmo objeto lista que 'estoque_original' no escopo global.
# Como listas são mutáveis, modificações nos elementos afetam o objeto compartilhado.
# Não há cópia automática. Para evitar isso, seria necessário criar uma cópia manual
# (ex: estoque[:]) ou usar tuplas imutáveis.