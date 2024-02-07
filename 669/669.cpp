#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

bool casoDePrueba() {

    size_t n_varas;

    cin >> n_varas;

    if (n_varas == 0)
        return false;
    else {
        map<int, int> varillas;

        for (size_t i = 0; i < n_varas; i++) {
            int vara;
            cin >> vara;

            if (varillas.find(vara) != varillas.end()) {
                varillas[vara] += 1;
            } else {
                varillas[vara] = 1;
            }
        }

        int n_pares_sueltos = 0;
        int n_cuadruplas = 0;

        for (auto &par : varillas) {
            par.second /= 2;
            n_cuadruplas += par.second / 2;
            n_pares_sueltos += par.second % 2;
        }

        if (n_cuadruplas <= n_pares_sueltos) {
            cout << n_cuadruplas << "\n";
        } else {
            int n_cuadruplas_restantes = n_cuadruplas - n_pares_sueltos;
            cout << n_pares_sueltos + (2 * n_cuadruplas_restantes)/3 << "\n";
        }

        return true;
     }

} // casoDePrueba

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(casoDePrueba()) {
    }
  
    return 0;
}