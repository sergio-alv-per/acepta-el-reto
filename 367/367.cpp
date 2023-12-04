#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void casoDePrueba() {

    int portal_inicial, n;

    cin >> portal_inicial >> n;

    vector<int> portales(n);

    for (int i = 0; i < n; i++) {
        cin >> portales[i];
    }

    sort(portales.begin(), portales.end());

    
    auto posicion_insercion = lower_bound(portales.begin(), portales.end(), portal_inicial);

    vector<int>::iterator portal_actual;

    if (*posicion_insercion == portal_inicial) {
        portal_actual = posicion_insercion;
    } else {
        if (posicion_insercion == portales.begin()) {
            portal_actual = posicion_insercion;
        } else if (posicion_insercion == portales.end()) {
            portal_actual = posicion_insercion - 1;
        } else {
            int distancia_anterior = abs(*(posicion_insercion-1) - portal_inicial);
            int distancia_siguiente = abs(*posicion_insercion - portal_inicial);
            if (distancia_anterior >= distancia_siguiente) {
                portal_actual = posicion_insercion;
            } else {
                portal_actual = posicion_insercion-1;
            }
        }
    }

    size_t indice_portal_actual = portal_actual - portales.begin();

    while (portales.size() > 1) {
        cout << portales[indice_portal_actual] << " ";
        size_t indice_portal_siguiente;
        if (indice_portal_actual == 0) {
            // Seguimos en 0 cuando se actualice
            indice_portal_siguiente = 0;
        } else if (indice_portal_actual == portales.size()-1) {
            // Seguimos en el último cuando se actualice
            indice_portal_siguiente = indice_portal_actual-1;
        } else {
            int distancia_anterior = abs(portales[indice_portal_actual] - portales[indice_portal_actual-1]);
            int distancia_siguiente = abs(portales[indice_portal_actual] - portales[indice_portal_actual+1]);

            if (distancia_anterior >= distancia_siguiente) {
                indice_portal_siguiente = indice_portal_actual;
            } else {
                indice_portal_siguiente = indice_portal_actual-1;
            }
        }

        portales.erase(portales.begin()+indice_portal_actual);
        indice_portal_actual = indice_portal_siguiente;
    }

    cout << portales[0] << "\n";
} // casoDePrueba

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll numCasos;

    cin >> numCasos;
    for (ll i = 0; i < numCasos; ++i) {
        casoDePrueba();
    }
  
    return 0;
}