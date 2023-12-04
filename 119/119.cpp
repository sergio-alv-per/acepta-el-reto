#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<ll> cuadrados;

bool casoDePrueba() {

    ll num_legionarios;

    cin >> num_legionarios;

    if (num_legionarios == 0)
        return false;
    else {
        ll total_escudos = 0;
        while (num_legionarios > 0) {
            auto lado = upper_bound(cuadrados.begin(), cuadrados.end(), num_legionarios) - cuadrados.begin();
            
            total_escudos += 4*lado + lado*lado;

            num_legionarios -= lado*lado;
        }

        cout << total_escudos << "\n";
        return true;
     }

} // casoDePrueba

int main() {

    for (ll i = 1; i <= 3163; i++) {
        cuadrados.push_back(i*i);
    }

    while(casoDePrueba()) {
    }
  
    return 0;
}