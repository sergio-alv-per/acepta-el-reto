#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

bool casoDePrueba() {

    int n;
    cin >> n;
    if (n == 0)
        return false;
    else {
        // LIS significa longest increasing subsequence, que es el quid del problema.
        vector<int> precios;
        vector<int> LIS;

        precios.reserve(n);
        LIS.reserve(n);

        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            precios.push_back(temp);
        }

        int maximo_global_LIS = 1;

        LIS[0] = 1;

        for (int i = 1; i < n; i++) {
            int max_LIS = 1;
            for (int j = 0; j < i; j++) {
                if (precios[j] < precios[i]) {
                    max_LIS = max(max_LIS, LIS[j]+1);
                }
            }
            LIS[i] = max_LIS;
            maximo_global_LIS = max(maximo_global_LIS, max_LIS);
        }

        cout << maximo_global_LIS << "\n";
        
        return true;
     }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}