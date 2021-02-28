#include "13519106-jadwal.hpp"

string addMark(string x) {
    /*KAMUS*/
    /*ALGORITMA*/
    return x + "-";
}

string* separateCourse(string strInput) {
    /*KAMUS*/
    string* result;
    string delims = "-";
    size_t pos = 0;
    string token;
    int i = 0;
    string course;

    /*ALGORITMA*/
    course = addMark(strInput);
    result = new string[2];
    while ((pos = course.find_first_of(delims)) != string::npos) {
        token = course.substr(0, pos);
        if (token!="") {
            //cout << token << endl;
            result[i] = token;
            i += 1;
        }
        course.erase(0, pos + 1);
    }
    return result;
}

int let2num(char c) {
    /*KAMUS*/
    /*ALGORITMA*/
    if (c=='1') {
        return 1;
    } if (c=='2') {
        return 2;
    } if (c=='3') {
        return 3;
    } if (c=='4') {
        return 4;
    } if (c=='5') {
        return 5;
    } if (c=='6') {
        return 6;
    } if (c=='7') {
        return 7;
    } if (c=='8') {
        return 8;
    } if (c=='9') {
        return 9;
    } 
    return 0;
}

int str2num(string n) {
    /*KAMUS*/
    int result = 0;
    int i = 0;
    /*ALGORITMA*/
    while (n[i]!=' ' && n[i]!='\0') {
        result = let2num(n[i]);
        //cout << n[i];
        i += 1;
    }
    return result;
}

void addLineToGraph(string* array, int n, Graph *G, int lines_read) {
    /*KAMUS*/
    adrNode P;
    string x  = array[0];
    string* separated = separateCourse(x);
    string code = separated[0];
    int score = str2num(separated[1]);
    /*ALGORITMA*/
    //First node
    if (lines_read == 0) {
        CreateGraph(G, code, score);
    } else {
        if (SearchNode(*G, code) == NULL) {
            InsertNode(G, code, score, &P);
        }
    }
    //cout << "First node is: " << Id(First(*G)) << endl;
    for (int i=1; i<n; i++) {
        string y = array[i];
        string* separated2 = separateCourse(y);
        string code2 = separated2[0];
        int score2 = str2num(separated2[1]);
        if (SearchNode(*G, code2) == NULL) {
            InsertNode(G, code2, score2, &P);
        }
        InsertEdge(G, code2, code);
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

void generateJadwal(Graph *G, int sem, bool batasSks, int maxSks) {
    /*KAMUS*/
    adrNode P;
    string* toDelete;
    int i, j;
    int sks;

    /*ALGORITMA*/
    i = 0, j = 0;
    sks = 0;
    P = First(*G);
    toDelete = new string[100];
    cout << "Semester " << sem << ": " ;
    while (P != NULL) {
        if (NPred(P)==0) {
            if (!batasSks || (sks+Score(P)<=maxSks)) {
                toDelete[i] = Id(P);
                sks += Score(P);
                i += 1; 
            }
        }
        P = Next(P);
    }
    printJadwal(toDelete, i-1);
    cout << "Total SKS semester ini: " << sks << endl;
    // cout << endl;
    //Deleting all nodes
    while (j<i) {
        DeleteNode(G, toDelete[j]);
        j += 1;
    }

    delete[] toDelete;
}