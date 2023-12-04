#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

bool casoDePrueba() {

    // leer caso de prueba
    string caracter;
    cin >> caracter;
    if (caracter == ".")
        return false;
    else {
        ll verano = 0;
        ll invierno = 0;

        do
        {
            if (caracter == "V") {
                verano++;
            } else if (caracter == "I") {
                invierno++;
            } else {
                verano++;
                invierno++;
            }
            
            cin >> caracter;
        } while (caracter != ".");

        if (verano > invierno) {
            cout << "VERANO\n";
        } else if (verano < invierno) {
            cout << "INVIERNO\n";
        } else {
            cout << "EMPATE\n";
        }
        
        return true;
     }

} // casoDePrueba

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    while(casoDePrueba()) {
    }
  
    return 0;
}