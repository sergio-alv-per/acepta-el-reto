#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

bool comparador(const pair<string, ll>& a, const pair<string, ll>& b) {
    if (a.second != b.second) {
        return a.second > b.second;
    } else {
        return a.first < b.first;
    }
    
}
 

bool casoDePrueba() {

    ll num_sesiones;

    cin >> num_sesiones;

    if (num_sesiones == 0)
        return false;
    else {

        unordered_map<string, ll> minutos_visto;

        for (int i = 0; i < num_sesiones; i++) {
            ll tiempo_vision;
            string nombre_serie;

            cin >> tiempo_vision >> ws;

            getline(cin, nombre_serie);

            minutos_visto[nombre_serie] += tiempo_vision;
        }

        vector<pair<string, ll>> pares_serie_minutos;

        for (auto& it : minutos_visto) {
            pares_serie_minutos.push_back(it);
        }

        sort(pares_serie_minutos.begin(), pares_serie_minutos.end(), comparador);

        int impresas = 0;
        for (auto& serie_minutos : pares_serie_minutos) {
            if (impresas == 3) {
                break;
            }
            if (serie_minutos.second < 30) {
                break;
            } else {
                cout << serie_minutos.first << "\n";
            }
            impresas++;
        }

        cout << "---\n";

        return true;
     }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}