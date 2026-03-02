#include <iostream>
using namespace std;

void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int j, m;

    cout << "Masukkan nilai j: ";
    cin >> j;
    cout << "Masukkan nilai m: ";
    cin >> m;

    cout << "\nSebelum ditukar:\n";
    cout << "j = " << j << ", m = " << m << endl;

    tukar(j, m);

    cout << "\nSetelah ditukar:\n";
    cout << "j = " << j << ", m = " << m << endl;

    return 0;
}