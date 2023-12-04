#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

bool casoDePrueba() {

    ll num_vertices;

    cin >> num_vertices;

    if (num_vertices == 0)
        return false;
    else {
        ll v1, v2;
        ll num_aristas = 0;

        cin >> v1 >> v2;

        while (v1 != 0 || v2 != 0) {
            num_aristas++;
            cin >> v1 >> v2;
        }

        ll min_aristas = num_vertices - 1;

        if (min_aristas < num_aristas) {
            cout << num_aristas - min_aristas << "\n";
        } else {
            cout << "0\n";
        }

        return true;
     }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}