#include <iostream>

using namespace std;

struct node {
    string nama, nim;
    int n_data = 0;
    float uts, uas, rata, total;
    node *next;
    node *prev;
} s;

node *head = NULL, *tail = NULL, *baru;

void tambah_belakang() {
    baru = new(node);
    baru->nama = s.nama;
    baru->nim = s.nim;
    baru->uts = s.uts;
    baru->uas = s.uas;
    baru->rata = (s.uts + s.uas) / 2;
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

void rata_semua() {
    node *rataa;
    float t = 0;
    if (head == NULL) {
        cout << "\nData Kosong\n\n";
    } else {
        rataa = head;
        while (rataa != NULL) {
            rataa->total = 0;
            rataa = rataa->next;
        }
        rataa = head;
        while (rataa != NULL) {
            rataa->total = rataa->total + rataa->uts + rataa->uas;
            t = t + rataa->total;
            rataa = rataa->next;
        }
        cout << "- - - - - - - - - -" << endl;
        cout << "Rata-rata semua siswa = " << t / s.n_data << "\n\n";
    }
}

void cetak_depan() {
    node *cetak;
    if (head == NULL) {
        cout << "\nData Kosong\n";
    } else {
        cetak = head;
        cout << "\n= = = OUTPUT = = =" << endl;
        while (cetak != NULL) {
            cout << "- - - - - - - - - -" << endl;
            cout << "Nama siswa = " << cetak->nama << endl;
            cout << "NIM = " << cetak->nim << endl;
            cout << "Nilai UTS = " << cetak->uts << endl;
            cout << "Nilai UAS = " << cetak->uas << endl;
            cout << "Rata-rata nilai = " << cetak->rata << endl;
            cetak = cetak->next;
        }
    }
}

int main() {
    int pilih;
    do {
        cout << "1. Tambah belakang" << endl;
        cout << "2. Cetak data" << endl;
        cout << "3. Cetak rata-rata semua siswa" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu = ";
        cin>>pilih;
        switch (pilih) {
            case 1:
                cin.sync();
                cout << "- - - - - - - - - -" << endl;
                cout << "Nama siswa = ";
                getline(cin, s.nama);
                cout << "NIM = ";
                cin >> s.nim;
                cout << "Nilai UTS = ";
                cin >> s.uts;
                cout << "Nilai UAS = ";
                cin >> s.uas;
                tambah_belakang();
                cout << endl;
                s.n_data++;
                break;

            case 2:
                cetak_depan();
                cout << endl;
                break;

            case 3:
                rata_semua();
        }
    } while (pilih != 4);
}
