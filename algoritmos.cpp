#ifndef ALGORITMOS_HPP
#define ALGORITMOS_HPP

#include <vector>
#include <utility> // Para std::swap

// ==========================================
// 1. BÚSQUEDA BINARIA (Divide y Vencerás)
// ==========================================
template <typename T>
int busquedaBinaria(const T& x, const std::vector<T>& v, int ini, int fin) {
    // Si ini > fin, el elemento no se encuentra en el vector
    if (ini > fin) {
        return -1; // -1 indica "No se encuentra en el array"
    }

    int medio = (ini + fin) / 2;

    if (v[medio] == x) {
        return medio; // Elemento encontrado
    } else if (v[medio] > x) {
        // Buscar recursivamente en la porción inicial
        return busquedaBinaria(x, v, ini, medio - 1);
    } else {
        // Buscar recursivamente en la porción final
        return busquedaBinaria(x, v, medio + 1, fin);
    }
}

// ==========================================
// 2. QUICKSORT (Divide y Vencerás)
// ==========================================

// Función de partición según el pseudocódigo
template <typename T>
int partition(std::vector<T>& v, int ini, int fin) {
    T x = v[fin]; // Se toma el último elemento como pivote
    int i = ini;

    for (int j = ini; j < fin; ++j) {
        if (v[j] <= x) {
            std::swap(v[i], v[j]);
            i = i + 1;
        }
    }
    std::swap(v[i], v[fin]);
    return i;
}

// Algoritmo recursivo QuickSort
template <typename T>
void quickSort(std::vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int pivot = partition(v, ini, fin);
        quickSort(v, ini, pivot - 1); // Sub-vector izquierdo
        quickSort(v, pivot + 1, fin); // Sub-vector derecho
    }
}

#endif // ALGORITMOS_HPP
