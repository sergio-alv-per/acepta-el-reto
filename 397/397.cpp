#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void casoDePrueba() {

    int n;

    cin >> n;

    if (n%3 == 1) {
        cout << "NO\n";
    } else {
        cout << "SI\n";
    }

} // casoDePrueba

int main() {
    ll numCasos;

    cin >> numCasos;
    for (ll i = 0; i < numCasos; ++i) {
        casoDePrueba();
    }
  
    return 0;
}