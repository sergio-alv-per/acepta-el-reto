#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

ll mc(vector<vector<ll>> &cache, vector<ll> &cubos, int i, int j) {
    // Máxima comida

    if (i >= j) {
        return 0;
    }

    if (cache[i][j] != -1) {
        return cache[i][j];
    }
    
    // 1. Come Devoradora
    int nuevo_i = i;
    int nuevo_j = j;
    if (cubos[i] > cubos[j]) {
        nuevo_i = i+1;
    } else {
        nuevo_j = j-1;
    }

    // 2. Posibilidades de comer yo
    ll comer_izquierda = cubos[nuevo_i] + mc(cache, cubos, nuevo_i+1, nuevo_j);
    ll comer_derecha = cubos[nuevo_j] + mc(cache, cubos, nuevo_i, nuevo_j-1);

    // 3. Guardar resultado y devolver máximo
    cache[i][j] = max(comer_izquierda, comer_derecha);
    return cache[i][j];
}

bool casoDePrueba()
{
    size_t n_cubos;

    cin >> n_cubos;

    if (n_cubos == 0)
        return false;
    else
    {
        vector<ll> cubos(n_cubos + 1);
        vector<vector<ll>> cache(n_cubos + 1, vector<ll>(n_cubos + 1, -1));

        cubos[n_cubos] = 100000; // Valor por encima del máximo de los cubos

        for (size_t i = 0; i < n_cubos; i++) {
            cin >> cubos[i];
        }

        cout << mc(cache, cubos, 0, n_cubos) << "\n";

        return true;
    }

} // casoDePrueba

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (casoDePrueba())
    {
    }

    return 0;
}