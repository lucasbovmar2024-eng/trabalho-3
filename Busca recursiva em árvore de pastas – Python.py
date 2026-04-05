# ex06/busca_recursiva.py

# Estrutura de pastas aninhadas (dicionários)
sistema_arquivos = {
    "Documentos": {
        "Trabalho": {
            "relatorio.pdf": None,
            "planilha.xlsx": None
        },
        "Pessoal": {
            "foto.jpg": None
        }
    },
    "Downloads": {
        "programa.exe": None,
        "musica.mp3": None
    }
}

def buscar_arquivo(pasta, alvo):
    """
    Função recursiva que busca um arquivo na árvore.
    Retorna o caminho (lista de chaves) se encontrar, senão None.
    """
    # Caso base 1: se o nó atual já é o arquivo procurado
    if pasta == alvo:
        return [alvo]

    # Se não é dicionário (é folha), não há como descer
    if not isinstance(pasta, dict):
        return None

    # Passo recursivo: percorre cada subpasta
    for chave, conteudo in pasta.items():
        resultado = buscar_arquivo(conteudo, alvo)
        if resultado is not None:
            return [chave] + resultado
    return None

# Teste
alvo = "relatorio.pdf"
caminho = buscar_arquivo(sistema_arquivos, alvo)
if caminho:
    print(f"Arquivo '{alvo}' encontrado em: {' -> '.join(caminho)}")
else:
    print(f"'{alvo}' não encontrado.")