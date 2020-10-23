#include <iostream>
#define size 5
using namespace std;

struct mahasiswa {
    string nama;
    int nilai;
} mhs[size];

int top = -1;

void push(string nama, int nilai) {
    if (top < size - 1) {
        top = top + 1;
        cout << "Input nama = ";
        cin >> mhs[top].nama;
        cout << "Input nilai = ";
        cin >> mhs[top].nilai;
        cout << endl;
    } else if (top >= size - 1) {
        cout << "\n- - - Data sudah penuh - - -" << endl << endl;
    }
}

void pop() {
    if (top>-1) {
        cout << "\n- - - Data Out - - -" << endl;
        cout << "Nama = " << mhs[top].nama << endl;
        cout << "Nilai = " << mhs[top].nilai << endl << endl;
        top--;
    } else if (top == -1) {
        cout << "\n- - - Data kosong - - -" << endl << endl;
    }
}

int main() {
    int pilihan;
    do {
        string n;
        int ni;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Exit" << endl;
        cout << "Masukkan pilihan = ";
        cin>>pilihan;
        switch (pilihan) {
            case 1:
                push(n, ni);
                break;

            case 2: pop();
        }
    } while (pilihan == 1 || pilihan == 2);
}
