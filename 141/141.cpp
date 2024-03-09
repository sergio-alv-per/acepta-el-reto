#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

bool casoDePrueba()
{

    string linea;

    getline(cin, linea);

    if (!cin)
        return false;
    else
    {

        vector<char> pila;

        for (char c : linea) {
            switch (c) {
            case '(':
                pila.push_back(')');
                break;
            case ')':
                if (pila.empty() || pila.back() != ')') {
                    cout << "NO\n";
                    return true;
                } else {
                    pila.pop_back();
                }
                break;
            case '[':
                pila.push_back(']');
                break;
            case ']':
                if (pila.empty() || pila.back() != ']') {
                    cout << "NO\n";
                    return true;
                } else {
                    pila.pop_back();
                }
                break;
            case '{':
                pila.push_back('}');
                break;
            case '}':
                if (pila.empty() || pila.back() != '}') {
                    cout << "NO\n";
                    return true;
                } else {
                    pila.pop_back();
                }
                break;
            default:
                break;
            }
        }

        if (pila.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

        return true;
    }

} // casoDePrueba

int main()
{
    while (casoDePrueba()){}

    return 0;
}