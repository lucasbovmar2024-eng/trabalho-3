# ex08/linha_montagem.py

def linha_de_montagem(pecas):
    """Gerador (corrotina) que processa uma peça por vez, suspendendo com yield"""
    print("Linha de montagem iniciada.")
    for peca in pecas:
        # Processa a peça (simulação)
        resultado = f"Peça '{peca}' processada"
        print(f"  -> Processando: {peca}")
        yield resultado   # suspende e devolve o controle
    print("Linha de montagem finalizada.")

# Programa principal (chamador)
pecas_para_processar = ["Parafuso", "Porca", "Arruela", "Engrenagem"]
montagem = linha_de_montagem(pecas_para_processar)

print("Início do programa principal.")
for i in range(len(pecas_para_processar)):
    item = next(montagem)   # ativa a corrotina até o próximo yield
    print(f"Principal recebeu: {item}")
print("Fim do programa principal.")

# Análise:
# Diferente de uma sub-rotina tradicional (run-to-completion), o gerador executa
# até encontrar 'yield', salva todo o estado (variáveis locais, posição no loop)
# e retorna o controle. Na próxima chamada next(), retoma exatamente de onde parou.
# Isso permite processamento incremental e lazy evaluation.