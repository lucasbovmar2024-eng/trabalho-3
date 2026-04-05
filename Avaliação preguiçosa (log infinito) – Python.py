# ex09/log_infinito.py

def gerador_log_infinito():
    """Simula um arquivo de log infinito. A cada chamada, produz um novo registro."""
    contador = 1
    while True:          # loop infinito, mas controlado pelo chamador
        yield f"Log #{contador}: Evento simulado em {__import__('time').ctime()}"
        contador += 1

# Programa principal
logs = gerador_log_infinito()

print("Lendo os primeiros 5 registros do log infinito (under demand):")
for _ in range(5):
    registro = next(logs)
    print(registro)

print("\n... e assim por diante. Memória RAM não explode porque os dados")
print("não são armazenados todos de uma vez. Cada registro é gerado sob demanda.")

# Análise:
# Se tentássemos carregar um arquivo de log infinito em uma lista, a memória
// acabaria instantaneamente. Com o gerador, apenas um registro existe por vez.
// Isso é lazy evaluation: os valores são calculados apenas quando solicitados,
// permitindo trabalhar com sequências potencialmente infinitas sem estouro.