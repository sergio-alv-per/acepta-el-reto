#include <bits/stdc++.h>

using namespace std;

double f(vector<int> coef, double x) {
    double exponent = 0;
    double result = 0;
    for (auto c = coef.rbegin(); c != coef.rend(); ++c) {
        result += *c * pow(x, exponent);
        exponent += 1;
    }

    return result;
}

bool casoDePrueba() {

    size_t grado;
    cin >> grado;

    if (grado == 20)
        return false;
    else {
        vector<int> coeficientes(grado+1, 0);
        
        for (size_t i = 0; i <= grado; i++) {
            cin >> coeficientes[i];
        }

        size_t rectangulos;

        cin >> rectangulos;

        double suma_riemann = 0;
        for (size_t r = 0; r < rectangulos; r++) {
            suma_riemann += min(1.0, max(0.0, f(coeficientes, r/(double)rectangulos)));
        }

        suma_riemann /= rectangulos;

        if (suma_riemann > 0.501) {
            cout << "CAIN\n";
        } else if (suma_riemann < 0.499) {
            cout << "ABEL\n";
        } else {
            cout << "JUSTO\n";
        }
        
        return true;
     }

} // casoDePrueba

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(casoDePrueba()) {}
  
    return 0;
}