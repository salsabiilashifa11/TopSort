#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <string>
using namespace std;

typedef struct tadrNode *adrNode;
typedef struct tadrSuccNode *adrSuccNode;
typedef struct tadrNode {
    int NPred;
    string Id;
    int Score;
    adrNode Next;
    adrSuccNode Trail;
} Node;

typedef struct tadrSuccNode {
    adrNode Succ;
    adrSuccNode NextT;
} SuccNode;

typedef struct {
    adrNode First;
} Graph;

#define First(G) (G).First
#define Id(P) (P)->Id
#define Score(P) (P)->Score
#define NPred(P) (P)->NPred
#define Trail(P) (P)->Trail
#define Succ(Pt) (Pt)->Succ
#define NextT(Pt) (Pt)->NextT
#define Next(P) (P)->Next

adrNode AlokNode(string X, int S);
void DealokNode(adrNode P);
adrSuccNode AlokSuccNode(adrNode Pn);
void DealokSuccNode(adrSuccNode Pt);
void CreateGraph (Graph *G, string X, int S);
adrNode SearchNode(Graph G, string X);
adrSuccNode SearchEdge(Graph G, string prec, string succ);
void InsertNode(Graph *G, string X, int S, adrNode *Pn);
void DeleteNode(Graph *G, string X);
void InsertEdge(Graph *G, string prec, string succ);
void DeleteAllEdges(Graph *G, adrNode Pn);

#endif
