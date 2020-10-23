#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct user {
    string nama_user, password;
} user[2];

struct node_barang {
    string nama_barang;
    int harga_barang;
    node_barang *next;
} barang;

void insert_barang(node_barang *simpul) {
    cout << "\nInsert Barang\n";
    cin.sync();
    cout << "Nama barang = ";
    getline(cin, barang.nama_barang);
    cout << "Harga barang = ";
    cin >> barang.harga_barang;
    node_barang *baru;
    baru = new (node_barang);
    baru->nama_barang = barang.nama_barang;
    baru->harga_barang = barang.harga_barang;
    baru->next = simpul->next;
    simpul->next = baru;
}

void update_barang(node_barang *simpul) {
    if (simpul->next == NULL) {
        cout << "\nData kosong\n";
    } else {
        node_barang *cari;
        string n;
        int ketemu = 1;
        cout << "Nama barang yang ingin diupdate : ";
        cin.sync();
        getline(cin, n);
        cari = simpul->next;
        while (cari->nama_barang != n && ketemu == 1) {
            if (cari->next == NULL) {
                cout << "\nData tidak ditemukan\n\n";
                ketemu = 0;
            } else {
                cari = cari->next;
            }
        }
        if (ketemu == 1) {
            cout << "\nData yang akan diupdate\n";
            cout << "Nama barang : " << cari->nama_barang << endl;
            cout << "Harga satuan barang : " << cari->harga_barang << endl;
            cout << "\nData diupdate menjadi\n";
            cin.sync();
            cout << "Nama barang : ";
            getline(cin, cari->nama_barang);
            cout << "Harga barang : ";
            cin >> cari->harga_barang;
        }
    }
}

void delete_barang(node_barang *simpul) {
    if (simpul->next == NULL) {
        cout << "\nData kosong\n";
    } else {
        node_barang *hapus, *temu;
        string n;
        bool ketemu = true;
        cout << "Nama barang yang ingin dihapus : ";
        cin.sync();
        getline(cin, n);
        hapus = simpul->next;
        temu = simpul->next;
        while (temu->nama_barang != n && ketemu == true) {
            if (temu->next == NULL) {
                cout << "\nData tidak ada\n";
                ketemu = false;
            } else {
                temu = temu->next;
            }
        }
        //untuk data hanya 1 dan data paling depan
        if (simpul->next->nama_barang == n && ketemu == true) {
            simpul->next = simpul->next->next;
            cout << "\nData berhasil dihapus\n";
        } else {
            if (ketemu == true) {
                while (hapus->next->nama_barang != n) {
                    hapus = hapus->next;
                }
                hapus->next = hapus->next->next;
                cout << "\nData berhasil dihapus\n";
            }
        }
    }
}

void view_barang(node_barang *simpul) {
    if (simpul->next == NULL) {
        cout << "\nData kosong\n";
    }
    node_barang *cetak;
    cetak = simpul->next;
    if (simpul->next != NULL) {
        cout << "\nDaftar Semua Barang\n";
    }
    while (cetak != NULL) {
        cout << "= = = = = = = = =\n";
        cout << "Nama barang : " << cetak->nama_barang << endl;
        cout << "Harga satuan barang : " << cetak->harga_barang << endl;
        cetak = cetak->next;
    }
}

void login(node_barang *simpul) {
    node_barang *cek_barang;
    int pilihan_admin, ketemu;
    char pilihan_kasir, pilihan_barang;
    string namauser, pass;
    user[0].nama_user = "admin";
    user[0].password = "admin";
    user[1].nama_user = "kasir";
    user[1].password = "kasir";

    do {
        system("cls");
        cout << "= = = Program Kasir = = =" << endl;
        cout << "Silahkan Login" << endl;
        cin.sync();
        cout << "Nama : ";
        getline(cin, namauser);
        cout << "Password : ";
        getline(cin, pass);
        ketemu = 0;
        for (int i = 0; i < 2; i++) {
            if (namauser == user[i].nama_user && pass == user[i].password && namauser == "admin") {
                ketemu = 1;
                do {
                    cout << "\n===========\n";
                    cout << "Menu Admin\n";
                    cout << "===========\n";
                    cout << "1. Insert" << endl;
                    cout << "2. Update" << endl;
                    cout << "3. Delete" << endl;
                    cout << "4. View" << endl;
                    cout << "5. Logout" << endl;
                    cout << "Pilih menu nomor : ";
                    cin>>pilihan_admin;
                    switch (pilihan_admin) {
                        case 1:
                            insert_barang(simpul);
                            break;
                        case 2:
                            update_barang(simpul);
                            break;
                        case 3:
                            delete_barang(simpul);
                            break;
                        case 4:
                            view_barang(simpul);
                            break;
                        case 5:
                            cout << "\nAnda berhasil logout\n\n";
                    }
                } while (pilihan_admin != 5);
            } else if (namauser == user[i].nama_user && pass == user[i].password && namauser == "kasir") {
                ketemu = 1;
                do {
                    string namabarang;
                    int temu, total_harga, total_belanja, jumlah_barang, bayar, kembalian;
                    total_belanja = 0;
                    cout << "\n===========\n";
                    cout << "Menu Kasir\n";
                    cout << "===========\n";
                    do {
                        total_harga = 0;
                        temu = 1;
                        cout << "Pembelian\n";
                        cout << "===========\n";
                        cout << "Nama barang : ";
                        cin>>namabarang;
                        cout << "Jumlah barang : ";
                        cin>>jumlah_barang;
                        cek_barang = simpul->next;
                        while (cek_barang->nama_barang != namabarang && temu == 1) {
                            if (cek_barang->next == NULL) {
                                cout << "\nBarang tidak ada\n\n";
                                temu = 0;
                            } else {
                                cek_barang = cek_barang->next;
                            }
                        }
                        if (temu == 1) {
                            total_harga = total_harga + (cek_barang->harga_barang * jumlah_barang);
                            total_belanja = total_belanja + total_harga;
                            cout << "Harga barang : " << cek_barang->harga_barang << endl;
                            cout << "Total harga : " << total_harga << endl;
                        }
                        cout << "\nTambah barang (y/t) ? ";
                        cin>>pilihan_barang;
                    } while (pilihan_barang == 'y');

                    cout << "Total belanja : " << total_belanja << endl;
                    cout << "Bayar berapa : ";
                    cin>>bayar;
                    kembalian = bayar - total_belanja;
                    cout << "Kembali: " << kembalian << endl;
                    cout << "Logout (y/t) ? ";
                    cin>>pilihan_kasir;
                    cout << endl;
                } while (pilihan_kasir != 'y');
            } else if (i == 1 && ketemu == 0) {
                cout << "\nNama dan password user salah\n\n";
                cout << "Tekan Enter untuk login kembali\n";
                getch();
            }
        }
    } while (pilihan_admin == 5 || pilihan_kasir == 'y' || ketemu == 0);
}

int main() {
    node_barang simpul;
    simpul.next = NULL;
    login(&simpul);
}
