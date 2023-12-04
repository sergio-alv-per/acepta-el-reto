#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

bool casoDePrueba() {

    int N, K;
    cin >> N;
    if (!cin)
        return false;
    else {
        cin >> K;
        vector<int> satisfaccion;

        for (int i = 0; i < N; i++) {
            int grado;
            cin >> grado;
            satisfaccion.push_back(grado);
        }

        ll max_grado_satisfaccion = -10000000000000;
        for(int i = 0; i <= N-K; i++) {
            max_grado_satisfaccion = max(max_grado_satisfaccion, (ll)satisfaccion[i+K-1] - (ll)satisfaccion[i]);
        }

        for(int i = N-1; i >= K-1; i--) {
            max_grado_satisfaccion = max(max_grado_satisfaccion, (ll)satisfaccion[i-K+1] - (ll)satisfaccion[i]);
        }

        cout << max_grado_satisfaccion << "\n";


        return true;
    }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}