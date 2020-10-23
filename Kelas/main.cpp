#include <iostream>

using namespace std;

int main() {
    int size;
    cout << "Masukkan jumlah data = ";
    cin>>size;
    string nama[size];
    float ipk[size];

    //untuk input saja
    for (int a = 0; a < size; a++) {
        cout << "Nama ke-" << a + 1 << " = ";
        cin >> nama[a];
        cout << "IPK = ";
        cin >> ipk[a];
    }

    cout << endl;

    //untuk total IPK
    float total = 0;
    for (int a = 0; a < size; a++) {
        total = total + ipk[a];
    }
    cout << "Total IPK = " << total << endl;

    float rata = total / size;
    cout << "Rata-rata = " << rata << endl;

    // untuk mahasiswa terbaik
    float max = ipk[0];
    int index = 0;
    for (int i = 1; i < size; i++) {
        if (max < ipk[i]) {
            max = ipk[i];
            index = i;
        }
    }
    cout << "IPK terbesar = " << max << endl;
    cout << "Mahasiswa dengan IPK terbesar = " << nama[index] << endl;

    float min = ipk[0];
    int ind = 0;
    for (int i = 1; i < size; i++) {
        if (min > ipk[i]) {
            min = ipk[i];
            ind = i;
        }
    }
    cout << "IPK terkecil = " << min << endl;
    cout << "Mahasiswa dengan IPK terkecil = " << nama[ind] << endl;
}
