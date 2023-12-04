#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

bool casoDePrueba() {

    // leer caso de prueba
    int num_versos;

    cin >> num_versos;
    cin >> ws;
    if (num_versos == 0)
        return false;
    else {
        
        vector<string> palabras_finales;

        for (int i = 0; i < num_versos; i++) {
            string verso;
            getline(cin, verso);

            auto indice_ultimo_espacio = verso.find_last_of(' ');

            string ultima_palabra;

            if (indice_ultimo_espacio != string::npos) {
                ultima_palabra = verso.substr(indice_ultimo_espacio+1);
            } else {
                ultima_palabra = verso;
            }

            palabras_finales.push_back(ultima_palabra);

            cout << ultima_palabra << "\n";
        }
        return true;
     }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}