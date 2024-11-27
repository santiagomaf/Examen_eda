#include <iostream>
#include <vector>
using namespace std;

// Función para combinar dos subarreglos ordenados
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Tamaño del subarreglo izquierdo
    int n2 = right - mid;    // Tamaño del subarreglo derecho

    // Crear subarreglos temporales
    vector<int> L(n1), R(n2);

    // Copiar datos a los subarreglos
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[mid + 1 + i];

    // Indices iniciales de subarreglos y arreglo combinado
    int i = 0, j = 0, k = left;

    // Combinar los subarreglos en orden
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función principal de Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordenar la primera y segunda mitad
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Combinar las mitades ordenadas
        merge(arr, left, mid, right);
    }
}

// Función para probar Merge Sort
int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    cout << "Arreglo original: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Arreglo ordenado: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}


// g++ -o mergesort mergesort.cpp
// ./mergesort