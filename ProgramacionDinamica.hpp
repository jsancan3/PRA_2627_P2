#ifndef PROGRAMACION_DINAMICA_HPP
#define PROGRAMACION_DINAMICA_HPP

#include <vector>
#include <algorithm>
#include <limits>

// Constante para representar valor infinito/inalcanzable
const int INF = std::numeric_limits<int>::max();

/**
 * 1. CAMBIO DE MONEDAS
 * Entradas:
 *  - m: Vector de enteros con los valores de cada moneda.
 *  - d: Valor entero con el valor a devolver.
 * Salidas:
 *  - s: Vector de enteros con la cantidad devuelta de cada tipo de moneda (parámetro por referencia).
 *  Devuelve: El número mínimo de monedas necesarias.
 */
int monedas(const std::vector<int>& m, int d, std::vector<int>& s) {
    int n = m.size();
    s.assign(n, 0); // Inicializar vector de solución a ceros

    if (d == 0) return 0;

    // Crear la tabla T[n][d + 1] e inicializarla
    std::vector<std::vector<int>> T(n, std::vector<int>(d + 1, INF));

    // Caso base: Para cantidad 0, se necesitan 0 monedas
    for (int i = 0; i < n; ++i) {
        T[i][0] = 0;
    }

    // Cálculo de la primera fila (usando solo la moneda m[0])
    for (int j = 1; j <= d; ++j) {
        if (j >= m[0] && T[0][j - m[0]] != INF) {
            T[0][j] = 1 + T[0][j - m[0]];
        }
    }

    // Cálculo del resto de la tabla
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= d; ++j) {
            if (j < m[i] || T[i][j - m[i]] == INF) {
                T[i][j] = T[i - 1][j];
            } else {
                if (T[i - 1][j] != INF) {
                    T[i][j] = std::min(T[i - 1][j], 1 + T[i][j - m[i]]);
                } else {
                    T[i][j] = 1 + T[i][j - m[i]];
                }
            }
        }
    }

    // Recuperar la solución (Backtracking)
    int i = n - 1;
    int j = d;
    while (i >= 0 && j > 0) {
        if (i == 0) {
            if (T[i][j] != INF) {
                s[0] = j / m[0];
            }
            break;
        }
        if (T[i][j] != T[i - 1][j]) {
            s[i]++;
            j -= m[i];
        } else {
            i--;
        }
    }

    return T[n - 1][d];
}

/**
 * 2. PROBLEMA DE LA MOCHILA (0/1 KNAPSACK)
 * Entradas:
 *  - p: Vector con los pesos de cada elemento.
 *  - b: Vector con los beneficios de cada elemento.
 *  - m: Capacidad máxima de la mochila.
 * Salidas:
 *  - s: Vector de enteros indicando si el elemento i se elige (1) o no (0).
 *  Devuelve: El beneficio máximo obtenido.
 */
int mochila(const std::vector<int>& p, const std::vector<int>& b, int m, std::vector<int>& s) {
    int n = p.size();
    s.assign(n, 0); // Inicializar vector de selecciones con 0

    // Tabla de tamaño (n + 1) x (m + 1)
    std::vector<std::vector<int>> g(n + 1, std::vector<int>(m + 1, 0));

    // Llenado de la tabla según la ecuación en recurrencia
    for (int i = 1; i <= n; ++i) {
        for (int c = 1; c <= m; ++c) {
            if (p[i - 1] > c) {
                g[i][c] = g[i - 1][c];
            } else {
                g[i][c] = std::max(g[i - 1][c], g[i - 1][c - p[i - 1]] + b[i - 1]);
            }
        }
    }

    // Reconstrucción de la solución óptima
    int c = m;
    for (int i = n; i > 0; --i) {
        if (g[i][c] != g[i - 1][c]) {
            s[i - 1] = 1;  // El elemento fue seleccionado
            c -= p[i - 1]; // Reducir la capacidad restante
        } else {
            s[i - 1] = 0;  // El elemento no fue seleccionado
        }
    }

    return g[n][m];
}

#endif // PROGRAMACION_DINAMICA_HPP
