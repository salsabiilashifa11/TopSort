#include "Graph.hpp"
#include <fstream>
using namespace std;


void addLineToGraph(string* array, int n, Graph *G, int lines_read) {
    /*KAMUS*/
    adrNode P;
    string x  = array[0];
    /*ALGORITMA*/
    //First node
    if (lines_read == 0) {
        CreateGraph(G, x);
    } else {
        if (SearchNode(*G, array[0]) == NULL) {
            InsertNode(G, array[0], &P);
        }
    }
    //cout << "First node is: " << Id(First(*G)) << endl;
    for (int i=1; i<n; i++) {
        if (SearchNode(*G, array[i]) == NULL) {
            InsertNode(G, array[i], &P);
        }
        InsertEdge(G, array[i], array[0]);
    }
}

void readLine(string* array, string line, Graph *G, int lines_read) {
    /*KAMUS*/
    string delims = ",. ";
    size_t pos = 0;
    string token;
    int i = 0;

    /*ALGORITMA*/
    while ((pos = line.find_first_of(delims)) != string::npos) {
        token = line.substr(0, pos);
        if (token!="") {
            array[i] = token;
            i += 1;
        }
        line.erase(0, pos + 1);
    }
    addLineToGraph(array, i, G, lines_read);
}

void readFile(string path, Graph *G) {
    /*KAMUS*/
    ifstream fileInput;
    string x;
    string* array;
    int lines_read;

    /*ALGORITMA*/
    lines_read = 0;
    fileInput.open(path);
    array = new string[100];
    if (!fileInput) {
        cerr << "File not found!" << endl;
    }

    while (getline(fileInput, x)) {
        readLine(array, x, G, lines_read);
        lines_read += 1;
    }
}



int main () {
    /*KAMUS*/
    Graph G;

    /*ALGORITMA*/
    readFile("./test/test.txt", &G);

    adrNode cP = First(G);
    while (cP != NULL) {
        cout << "Terdapat " << NPred(cP) << " busur terhubung ke node dengan Id = " << Id(cP) << endl;
        cP = Next(cP);
    }

    cout << "--------" << endl;

    adrSuccNode cT = Trail(First(G));
    cout << Id(First(G)) << " adalah prereq untuk "<< endl;
    while (cT != NULL) {
        cout << "-" << Id(Succ(cT)) << endl;
        cT = NextT(cT);
    }

    cout << "--------" << endl;
    
    cout << "Mata kuliah yang bisa diambil saat ini: " << endl;
    cP = First(G);
    while (cP != NULL) {
        if (NPred(cP)==0) {
            cout << "-" << Id(cP) << endl;
        }
        cP = Next(cP);
    }
    DeleteNode(&G, "C3");

    cout << "--------" << endl;
    
    cout << "Mata kuliah yang bisa diambil saat ini: " << endl;
    cP = First(G);
    while (cP != NULL) {
        if (NPred(cP)==0) {
            cout << "-" << Id(cP) << endl;
        }
        cP = Next(cP);
    }
    DeleteNode(&G, "C1");

    cout << "--------" << endl;
    
    cout << "Mata kuliah yang bisa diambil saat ini: " << endl;
    cP = First(G);
    while (cP != NULL) {
        if (NPred(cP)==0) {
            cout << "-" << Id(cP) << endl;
        }
        cP = Next(cP);
    }

    
    return 0;

}
