#include <iostream>

using namespace std;

int main() {
    char ulang;
    do {
        int siswa, mapel;

        cout << "Masukkan jumlah siswa = ";
        cin>>siswa;
        cout << endl;
        string nama[siswa];
        for (int i = 0; i < siswa; i++) {
            cout << "Siswa ke-" << i + 1 << " = ";
            cin >> nama[i];
        }
        cout << endl;

        cout << "Masukkan jumlah pelajaran = ";
        cin>>mapel;
        string mata[mapel];
        for (int i = 0; i < mapel; i++) {
            cout << "Pelajaran ke-" << i + 1 << " = ";
            cin >> mata[i];
        }
        cout << endl;

        float nilai[siswa][mapel];
        for (int i = 0; i < siswa; i++) {
            cout << "Inputkan data " << nama[i] << " :" << endl;
            for (int n = 0; n < mapel; n++) {
                cout << "Nilai " << mata[n] << " = ";
                cin >> nilai[i][n];
            }
            cout << endl;
        }

        // 2. untuk total nilai per mata pelajaran
        cout << "Total nilai per mata pelajaran :" << endl;
        for (int i = 0; i < mapel; i++) {
            float totalpermapel = 0;
            for (int s = 0; s < siswa; s++) {
                totalpermapel = totalpermapel + nilai[s][i];
            }
            cout << "Total nilai " << mata[i] << " = " << totalpermapel << endl;
        }
        cout << endl;

        // 3. untuk total nilai per siswa
        cout << "Total nilai per siswa :" << endl;
        float totalsemua = 0, ratasemua;
        for (int i = 0; i < siswa; i++) {
            float totalpersiswa = 0;
            for (int n = 0; n < mapel; n++) {
                totalpersiswa = totalpersiswa + nilai[i][n];
            }
            totalsemua = totalsemua + totalpersiswa;
            ratasemua = totalsemua / siswa;
            cout << "Total nilai " << nama[i] << " = " << totalpersiswa << endl;
        }
        cout << endl;

        // 4. untuk rata-rata per mapel
        cout << "Rata-rata per mata pelajaran :" << endl;
        for (int i = 0; i < mapel; i++) {
            float totalpermapel = 0, ratapermapel = 0;
            for (int s = 0; s < siswa; s++) {
                totalpermapel = totalpermapel + nilai[s][i];
            }
            ratapermapel = totalpermapel / siswa;
            cout << "Rata-rata nilai " << mata[i] << " = " << ratapermapel << endl;
        }
        cout << endl;

        // 5. untuk rata-rata per siswa
        cout << "Rata-rata per siswa :" << endl;
        for (int i = 0; i < siswa; i++) {
            float totalpersiswa = 0, ratapersiswa = 0;
            for (int n = 0; n < mapel; n++) {
                totalpersiswa = totalpersiswa + nilai[i][n];
            }
            ratapersiswa = totalpersiswa / mapel;
            cout << "Rata-rata nilai " << nama[i] << " = " << ratapersiswa << endl;
        }
        cout << endl;

        // 6. untuk rata-rata kelas
        cout << "Rata-rata kelas :" << endl;
        cout << "Rata-rata nilai kelas = " << ratasemua << "\n\n";

        cout << "Ingin mengulang program (y/t) ? ";
        cin>>ulang;
        cout << endl;
    } while (ulang == 'y');
}
