#include <iostream>
#define max 5
using namespace std;

struct dealer_motor {
    string nama_barang, kategori;
    int stok, harga;
} dealer[max];

int F = -1, R = -1;

void enqueue() {
    if (R < max - 1) {
        R = R + 1;
        cin.sync();
        cout << "\n- - - Input - - -" << endl;
        cout << "Nama Barang = ";
        getline(cin, dealer[R].nama_barang);
        cout << "Kategori = ";
        getline(cin, dealer[R].kategori);
        cout << "Stok = ";
        cin >> dealer[R].stok;
        cout << "Harga satuan = ";
        cin >> dealer[R].harga;
        cout << endl;
    } else if (R >= max - 1) {
        cout << "\nData penuh\n\n";
    }
}

void dequeue() {
    if (F < R) {
        F++;
        cout << "\n- - - Data Out - - -\n";
        cout << "Nama Barang = " << dealer[F].nama_barang << endl;
        cout << "Kategori = " << dealer[F].kategori << endl;
        cout << "Stok = " << dealer[F].stok << endl;
        cout << "Harga satuan = " << dealer[F].harga << endl << endl;
    } else {
        cout << "\nData kosong\n\n";
    }
}

void print() {
    if (F >= R) {
        cout << "\nData kosong\n\n";
    } else {
        cout << "\n- - - Isi Queue - - -\n";
        for (int i = F + 1; i <= R; i++) {
            cout << "Nama barang = " << dealer[i].nama_barang << endl;
            cout << "Kategori = " << dealer[i].kategori << endl;
            cout << "Jumlah stok = " << dealer[i].stok << endl;
            cout << "Harga satuan = " << dealer[i].harga << endl;
            cout << "- - - - - - - - - -\n";
        }
    }
}

int main() {
    int option;
    do {
        cout << "1. Tambah data" << endl;
        cout << "2. Hapus data" << endl;
        cout << "3. Tampilkan data" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan pilihan = ";
        cin>>option;
        switch (option) {
            case 1: enqueue();
                break;
            case 2: dequeue();
                break;
            case 3: print();
        }
    } while (option != 4);
}
