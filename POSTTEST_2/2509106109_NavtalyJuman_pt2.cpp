#include <iostream>
#include <string>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    int harga;
};

int jumlah = 0;

void tampilData(Hewan *p) {
    if (jumlah == 0) {
        cout << "Data kosong!\n";
        return;
    }

    cout << "\n=== DATA HEWAN ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "ID     : " << (p+i)->id << endl;
        cout << "Nama   : " << (p+i)->nama << endl;
        cout << "Jenis  : " << (p+i)->jenis << endl;
        cout << "Harga  : " << (p+i)->harga << endl;
        cout << "----------------------\n";
    }
}

void tambahData(Hewan *p) {
    cout << "\nTambah Data Hewan\n";
    cout << "ID     : "; cin >> (p+jumlah)->id;
    cin.ignore();
    cout << "Nama   : "; getline(cin, (p+jumlah)->nama);
    cout << "Jenis  : "; getline(cin, (p+jumlah)->jenis);
    cout << "Harga  : "; cin >> (p+jumlah)->harga;

    jumlah++;
}

void linearSearch(Hewan *p, string cari) {
    bool found = false;

    for (int i = 0; i < jumlah; i++) {
        if ((p+i)->nama == cari) {
            cout << "\nData ditemukan:\n";
            cout << "ID    : " << (p+i)->id << endl;
            cout << "Nama  : " << (p+i)->nama << endl;
            cout << "Jenis : " << (p+i)->jenis << endl;
            cout << "Harga : " << (p+i)->harga << endl;
            found = true;
        }
    }

    if (!found) cout << "Data tidak ditemukan!\n";
}

int fibonacciSearch(Hewan *p, int x) {
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < jumlah) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    cout << "\nProses Fibonacci Search:\n";

    while (fibM > 1) {
        int i = min(offset + fibMMm2, jumlah - 1);

        cout << "Cek index ke-" << i << endl;

        if ((p+i)->id < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if ((p+i)->id > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else {
            return i;
        }
    }

    if (fibMMm1 && (p+offset+1)->id == x)
        return offset + 1;

    return -1;
}

void swap(Hewan *a, Hewan *b) {
    Hewan temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Hewan *p) {
    for (int i = 0; i < jumlah-1; i++) {
        for (int j = 0; j < jumlah-i-1; j++) {
            if ((p+j)->nama > (p+j+1)->nama) {
                swap(p+j, p+j+1);
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan nama!\n";
}

void selectionSort(Hewan *p) {
    for (int i = 0; i < jumlah-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < jumlah; j++) {
            if ((p+j)->harga < (p+minIdx)->harga) {
                minIdx = j;
            }
        }
        swap(p+i, p+minIdx);
    }
    cout << "Data berhasil diurutkan berdasarkan harga!\n";
}

int main() {
    Hewan data[100];
    Hewan *ptr = data;

    int pilihan;
    do {
        cout << "\n=== PAWCARE PETSHOP ===\n";
        cout << "1. Tampil Data\n";
        cout << "2. Tambah Data\n";
        cout << "3. Cari Nama\n";
        cout << "4. Cari ID\n";
        cout << "5. Sort Nama\n";
        cout << "6. Sort Harga\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            tampilData(ptr);
        }
        else if (pilihan == 2) {
            tambahData(ptr);
        }
        else if (pilihan == 3) {
            string cari;
            cin.ignore();
            cout << "Masukkan nama: ";
            getline(cin, cari);
            linearSearch(ptr, cari);
        }
        else if (pilihan == 4) {
            int id;
            cout << "Masukkan ID: ";
            cin >> id;

            int hasil = fibonacciSearch(ptr, id);
            if (hasil != -1) {
                cout << "\nData ditemukan:\n";
                cout << "Nama: " << (ptr+hasil)->nama << endl;
            } else {
                cout << "Data tidak ditemukan!\n";
            }
        }
        else if (pilihan == 5) {
            bubbleSort(ptr);
        }
        else if (pilihan == 6) {
            selectionSort(ptr);
        }

    } while (pilihan != 0);

    return 0;
}