#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;


ll equilibrio(ll pi, ll di, ll pd, ll dd) {
    bool submoviles_equilibrados = true;
    ll pi_hijo, di_hijo, pd_hijo, dd_hijo;

    if (pi == 0) {
        cin >> pi_hijo >> di_hijo >> pd_hijo >> dd_hijo;
        pi = equilibrio(pi_hijo, di_hijo, pd_hijo, dd_hijo);

        if (pi == -1) {
            submoviles_equilibrados = false;
        }
    }

    if (pd == 0) {
        cin >> pi_hijo >> di_hijo >> pd_hijo >> dd_hijo;
        pd = equilibrio(pi_hijo, di_hijo, pd_hijo, dd_hijo);

        if (pd == -1) {
            submoviles_equilibrados = false;
        }
    }

    if (submoviles_equilibrados && pi*di == pd*dd) {
        return pi+pd;
    } else {
        return -1;
    }
}


bool casoDePrueba() {

    ll pi, di, pd, dd;

    cin >> pi >> di >> pd >> dd;

    if (pi + di + pd + dd == 0)
        return false;
    else {
        if (equilibrio(pi, di, pd, dd) > 0) {
            cout << "SI\n";
        } else {
            cout << "NO\n";
        }
        return true;
     }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}