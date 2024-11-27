# Examen EDA

### Algoritmos 
Es cualquier proceso computacional bien definido que toma uno o varios vaores como entrada y genera una o mas salidas, este debe ser preciso, finito y bien definido.

# Notacion Big O 

- Constante: cualquier cosa que no dependa de N como entrada\
```c++
int var = 100*100
```
siempre es igual, esto se ignora, osea es notacion O(1)

- Linear: cuando depende linearmente de N\
```c++
int arr[4] = {1, 2, 3, 4};
for (int i = 0; i < 4; ++i) {
    std::cout << arr[i] << std::endl;
}
```

aca podemos ver que el for actua dependiendo de N, en este caso el arreglo de largo 4 osea podemos decir que es de notacion O(N)

- Cuadratica:
```c++
int arr[4] = {1, 2, 3, 4};
for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; j++){
        std::cout << arr[i] << std::endl;
    }
}
```
En este caso, el primer for depende de N y el segundo for también depende de N, por lo tanto, la notación es O(N^2) ya que es N x N.

- Cubica:
```c++
int arr[4] = {1, 2, 3, 4};
for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
        for (int k = 0; k < 4; ++k) {
            std::cout << arr[i] << std::endl;
        }
    }
}
```
En este caso, el primer for depende de N, el segundo for también depende de N, y el tercer for también depende de N, por lo tanto, la notación es O(N^3) ya que seria N x N x N.

- Logaritmica:

```c++
void Log(int number){
    if (number != 0){
        number = number / 2;
    }
    return number;
}
```
Recordemos que en el computador todo se hace en log<sub>2</sub>(), osea la base siempre es 2, ejemplo si elegimos el numero 8, log<sub>2</sub>(8) = 3, y si vemos el codigo el numero iria así 8 -> 4 -> 2 -> 1, son las mismas catidades de flechas por decirlo que el resultado del logaritmo por lo que podemos decir que esta en notacion O(log(N))

-N log(N): 
```c++
void nlog(int number){
    int n = number;
    while (number > 1){
        number = number/2;
        for (int i = 0; i < n; i++){
            std::cout << i << std::endl;
        }
    }

}
```

aca podemos ver una mezcla de dos algoitmos, el primero un Olog(N) y el segundo un O(N) osea seria N x Log(N) o en otras palabras Nlog(N) que se usa en el caso del radix sort por ejemplo.


## Algoritmos de Ordenación 

Es la ordenación de distintos elementos dentro de una lista 

### Ordenación por selección 
es ir recorriendo el arreglo de entrada y seleccionar el menor de los que faltan por ordenar y es cambiado por el elemento de la posicion actual. 

![image](selection_sort.png)

*codigo en c++*
```cpp
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        // Find the minimum element in the unsorted portion
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted portion
        swap(arr[i], arr[minIndex]);
    }
}
```
Se puede ver aca que entra un arreglo a la función, primero sacamos el largo del arreglo que se definira como *n* luego entramos en el ciclo for que encontrara el valor minimos que usaremos, luego entra a otro for que parte desde el valor minimo en adelante, si encuentra un valor menor cambiala variable minIndex, una vez terminado el segundo for cambia la posicion i osea la primera del minIndex a por el valor menor que encontramos.\
Tambien se puede ver que hay un for dentro de un for por lo que se definira este algoritmo como O(n<sup>2</sup>).
### Inserción

Ocupa la estrategia de ordenacion de barajas. 