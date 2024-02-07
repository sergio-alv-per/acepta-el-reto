#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void casoDePrueba() {
    ll total, ultimo, actual;
    ll arriba = 0;
    ll abajo = 0;

    cin >> total >> ultimo;

    for (int i = 1; i < total; i++) {
        cin >> actual;
        if (actual > ultimo) {
            arriba++;
        } else if (actual < ultimo) {
            abajo++;
        }
        ultimo = actual;
    }

    cout << arriba << " " << abajo << "\n";

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