#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

unordered_set<int> repdigits = {0, 1111, 2222, 3333, 4444, 5555, 6666, 7777, 8888, 9999};

void casoDePrueba() {

    int n;

    cin >> n;

    if (repdigits.count(n)) {
        cout << 8 << "\n";
        return;
    }

    if (n == 6174) {
        cout << 0 << "\n";
        return;
    }

    int pasos = 0;

    while (n != 6174) {
        auto numero_string = to_string(n);

        int ceros = 4 - numero_string.size();

        numero_string = string(ceros, '0').append(numero_string);

        vector<char> digitos_asc (numero_string.begin(), numero_string.end());

        vector<char> digitos_desc = digitos_asc;

        sort(digitos_asc.begin(), digitos_asc.end());

        sort(digitos_desc.begin(), digitos_desc.end(), greater<int>());

        string num_asc (digitos_asc.begin(), digitos_asc.end());
        string num_desc (digitos_desc.begin(), digitos_desc.end());

        int asc = stoi(num_asc);
        int desc = stoi(num_desc);
        
        pasos++;
        n = desc - asc;
    }

    cout << pasos << "\n";

} // casoDePrueba

int main() {
    unsigned int numCasos;

    cin >> numCasos;
    for (unsigned int i = 0; i < numCasos; ++i) {
        casoDePrueba();
    }
  
    return 0;
}