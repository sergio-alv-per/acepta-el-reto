#include <bits/stdc++.h>

using namespace std;

bool casoDePrueba() {
    int peso_maximo, n_usuarios;

    cin >> peso_maximo >> n_usuarios;

    if (peso_maximo == 0 && n_usuarios == 0)
        return false;
    else {

        vector<int> usuarios;

        for (int i = 0; i < n_usuarios; i++) {
            int usr;
            cin >> usr;
            usuarios.push_back(usr);
        }
        
        sort(usuarios.begin(), usuarios.end());

        auto begin = usuarios.begin();
        int sillas = 0;

        for (auto usr = usuarios.rbegin(); usr != usuarios.rend(); ++usr) {
            if (begin == usr.base()) {
                sillas++;
                break;
            }
            
            if (*begin + *usr <= peso_maximo) {
                begin++;
            }
            sillas++;

            if (begin == usr.base()) {
                break;
            }
        }


        cout << sillas << "\n";

        return true;
     }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}