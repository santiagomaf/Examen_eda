#include <iostream>
#include <vector>
using namespace std;

// Función de ordenación por inserción
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int ele = arr[i];
        int j = i - 1;

        // Mover elementos mayores que 'ele' una posición hacia adelante
        while (j >= 0 && ele < arr[j]) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Insertar 'ele' en su posición correcta
        arr[j + 1] = ele;
    }
}

// Función principal para probar el algoritmo
int main() {
    vector<int> arr = {9, 5, 1, 4, 3};
    cout << "Arreglo original: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    insertionSort(arr);

    cout << "Arreglo ordenado: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


// g++ -o insertion insertion_sort.cpp
// ./insertion