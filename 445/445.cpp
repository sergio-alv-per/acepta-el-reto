#include <bits/stdc++.h>

using namespace std;

bool casoDePrueba() {

    // leer el inicio del caso de prueba (cin)
    int N;

    cin >> N;

    if (!cin)
        return false;
    else {
        vector<pair<int, int>> actividades;

        for (int i = 0; i < N; ++i) {
            int inicio, fin;
            cin >> inicio >> fin;
            actividades.push_back(make_pair(inicio, fin));
        }

        sort(actividades.begin(), actividades.end());

        priority_queue<int, vector<int>, greater<int>> actividades_activas;
        size_t minimo_personas = 1;

        for (auto actividad : actividades) {
            while (!actividades_activas.empty() && actividad.first >= actividades_activas.top()) {
                actividades_activas.pop();
            }

            actividades_activas.push(actividad.second);

            minimo_personas = max(minimo_personas, actividades_activas.size());
        }

        cout << minimo_personas-1 << "\n";

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