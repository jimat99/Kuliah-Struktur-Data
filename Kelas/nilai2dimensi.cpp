#include <iostream>

using namespace std;

int main() {
    float total_IPA, rata_IPA, total_BHS, rata_BHS;
    int size;
    cout << "Jumlah Siswa = ";
    cin>>size;
    cout << endl;

    string nama[size];
    float nilai[size][2];
    for (int a = 0; a < size; a++) {
        cout << "Nama ke-" << a + 1 << " = ";
        cin >> nama[a];
        cout << "Nilai IPA = ";
        cin >> nilai[a][0];
        cout << "Nilai Bahasa = ";
        cin >> nilai[a][1];
        cout << endl;
    }

    total_IPA = 0;
    for (int a = 0; a < size; a++) {
        total_IPA = total_IPA + nilai[a][0];
    }

    total_BHS = 0;
    for (int a = 0; a < size; a++) {
        total_BHS = total_BHS + nilai[a][1];
    }

    rata_IPA = total_IPA / size;
    rata_BHS = total_BHS / size;
    cout << "Total IPA = " << total_IPA << endl;
    cout << "Rata - rata IPA = " << rata_IPA << endl;
    cout << "Total Bahasa = " << total_BHS << endl;
    cout << "Rata - rata Bahasa = " << rata_BHS << endl;
}
