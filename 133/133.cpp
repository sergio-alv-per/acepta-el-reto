#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

map<char, int> charToInt{
        {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9},
        {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}, {'G', 16}, {'H', 17}, {'I', 18}, {'J', 19},
        {'K', 20}, {'L', 21}, {'M', 22}, {'N', 23}, {'O', 24}, {'P', 25}, {'Q', 26}, {'R', 27}, {'S', 28}, {'T', 29},
        {'U', 30}, {'V', 31}, {'W', 32}, {'X', 33}, {'Y', 34}, {'Z', 35}
    };

map<int, char> intToChar{
        {0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'},
        {10, 'A'}, {11, 'B'}, {12, 'C'}, {13, 'D'}, {14, 'E'}, {15, 'F'}, {16, 'G'}, {17, 'H'}, {18, 'I'}, {19, 'J'},
        {20, 'K'}, {21, 'L'}, {22, 'M'}, {23, 'N'}, {24, 'O'}, {25, 'P'}, {26, 'Q'}, {27, 'R'}, {28, 'S'}, {29, 'T'},
        {30, 'U'}, {31, 'V'}, {32, 'W'}, {33, 'X'}, {34, 'Y'}, {35, 'Z'}
    };

char suma_un_digito_base_M_mod(int M, char n1, char n2) {
    return intToChar[(charToInt[n1] + charToInt[n2]) % (M-1)];
}

char producto_un_digito_base_M_mod(int M, char n1, char n2) {
    return intToChar[(charToInt[n1] * charToInt[n2]) % (M-1)];
}

char resumen(int M, string numero) {
    char resumen = '0';
    for (char c : numero) {
        resumen = suma_un_digito_base_M_mod(M, resumen, c);
    }

    return resumen;
}

void casoDePrueba() {
    int M;
    string dividendo, divisor, cociente, resto;
    cin >> M >> dividendo >> divisor >> cociente >> resto;

    char resumen_dividendo = resumen(M, dividendo);
    char resumen_divisor = resumen(M, divisor);
    char resumen_cociente = resumen(M, cociente);
    char resumen_resto = resumen(M, resto);

    if (resumen_dividendo == suma_un_digito_base_M_mod(M, resumen_resto, producto_un_digito_base_M_mod(M, resumen_divisor, resumen_cociente))) {
        cout << "POSIBLEMENTE CORRECTO\n";
    } else {
        cout << "INCORRECTO\n";
    }
} // casoDePrueba

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll numCasos;

    cin >> numCasos;
    for (ll i = 0; i < numCasos; ++i) {
        casoDePrueba();
    }
  
    return 0;
}