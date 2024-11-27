#include <iostream>
#include <vector>
#include <algorithm> // Para std::max_element

// Obtener el dígito en la posición dada
int getDigit(int number, int position) {
    return (number / position) % 10;
}

// Radix Sort usando Bucket Sort
void radixSort(std::vector<int>& arr) {
    int maxElement = *std::max_element(arr.begin(), arr.end()); // Encontrar el valor máximo
    int position = 1;

    while (maxElement / position > 0) {
        // Crear buckets para cada dígito (0-9)
        std::vector<std::vector<int>> buckets(10);

        // Distribuir los números en los buckets
        for (int num : arr) {
            int digit = getDigit(num, position);
            buckets[digit].push_back(num);
        }

        // Reconstruir el arreglo desde los buckets
        int index = 0;
        for (const auto& bucket : buckets) {
            for (int num : bucket) {
                arr[index++] = num;
            }
        }

        // Moverse al siguiente dígito
        position *= 10;
    }
}

// Programa principal
int main() {
    std::vector<int> arr = {3, 2, 492, 108};
    std::cout << "Arreglo original: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    radixSort(arr);

    std::cout << "Arreglo ordenado: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
// g++ -o radix radix.cpp
// ./radix