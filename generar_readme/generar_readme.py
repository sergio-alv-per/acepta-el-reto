import pickle as pkl
import subprocess
import requests
from bs4 import BeautifulSoup

def cargar_datos_problemas(archivo_datos_problemas="./datos_problemas.pkl"):
    print("LOG: cargando datos de problemas...")
    with open(archivo_datos_problemas, "rb") as f:
        datos_problemas = pkl.load(f)
    
    return datos_problemas

def obtener_problemas_resueltos_este_commit():
    print("LOG: obteniendo problemas resueltos este commit...")
    problemas_resueltos_este_commit = subprocess.check_output("git diff --cached --name-only --diff-filter=ACM".split())
    problemas_resueltos_este_commit = problemas_resueltos_este_commit.decode("utf-8").strip().split("\n")
    problemas_resueltos_este_commit = [p.split("/")[0] for p in problemas_resueltos_este_commit]
    problemas_resueltos_este_commit = [p for p in problemas_resueltos_este_commit if p.isdigit()]
    problemas_resueltos_este_commit = list(set(problemas_resueltos_este_commit))
    
    return problemas_resueltos_este_commit

def actualizar_datos_problemas(datos_problemas, problemas_resueltos_este_commit):
    for p in problemas_resueltos_este_commit:
        if p not in datos_problemas:
            print(f"LOG: descargando problema {p}...")
            enlace_problema = f"https://aceptaelreto.com/problem/statement.php?id={p}"
            respuesta = requests.get(enlace_problema)
            html = BeautifulSoup(respuesta.text, features="html.parser")

            titulo_problema = html.find_all("h1")[1].text

            datos_problemas[p] = {"titulo": titulo_problema,
                                  "enlace": enlace_problema}
    
    return datos_problemas

def guardar_datos_problemas(datos_problemas, archivo_datos_problemas="./datos_problemas.pkl"):
    print("LOG: guardado datos de problemas...")
    with open(archivo_datos_problemas, "wb") as f:
        pkl.dump(datos_problemas, f)
    
    return datos_problemas

def generar_texto_readme(datos_problemas):
    print("LOG: generando texto de README.md...")

    texto = "# Acepta el reto\n"
    texto += "Repositorio con las soluciones de agunos de los problemas de [Acepta el Reto](https://aceptaelreto.com/).\n"

    texto += "## Problemas resueltos\n"

    for p, datos in sorted(datos_problemas.items(), key=lambda p: p[0]):
        texto += f"- [{p}: {datos['titulo']}]({datos['enlace']}).\n"
    
    return texto

def escribir_readme(texto, archivo_readme="../README.md"):
    print("LOG: escribiendo README.md...")
    with open(archivo_readme, "w") as f:
        f.write(texto)

def actualizar_readme():
    datos_problemas = cargar_datos_problemas()
    problemas_resueltos_este_commit = obtener_problemas_resueltos_este_commit()

    datos_problemas = actualizar_datos_problemas(datos_problemas, problemas_resueltos_este_commit)
    guardar_datos_problemas(datos_problemas)

    texto_readme = generar_texto_readme(datos_problemas)
    escribir_readme(texto_readme)


if __name__ == "__main__":
    actualizar_readme()
    print("Hecho!")