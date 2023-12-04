#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void casoDePrueba() {

    int a;
    cin >> a;
    int siglo = a%100 != 0 ? a/100 + 1 : a/100;
    cout <<  siglo << "\n";

} // casoDePrueba

int main() {
    ll numCasos;

    cin >> numCasos;
    for (ll i = 0; i < numCasos; ++i) {
        casoDePrueba();
    }
  
    return 0;
}