#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> cache_factores = {{1},
{1},
{1},
{1, 2},
{1},
{1, 2, 3},
{1},
{1, 2, 4},
{1, 3},
{1, 2, 5},
{1},
{1, 2, 3, 4, 6},
{1},
{1, 2, 7},
{1, 3, 5},
{1, 2, 4, 8},
{1},
{1, 2, 3, 6, 9},
{1},
{1, 2, 4, 5, 10},
{1, 3, 7},
{1, 2, 11},
{1},
{1, 2, 3, 4, 6, 8, 12},
{1, 5},
{1, 2, 13},
{1, 3, 9},
{1, 2, 4, 7, 14},
{1},
{1, 2, 3, 5, 6, 10, 15},
{1},
{1, 2, 4, 8, 16},
{1, 3, 11},
{1, 2, 17},
{1, 5, 7},
{1, 2, 3, 4, 6, 9, 12, 18},
{1},
{1, 2, 19},
{1, 3, 13},
{1, 2, 4, 5, 8, 10, 20},
{1},
{1, 2, 3, 6, 7, 14, 21},
{1},
{1, 2, 4, 11, 22},
{1, 3, 5, 9, 15},
{1, 2, 23},
{1},
{1, 2, 3, 4, 6, 8, 12, 16, 24},
{1, 7},
{1, 2, 5, 10, 25},
{1, 3, 17},
{1, 2, 4, 13, 26},
{1},
{1, 2, 3, 6, 9, 18, 27},
{1, 5, 11},
{1, 2, 4, 7, 8, 14, 28},
{1, 3, 19},
{1, 2, 29},
{1},
{1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30},
{1},
{1, 2, 31},
{1, 3, 7, 9, 21},
{1, 2, 4, 8, 16, 32},
{1, 5, 13},
{1, 2, 3, 6, 11, 22, 33},
{1},
{1, 2, 4, 17, 34},
{1, 3, 23},
{1, 2, 5, 7, 10, 14, 35},
{1},
{1, 2, 3, 4, 6, 8, 9, 12, 18, 24, 36},
{1},
{1, 2, 37},
{1, 3, 5, 15, 25},
{1, 2, 4, 19, 38},
{1, 7, 11},
{1, 2, 3, 6, 13, 26, 39},
{1},
{1, 2, 4, 5, 8, 10, 16, 20, 40},
{1, 3, 9, 27},
{1, 2, 41},
{1},
{1, 2, 3, 4, 6, 7, 12, 14, 21, 28, 42},
{1, 5, 17},
{1, 2, 43},
{1, 3, 29},
{1, 2, 4, 8, 11, 22, 44},
{1},
{1, 2, 3, 5, 6, 9, 10, 15, 18, 30, 45},
{1, 7, 13},
{1, 2, 4, 23, 46},
{1, 3, 31},
{1, 2, 47},
{1, 5, 19},
{1, 2, 3, 4, 6, 8, 12, 16, 24, 32, 48},
{1},
{1, 2, 7, 14, 49},
{1, 3, 9, 11, 33},
{1, 2, 4, 5, 10, 20, 25, 50},
{1},
{1, 2, 3, 6, 17, 34, 51},
{1},
{1, 2, 4, 8, 13, 26, 52},
{1, 3, 5, 7, 15, 21, 35},
{1, 2, 53},
{1},
{1, 2, 3, 4, 6, 9, 12, 18, 27, 36, 54},
{1},
{1, 2, 5, 10, 11, 22, 55},
{1, 3, 37},
{1, 2, 4, 7, 8, 14, 16, 28, 56},
{1},
{1, 2, 3, 6, 19, 38, 57},
{1, 5, 23},
{1, 2, 4, 29, 58},
{1, 3, 9, 13, 39},
{1, 2, 59},
{1, 7, 17},
{1, 2, 3, 4, 5, 6, 8, 10, 12, 15, 20, 24, 30, 40, 60},
{1, 11},
{1, 2, 61},
{1, 3, 41},
{1, 2, 4, 31, 62},
{1, 5, 25},
{1, 2, 3, 6, 7, 9, 14, 18, 21, 42, 63},
{1},
{1, 2, 4, 8, 16, 32, 64},
{1, 3, 43},
{1, 2, 5, 10, 13, 26, 65},
{1},
{1, 2, 3, 4, 6, 11, 12, 22, 33, 44, 66},
{1, 7, 19},
{1, 2, 67},
{1, 3, 5, 9, 15, 27, 45},
{1, 2, 4, 8, 17, 34, 68},
{1},
{1, 2, 3, 6, 23, 46, 69},
{1},
{1, 2, 4, 5, 7, 10, 14, 20, 28, 35, 70},
{1, 3, 47},
{1, 2, 71},
{1, 11, 13},
{1, 2, 3, 4, 6, 8, 9, 12, 16, 18, 24, 36, 48, 72},
{1, 5, 29},
{1, 2, 73},
{1, 3, 7, 21, 49},
{1, 2, 4, 37, 74},
{1},
{1, 2, 3, 5, 6, 10, 15, 25, 30, 50, 75},
{1},
{1, 2, 4, 8, 19, 38, 76},
{1, 3, 9, 17, 51},
{1, 2, 7, 11, 14, 22, 77},
{1, 5, 31},
{1, 2, 3, 4, 6, 12, 13, 26, 39, 52, 78},
{1},
{1, 2, 79},
{1, 3, 53},
{1, 2, 4, 5, 8, 10, 16, 20, 32, 40, 80},
{1, 7, 23},
{1, 2, 3, 6, 9, 18, 27, 54, 81},
{1},
{1, 2, 4, 41, 82},
{1, 3, 5, 11, 15, 33, 55},
{1, 2, 83},
{1},
{1, 2, 3, 4, 6, 7, 8, 12, 14, 21, 24, 28, 42, 56, 84},
{1, 13},
{1, 2, 5, 10, 17, 34, 85},
{1, 3, 9, 19, 57},
{1, 2, 4, 43, 86},
{1},
{1, 2, 3, 6, 29, 58, 87},
{1, 5, 7, 25, 35},
{1, 2, 4, 8, 11, 16, 22, 44, 88},
{1, 3, 59},
{1, 2, 89},
{1},
{1, 2, 3, 4, 5, 6, 9, 10, 12, 15, 18, 20, 30, 36, 45, 60, 90},
{1},
{1, 2, 7, 13, 14, 26, 91},
{1, 3, 61},
{1, 2, 4, 8, 23, 46, 92},
{1, 5, 37},
{1, 2, 3, 6, 31, 62, 93},
{1, 11, 17},
{1, 2, 4, 47, 94},
{1, 3, 7, 9, 21, 27, 63},
{1, 2, 5, 10, 19, 38, 95},
{1},
{1, 2, 3, 4, 6, 8, 12, 16, 24, 32, 48, 64, 96},
{1},
{1, 2, 97},
{1, 3, 5, 13, 15, 39, 65},
{1, 2, 4, 7, 14, 28, 49, 98},
{1},
{1, 2, 3, 6, 9, 11, 18, 22, 33, 66, 99},
{1},
{1, 2, 4, 5, 8, 10, 20, 25, 40, 50, 100},
};

bool casoDePrueba() {

    string frase;

    cin >> frase;

    if (!cin)
        return false;
    else {
        for (int factor : cache_factores[frase.length()-1]) {
            bool funciona = true;
            for (unsigned int i = factor; i < frase.length(); i++) {
                if (tolower(frase[i]) != tolower(frase[i%factor])) {
                    funciona = false;
                    break;
                }
            }

            if (funciona) {
                cout << factor << "\n";
                return true;
            }
        }

        cout << frase.length() << "\n";
        
        return true;
    }

} // casoDePrueba

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(casoDePrueba()) {}
  
    return 0;
}