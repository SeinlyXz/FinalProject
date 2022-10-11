#include <iostream>
//#include <cmath>

using namespace std;

int main() {
    // Membuat keliling dan luas lingkaran
    const float pi = 3.14;
    float keliling, r, luas;
    int validation;


    cout << "Aplikasi Penghitung Luas dan Keliling Lingkaran" << endl;
    cout << "[1] Luas Lingkaran" << endl;
    cout << "[2] Keliling Lingkaran" << endl;
    cout << "[x] Pilih > ";
    cin >> validation;

    // if (statement True or False) {kode jalan di sini}

    if (validation == 1) {
        cout << "Masukkan Jari-jari lingkaran: ";
        cin >> r;
        luas = pi*(r*r);
        cout << "Luas lingkaran adalah: " << luas << endl;
    } else if (validation == 2) {
        float r, keliling;
        cout << "Masukkan jari-jari lingkaran: ";
        cin >> r;
        keliling = 2*pi*r;
        cout << "Keliling Lingkaran adalah: " << keliling;
    } else {
        cout << "ERROR: ERROR";
        return 0;
    }

    return 0;
}