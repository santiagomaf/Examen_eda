#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

using namespace std;

void bucketSort(vector<int>& A, int M) {
    // Step 1: Create M buckets
    vector<vector<int>> buckets(M + 1);

    // Step 2: Distribute elements into buckets
    for (int num : A) {
        buckets[num].push_back(num); // Place each number in the appropriate bucket
    }

    // Step 3: Combine elements from the buckets back into the array
    vector<int> Aaux(A.size());
    int k = 0; // Index for Aaux
    for (int i = 0; i <= M; ++i) {
        if (!buckets[i].empty()) { // If bucket[i] is not empty
            for (int b : buckets[i]) {
                Aaux[k++] = b;
            }
        }
    }

    // Copy sorted elements back to the original array
    A = Aaux;
}

int main() {
    // Example usage
    vector<int> A = {4, 2, 2, 8, 3, 3, 1};
    int M = 8; // Maximum value in the array

    cout << "Original Array: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    // Perform bucket sort
    bucketSort(A, M);

    cout << "Sorted Array: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
