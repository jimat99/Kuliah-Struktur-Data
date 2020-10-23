#include <iostream>

using namespace std;

struct {
    string nama;
    string alamat;
    float ipk;
} mahasiswa[100];

int main() {
    int jumlah;
    cout << "Masukkan jumlah mahasiswa = ";
    cin>>jumlah;
    cout << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << "Masukkan nama mahasiswa = ";
        cin >> mahasiswa[i].nama;
        cout << "Masukkan alamat mahasiswa = ";
        cin >> mahasiswa[i].alamat;
        cout << "Masukkan IPK = ";
        cin >> mahasiswa[i].ipk;
        cout << endl;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "Nama mahasiswa ke-" << i + 1 << " = " << mahasiswa[i].nama << endl;
        cout << "Alamat mahasiswa ke-" << i + 1 << " = " << mahasiswa[i].alamat << endl;
        cout << "IPK mahasiswa ke-" << i + 1 << " = " << mahasiswa[i].ipk << endl << endl;
    }

    float totalipk = 0;
    for (int i = 0; i < jumlah; i++) {
        totalipk = totalipk + mahasiswa[i].ipk;
    }
    cout << "Total IPK = " << totalipk << "\n\n";

    float rataipk = 0;
    for (int i = 0; i < jumlah; i++) {
        rataipk = totalipk / jumlah;
    }
    cout << "Rata-rata IPK = " << rataipk << "\n\n";
}

