#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

bool casoDePrueba() {

    string frase;

    cin >> frase;

    transform(frase.begin(), frase.end(), frase.begin(), ::tolower);

    if (!cin)
        return false;
    else {
        size_t i, longitud_inicio;
        char letra_inicial = frase.front();
        int estado = 0;
        i = 0;
        longitud_inicio = 1000;

        for (size_t j = 1; j < frase.length(); j++) {
            switch (estado)
            {
            case 0:
                // En el inicio, buscando repetición
                if (frase[j] == letra_inicial) {
                    longitud_inicio = j;
                    estado = 1;
                    i = 0;
                    j--;
                }
                break;
            case 1:
                // En repetición, comprobando que son iguales
                if (frase[i] != frase[j]) {
                    estado = 0;
                    longitud_inicio = 1000;
                    j--;
                } else {
                    i++;

                    if (i == longitud_inicio) {
                        i = 0;
                    }
                }
            default:
                break;
            }
        }

        if (i == 0) {
            cout << min(longitud_inicio, frase.length()) << "\n";
        } else {
            cout << frase.length() << "\n";
        }
        
        return true;
    }

} // casoDePrueba

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(casoDePrueba()) {}
  
    return 0;
}