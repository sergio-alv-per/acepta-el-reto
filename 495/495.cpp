#include <bits/stdc++.h>

using namespace std;

bool casoDePrueba() {

    int n_ubicaciones;
    vector<int> alturas;
    vector<int> costes;
    int maximo_desnivel;

    cin >> n_ubicaciones;
    if (!cin)
        return false;
    else {
        alturas.push_back(0);
        for (int i = 0; i < n_ubicaciones; i++) {
            int n;
            cin >> n;
            alturas.push_back(n);
        }

        costes.push_back(0);
        for (int i = 0; i < n_ubicaciones; i++) {
            int n;
            cin >> n;
            costes.push_back(n);
        }

        cin >> maximo_desnivel;

        // Los campamentos forman un grafo acíclico, cada campamento tiene como
        // siguientes aquellos a los que puede llegar sin desnivel.
        // Al ordenarlos por altura se tiene un orden topológico.

        vector<int> coste_hasta_campamento(n_ubicaciones+1, 1000000);
        coste_hasta_campamento[0] = 0;

        for (int i = 0; i <= n_ubicaciones; i++) {
            for (int j = i+1; j <= n_ubicaciones; j++) {
                // Recorremos todos los campamentos siguientes
                if (alturas[i] + maximo_desnivel >= alturas[j]) {
                    // Se puede llegar al campamento j desde el i
                    if (coste_hasta_campamento[j] > coste_hasta_campamento[i] + costes[j]) {
                        coste_hasta_campamento[j] = coste_hasta_campamento[i] + costes[j];
                    }
                } else {
                    // No se puede llegar al campamento j => no se puede
                    // llegar a ninguno de los siguientes desde i
                    break;
                }
            }
        }

        cout << coste_hasta_campamento[n_ubicaciones] << "\n";

        return true;
    }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}