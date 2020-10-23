#include <iostream>

using namespace std;

struct node {
    string nama, nim;
    float uts, uas, rata;
    node *next;
} sekolah;

void tambah_depan(node *head, node *simpul, string nama, string nim, float uts, float uas) {
    node *baru, *depan;
    baru = new(node);
    baru->nama = nama;
    baru->nim = nim;
    baru->uts = uts;
    baru->uas = uas;
    baru->rata = (uts + uas) / 2;
    baru->next = NULL;
    if (simpul->next == NULL) {
        head->next = baru;
        simpul->next = baru;
    } else {
        depan = head->next;
        depan->next = baru;
        head->next = baru;
    }
}

void cetak_data(node *head, node *simpul) {
    node *cetak;
    cetak = simpul->next;
    cout << "\n- - - Output - - -\n";
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

int main() {
    node simpul, head;
    simpul.next = NULL;
    head.next = NULL;
    char pilih = 'y';
    
    while (pilih == 'y') {
        cin.sync();
        cout << "- - - - - - - - - -" << endl;
        cout << "Nama siswa = ";
        getline(cin, sekolah.nama);
        cout << "NIM = ";
        cin >> sekolah.nim;
        cout << "Nilai UTS = ";
        cin >> sekolah.uts;
        cout << "Nilai UAS = ";
        cin >> sekolah.uas;
        tambah_depan(&head, &simpul, sekolah.nama, sekolah.nim, sekolah.uts, sekolah.uas);
        cout << "Tambah data (y/t) ? ";
        cin>>pilih;
    }
    
    cetak_data(&head, &simpul);
}
