#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Hewan {
    int id;
    string nama;
    string jenis;
    int harga;
};

Hewan daftarHewan[MAX];
int jumlah = 0;

Hewan antrian[MAX];
int front = 0, rear = -1;

Hewan riwayat[MAX];
int top = -1;

void tambahData(Hewan *p) {
    if (jumlah >= MAX) {
        cout << "Data penuh!\n";
        return;
    }

    cout << "\nTambah Data Hewan\n";
    cout << "ID     : "; cin >> (p+jumlah)->id;
    cin.ignore();

    cout << "Nama   : "; getline(cin, (p+jumlah)->nama);
    cout << "Jenis  : "; getline(cin, (p+jumlah)->jenis);
    cout << "Harga  : "; cin >> (p+jumlah)->harga;
    jumlah++;
}

void tampilData(Hewan *p) {
    if (jumlah == 0) {
        cout << "Data kosong!\n";
        return;
    }

    cout << "\n=== DATA HEWAN ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << (p+i)->id << " - " << (p+i)->nama << endl;
    }
}

void linearSearch(Hewan *p, string cari) {
    bool found = false;

    for (int i = 0; i < jumlah; i++) {
        if ((p+i)->nama == cari) {
            cout << "Ditemukan: " << (p+i)->nama << endl;
            found = true;
        }
    }

    if (!found) cout << "Tidak ditemukan\n";
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
    cout << "Sort nama berhasil\n";
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
    cout << "Sort harga berhasil\n";
}

// ================= QUEUE =================
void enqueue(Hewan h) {
    if (rear == MAX-1) {
        cout << "Antrian penuh (Overflow)\n";
        return;
    }
    antrian[++rear] = h;
    cout << "Masuk antrian: " << h.nama << endl;
}

Hewan dequeue() {
    Hewan kosong;
    kosong.id = -1;

    if (front > rear) {
        cout << "Antrian kosong (Underflow)\n";
        return kosong;
    }

    return antrian[front++];
}

void tampilAntrian(Hewan *p) {
    if (front > rear) {
        cout << "Antrian kosong\n";
        return;
    }

    cout << "\n=== ANTRIAN ===\n";
    for (Hewan *i = p+front; i <= p+rear; i++) {
        cout << i->id << " - " << i->nama << endl;
    }
}

void push(Hewan h) {
    if (top == MAX-1) {
        cout << "Stack penuh (Overflow)\n";
        return;
    }
    riwayat[++top] = h;
}

void pop() {
    if (top == -1) {
        cout << "Riwayat kosong (Underflow)\n";
        return;
    }
    cout << "Hapus: " << riwayat[top].nama << endl;
    top--;
}

void tampilRiwayat(Hewan *p) {
    if (top == -1) {
        cout << "Riwayat kosong\n";
        return;
    }

    cout << "\n=== RIWAYAT ===\n";
    for (Hewan *i = p+top; i >= p; i--) {
        cout << i->id << " - " << i->nama << endl;
    }
}

void peek() {
    if (front <= rear)
        cout << "Antrian depan: " << antrian[front].nama << endl;
    else
        cout << "Antrian kosong\n";

    if (top != -1)
        cout << "Riwayat terakhir: " << riwayat[top].nama << endl;
    else
        cout << "Riwayat kosong\n";
}

int main() {
    int pilih;
    do {
        cout << "\n=== PAWCARE PETSHOP ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampil Data\n";
        cout << "3. Cari Nama\n";
        cout << "4. Sort Nama\n";
        cout << "5. Sort Harga\n";
        cout << "6. Masuk Antrian\n";
        cout << "7. Panggil Pasien\n";
        cout << "8. Tampil Antrian\n";
        cout << "9. Tampil Riwayat\n";
        cout << "10. Pop Riwayat\n";
        cout << "11. Peek\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) tambahData(daftarHewan);
        else if (pilih == 2) tampilData(daftarHewan);
        else if (pilih == 3) {
            string cari;
            cin.ignore();
            cout << "Nama: ";
            getline(cin, cari);
            linearSearch(daftarHewan, cari);
        }
        else if (pilih == 4) bubbleSort(daftarHewan);
        else if (pilih == 5) selectionSort(daftarHewan);
        else if (pilih == 6) {
            int idx;
            cout << "Index hewan: ";
            cin >> idx;

            if (idx >= 0 && idx < jumlah)
                enqueue(daftarHewan[idx]);
            else
                cout << "Index tidak valid!\n";
        }
        else if (pilih == 7) {
            Hewan h = dequeue();
            if (h.id != -1) {
                cout << "Dipanggil: " << h.nama << endl;
                push(h);
            }
        }
        else if (pilih == 8) tampilAntrian(antrian);
        else if (pilih == 9) tampilRiwayat(riwayat);
        else if (pilih == 10) pop();
        else if (pilih == 11) peek();

    } while (pilih != 0);
    return 0;
}