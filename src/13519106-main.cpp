#include "13519106-jadwal.hpp"
using namespace std;

int main () {
    /*KAMUS*/
    Graph G;
    int sem;
    bool batasSks;
    string denganBatas;
    int maxSks;
    string namaFile;

    /*ALGORITMA*/
    maxSks = 0;

    cout << "Masukkan nama file: ";
    cin >> namaFile;
    namaFile = "../test/" + namaFile;

    cout << "Apakah ada batasan SKS setiap semester? (Y/N)\n";
    cin >> denganBatas;

    batasSks = denganBatas == "Y" || denganBatas == "y";
    if (batasSks) {
        cout << "Berapa batas maksimum SKS setiap semester?\n";
        cin >> maxSks;
    }
    
    readFile(namaFile, &G);
    sem = 1;
    cout << "\n------------------------------------------\n";
    cout << "Berikut rencana  studi yang dapat diambil:\n";
    if (batasSks) {
        cout << "SKS maksimum setiap semester: " << maxSks << endl;
    }
    cout << endl;
    while (First(G) != NULL) {
        generateJadwal(&G, sem, batasSks, maxSks);
        sem += 1;
        cout << endl;
    }

    return 0;

}
