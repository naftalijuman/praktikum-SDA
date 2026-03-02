#include <iostream>
using namespace std;

int FindMin(int A[], int s, int &indexMin) {
    int min = A[0];
    indexMin = 0;

    for (int k = 1; k < s; k++) {
        if (A[k] < min) {
            min = A[k];
            indexMin = k;
        }
    }
    return min;
}

int main() {
    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int indexMin;

    int minimum = FindMin(A, 8, indexMin);
    cout << "Nilai minimum: " << minimum << endl;
    cout << "Indeks minimum: " << indexMin << endl;

    return 0;
}