#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

bool casoDePrueba() {
    int tam_vector;
    cin >> tam_vector;
    if (tam_vector == 0)
        return false;
    else {
        vector<int> vector(tam_vector);

        for (int i = 0; i < tam_vector; i++) {
            cin >> vector[i];
        }

        int salto = 0;
        for (int i = tam_vector-1; i >= 1; i--) {
            if (vector[i-1] == vector[i]) {
                salto = i;
                break;
            }
        }

        vector[salto]++;

        for (int i = salto+1; i < tam_vector; i++) {
            vector[i] = vector[salto];
        }

        for (int i = 0; i < tam_vector-1; i++) {
            cout << vector[i] << " ";
        }

        cout << vector[tam_vector-1] << "\n";

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