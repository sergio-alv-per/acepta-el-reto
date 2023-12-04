#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

ll suma_digitos_multiplos_3_de_1_a_n(ll n);
ll suma_digitos_multiplos_3_mas_1_de_1_a_n(ll n);
ll suma_digitos_multiplos_3_mas_2_de_1_a_n(ll n);

vector<ll> sumas_1 = {0, 45, 900, 13500, 180000, 2250000, 27000000, 315000000, 3600000000, 40500000000, 450000000000, 4950000000000, 54000000000000, 585000000000000, 6300000000000000};
vector<vector<ll>> sumas_3 = {
{0, 18, 306, 4509, 60012, 750015, 9000018, 105000021, 1200000024, 13500000027, 150000000030, 1650000000033, 18000000000036, 195000000000039, 2100000000000042, 22500000000000045},
{0, 12, 294, 4491, 59988, 749985, 8999982, 104999979, 1199999976, 13499999973, 149999999970, 1649999999967, 17999999999964, 194999999999961, 2099999999999958, 22499999999999955},
{0, 15, 300, 4500, 60000, 750000, 9000000, 105000000, 1200000000, 13500000000, 150000000000, 1650000000000, 18000000000000, 195000000000000, 2100000000000000, 22500000000000000}
};

vector<ll> diez_elevado_d = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000, 1000000000000000};
vector<ll> d_treses = {0, 3, 33, 333, 3333, 33333, 333333, 3333333, 33333333, 333333333, 3333333333, 33333333333, 333333333333, 3333333333333, 33333333333333, 333333333333333};

ll posmod(ll a, ll b) {
    return (b + (a)%b)%b;
}

ll suma_digitos(ll n) {
    ll suma = 0;

    while (n > 9) {
        suma += n%10;
        n = n/10;
    }

    return suma + n;
}


ll suma_digitos_multiplos_3_de_1_a_n(ll n) {
    n = n - n%3;
    string str_num = to_string(n);
    ll d = str_num.length() - 1;
    ll msd = stoll(str_num.substr(0, 1));

    if (n < 100) {
        ll suma = 0;
        for (ll i = 0; i <= n; i++) {
            if (i%3 == 0) {
                suma += suma_digitos(i);
            }
        }
        return suma;
    }

    ll term_1, term_2;

    term_1 = 0;
    for (ll i = 1; i <= msd; i++) {
        if (posmod(-(i-1), 3) == 0) {
            term_1 += (i-1)*(d_treses[d] + 1);
        } else {
            term_1 += (i-1)*(d_treses[d]);
        }

        term_1 += sumas_3[posmod(1-i, 3)][d];
    }

    term_2 = msd*(n%(diez_elevado_d[d]) + 3 - posmod(-msd, 3))/3;

    if (posmod(-msd, 3) == 0) {
        term_2 += suma_digitos_multiplos_3_de_1_a_n(n%(diez_elevado_d[d]));
    } else if (posmod(-msd, 3) == 1) {
        term_2 += suma_digitos_multiplos_3_mas_1_de_1_a_n(n%(diez_elevado_d[d]));
    } else {
        term_2 += suma_digitos_multiplos_3_mas_2_de_1_a_n(n%(diez_elevado_d[d]));
    }

    return term_1 + term_2;
}

ll suma_digitos_multiplos_3_mas_1_de_1_a_n(ll n) {
    if (n < 10) {
        ll suma = 0;
        for (ll i = 0; i <= n; i++) {
            if (i%3 == 1) {
                suma += suma_digitos(i);
            }
        }
        return suma;
    } else {
        n = n - (n-1)%3;
        
        ll acarreos = 0;
        for (int d = 1; d <= 15; d++) {
            acarreos += (n + 2*(diez_elevado_d[d]) + 1)/(3*(diez_elevado_d[d]));
        }

        return suma_digitos_multiplos_3_de_1_a_n(n) + (n+3)/3 - 9*acarreos;
    }
}

ll suma_digitos_multiplos_3_mas_2_de_1_a_n(ll n) {
    if (n < 10) {
        ll suma = 0;
        for (ll i = 0; i <= n; i++) {
            if (i%3 == 2) {
                suma += suma_digitos(i);
            }
        }
        return suma;
    } else {
        n = n - (n-2)%3;

        ll acarreos = 0;
        for (int d = 1; d <= 15; d++) {
            acarreos += (n + 2*(diez_elevado_d[d]) + 1)/(3*(diez_elevado_d[d]));
            acarreos += (n + diez_elevado_d[d] + 2)/(3*(diez_elevado_d[d]));
        }

        return suma_digitos_multiplos_3_de_1_a_n(n) + 2*((n+3)/3) - 9*acarreos;
    }
}


bool casoDePrueba() {

    ll a, b;

    cin >> a >> b;
    if (a == 0 && b == 0)
        return false;
    else {
        cout << suma_digitos_multiplos_3_de_1_a_n(b) - suma_digitos_multiplos_3_de_1_a_n(a-1) << "\n";
        return true;
     }

} // casoDePrueba

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(casoDePrueba()) {}
    
    return 0;
}