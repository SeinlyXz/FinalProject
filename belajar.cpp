#include <iostream>
#include <cmath>
// Library


using namespace std;

// Notes
// endl --> end line --> akhir baris
// \n (backslash n) --> (n) new line --> Dipakai di dalam string ("")
// \t (backslash t) --> (t) tab (4 spasi)


// Kode dijalankan bermulai dari sini
int main() {
    // Deklarasi variabel
    // int -> integer -> bilangan bulat
    // bool -> boolean (True / False)
    // char -> character biasanya 1 character contohnya L/P, Y/N
    // string -> diapit petik dua --> "Bebas apa aja"
    // double -> sama kaya float cuma lebih besar
    // float -> desimal (19.8)
    // string nama, nim, asal, jurusan;
    // char kelamin;

    // cout << "=======================\n";
    // cout << "\tBiodataku\n";
    // cout << "=======================\n";


    // cout << "Masukkan nama kamu\t\t:";
    // cin >> nama;

    // cout << "Masukkan nim kamu\t\t:";
    // cin >> nim;

    // cout << "Masukkan asal\t\t\t:";
    // cin >> asal;

    // cout << "Masukkan jurusan\t\t:";
    // cin >> jurusan;

    // cout << "Masukkan Jenis Kelamin(L/P)\t:";
    // cin >> kelamin;


    // OPERATOR

    // Penjumlahan => a + b
    // Pengurangan => a - b
    // Perkalian => a * b
    // Pembagian => a / b

    // int p,q,r,s;

    // cout << "Operasi Matematika\n"; 

    // cout << "Masukkan p: ";
    // cin >> p;

    // cout << "Masukkan q: ";
    // cin >> q;

    // cout << "Hasilnya p - q adalah: " << p - q << endl;
    // cout << "Hasilnya p * q adalah: " << p * q << endl;
    // cout << "Hasilnya p / q adalah: " << p / q << endl;
    // cout << "Hasilnya p ^ q adalah: " << pow(p,q) << endl;
    // cout << "Hasilnya p square root adalah: " << sqrt(p);

    int bb = 0, bmi = 0;
    float tb = 0, tbs;

    cout << "Masukkan Berat Badan: ";
    cin >> bb;

    cout << "Masukkan Tinggi Badan: ";
    cin >> tb;
    tbs = tb/100;
    bmi = bb / pow(tbs,2);

    cout << "BMI ku adalah: " << bmi;


    return 0;
}