#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

class NodoArbol {
public:
    int raiz;
    NodoArbol* izq;
    NodoArbol* der;

    NodoArbol(){
        this->raiz = 0;
        this->izq = NULL;
        this->der = NULL;
    };
    ~NodoArbol(){
        if (izq != NULL) {
            delete izq;
        }

        if (der != NULL) {
            delete der;
        }
    }
};

NodoArbol* generarArbol(vector<int>::iterator inicio_preorden, vector<int>::iterator fin_preorden, vector<int>::iterator inicio_inorden, vector<int>::iterator fin_inorden) {
    if (inicio_preorden == fin_preorden) {
        return NULL;
    }

    int raiz = *inicio_preorden;
    auto division_inorden = find(inicio_inorden, fin_inorden, raiz);
    auto noEstaEnSubarbolIzquierda = [inicio_inorden, division_inorden](int i) {
        return find(inicio_inorden, division_inorden, i) == division_inorden;
    };
    
    auto inicio_arbol_derecha_preorden = find_if(inicio_preorden+1, fin_preorden, noEstaEnSubarbolIzquierda);

    NodoArbol* N = new NodoArbol();
    N->raiz = raiz;
    N->izq = generarArbol(inicio_preorden+1, inicio_arbol_derecha_preorden, inicio_inorden, division_inorden);
    N->der = generarArbol(inicio_arbol_derecha_preorden, fin_preorden, division_inorden+1, fin_inorden);

    return N;
}

void imprimirPostOrden(NodoArbol* arbol, bool espacio_final) {
    if (arbol != NULL) {
        imprimirPostOrden(arbol->izq, true);
        imprimirPostOrden(arbol->der, true);
        cout << arbol->raiz;
        if (espacio_final) {
            cout << " ";
        }
    }
}


bool casoDePrueba() {

    vector<int> preorden;
    vector<int> inorden;

    int numero_leido;

    cin >> numero_leido;

    if (numero_leido == -1)
        return false;
    else {
        
        do {
            preorden.push_back(numero_leido);
            cin >> numero_leido;
        } while (numero_leido != -1);

        cin >> numero_leido;
        do {
            inorden.push_back(numero_leido);
            cin >> numero_leido;
        } while (numero_leido != -1);
        
        NodoArbol* arbol = generarArbol(preorden.begin(), preorden.end(), inorden.begin(), inorden.end());

        imprimirPostOrden(arbol, false);
        cout << "\n";

        delete arbol;

        return true;
     }

} // casoDePrueba

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(casoDePrueba()) {
    }
  
    return 0;
}