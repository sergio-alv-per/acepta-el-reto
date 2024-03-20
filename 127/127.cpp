#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void casoDePrueba() {

    vector<string> nombres;
    string nombre;

    while (cin >> nombre && nombre != "F") {
        nombres.push_back(nombre);
    }

    size_t C;
    size_t P;

    cin >> C >> P;

    if (C == 0) {
        cout << "NADIE TIENE CAMA\n";
    } else if (C >= nombres.size()) {
        cout << "TODOS TIENEN CAMA\n";
    } else {
        size_t actual = 0;
        while (nombres.size() > C) {
            size_t elegido = (actual + P - 1) % nombres.size();
            nombres.erase(nombres.begin() + elegido);
            actual = elegido;
        }

        cout << nombres[0];

        for (size_t i = 1; i < nombres.size(); ++i) {
            cout << ' ' << nombres[i];
        }

        cout << '\n';
    }

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