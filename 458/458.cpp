#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

bool casoDePrueba() {

    ll n;

    cin >> n;
    if (n == 0)
        return false;
    else {
        ll a,b,c,d;
        bool hay_ceros = false;

        a = 0;
        b = 0,
        c = 0;
        d = 0;

        for (ll i = 0; i < n; i++) {
            ll num;

            cin >> num;

            if (num == 0) {
                hay_ceros = true;
            } else if (num < 0) {
                if (num <= a) {
                    b = a;
                    a = num;
                } else if (num < b) {
                    b = num;
                }
            } else {
                if (num >= d) {
                    c = d;
                    d = num;
                } else if (num > c) {
                    c = num;
                }
            }
        }

        /*
        Diagrama de casos
        +------+---------------+--------------+---+
        |  -\+ |      >= 2     |       1      | 0 |
        +------+---------------+--------------+---+
        | >= 2 |   max ambos   |   max negativos  |
        +------+---------------+--------------+---+
        |   1  |               | si no hay 0, |   |
        |      |               |    pos*neg   |   |
        |      | max positivos +--------------+ 0 |
        |      |               |       0      |   |
        +------+               +--------------+---+
        |   0  |               |       0      | 0 |
        +------+---------------+--------------+---+
        */

        if (a != 0 && b != 0 && c != 0 && d != 0) {
            cout << max(a*b, c*d) << "\n";
        } else if (a != 0 && b != 0 && c == 0) {
            cout << a*b << "\n";
        } else if (b == 0 && c != 0 && d != 0) {
            cout << c*d << "\n";
        } else if (a != 0 && d != 0 && !hay_ceros) {
            cout << a*d << "\n";
        } else {
            cout <<"0\n";
        }

        return true;
     }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}