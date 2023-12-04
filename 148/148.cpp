#include <iostream>

#define ll long long
#define ld long double

using namespace std;

bool casoDePrueba() {

    // leer caso de prueba
    ll horas;
    char sep;
    ll minutos;

    cin >> horas >> sep >> minutos;

    if (horas == 0 && minutos == 0) {
        return false;
    } else {
        
        minutos = horas*60 + minutos;

        cout << 24*60 - minutos << "\n";

        return true;
    }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}