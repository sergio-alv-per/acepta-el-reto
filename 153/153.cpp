#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void casoDePrueba() {
    int hora, minuto;
    char divisor;

    cin >> hora >> divisor >> minuto;

    int minuto_reflejado = (60 - minuto) % 60;

    hora = hora % 12;
    int hora_reflejada;
    
    if (minuto_reflejado == 0) {
        hora_reflejada = (12 - hora) % 12;
    } else {
        hora_reflejada = (11 - hora) % 12;
    }
    
    if (hora_reflejada == 0) hora_reflejada = 12;

    cout << setfill('0') << setw(2) << hora_reflejada << ":" << setfill('0') << setw(2) << minuto_reflejado << "\n";



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