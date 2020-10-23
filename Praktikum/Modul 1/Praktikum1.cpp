#include <iostream>

using namespace std;

struct depot {
    string nama_pelanggan, nama_makan, nama_minum;
    int harga_makan, harga_minum;
} depot;

int main() {
    cout << "- - Input - -" << endl;
    cout << "Nama pelanggan = ";
    std::getline(std::cin, depot.nama_pelanggan);
    cout << "Makanan = ";
    std::getline(std::cin, depot.nama_makan);
    cout << "Minuman = ";
    std::getline(std::cin, depot.nama_minum);
    cout << "Harga makanan = ";
    cin >> depot.harga_makan;
    cout << "Harga minuman = ";
    cin >> depot.harga_minum;
    cout << endl;

    cout << "- - Data yang telah dimasukkan - -";
    cout << "\nNama pelanggan = " << depot.nama_pelanggan;
    cout << "\nMakanan = " << depot.nama_makan;
    cout << "\nMinuman = " << depot.nama_minum;
    cout << "\nHarga makanan = Rp. " << depot.harga_makan;
    cout << "\nHarga minuman = Rp. " << depot.harga_minum << endl;
}
