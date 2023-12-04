#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

bool casoDePrueba() {

    ll maximo_veces_sacar_basura, n_datos_recogidos;

    cin >> maximo_veces_sacar_basura >> n_datos_recogidos;

    if (maximo_veces_sacar_basura == 0 || n_datos_recogidos == 0)
        return false;
    else {
        ll cantidad_basura;
        char tipo;

        vector<pair<int, char>> basura;

        ll cota_inferior = -1;

        for (int i = 0; i < n_datos_recogidos; i++) {
            cin >> cantidad_basura >> tipo;

            if (tipo == 'R') {
                cota_inferior = max(cota_inferior, cantidad_basura);
            } else {
                cota_inferior = max(cota_inferior, cantidad_basura/2+cantidad_basura%2);
            }

            basura.push_back(make_pair(cantidad_basura, tipo));
        }

        ll lim_inf = cota_inferior;
        ll lim_sup = cota_inferior * n_datos_recogidos;
        
        ll medio = -1;
        do {
            medio = lim_inf + (lim_sup - lim_inf)/2;

            ll veces_sacar_basura = 0;
            ll capacidad_envases = 0;
            ll capacidad_resto = 0;

            for (auto p : basura) {
                ll peso = p.first;
                char tipo = p.second;
                if (tipo == 'R') {
                    if (capacidad_resto + peso > medio) {
                        veces_sacar_basura += 1;
                        capacidad_envases = 0;
                        capacidad_resto = 0;
                    }
                    capacidad_resto += peso;
                } else {
                    if (capacidad_envases + peso > 2*medio) {
                        veces_sacar_basura += 1;
                        capacidad_envases = 0;
                        capacidad_resto = 0;
                    }
                    capacidad_envases += peso;
                }
            }

            if (capacidad_envases > 0 || capacidad_resto > 0) {
                veces_sacar_basura += 1;
            }

            if (veces_sacar_basura <= maximo_veces_sacar_basura) {
                lim_sup = medio;
            } else {
                lim_inf = medio;
            }
        } while (lim_inf < lim_sup);

        cout << lim_sup << "\n";
        
        return true;
     }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {}
  
    return 0;
}