#include <iostream>
using namespace std;

void reverseArray(int* arr, int n) {
    int* start = arr;
    int* end = arr + n - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() {
    int A[7] = {2, 3, 5, 7, 11, 13, 17};

    cout << "Array sebelum dibalik:\n";
    for (int w = 0; w < 7; w++) {
        cout << A[w] << " ";
    }

    cout << "\n\nAlamat memori tiap elemen:\n";
    for (int w = 0; w < 7; w++) {
        cout << "A[" << w << "] = " << (A + w) << endl;
    }

    reverseArray(A, 7);

    cout << "\nArray setelah dibalik:\n";
    for (int w = 0; w < 7; w++) {
        cout << A[w] << " ";
    }

    return 0;
}