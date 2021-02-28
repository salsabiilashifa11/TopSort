#include "13519106-graph.hpp"

adrNode AlokNode(string X, int S) {   
    /*KAMUS*/
    Node *P = (Node*) malloc(sizeof(Node));
    /*ALGORITMA*/
    if (P != NULL) {
        Id(P) = X;
        Score(P) = S;
        NPred(P) = 0;
        Trail(P) = NULL;
        Next(P) = NULL;
    }
    return P;
}

void DealokNode(adrNode P) {   
    /*KAMUS*/
    /*ALGORITMA*/
    free(P);
}

adrSuccNode AlokSuccNode(adrNode Pn) {   
    /*KAMUS*/
    adrSuccNode Pt;
    /*ALGORITMA*/
    Pt = (SuccNode*) malloc (sizeof(SuccNode));
    if (Pt != NULL) {
        Succ(Pt) = Pn;
        NextT(Pt) = NULL;
    }
    return Pt;
}

void DealokSuccNode(adrSuccNode Pt) {   
    /*KAMUS*/
    /*ALGORITMA*/
    free(Pt);
}

void CreateGraph (Graph *G, string X, int S) {   
    /*KAMUS*/
    adrNode P;
    /*ALGORITMA*/
    P  = AlokNode(X, S);
    First(*G) = P;
}

//Fungsi/prosedur lain
adrNode SearchNode(Graph G, string X) {   
    /*KAMUS*/
    adrNode P;
    /*ALGORITMA*/
    P = First(G);
    while (P != NULL && Id(P) != X){
        P = Next(P);
    }
    return P;
}

adrSuccNode SearchEdge(Graph G, string prec, string succ) {   
    /*KAMUS*/
    adrNode P;
    adrSuccNode T;
    /*ALGORITMA*/
    P = SearchNode(G, prec);
    
    if (P == NULL){
        return NULL;
    } else{
        T = Trail(P);
        if (T == NULL){
            return NULL;
        } else{
            while ((Id(Succ(T)) != succ) && (NextT(T) != NULL)) {
                T = NextT(T);
            }
            if (NextT(T) == NULL){
                return NULL;
            } else{
                return T;
            }
        }
        
    }
    
}

void InsertNode(Graph *G, string X, int S, adrNode *Pn) {   
    /*KAMUS*/
    adrNode LastG;
    /*ALGORITMA*/
    LastG = First(*G);
    *Pn = AlokNode(X, S);
    if (*Pn != NULL){
        while (Next(LastG) != NULL){
            LastG = Next(LastG);
        }
        Next(LastG) = *Pn;
    }
}

void DeleteNode(Graph *G, string X) {
    /*KAMUS*/
    adrNode P;
    adrNode Prev;
    /*ALGORITMA*/
    P = SearchNode(*G, X);
    Prev = First(*G);

    //Removing from main list
    if (P != NULL) {
        if (P == First(*G)) {
            First(*G) = Next(P);
        } else {
            while (Next(Prev)!=P) {
                Prev = Next(Prev);
            }
            Next(Prev) = Next(P);
        }
        //Removing all edges that P is connected to 
        DeleteAllEdges(G, P);
    }
}

void InsertEdge(Graph *G, string prec, string succ) {   
    /*KAMUS*/
    adrNode Pprec;
    adrNode Psucc;
    adrSuccNode T;
    /*ALGORITMA*/
    Pprec = SearchNode(*G,prec);
    Psucc = SearchNode(*G,succ);
    if (SearchEdge(*G,prec,succ) == NULL){
        T = Trail(Pprec);
        if (T == NULL){
            Trail(Pprec) = AlokSuccNode(Psucc);
        }
        else{
            while (NextT(T) != NULL){
                T = NextT(T);
            }
            NextT(T) = AlokSuccNode(Psucc);
            
        }
        NPred(Psucc)++;
    }
}

void DeleteAllEdges(Graph *G, adrNode Pn) {
    /*KAMUS*/
    adrSuccNode Pt;
    /*ALGORITMA*/
    Pt = Trail(Pn);
    while (Pt != NULL) {
        NPred(Succ(Pt)) -= 1;
        Pt = NextT(Pt);
    }
}