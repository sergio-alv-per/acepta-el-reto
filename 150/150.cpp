#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

bool casoDePrueba() {

    int lado;
    char simbolo;
    cin >> lado >> simbolo;
    if (lado == 0)
        return false;
    else {
        for (int i = 0; i < lado; i++) {
            for (int j = 0; j < lado-1-i; j++) {
                cout << " ";
            }
            for (int j = 0; j < lado + 2*i; j++) {
                cout << simbolo;
            }
            cout << "\n";
        }
        for (int i = lado-2; i >= 0; i--) {
            for (int j = 0; j < lado-1-i; j++) {
                cout << " ";
            }
            for (int j = 0; j < lado + 2*i; j++) {
                cout << simbolo;
            }
            cout << "\n";
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