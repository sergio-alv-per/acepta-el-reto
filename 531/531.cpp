#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

bool casoDePrueba() {

    int rep_test, rep_mal, hum_test, hum_mal, tot_hum, tot_rep;
    cin >> rep_test >> rep_mal >> hum_test >> hum_mal >> tot_hum >> tot_rep;
    if (!cin)
        return false;
    else {

        double tasa_replicantes_retirados = 1 - ((double)rep_mal / rep_test);
        double tasa_humanos_retirados = (double)hum_mal / hum_test;

        double tasa_humanos_retirados_total = (tot_hum * tasa_humanos_retirados) / (tot_hum * tasa_humanos_retirados + tot_rep * tasa_replicantes_retirados);

        if (hum_mal == 0 || tasa_humanos_retirados_total <= 0.1) {
            cout << "APRUEBA\n";
        } else {
            cout << "SUSPENDE\n";
        }
        
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