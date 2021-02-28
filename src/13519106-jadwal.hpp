#ifndef JADWAL_HPP
#define JADWAL_HPP

#include "13519106-graph.hpp"
#include <fstream>
#include <math.h>
using namespace std;


string addMark(string x);
string* separateCourse(string strInput);
int let2num(char c);
int str2num(string n);
void addLineToGraph(string* array, int n, Graph *G, int lines_read);
void readLine(string* array, string line, Graph *G, int lines_read);
void readFile(string path, Graph *G);
void printJadwal(string* matkul, int n);
void generateJadwal(Graph *G, int sem, bool batasSks, int maxSks);

#endif