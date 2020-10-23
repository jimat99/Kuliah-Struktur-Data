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

void tambah_depan() {
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
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
}

void hapus_depan() {
    if (head == NULL) {
        cout << "\nData Kosong\n\n";
    } else if (head->next == NULL) {
        head = NULL;
        tail = NULL;
        cout << "\nData depan berhasil dihapus\n\n";
    } else {
        head = head->next;
        head->prev = NULL;
        cout << "\nData depan berhasil dihapus\n\n";
    }
}

void hapus_belakang() {
    if (head == NULL) {
        cout << "\nData Kosong\n\n";
    } else if (tail->prev == NULL) {
        head = NULL;
        tail = NULL;
        cout << "\nData belakang berhasil dihapus\n\n";
    } else {
        tail = tail->prev;
        tail->next = NULL;
        cout << "\nData belakang berhasil dihapus\n\n";
    }
}

void hapus_tengah() {
    if (head == NULL) {
        cout << "\nData Kosong\n\n";
    } else {
        node *hapus, *b1, *b2;
        string a;
        int temu = 0;
        cout << "Nama data yang ingin dihapus ? ";
        cin>>a;
        hapus = head;
        while (hapus->nama != a && temu != 1) {
            if (hapus->next == NULL) {
                cout << "\nData tidak ditemukan\n\n";
                temu = 1;
            } else {
                hapus = hapus->next;
            }
        }
        if (temu == 0 && hapus->prev == NULL) {
            hapus_depan();
        } else if (temu == 0 && hapus->next == NULL) {
            hapus_belakang();
        } else if (temu == 0 && hapus->prev != NULL && hapus->next != NULL) {
            b1 = hapus->prev;
            b2 = hapus->next;
            b1->next = b2;
            b2->prev = b1;
            cout << "\nData terhapus\n\n";
        }
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
        cout << "4. Hapus belakang" << endl;
        cout << "5. Tambah depan" << endl;
        cout << "6. Hapus depan" << endl;
        cout << "7. Hapus tengah" << endl;
        cout << "8. Keluar" << endl;
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
                break;

            case 4:
                hapus_belakang();
                s.n_data--;
                break;

            case 5:
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
                tambah_depan();
                cout << endl;
                s.n_data++;
                break;

            case 6:
                hapus_depan();
                s.n_data--;
                break;

            case 7:
                hapus_tengah();
                s.n_data--;
        }
    } while (pilih != 8);
}

