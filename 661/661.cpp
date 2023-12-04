#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

bool ordenartupla(const tuple<int, int, int, string>& a,  
               const tuple<int, int, int, string>& b) {
    
    if (get<0>(a) == get<0>(b)) {
        if (get<1>(a) == get<1>(b)) {
            return (get<2>(a) < get<2>(b));
        } else {
            return (get<1>(a) < get<1>(b));
        }
    } else {
        return (get<0>(a) > get<0>(b));
    }
} 

bool casoDePrueba() {

    ll N;
    cin >> N;
    if (N == 0)
        return false;
    else {
        vector<tuple<int, int, int, string>> objetos;
        string nombre;
        int valor, peso;
        for (int i = 0; i < N; ++i) {
            cin >> nombre >> valor >> peso;
            objetos.push_back(make_tuple(valor, peso, i, nombre));
        }

        sort(objetos.begin(), objetos.end(), ordenartupla);

        cout << get<3>(objetos[0]);
        for (int i = 1; i < N; ++i) {
            cout << " " << get<3>(objetos[i]);
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