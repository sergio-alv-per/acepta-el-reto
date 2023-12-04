#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

ll suma_digitos_multiplos_3_de_1_a_n(ll n);
ll suma_digitos_multiplos_3_mas_1_de_1_a_n(ll n);
ll suma_digitos_multiplos_3_mas_2_de_1_a_n(ll n);

// Vector de cache de las sumas de los dígitos de los números desde 1 hasta 9, 99, 999... En general
// el elemento d denota la suma de los dígitos de los números desde 1 hasta 10^d - 1
vector<ll> sumas_1 = {0, 45, 900, 13500, 180000, 2250000, 27000000, 315000000, 3600000000, 40500000000, 450000000000, 4950000000000, 54000000000000, 585000000000000, 6300000000000000};

// Vector que contiene tres vectores. El primero es similar al anterior, pero solo tiene en cuenta
// los número múltiplos de 3 (0, 3, 6, 9, 12, ...). El segundo tiene en cuenta solo los números
// múltiplos de 3 más uno (1, 4, 7, 10, 13, ...). El último tiene en cuenta lo análogo para los
// múltiplos de 3 más dos.
// Experimentalmente se tiene que sumas_3[1][d] = sumas_3[0][d] - 6*d y sumas_3[2][d] = sumas_3[0][d] - 3*d
// sumas_3[0] se calcula en sí a partir de la fórmula dada en https://www.geeksforgeeks.org/count-sum-of-digits-in-numbers-from-1-to-n/
// haciendo modificaciones pertientes y aplicando propiedades.
vector<vector<ll>> sumas_3 = {
{0, 18, 306, 4509, 60012, 750015, 9000018, 105000021, 1200000024, 13500000027, 150000000030, 1650000000033, 18000000000036, 195000000000039, 2100000000000042, 22500000000000045},
{0, 12, 294, 4491, 59988, 749985, 8999982, 104999979, 1199999976, 13499999973, 149999999970, 1649999999967, 17999999999964, 194999999999961, 2099999999999958, 22499999999999955},
{0, 15, 300, 4500, 60000, 750000, 9000000, 105000000, 1200000000, 13500000000, 150000000000, 1650000000000, 18000000000000, 195000000000000, 2100000000000000, 22500000000000000}
};

// Vector en el que el elemento d representa el número 10^d. Es un orden de magnitud más rápido que calcularlo con pow o con strings
vector<ll> diez_elevado_d = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000, 1000000000000000};
// Vector en el que el elemento d representa el entero concatenando d '3'
vector<ll> d_treses = {0, 3, 33, 333, 3333, 33333, 333333, 3333333, 33333333, 333333333, 3333333333, 33333333333, 333333333333, 3333333333333, 33333333333333, 333333333333333};


vector<vector<ll>> terminos_1 = {
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 18, 306, 4509, 60012, 750015, 9000018, 105000021, 1200000024, 13500000027, 150000000030, 1650000000033, 18000000000036, 195000000000039, 2100000000000042, 22500000000000045},
{0, 36, 639, 9342, 123345, 1533348, 18333351, 213333354, 2433333357, 27333333360, 303333333363, 3333333333366, 36333333333369, 393333333333372, 4233333333333375, 45333333333333378},
{0, 54, 999, 14499, 189999, 2349999, 27999999, 324999999, 3699999999, 41499999999, 459999999999, 5049999999999, 54999999999999, 594999999999999, 6399999999999999, 68499999999999999},
{0, 84, 1407, 20010, 260013, 3200016, 38000019, 440000022, 5000000025, 56000000028, 620000000031, 6800000000034, 74000000000037, 800000000000040, 8600000000000043, 92000000000000046},
{0, 111, 1839, 25842, 333345, 4083348, 48333351, 558333354, 6333333357, 70833333360, 783333333363, 8583333333366, 93333333333369, 1008333333333372, 10833333333333375, 115833333333333378},
{0, 138, 2298, 31998, 409998, 4999998, 58999998, 679999998, 7699999998, 85999999998, 949999999998, 10399999999998, 112999999999998, 1219999999999998, 13099999999999998, 139999999999999998},
{0, 180, 2808, 38511, 490014, 5950017, 70000020, 805000023, 9100000026, 101500000029, 1120000000032, 12250000000035, 133000000000038, 1435000000000041, 15400000000000044, 164500000000000047},
{0, 216, 3339, 45342, 573345, 6933348, 81333351, 933333354, 10533333357, 117333333360, 1293333333363, 14133333333366, 153333333333369, 1653333333333372, 17733333333333375, 189333333333333378},
{0, 252, 3897, 52497, 659997, 7949997, 92999997, 1064999997, 11999999997, 133499999997, 1469999999997, 16049999999997, 173999999999997, 1874999999999997, 20099999999999997, 214499999999999997}
};

// Calcula a módulo b, asignando el valor del módulo positivo (entre 0 y b-1) a los números negativos
// Ejemplo: (-4)%3 == -1. posmod(-4, 3) == 2.
ll posmod(ll a, ll b) {
    return (b + (a)%b)%b;
}

// Suma por fuerza bruta de los dígitos de los números de 1 hasta n
ll suma_digitos(ll n) {
    ll suma = 0;

    while (n > 9) {
        suma += n%10;
        n = n/10;
    }

    return suma + n;
}

ll calcular_termino_1(ll msd, ll d) {
    ll term_1 = 0;

    for (ll i = 1; i <= msd; i++) {
        if (posmod(-(i-1), 3) == 0) {
            term_1 += (i-1)*(d_treses[d] + 1);
        } else {
            term_1 += (i-1)*(d_treses[d]);
        }

        term_1 += sumas_3[posmod(1-i, 3)][d];
    }

    return term_1;
}

// Suma de los dígitos de los múltiplos de 3 desde 1 hasta n.
// Basado en el algoritmo expuesto en https://www.geeksforgeeks.org/count-sum-of-digits-in-numbers-from-1-to-n/
// Yo creo que este algoritmo es de orden logarítmico, es recursivo pero en cada recursión se divide el problema /10
ll suma_digitos_multiplos_3_de_1_a_n(ll n) {
    // Podemos tomar n como el mayor múltiplo de 3 menor o igual que n sin afectar al resultado.
    n = n - n%3;

    string str_num = to_string(n);

    // d es el número de dígitos de n menos 1
    ll d = str_num.length() - 1;

    // msd es el dígito más significativo
    ll msd = stoll(str_num.substr(0, 1));

    // Para n < 100 se hace por fuerza bruta, caso base de la recursión
    if (n < 100) {
        ll suma = 0;
        for (ll i = 0; i <= n; i++) {
            if (i%3 == 0) {
                suma += suma_digitos(i);
            }
        }
        return suma;
    }

    // Si n >= 100, la suma se compondrá de dos términos

    ll term_1, term_2;

    // El término 1 supone la suma de los múltiplos de 3 desde 1 hasta msd*10^d -1.
    // Por ejemplo, para 357 sería la suma hasta 299.
    // La idea es que esta suma se puede calcular fácilmente a partir del número de
    // múltiplos de 3 que hay en cada rango [0, 99], [100, 199], [200, 299]...
    // y a partir de la suma de los múltiplos de 3, 3 más 1 o 3 más 2 en esos intervalos.
    // Se itera por cada número hasta el msd. En cada iteración calcularemos la suma para uno
    // de los intervalos. Por ejemplo, para 357, calcularemos la suma hasta 299:
    // i = 1: suma de los dígitos de los múltiplos de 3 desde 0 a 99
    // Este valor se tiene de la cache y se suma directamente.
    // i = 2: suma de los dígitos de los múltiplos de 3 desde 100 a 199
    // Sabemos que estos mútlplos serán 102, 105, 108, ...
    // Si no tenemos en cuenta las decenas, se tendrá que son múltplos de 3 menos 1
    // o equivalentemente más 2 si se tiene en cuenta 0%3 == 0. También se tiene en
    // la cache el valor de la suma de los dígitos de todos los múltiplos de 3 más 2.
    // Además, tenemos que sumarle la influencia de las centenas. Tendremos que sumar 1
    // por cada uno de los múltiplos de 3 entre 100 y 199. Por el mismo razonamiento que
    // antes, el número de múltiplos de 3 entre 100 y 199 es el número de múltiplos de
    // 3 más 2 entre 0 y 99. Se intuye que este valor mantiene una relación con un tercio
    // de la longitud del intervalo, y será 33. Por tanto para i = 2 sumaremos 1*33 + sumas_3[2][2]
    // i = 3 es análogo a lo que se ha visto hasta ahora, suma entre 200 y 299. En este caso los
    // múltiplos de 3 serán 201, 204, 207, ... múltiplos de 3 más 1. Habrá que sumar la suma de
    // los múltiplos de 3 más 1 de 1 a 99 y 2 por el número de múltiplos de 3 más 1 de 1 a 99.
    term_1 = terminos_1[msd][d];

    // El término 2 supone la suma de los dígitos de los múltiplos de 3 desde msd*10^d
    // hasta n. Lo primero es sumar el msd tantas veces como múltiplos de 3 haya en ese
    // intervalo. Para obtener el número de múltiplos de 3 de msd*10^d a n primero se obtiene
    // la parte "no msd" del número, es decir, obtener el resto al dividir entre 10^d.
    // Por ejemplo para 357 sería 357%100 = 57.
    // Utilizando el mismo mecanismo de antes, el número de múltiplos se obtendrá por el
    // número de múltiplos de 3 (más 1 o más 2) entre 1 y n%10^d. El ajuste en función
    // del msd se hace con la parte "+ 3 - posmod(-msd, 3)", y al dividir entre 3 se obtiene
    // el número de múltiplos que corresponde.
    // Por otro lado, además del impacto del msd se calcula el impacto de los múltiplos trasladándolos
    // al 1 ... n%10^d igual que se hizo antes. Aquí entra la parte recursiva.

    term_2 = msd*(n%(diez_elevado_d[d]) + 3 - posmod(-msd, 3))/3;

    if (posmod(-msd, 3) == 0) {
        term_2 += suma_digitos_multiplos_3_de_1_a_n(n%(diez_elevado_d[d]));
    } else if (posmod(-msd, 3) == 1) {
        term_2 += suma_digitos_multiplos_3_mas_1_de_1_a_n(n%(diez_elevado_d[d]));
    } else {
        term_2 += suma_digitos_multiplos_3_mas_2_de_1_a_n(n%(diez_elevado_d[d]));
    }

    return term_1 + term_2;
}


// Obtiene la suma de los múltiplos de 3 más 1 desde 1 hasta n.
ll suma_digitos_multiplos_3_mas_1_de_1_a_n(ll n) {
    
    // Para valores menores que 10 se calcula por fuerza bruta
    if (n < 10) {
        ll suma = 0;
        for (ll i = 0; i <= n; i++) {
            if (i%3 == 1) {
                suma += suma_digitos(i);
            }
        }
        return suma;
    } else {
        // Se transforma n en el mayor múltiplo de 3 más 1 menor que n. Esto no altera el resultado
        n = n - (n-1)%3;


        // Para obtener esta suma se aplican muchas propiedades. Principalmente, la propiedad matemática
        // de que, si S es la función que suma los dígitos de un número:
        //              S(a+b)=S(a)+S(b)−9c(a,b)
        // Siendo c(a,b) el número de acarreos que se producen al sumar a y b.
        // Fuente: https://www.math.hkust.edu.hk/excalibur/v22_n3.pdf

        // La suma de los dígitos de los múltiplos de 3 más 1 hasta n se puede expresar como
        // suma(S(k+1) con k múltiplos de 3 hasta n)
        // Aplicando la propiedad anterior esto es igual a
        // suma(S(k) + S(1) - 9c(k,1) con k múltiplos de 3 hasta n)
        // Desglosando la suma, se tiene:
        // suma(S(k) con k múltiplos de 3 hasta n)
        // + suma(1 tantas veces como múltiplos de 3 hasta n)
        // -9*suma(c(k,1) con k múltiplos de 3 hasta n)
        // El número de múltiplos de 3 hasta n se calcula fácilmente
        // Falta ver el número de acarreos que se producen. Se ve claramente que
        // solo se produce un acarreo al sumar 1 si el último dígito es 9. Sin embargo,
        // si los últimos dos dígitos son 99, se producen 2 acarreos, y así sucesivamente.
        // Por tanto para contar los acarreos se debe sumar 1 por cada mult. de 3 acabado en _9 (_ distinto de 9)
        // 2 por cada mult. de 3 acabado en _99
        // 3 por cada mult. de 3 acabado en _999
        // sucesivamente hasta 15, que es el límite del problema.
        // esto equivale a sumar
        // 1 por cada mult. de 3 acabado en _9 (sea _ 9 o no)
        // 1 por cada mult. de 3 acabado en _99
        // 1 por cada mult. de 3 acabado en _999
        // etc.

        // Este es un problema de conteo. Se puede intuir que un múltiplo de 9 acabado en 3
        // aparecerá cada 30 unidades (9, 39, 69, 99...)
        // Para los acabados en 99 será cada 300 unidades (99, 399, 699, ...)
        // Se obtiene la siguiente fórmula empíricamente:
        ll acarreos = 0;
        for (int d = 1; d <= 15; d++) {
            acarreos += (n + 2*(diez_elevado_d[d]) + 1)/(3*(diez_elevado_d[d]));
        }

        return suma_digitos_multiplos_3_de_1_a_n(n) + (n+3)/3 - 9*acarreos;
    }
}

ll suma_digitos_multiplos_3_mas_2_de_1_a_n(ll n) {
    // Este caso es completamente análogo al anterior.
    if (n < 10) {
        ll suma = 0;
        for (ll i = 0; i <= n; i++) {
            if (i%3 == 2) {
                suma += suma_digitos(i);
            }
        }
        return suma;
    } else {
        n = n - (n-2)%3;

        ll acarreos = 0;
        for (int d = 1; d <= 15; d++) {
            acarreos += (n + 2*(diez_elevado_d[d]) + 1)/(3*(diez_elevado_d[d]));
            acarreos += (n + diez_elevado_d[d] + 2)/(3*(diez_elevado_d[d]));
        }

        return suma_digitos_multiplos_3_de_1_a_n(n) + 2*((n+3)/3) - 9*acarreos;
    }
}


bool casoDePrueba() {

    ll a, b;

    cin >> a >> b;
    if (a == 0 && b == 0)
        return false;
    else {
        cout << suma_digitos_multiplos_3_de_1_a_n(b) - suma_digitos_multiplos_3_de_1_a_n(a-1) << "\n";
        return true;
     }

} // casoDePrueba

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(casoDePrueba()) {}
    
    return 0;
}