#include <iostream>

using namespace std;

struct pelanggan {
    string id[10], nama_pelanggan[10];
};

struct menu {
    string nama_makan[10], nama_minum[10];
    int hargamakan[10], hargaminum[10];
};

struct transaksi {
    pelanggan p;
    menu m;
} t;

int main() {
    int i = 0;
    int pilihan;
    do {
        cout << "1. Input Data" << endl;
        cout << "2. View Data" << endl;
        cout << "Pilih menu = ";
        cin>>pilihan;

        switch (pilihan) {
            case 1:
                cin.sync();
                cout << "- - Input - -" << endl;
                cout << "ID pelanggan = ";
                std::getline(std::cin, t.p.id[i]);
                cout << "Nama pelanggan = ";
                std::getline(std::cin, t.p.nama_pelanggan[i]);
                cout << "Makanan = ";
                std::getline(std::cin, t.m.nama_makan[i]);
                cout << "Minuman = ";
                std::getline(std::cin, t.m.nama_minum[i]);
                cout << "Harga makanan = ";
                cin >> t.m.hargamakan[i];
                cout << "Harga minuman = ";
                cin >> t.m.hargaminum[i];
                cout << endl;
                i++;
                break;

            case 2:
                if (i == 0) {
                    cout << "\nData masih kosong\n\n";
                } else {
                    cout << "\n- - Data yang telah dimasukkan - -";
                    for (int a = 0; a < i; a++) {
                        cout << "\nID Pelanggan = " << t.p.id[a];
                        cout << "\nNama pelanggan = " << t.p.nama_pelanggan[a];
                        cout << "\nMakanan = " << t.m.nama_makan[a];
                        cout << "\nMinuman = " << t.m.nama_minum[a];
                        cout << "\nHarga makanan = Rp. " << t.m.hargamakan[a];
                        cout << "\nHarga minuman = Rp. " << t.m.hargaminum[a];
                        cout << endl << endl;
                    }
                }
        }
    } while (pilihan == 1 || pilihan == 2);
}
