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


void printJadwal(string* matkul, int n) {
    /*KAMUS*/
    int i;
    /*ALGORITMA*/
    i = 0;
    while (i <= n) {
        cout << matkul[i];
        if (i != n) {
            cout << ", ";
        }
        i += 1; 
    }   
    cout << endl;
}

void generateJadwal(Graph *G, int sem) {
    /*KAMUS*/
    adrNode P;
    string* toDelete;
    int i, j;

    /*ALGORITMA*/
    i = 0, j = 0;
    P = First(*G);
    toDelete = new string[100];
    cout << "Semester " << sem << ": " ;
    while (P != NULL) {
        if (NPred(P)==0) {
            // cout << Id(P) << " ";
            toDelete[i] = Id(P);
            i += 1;   
        }
        P = Next(P);
    }
    printJadwal(toDelete, i-1);
    // cout << endl;
    //Deleting all nodes
    while (j<i) {
        DeleteNode(G, toDelete[j]);
        j += 1;
    }

    delete[] toDelete;
}

int main () {
    /*KAMUS*/
    Graph G;
    int sem;

    /*ALGORITMA*/
    readFile("../test/test8.txt", &G);
    sem = 1;

    while (First(G) != NULL) {
        generateJadwal(&G, sem);
        sem += 1;
    }
    
    return 0;

}
