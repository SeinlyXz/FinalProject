#include <iostream>
#include <ctime>
#include <time.h>
#include "encryptions/sha256.h"
#include <random>
#include <fstream>
#include <unistd.h>
#include <string>
#include <cstdlib>

using namespace std;

void loginSuccess(){
    cout << "[*] You are logged in" << endl;
}

void successCreateAcc(){
    cout << "[*] Your account successfully created...!!" << endl;
}

void showMenu(){
    system("clear");
    cout << "[*] ---------------------------------- [*]\n";
    cout << "[*]      LET'S BOOK YOUR TICKET !!     [*]\n";
    cout << "[*]         BUS TICKETING SYSTEM       [*]\n";
    cout << "[*] ---------------------------------- [*]\n";
}

void Date_and_Destination(){

}

void BusFunc(int arr[], int n){
    bool check = false;
    showMenu();
    loginSuccess();
    int counter2 = 0;
    unsigned seed = 0;
    srand(time(0)); 
    shuffle(arr, arr + n,
            default_random_engine(seed));

    // Untuk mengacak kursi

    for (int i = 0; i < n; i++){
        int index = rand() % n;
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }

    // Untuk memilih sejumlah x kursi
    srand(time(0));
    int a = rand() % 500, b;

    // Komputer bakal nyariin nilai acak dari 0 - 30
    while (!check){
        a = a / 2;
        if (a > 0 and a <= n){
            b = a;
            check = true;
        }
    }

    menu2:
    int seats, seatsSum, counter3 = 0, TempSeats[1];
    cout << "[*] Available seats:" << endl << "[*] ";
    for (int i = 0; i <= b/2; i++){
        cout << arr[i] << " ";
    }
    cout << endl << "[*] ";
    for (int i = b/2; i < b; i++){
        cout << arr[i] << " ";
    }
    cout << "\n[*] Choose your seats. max (" << b << ") ";
    cin >> seatsSum;
    if (seatsSum <= b) {
        for (int i = 0, j; i < seatsSum; i++){
            cout << "[*] Seats [" << i+1 << "] ";
            cin >> seats;
            TempSeats[i] = seats;
            if (i > 0){
                if (seats == TempSeats[i-1]){
                    cout << "[*] Cannot choose same seats..." << endl;
                    sleep(1);
                    system("clear");
                    goto menu2;
                } else{
                    continue;
                }
            }
            for (j = 0; j < n; j++){
                if (seats == arr[j]){
                    cout << "[*] OK" << endl;
                    counter3++;
                    break;
                } else if (seats != arr[j]){
                    counter3 = 0;
                }
            }            
            if (counter3 == 0){
                cout << "[*] Seats not available...";
                goto menu2;
            }
        }
    } else {
        cout << "[*] You Are Exceeding Avaiable Seats. Try Again...";
        sleep(1);
        goto menu2; 
    }
}

int main(int argc, char *argv[])
{   
    bool validate1, validate2;
    int counter = 0, busSeats[30] = 
    {
    1, 2, 3, 4, 5, 
    6, 7, 8, 9, 10, 
    11, 12, 13, 14, 15, 
    16, 17, 18, 19, 20, 
    21, 22, 23, 24, 25, 
    26, 27, 28, 29, 30
    },

    busSeatsLen = sizeof(busSeats) / sizeof(busSeats[0]), choose;

    string username, password, output;

    menu1:
    showMenu();
    cout << "[1] Login" << endl;
    cout << "[2] Register" << endl;
    cout << "[x] Exit" << endl;
    cout << "[*] Choose> ";
    cin >> choose;

    if (choose == 1){
        showMenu();
        cout << "[*] ---------------------------------- [*]\n";
        cout << "[*] ------------[ Login ]------------- [*]\n";
        cout << "\n";
        cout << "[*] Username: ";
        cin >> username;
        cout << "[*] Password: ";
        cin >> password;

        output = sha256(password);

        fstream f;
        ofstream fout;
        ifstream fin;
        fin.open("Database");
        if(fin.is_open())
            fin.close();
            string word;
            f.open("Database");
            while (f >> word) {
                counter++;
                if (counter % 2 == 0){
                    if (word == output){
                        validate1 = true;
                    }
                } else {
                    if (word == username){
                        validate2 = true;
                    }
                }
            }
        if (validate1 == true and validate2 == true){
            Date_and_Destination();
            BusFunc(busSeats, busSeatsLen);
        } else {
            cout << "[*] Try again, from start" << endl;
            sleep(2);
            goto menu1;
        }
    }

    else if (choose == 2) {
        showMenu();
        cout << "[*] ---------[ Registration ]--------- [*]\n";
        cout << "[*] ---------------------------------- [*]\n";
        cout << "[*] Username: ";
        cin >> username;
        cout << "[*] Password: ";
        cin >> password;
        
        output = sha256(password);
        
        ofstream fout;
        ifstream fin;
            fin.open("Database");
            fout.open ("Database",ios::app);
        if(fin.is_open())
            fout<< username << "\n";
            fout<< output << "\n";
            fin.close();
            fout.close();
        successCreateAcc();
        sleep(2);
        goto menu1;
    }
    else {
        return 0;
    }
    return 0;
}