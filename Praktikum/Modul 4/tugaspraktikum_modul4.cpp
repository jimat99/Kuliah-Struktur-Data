#include <iostream>

using namespace std;

struct data_pelamar {
    string nama_pelamar, pendidikan_terakhir;
    int umur, tahun_lulus;
} pelamar[10];

void selection_sort(int input) {
    cout << "\n- - - Data sebelum diurutkan - - -\n";
    for (int i = 0; i < input; i++) {
        cout << "Nama pelamar = " << pelamar[i].nama_pelamar << endl;
        cout << "Umur = " << pelamar[i].umur << endl;
        cout << "Tahun kelulusan = " << pelamar[i].tahun_lulus << endl;
        cout << "Pendidikan terakhir = " << pelamar[i].pendidikan_terakhir << endl;
        cout << "- - - - - - - - - - - -" << endl;
    }
    int index, kecil, kecil3;
    string kecil2, kecil4;
    for (int i = 0; i < input; i++) {
        kecil = pelamar[i].tahun_lulus;
        kecil2 = pelamar[i].nama_pelamar;
        kecil3 = pelamar[i].umur;
        kecil4 = pelamar[i].pendidikan_terakhir;
        index = i;
        for (int j = i + 1; j < input; j++) {
            if (kecil > pelamar[j].tahun_lulus) {
                kecil = pelamar[j].tahun_lulus;
                kecil2 = pelamar[j].nama_pelamar;
                kecil3 = pelamar[j].umur;
                kecil4 = pelamar[j].pendidikan_terakhir;
                index = j;
            }
        }
        pelamar[index].tahun_lulus = pelamar[i].tahun_lulus;
        pelamar[index].nama_pelamar = pelamar[i].nama_pelamar;
        pelamar[index].umur = pelamar[i].umur;
        pelamar[index].pendidikan_terakhir = pelamar[i].pendidikan_terakhir;
        pelamar[i].tahun_lulus = kecil;
        pelamar[i].nama_pelamar = kecil2;
        pelamar[i].umur = kecil3;
        pelamar[i].pendidikan_terakhir = kecil4;
    }
    cout << "\n- - - Hasil selection sort berdasarkan tahun kelulusan - - -\n";
    for (int i = 0; i < input; i++) {
        cout << "Nama pelamar = " << pelamar[i].nama_pelamar << endl;
        cout << "Umur = " << pelamar[i].umur << endl;
        cout << "Tahun kelulusan = " << pelamar[i].tahun_lulus << endl;
        cout << "Pendidikan terakhir = " << pelamar[i].pendidikan_terakhir << endl;
        cout << "- - - - - - - - - - - -" << endl;
    }
    cout << endl;
}

void sequential_search(int input) {
    string cari;
    int ketemu = 0;
    cin.sync();
    cout << "\nNama pelamar yang dicari = ";
    getline(cin, cari);
    for (int i = 0; i <= input; i++) {
        if (pelamar[i].nama_pelamar == cari) {
            cout << "Data " << pelamar[i].nama_pelamar << " ditemukan pada indeks ke-" << i << "\n\n";
            ketemu = 1;

        } else if (i == input && ketemu == 0) {
            cout << "Data tidak ditemukan\n\n";
        }
    }
}

int main() {
    int pilihan, i = 0;
    do {
        cout << "1. Input data" << endl;
        cout << "2. Selection sort" << endl;
        cout << "3. Sequential search" << endl;
        cout << "4. Keluar" << endl;
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

            case 2: selection_sort(i);
                break;

            case 3: sequential_search(i);
        }
    } while (pilihan != 4);
}
