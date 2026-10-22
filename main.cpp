#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "Algoritmos.hpp"

// Función auxiliar para imprimir vectores pequeños
template <typename T>
void imprimirVector(const std::vector<T>& v) {
    std::cout << "[ ";
    for (const auto& elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "]\n";
}

int main() {
    // ------------------------------------------------------------------------
    // PRUEBA 1: Validación básica con el ejemplo de la diapositiva
    // ------------------------------------------------------------------------
    std::cout << "=== PRUEBA 1: QuickSort con enteros (Ejemplo diapositiva) ===\n";
    std::vector<int> datosEjemplo = {9, -4, 3, 6, 1, 5};
    
    std::cout << "Original: ";
    imprimirVector(datosEjemplo);

    quickSort(datosEjemplo, 0, datosEjemplo.size() - 1);

    std::cout << "Ordenado: ";
    imprimirVector(datosEjemplo);

    // Búsqueda binaria sobre el vector ordenado
    int buscado = 3;
    int pos = busquedaBinaria(buscado, datosEjemplo, 0, datosEjemplo.size() - 1);
    if (pos != -1) {
        std::cout << "Elemento " << buscado << " encontrado en la posición: " << pos << "\n";
    } else {
        std::cout << "Elemento " << buscado << " no encontrado.\n";
    }

    // ------------------------------------------------------------------------
    // PRUEBA 2: Programación genérica (template) con cadenas (std::string)
    // ------------------------------------------------------------------------
    std::cout << "\n=== PRUEBA 2: QuickSort y Búsqueda con cadenas (std::string) ===\n";
    std::vector<std::string> palabras = {"pera", "manzana", "naranja", "platano", "kiwi"};
    
    std::cout << "Original: ";
    imprimirVector(palabras);

    quickSort(palabras, 0, palabras.size() - 1);

    std::cout << "Ordenado: ";
    imprimirVector(palabras);

    std::string frutaBuscada = "manzana";
    int posFruta = busquedaBinaria(frutaBuscada, palabras, 0, palabras.size() - 1);
    std::cout << "La fruta '" << frutaBuscada << "' esta en el indice: " << posFruta << "\n";

    // ------------------------------------------------------------------------
    // PRUEBA 3: Medición de tiempos con <chrono> sobre un volumen grande
    // ------------------------------------------------------------------------
    std::cout << "\n=== PRUEBA 3: Medición de tiempos (<chrono>) ===\n";
    const int N = 100000; // 100.000 elementos aleatorios
    std::vector<int> vectorGrande(N);

    std::srand(std::time(nullptr));
    for (int i = 0; i < N; ++i) {
        vectorGrande[i] = std::rand();
    }

    std::cout << "Ordenando vector aleatorio de " << N << " elementos con QuickSort...\n";

    // Medición del tiempo de QuickSort
    auto t1 = std::chrono::high_resolution_clock::now();
    quickSort(vectorGrande, 0, vectorGrande.size() - 1);
    auto t2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> tiempoQuickSort = t2 - t1;
    std::cout << "Tiempo de QuickSort: " << tiempoQuickSort.count() << " ms\n";

    // Medición del tiempo de Búsqueda Binaria
    int target = vectorGrande[N / 2]; // Buscamos un elemento existente
    auto t3 = std::chrono::high_resolution_clock::now();
    int idx = busquedaBinaria(target, vectorGrande, 0, vectorGrande.size() - 1);
    auto t4 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::nano> tiempoBusqueda = t4 - t3;
    std::cout << "Elemento " << target << " encontrado en índice " << idx << "\n";
    std::cout << "Tiempo de Búsqueda Binaria: " << tiempoBusqueda.count() << " ns\n";

    return 0;
}
