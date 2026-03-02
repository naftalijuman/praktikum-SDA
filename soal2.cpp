#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    const int Juml4h = 5;
    Mahasiswa mhs[Juml4h]; 
    
    for (int i = 0; i < Juml4h; i++) {
        cout << "\nMahasiswa ke-" << (i+1) << ":" << endl;
        cout << "Nama: ";
        cin >> mhs[i].nama;
        cout << "NIM: ";
        cin >> mhs[i].nim;
        cout << "IPK: ";
        cin >> mhs[i].ipk;
    }
    
    int idxTertinggi = 0;
    float maxIPK = mhs[0].ipk;
    
    for (int i = 1; i < Juml4h; i++) {
        if (mhs[i].ipk > maxIPK) {
            maxIPK = mhs[i].ipk;
            idxTertinggi = i;
        }
    }
    
    cout << "=== Mahasiswa dengan IPK Tertinggi ===" << endl;
    cout << "Nama : " << mhs[idxTertinggi].nama << endl;
    cout << "NIM  : " << mhs[idxTertinggi].nim << endl;
    cout << "IPK  : " << mhs[idxTertinggi].ipk << endl;
    
    return 0;
}