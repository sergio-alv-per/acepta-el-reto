#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

// -------------------------- NO TIENE AC -----------------------

bool casoDePrueba() {
    ll tam_caras, numero_juegos;

    cin >> tam_caras >> numero_juegos;

    if (!cin)
        return false;
    else {
        
        ll minima_diferencia, suma_juegos;

        cin >> minima_diferencia;
        suma_juegos = minima_diferencia;

        for (ll i = 1; i < numero_juegos; i++) {
            ll juego;
            cin >> juego;
            minima_diferencia = abs(minima_diferencia - juego);
            suma_juegos += juego;
        }

        if ((suma_juegos + minima_diferencia) / 2 <= tam_caras) {
            cout << "SI\n";
        } else {
            cout << "NO\n";
        }
        
        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(casoDePrueba()) {}
  
    return 0;
}