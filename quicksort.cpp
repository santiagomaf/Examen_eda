#include <iostream>
#include <vector>
#include <cstdlib> // Para srand() y rand()
#include <ctime>   // Para time()

using namespace std;

// Función para generar un índice aleatorio dentro de un rango
int random(int i, int j) {
    return i + rand() % (j - i + 1);
}

// Función de partición con pivote aleatorio
int split(vector<int>& arr, int i, int j) {
    int p = random(i, j);    // Selección del pivote aleatorio
    int pivot = arr[p];

    while (i < j) {
        // Mover el índice i hacia adelante hasta encontrar un elemento mayor al pivote
        while (i < p && arr[i] <= pivot) {
            i++;
        }

        // Mover el índice j hacia atrás hasta encontrar un elemento menor al pivote
        while (j > p && arr[j] >= pivot) {
            j--;
        }

        // Intercambiar si los índices no se cruzan
        if (i < j) {
            swap(arr[i], arr[j]);
        }

        // Actualizar la posición del pivote si i o j lo alcanza
        if (i == p) {
            p = j;
        } else if (j == p) {
            p = i;
        }
    }
    return p;
}

// Función recursiva de Quicksort
void quicksort(vector<int>& arr, int i, int j) {
    if (i < j) {
        int pivotIndex = split(arr, i, j);

        // Ordenar recursivamente las partes izquierda y derecha
        quicksort(arr, i, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, j);
    }
}

// Función principal para probar Quicksort
int main() {
    // Inicializar la semilla para números aleatorios
    srand(static_cast<unsigned int>(time(0)));

    // Ejemplo de arreglo a ordenar
    vector<int> arr = {10, 80, 30, 90, 40, 50, 70};

    cout << "Arreglo original: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Llamada a Quicksort
    quicksort(arr, 0, arr.size() - 1);

    cout << "Arreglo ordenado: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
// g++ -o quicksort quicksort.cpp
// ./quicksort