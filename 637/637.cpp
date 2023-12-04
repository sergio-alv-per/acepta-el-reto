#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

unordered_map<char, ll> coste = {
{'A', 5},
{'B', 9},
{'C', 11},
{'D', 7},
{'E', 1},
{'F', 9},
{'G', 9},
{'H', 7},
{'I', 3},
{'J', 13},
{'K', 9},
{'L', 9},
{'M', 7},
{'N', 5},
{'O', 11},
{'P', 11},
{'Q', 13},
{'R', 7},
{'S', 5},
{'T', 3},
{'U', 7},
{'V', 9},
{'W', 9},
{'X', 11},
{'Y', 13},
{'Z', 11},
{'!', 19},
{'?', 15},
};

void casoDePrueba() {

    string mensaje;

    ll coste_mensaje = 0;

    getline(cin, mensaje);

    for (char c : mensaje) {
        auto it = coste.find(c);
        
        if (it != coste.end()) {
            coste_mensaje += it->second;
            coste_mensaje += 3;
        } else if (c == ' ') {
            coste_mensaje -= 3;
            coste_mensaje += 5;
        }
    }

    coste_mensaje -= 3;

    cout << coste_mensaje << "\n";

} // casoDePrueba

int main() {
    ll numCasos;

    cin >> numCasos;
    std::cin.ignore( 1024, '\n' );
    
    for (ll i = 0; i < numCasos; ++i) {
        casoDePrueba();
    }
  
    return 0;
}