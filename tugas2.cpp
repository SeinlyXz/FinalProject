#include <iostream>

using namespace std;

int main() {
    int luas, keliling, panjang, lebar, validation;

    cout << "Program untuk menghitung luas dan keliling persegi panjang\n";
    cout << "[1] Luas Persegi Panjang\n";
    cout << "[2] Keliling Persegi Panjang\n";
    cout << "[x] Pilih> ";
    cin >> validation;

    if (validation == 1) {
        cout << "Masukkan Panjang: ";
        cin >> panjang;
        cout << "Masukkan Lebar: ";
        cin >> lebar;
        luas = panjang*lebar;
        cout << "Luas persegi panjang adalah: " << luas;
    } else if (validation == 2) {
        cout << "Masukkan Panjang: ";
        cin >> panjang;
        cout << "Masukkan Lebar: ";
        cin >> lebar;
        keliling = 2*(panjang+lebar);
        cout << "Keliling persegi panjang adalah: " << luas;
    } else {
        cout << "ERROR: ERROR";
        return 0;
    }
    return 0;
}