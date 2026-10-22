#include <iostream>
#include <vector>
#include "ProgramacionDinamica.hpp"

int main() {
    std::cout << "===========================================\n";
    std::cout << "  PRÁCTICA: PROGRAMACIÓN DINÁMICA\n";
    std::cout << "===========================================\n\n";

    // -------------------------------------------------------------
    // PRUEBA 1: CAMBIO DE MONEDAS
    // -------------------------------------------------------------
    std::cout << "--- 1. PROBLEMA DEL CAMBIO DE MONEDAS ---\n";
    std::vector<int> m = {1, 4, 6}; // Monedas disponibles (del PDF)
    int d = 8;                     // Cantidad a devolver
    std::vector<int> s_monedas;

    int min_monedas = monedas(m, d, s_monedas);

    std::cout << "Monedas disponibles: {1, 4, 6}\n";
    std::cout << "Cantidad a devolver: " << d << "\n";
    std::cout << "Minimo de monedas devueltas: " << min_monedas << "\n";
    std::cout << "Desglose de monedas utilizadas:\n";
    for (size_t i = 0; i < m.size(); ++i) {
        std::cout << "  Monedas de valor " << m[i] << ": " << s_monedas[i] << "\n";
    }
    std::cout << "\n";

    // -------------------------------------------------------------
    // PRUEBA 2: PROBLEMA DE LA MOCHILA
    // -------------------------------------------------------------
    std::cout << "--- 2. PROBLEMA DE LA MOCHILA ---\n";
    std::vector<int> p = {9, 6, 5};   // Pesos (del PDF)
    std::vector<int> b = {38, 40, 24}; // Beneficios (del PDF)
    int M = 15;                       // Peso máximo
    std::vector<int> s_mochila;

    int beneficio_max = mochila(p, b, M, s_mochila);

    std::cout << "Capacidad de la mochila: " << M << "\n";
    std::cout << "Beneficio maximo alcanzado: " << beneficio_max << "\n";
    std::cout << "Elementos seleccionados (1 = Si, 0 = No):\n";
    for (size_t i = 0; i < p.size(); ++i) {
        std::cout << "  Elemento " << i << " (Peso: " << p[i] 
                  << ", Beneficio: " << b[i] << ") -> Elegido: " 
                  << s_mochila[i] << "\n";
    }

    return 0;
}
