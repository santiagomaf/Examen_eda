#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm> // Para std::binary_search y sort

// Función de búsqueda secuencial
int sequentialSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i;  // Retorna la posición del valor encontrado
        }
    }
    return -1;  // Si no se encuentra el valor
}

// Función de búsqueda binaria
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;  // El valor está en la posición mid
        if (arr[mid] < target)
            left = mid + 1;  // El valor está en la mitad derecha
        else
            right = mid - 1;  // El valor está en la mitad izquierda
    }
    return -1;  // Si no se encuentra el valor
}

int main() {
    // Creamos un arreglo grande de ejemplo
    std::vector<int> arr(1000000);
    for (int i = 0; i < 1000000; ++i) {
        arr[i] = i + 1;  // Llenamos el arreglo con valores 1, 2, 3, ..., 1000000
    }

    int target = 500000;  // El valor a buscar

    // Medir tiempo de búsqueda secuencial
    auto start = std::chrono::high_resolution_clock::now();
    int resultSeq = sequentialSearch(arr, target);
    auto end = std::chrono::high_resolution_clock::now();
    auto durationSeq = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // Medir tiempo de búsqueda binaria
    // El arreglo debe estar ordenado para la búsqueda binaria
    start = std::chrono::high_resolution_clock::now();
    int resultBin = binarySearch(arr, target);
    end = std::chrono::high_resolution_clock::now();
    auto durationBin = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    // Imprimir los resultados
    std::cout << "Búsqueda Secuencial: ";
    if (resultSeq != -1) {
        std::cout << "Elemento encontrado en la posición " << resultSeq;
    } else {
        std::cout << "Elemento no encontrado.";
    }
    std::cout << "\nTiempo de ejecución: " << durationSeq.count() << " microsegundos\n";

    std::cout << "Búsqueda Binaria: ";
    if (resultBin != -1) {
        std::cout << "Elemento encontrado en la posición " << resultBin;
    } else {
        std::cout << "Elemento no encontrado.";
    }
    std::cout << "\nTiempo de ejecución: " << durationBin.count() << " microsegundos\n";

    return 0;
}
