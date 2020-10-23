#include <iostream>
#define max 5
using namespace std;

struct dealer_motor {
    string nama_barang, kategori;
    int stok, harga;
} dealer[max];

int top = -1;

void push() {
    if (top < max - 1) {
        top = top + 1;
        cin.sync();
        cout << "\n- - - Input - - -" << endl;
        cout << "Nama barang = ";
        getline(cin, dealer[top].nama_barang);
        cout << "Kategori = ";
        getline(cin, dealer[top].kategori);
        cout << "Jumlah stok = ";
        cin >> dealer[top].stok;
        cout << "Harga satuan = ";
        cin >> dealer[top].harga;
        cout << endl;
    } else if (top >= max - 1) {
        cout << "\n- - - Data sudah penuh - - -" << endl << endl;
    }
}

void pop() {
    if (top>-1) {
        cout << "\n- - - Data Out - - -" << endl;
        cout << "Nama barang = " << dealer[top].nama_barang << endl;
        cout << "Kategori = " << dealer[top].kategori << endl;
        cout << "Jumlah stok = " << dealer[top].stok << endl;
        cout << "Harga satuan = " << dealer[top].harga << endl << endl;
        top--;
    } else if (top == -1) {
        cout << "\n- - - Data kosong - - -" << endl << endl;
    }
}

void print() {
    if (top>-1) {
        cout << "\n- - - Isi Stack - - -\n";
        for (int i = top; i>-1; i--) {
            cout << "Nama barang = " << dealer[i].nama_barang << endl;
            cout << "Kategori = " << dealer[i].kategori << endl;
            cout << "Jumlah stok = " << dealer[i].stok << endl;
            cout << "Harga satuan = " << dealer[i].harga << endl << endl;
        }
    } else if (top == -1) {
        cout << "\n- - - Data kosong - - -" << endl << endl;
    }
}

int main() {
    int pilihan;
    do {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Tampilkan semua data" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan pilihan = ";
        cin>>pilihan;
        switch (pilihan) {
            case 1: push();
                break;

            case 2: pop();
                break;

            case 3: print();
        }
    } while (pilihan != 4);
}
