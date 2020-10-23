#include <iostream>

using namespace std;

struct data_pelamar {
    string nama_pelamar, pendidikan_terakhir;
    int umur, tahun_lulus;
} pelamar[10];

void tampil_data(int input) {
    cout << "\n- - - Isi Data - - -\n";
    for (int i = 0; i < input; i++) {
        cout << "Nama pelamar = " << pelamar[i].nama_pelamar << endl;
        cout << "Umur = " << pelamar[i].umur << endl;
        cout << "Tahun kelulusan = " << pelamar[i].tahun_lulus << endl;
        cout << "Pendidikan terakhir = " << pelamar[i].pendidikan_terakhir << endl;
        cout << "- - - - - - - - - - - -\n";
    }
    cout << endl;
}

void bubble_sort(int input) {
    int kecil, kecil3;
    string kecil2, kecil4;
    for (int a = 0; a < input; a++) {
        for (int i = 0; i < input - (a + 1); i++) {
            if (pelamar[i].nama_pelamar > pelamar[i + 1].nama_pelamar) {
                kecil = pelamar[i].tahun_lulus;
                kecil2 = pelamar[i].nama_pelamar;
                kecil3 = pelamar[i].umur;
                kecil4 = pelamar[i].pendidikan_terakhir;
                pelamar[i].tahun_lulus = pelamar[i + 1].tahun_lulus;
                pelamar[i].nama_pelamar = pelamar[i + 1].nama_pelamar;
                pelamar[i].umur = pelamar[i + 1].umur;
                pelamar[i].pendidikan_terakhir = pelamar[i + 1].pendidikan_terakhir;
                pelamar[i + 1].tahun_lulus = kecil;
                pelamar[i + 1].nama_pelamar = kecil2;
                pelamar[i + 1].umur = kecil3;
                pelamar[i + 1].pendidikan_terakhir = kecil4;
            }
        }
    }
    cout << "\n- - - Hasil bubble sort berdasarkan nama pelamar (Ascending) - - -\n";
    for (int i = 0; i < input; i++) {
        cout << "Nama pelamar = " << pelamar[i].nama_pelamar << endl;
        cout << "Umur = " << pelamar[i].umur << endl;
        cout << "Tahun kelulusan = " << pelamar[i].tahun_lulus << endl;
        cout << "Pendidikan terakhir = " << pelamar[i].pendidikan_terakhir << endl;
        cout << "- - - - - - - - - - - -\n";
    }
    cout << endl;
}

void binary_search(int input) {
    bubble_sort(input);
    int bawah, atas, tengah;
    string cari;
    int ketemu = 0;
    cin.sync();
    cout << "Nama pelamar yang dicari = ";
    getline(cin, cari);
    bawah = 0;
    atas = input - 1;
    for (int i = 0; i < input; i++) {
        if (cari != pelamar[i].nama_pelamar && ketemu == 0) {
            ketemu = 0;
        } else if (cari == pelamar[i].nama_pelamar) {
            ketemu = 1;
        }
    }
    if (ketemu == 0) {
        cout << "\nData tidak ditemukan\n\n";
    }
    while (bawah <= atas && ketemu == 1) {
        tengah = (bawah + atas) / 2;
        if (cari > pelamar[tengah].nama_pelamar) {
            bawah = tengah + 1;
        } else if (cari < pelamar[tengah].nama_pelamar) {
            atas = tengah - 1;
        } else if (cari == pelamar[tengah].nama_pelamar) {
            cout << "\nPelamar dengan nama " << pelamar[tengah].nama_pelamar << " ditemukan pada indeks ke-" << tengah << "\n\n";
            ketemu = 0;
        }
    }
}

int main() {
    int pilihan, i = 0;
    do {
        cout << "1. Input data" << endl;
        cout << "2. Tampilkan data" << endl;
        cout << "3. Bubble sort" << endl;
        cout << "4. Binary search" << endl;
        cout << "5. Keluar" << endl;
        cout << "Piih menu = ";
        cin>>pilihan;
        switch (pilihan) {
            case 1:
                if (i < 10) {
                    cout << "- - - Input - - -\n";
                    cin.sync();
                    cout << "Nama pelamar = ";
                    getline(cin, pelamar[i].nama_pelamar);
                    cout << "Umur = ";
                    cin >> pelamar[i].umur;
                    cout << "Tahun kelulusan = ";
                    cin >> pelamar[i].tahun_lulus;
                    cin.sync();
                    cout << "Pendidikan terakhir = ";
                    getline(cin, pelamar[i].pendidikan_terakhir);
                    cout << endl;
                    i++;
                } else {
                    cout << "\nData penuh\n\n";
                }
                break;

            case 2: tampil_data(i);
                break;

            case 3: bubble_sort(i);
                break;

            case 4: binary_search(i);
        }
    } while (pilihan != 5);
}
