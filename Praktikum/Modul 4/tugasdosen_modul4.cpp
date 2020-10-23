#include <iostream>

using namespace std;

struct node {
    string nama_pelamar, pendidikan_terakhir;
    int umur, tahun_lulus;
    node *next, *prev;
} pelamar;

node *head = NULL, *tail = NULL, *baru;

void tambah_depan() {
    baru = new(node);
    baru->nama_pelamar = pelamar.nama_pelamar;
    baru->pendidikan_terakhir = pelamar.pendidikan_terakhir;
    baru->umur = pelamar.umur;
    baru->tahun_lulus = pelamar.tahun_lulus;
    baru->next = NULL;
    baru->prev = NULL;
    if (head == NULL) {
        head = baru;
        tail = baru;
    } else {
        head->prev = baru;
        baru->next = head;
        head = baru;
    }
}

void tambah_belakang() {
    baru = new(node);
    baru->nama_pelamar = pelamar.nama_pelamar;
    baru->pendidikan_terakhir = pelamar.pendidikan_terakhir;
    baru->umur = pelamar.umur;
    baru->tahun_lulus = pelamar.tahun_lulus;
    baru->next = NULL;
    baru->prev = NULL;
    if (head == NULL) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}

void cetak() {
    node *cetak;
    if (head == NULL) {
        cout << "\nData Kosong\n";
    } else {
        cetak = head;
        cout << "\n- - - Isi Data - - -\n";
        while (cetak != NULL) {
            cout << "- - - - - - - - - -" << endl;
            cout << "Nama pelamar = " << cetak->nama_pelamar << endl;
            cout << "Umur = " << cetak->umur << endl;
            cout << "Tahun kelulusan = " << cetak->tahun_lulus << endl;
            cout << "Pendidikan terakhir = " << cetak->pendidikan_terakhir << endl;
            cetak = cetak->next;
        }
    }
    cout << endl;
}

void selection_sort() {
    node *i, *j, *kecil;
    for (i = head; i != NULL && i->next != NULL; i = i->next) {
        kecil = i;
        for (j = i->next; j != NULL && i->next != NULL; j = j->next) {
            if (kecil->tahun_lulus > j->tahun_lulus) {
                kecil = j;
            }
        }
        if (kecil != i) {
            int temp, temp2;
            string temp3, temp4;
            temp = kecil->tahun_lulus;
            temp2 = kecil->umur;
            temp3 = kecil->nama_pelamar;
            temp4 = kecil->pendidikan_terakhir;
            kecil->tahun_lulus = i->tahun_lulus;
            kecil->umur = i->umur;
            kecil->nama_pelamar = i->nama_pelamar;
            kecil->pendidikan_terakhir = i->pendidikan_terakhir;
            i->tahun_lulus = temp;
            i->umur = temp2;
            i->nama_pelamar = temp3;
            i->pendidikan_terakhir = temp4;
        }
    }
    cout << "\nHasil Selection Sort Berdasarkan Tahun Kelulusan";
    cetak();
}

void bubble_sort() {
    node *a, *i;
    int temp, temp2;
    string temp3, temp4;
    for (a = head; a != NULL && a->next != NULL; a = a->next) {
        for (i = head; i != NULL && i->next != NULL; i = i->next) {
            if (i->tahun_lulus > i->next->tahun_lulus) {
                temp = i->tahun_lulus;
                temp2 = i->umur;
                temp3 = i->nama_pelamar;
                temp4 = i->pendidikan_terakhir;
                i->tahun_lulus = i->next->tahun_lulus;
                i->umur = i->next->umur;
                i->nama_pelamar = i->next->nama_pelamar;
                i->pendidikan_terakhir = i->next->pendidikan_terakhir;
                i->next->tahun_lulus = temp;
                i->next->umur = temp2;
                i->next->nama_pelamar = temp3;
                i->next->pendidikan_terakhir = temp4;
            }
        }
    }
    cout << "\nHasil Bubble Sort Berdasarkan Tahun Kelulusan";
    cetak();
}

void sequential_search() {
    node *i;
    string cari;
    int ketemu = 0, a = 1;
    cin.sync();
    cout << "\nNama pelamar yang dicari = ";
    getline(cin, cari);
    for (i = head; i != NULL; i = i->next) {
        if (i->nama_pelamar == cari) {
            cout << "Data " << i->nama_pelamar << " ditemukan pada data ke-" << a << "\n\n";
            ketemu = 1;
        } else if (i->next == NULL && ketemu == 0) {
            cout << "Data tidak ditemukan\n\n";
        }
        a++;
    }
}

int main() {
    int pilihan;
    do {
        cout << "1. Tambah belakang" << endl;
        cout << "2. Tambah depan" << endl;
        cout << "3. Tampilkan data" << endl;
        cout << "4. Selection sort" << endl;
        cout << "5. Bubble sort" << endl;
        cout << "6. Sequential search" << endl;
        cout << "7. Keluar" << endl;
        cout << "Piih menu = ";
        cin>>pilihan;
        switch (pilihan) {
            case 1:
                cout << "- - - Input - - -\n";
                cin.sync();
                cout << "Nama pelamar = ";
                getline(cin, pelamar.nama_pelamar);
                cout << "Umur = ";
                cin >> pelamar.umur;
                cout << "Tahun kelulusan = ";
                cin >> pelamar.tahun_lulus;
                cin.sync();
                cout << "Pendidikan terakhir = ";
                getline(cin, pelamar.pendidikan_terakhir);
                cout << endl;
                tambah_belakang();
                break;

            case 2:
                cout << "- - - Input - - -\n";
                cin.sync();
                cout << "Nama pelamar = ";
                getline(cin, pelamar.nama_pelamar);
                cout << "Umur = ";
                cin >> pelamar.umur;
                cout << "Tahun kelulusan = ";
                cin >> pelamar.tahun_lulus;
                cin.sync();
                cout << "Pendidikan terakhir = ";
                getline(cin, pelamar.pendidikan_terakhir);
                cout << endl;
                tambah_depan();
                break;

            case 3:
                cetak();
                break;

            case 4:
                selection_sort();
                break;

            case 5:
                bubble_sort();
                break;

            case 6:
                sequential_search();
        }
    } while (pilihan != 7);
}
