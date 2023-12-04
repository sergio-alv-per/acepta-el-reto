#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

int sum(vector<int> v) {
    int suma = 0;
    for (int i : v)
    {
        suma += i;
    }
    return suma;
}

bool casoDePrueba() {

    int n;
    cin >> n;

    if (n == 0)
        return false;
    else {
        vector<vector<int>> cuadrado(n, vector<int>(n));
        vector<int> aparece(n*n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int elem;
                cin >> elem;
                cuadrado[i][j] = elem;
                if (1 <= elem && elem <= n*n) {
                    aparece[elem-1] = 1;
                }
            }
        }

        // Comprobar mágico
        int constante_magica = sum(cuadrado[0]);
        int suma = 0;
        for (auto row : cuadrado) {
            if (sum(row) != constante_magica) {
                cout << "NO\n";
                return true;
            }
        }

        for (int j = 0; j < n; j++) {
            suma = 0;
            for (int i = 0; i < n; i++) {
                suma += cuadrado[i][j];
            }
            if (suma != constante_magica) {
                cout << "NO\n";
                return true;
            }
        }

        suma = 0;
        for (int i = 0; i < n; i++)
        {
            suma += cuadrado[i][i];
        }
        if (suma != constante_magica) {
            cout << "NO\n";
            return true;
        }

        suma = 0;
        for (int i = 0; i < n; i++)
        {
            suma += cuadrado[i][n-1-i];
        }
        if (suma != constante_magica) {
            cout << "NO\n";
            return true;
        }

        // Es mágico. Comprobamos si es esotérico

        if (sum(aparece) < n*n) {
            cout << "DIABOLICO\n";
            return true;
        }

        int constante_magica_2 = (4*constante_magica)/n;

        if (cuadrado[0][0] + cuadrado[0][n-1] + cuadrado[n-1][0] + cuadrado[n-1][n-1] != constante_magica_2) {
            cout << "DIABOLICO\n";
            return true;
        }

        if (n % 2 == 1) {
            if (cuadrado[0][n/2] + cuadrado[n-1][n/2] + cuadrado[n/2][0] + cuadrado[n/2][n-1] != constante_magica_2) {
                cout << "DIABOLICO\n";
                return true;
            }

            if (4*cuadrado[n/2][n/2] != constante_magica_2) {
                cout << "DIABOLICO\n";
                return true;
            }
        } else {
            if (cuadrado[0][n/2-1] + cuadrado[0][n/2] +
                cuadrado[n-1][n/2-1] + cuadrado[n-1][n/2] +
                cuadrado[n/2-1][0] + cuadrado[n/2][0] +
                cuadrado[n/2-1][n-1] + cuadrado[n/2][n-1] != 2 * constante_magica_2) {
                cout << "DIABOLICO\n";
                return true;
            }

            if (cuadrado[n/2-1][n/2-1] + cuadrado[n/2][n/2-1] +
                cuadrado[n/2-1][n/2] + cuadrado[n/2][n/2] != constante_magica_2) {
                cout << "DIABOLICO\n";
                return true;
            }

        }

        cout << "ESOTERICO\n";
        
        
        return true;
     }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}