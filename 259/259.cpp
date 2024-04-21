#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

bool casoDePrueba() {

    int digitos;

    cin >> digitos;

    // leer caso de prueba
    if (digitos == 0)
        return false;
    else if (digitos == 1) {
        cout << "10\n";
        return true;
    } else {
        cout << "9";

        for (int i = 0; i < (digitos-1)/2; i++) {
            cout << "0";
        }

        cout << "\n";

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