#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void casoDePrueba() {

    int horas, minutos, distancia, velocidad;
    char sep;

    cin >> horas >> sep >> minutos >> distancia >> velocidad;

    cout << ((horas*60 + minutos) * velocidad ) / 60 << "\n";
} // casoDePrueba

int main() {
    ll numCasos;

    cin >> numCasos;
    for (ll i = 0; i < numCasos; ++i) {
        casoDePrueba();
    }
  
    return 0;
}