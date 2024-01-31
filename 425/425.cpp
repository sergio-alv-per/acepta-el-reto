#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

int mip(vector<vector<int>> &cache, string palabra, size_t i, size_t j) {
    // Minimo de Inserciones para Palíndromo
    if (i >= j) {
        return 0;
    } else if (cache[i][j] != -1) {
        return cache[i][j];
    } else if (palabra[i] == palabra[j]) {
        cache[i][j] = mip(cache, palabra, i+1, j-1);
        return cache[i][j];
    } else {
        cache[i][j] = 1 + min(mip(cache, palabra, i+1, j), mip(cache, palabra, i, j-1));
        return cache[i][j];
    }
}

bool casoDePrueba() {
    string palabra;

    cin >> palabra;
    if (!cin)
        return false;
    else {
        if (palabra.size() == 1) {
            cout << "0\n";
            return true;
        }
        
        vector<vector<int>> cache(palabra.size(), vector<int>(palabra.size(), -1));

        for (size_t offset = 1; offset < palabra.size(); offset++) {
            for (size_t i = 0; i < palabra.size() - offset; i++) {
                size_t j = i + offset;
                mip(cache, palabra, i, j);                
            }
        }

        cout << cache[0][palabra.size()-1] << "\n";
        
        return true;
    }

} // casoDePrueba

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(casoDePrueba()) {}
  
    return 0;
}