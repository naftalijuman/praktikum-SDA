#include <iostream>
#include <string>
using namespace std;

struct Hewan {
    int id;
    string nama;
    string jenis;
    int harga;
    Hewan* next;
};

Hewan* head = NULL;
Hewan* front = NULL;
Hewan* rear = NULL;
Hewan* top = NULL;

void tambahData() {
    Hewan* baru = new Hewan;

    cout << "\nTambah Data Hewan\n";
    cout << "ID     : "; cin >> baru->id;
    cin.ignore();
    cout << "Nama   : "; getline(cin, baru->nama);
    cout << "Jenis  : "; getline(cin, baru->jenis);
    cout << "Harga  : "; cin >> baru->harga;

    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Hewan* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void tampilData() {
    if (head == NULL) {
        cout << "Data kosong!\n";
        return;
    }

    Hewan* temp = head;
    while (temp != NULL) {
        cout << temp->id << " - " << temp->nama << endl;
        temp = temp->next;
    }
}

void enqueue(Hewan* h) {
    Hewan* baru = new Hewan;
    *baru = *h;
    baru->next = NULL;

    if (rear == NULL) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }

    cout << "Masuk antrian: " << baru->nama << endl;
}

void dequeue() {
    if (front == NULL) {
        cout << "Antrian kosong\n";
        return;
    }

    Hewan* temp = front;
    cout << "Dipanggil: " << temp->nama << endl;

    front = front->next;
    if (front == NULL) rear = NULL;

    delete temp;
}

void tampilAntrian() {
    if (front == NULL) {
        cout << "Antrian kosong\n";
        return;
    }

    Hewan* temp = front;
    cout << "\n=== ANTRIAN ===\n";
    while (temp != NULL) {
        cout << temp->id << " - " << temp->nama << endl;
        temp = temp->next;
    }
}

void push(Hewan* h) {
    Hewan* baru = new Hewan;
    *baru = *h;

    baru->next = top;
    top = baru;
}

void pop() {
    if (top == NULL) {
        cout << "Riwayat kosong\n";
        return;
    }

    Hewan* temp = top;
    cout << "Hapus: " << temp->nama << endl;

    top = top->next;
    delete temp;
}

void tampilRiwayat() {
    if (top == NULL) {
        cout << "Riwayat kosong\n";
        return;
    }

    Hewan* temp = top;
    cout << "\n=== RIWAYAT ===\n";
    while (temp != NULL) {
        cout << temp->id << " - " << temp->nama << endl;
        temp = temp->next;
    }
}

void peek() {
    if (front != NULL)
        cout << "Antrian depan: " << front->nama << endl;
    else
        cout << "Antrian kosong\n";

    if (top != NULL)
        cout << "Riwayat terakhir: " << top->nama << endl;
    else
        cout << "Riwayat kosong\n";
}

int main() {
    int pilih;

    do {
        cout << "\n=== PAWCARE PETSHOP ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampil Data\n";
        cout << "3. Masuk Antrian\n";
        cout << "4. Panggil Pasien\n";
        cout << "5. Tampil Antrian\n";
        cout << "6. Tampil Riwayat\n";
        cout << "7. Pop Riwayat\n";
        cout << "8. Peek\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) tambahData();
        else if (pilih == 2) tampilData();
        else if (pilih == 3) {
            int id;
            cout << "Masukkan ID hewan: ";
            cin >> id;

            Hewan* temp = head;
            while (temp != NULL) {
                if (temp->id == id) {
                    enqueue(temp);
                    break;
                }
                temp = temp->next;
            }

            if (temp == NULL) cout << "Data tidak ditemukan\n";
        }
        else if (pilih == 4) dequeue();
        else if (pilih == 5) tampilAntrian();
        else if (pilih == 6) tampilRiwayat();
        else if (pilih == 7) pop();
        else if (pilih == 8) peek();

    } while (pilih != 0);

    return 0;
}