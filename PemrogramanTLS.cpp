#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>  // Untuk fungsi sleep
#include <thread>  // Untuk fungsi sleep_for

using namespace std;

// Fungsi untuk memberikan efek animasi pada tulisan
void printWithEffect(const string& text) {
    for (char c : text) {
        cout << c;
        cout.flush();  // Cetak langsung setiap karakter
        this_thread::sleep_for(chrono::milliseconds(100));  // Delay 100ms
    }
    cout << endl;
}

int main() {
    const short minValue = 1;
    const short maxValue = 6;
    srand(time(0));

    // Generate angka dadu acak untuk first dan second
    short first = (rand() % (maxValue - minValue + 1)) + minValue;
    short second = (rand() % (maxValue - minValue + 1)) + minValue;

    short tebakFirst, tebakSecond;
    bool tebakanBenar = false;

    // Perulangan hingga pengguna menebak kedua angka dengan benar
    do {
        // Minta pengguna untuk menebak angka dadu pertama dan kedua
        cout << "Tebak angka dadu pertama (1-6): ";
        cin >> tebakFirst;
        cout << "Tebak angka dadu kedua (1-6): ";
        cin >> tebakSecond;

        // Cek apakah tebakan benar
        if (tebakFirst == first && tebakSecond == second) {
            // Cetak dengan efek animasi
            printWithEffect("Congratulations! Kedua tebakan benar!");
            cout << "Hasil dadu pertama: " << first << ", dadu kedua: " << second << endl;
            tebakanBenar = true;  // Jika benar, keluar dari loop
        } else if (tebakFirst == first || tebakSecond == second) {
            cout << "Selamat! Salah satu tebakan benar! Coba lagi untuk menebak yang lain.\n" << endl;
        } else {
            cout << "Maaf, kedua tebakan salah. Coba lagi!\n" << endl;
        }

    } while (!tebakanBenar);  // Ulangi sampai kedua tebakan benar

    return 0;
}
