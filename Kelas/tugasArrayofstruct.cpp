#include <iostream>

using namespace std;

struct {
    string nama[10];
    string alamat[10];
    float ipk[10];
} mahasiswa;

int main() {
    int jumlah;
    cout << "Masukkan jumlah mahasiswa = ";
    cin>>jumlah;
    cout << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << "Masukkan nama mahasiswa = ";
        cin >> mahasiswa.nama[i];
        cout << "Masukkan alamat mahasiswa = ";
        cin >> mahasiswa.alamat[i];
        cout << "Masukkan IPK = ";
        cin >> mahasiswa.ipk[i];
        cout << endl;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "Nama mahasiswa ke-" << i + 1 << " = " << mahasiswa.nama[i] << endl;
        cout << "Alamat mahasiswa ke-" << i + 1 << " = " << mahasiswa.alamat[i] << endl;
        cout << "IPK mahasiswa ke-" << i + 1 << " = " << mahasiswa.ipk[i] << endl << endl;
    }

    float totalipk = 0;
    for (int i = 0; i < jumlah; i++) {
        totalipk = totalipk + mahasiswa.ipk[i];
    }
    cout << "Total IPK = " << totalipk << "\n\n";

    float rataipk = 0;
    for (int i = 0; i < jumlah; i++) {
        rataipk = totalipk / jumlah;
    }
    cout << "Rata-rata IPK = " << rataipk << "\n\n";
}
