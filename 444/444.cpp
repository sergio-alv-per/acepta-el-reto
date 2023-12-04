#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

bool casoDePrueba() {

    int n, k;

    cin >> n >> k;
    if (n == 0 && k == 0)
        return false;
    else {
        int max_longitud = 0;

        int indice_inicio = 0;
        int indice_fin = 0;
        int estado = 0;
        int malas_temperaturas_acumuladas = 0;
        int temperatura;
        for (int i = 0; i < n; i ++){
            cin >> temperatura;

            switch (estado)
            {
            case 0:
                // Esperando inicio de cadena
                if (temperatura == 1) {
                    indice_inicio = i;
                    estado = 1;
                }
                break;
            
            case 1:
                // En medio de una cadena, el último fue un 1
                if (temperatura == 0) {
                    indice_fin = i-1;
                    estado = 2;
                    malas_temperaturas_acumuladas += 1;

                    if (malas_temperaturas_acumuladas > k) {
                        max_longitud = max(max_longitud, indice_fin - indice_inicio + 1);
                        malas_temperaturas_acumuladas = 0;
                        estado = 0;
                    }
                }
                break;
            
            case 2:
                // en medio de una cadena, el último fue un 0
                if (temperatura == 0) {
                    malas_temperaturas_acumuladas += 1;
                    if (malas_temperaturas_acumuladas > k) {
                        max_longitud = max(max_longitud, indice_fin - indice_inicio + 1);
                        malas_temperaturas_acumuladas = 0;
                        estado = 0;
                    }
                } else {
                    malas_temperaturas_acumuladas = 0;
                    estado = 1;
                }
                break;
            }
        }


        if (estado == 1) {
            max_longitud = max(max_longitud, n - indice_inicio);
        } else if (estado == 2) {
            max_longitud = max(max_longitud, indice_fin - indice_inicio + 1);
        }


        cout << max_longitud << "\n";

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