#include <bits/stdc++.h>

using namespace std;

bool casoDePrueba() {

    unsigned int luchadores;
    unsigned int tipos_criaturas;
    unsigned int num_criaturas_totales;

    vector<unsigned int> criaturas_cada_tipo;
    vector<unsigned int> luchadores_cada_criatura;
    priority_queue<pair<unsigned int, unsigned int>> criaturas_por_luchador;

    cin >> luchadores >> tipos_criaturas;

    if (!cin)
        return false;
    else {
        num_criaturas_totales = 0;

        for (unsigned int i = 0; i < tipos_criaturas; i++) {
            unsigned int criaturas_temp;
            cin >> criaturas_temp;

            criaturas_cada_tipo.push_back(criaturas_temp);
            luchadores_cada_criatura.push_back(1);
            criaturas_por_luchador.push(make_pair(criaturas_temp, i));

            num_criaturas_totales = min(num_criaturas_totales + criaturas_temp, luchadores+1);
        }

        if (num_criaturas_totales <= luchadores) {
            cout << "1\n";
            return true;
        }

        luchadores -= tipos_criaturas;

        for (int i = 0; i < luchadores;i++) {
            unsigned int indice_maximo = criaturas_por_luchador.top().second;
            criaturas_por_luchador.pop();

            luchadores_cada_criatura[indice_maximo] += 1;
            unsigned int criaturas_por_luchador_actualizado = criaturas_cada_tipo[indice_maximo] / luchadores_cada_criatura[indice_maximo];
            
            if (criaturas_cada_tipo[indice_maximo] % luchadores_cada_criatura[indice_maximo] > 0) {
                criaturas_por_luchador_actualizado += 1;
            }

            criaturas_por_luchador.push(make_pair(criaturas_por_luchador_actualizado, indice_maximo));
        }

        cout << (criaturas_por_luchador.top()).first << "\n";

        return true;
    }
}

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}