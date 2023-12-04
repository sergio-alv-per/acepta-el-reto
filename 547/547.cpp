#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

ll longitud(ll n) {
    ll total = 0;
    ll potencia_2 = 1;
    for (int k = 0; k < n; k++) {
        total += potencia_2 * (n + 2 - k);
        potencia_2 *= 2;
    }

    return total;
}


char recursivo(ll n, ll k) {
    ll longitud_nm1 = longitud(n-1);
    
    if (k < longitud_nm1) {
        return recursivo(n-1, k);
    } else if (k >= longitud_nm1 + n + 2) {
        return recursivo(n-1, k - (longitud_nm1 + n + 2));
    } else if (k == longitud_nm1) {
        return 'B';
    } else if (k == longitud_nm1 + n + 1) {
        return 'H';
    } else {
        return 'U';
    }
}

bool casoDePrueba() {

    // leer el inicio del caso de prueba (cin)
    ll n, k;
    cin >> n >> k;

    if (!cin)
        return false;
    else {
        k = k-1;

        cout << recursivo(n, k) << "\n";
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