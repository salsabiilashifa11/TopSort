#include "13519106-graph.hpp"

int main(){
    /* KAMUS */
    Graph G;
    adrNode P;
    string ids[5] = {"C1", "C2", "C3", "C4", "C5"};

    /* ALGORITMA */
    CreateGraph(&G, "C1", 4);   /* Membuat sebuah graph baru dengan elemen node pertama dengan Id = C1 */           
 
    /* Menginput node pada graph dengan Id = C2,C3,C4,C5*/
    // InsertNode(&G, "C2", &P1); 
    // InsertNode(&G, "C3", &P2);         
    // InsertNode(&G, "C4", &P3);
    // InsertNode(&G, "C5", &P4);

    for (int i=1; i<5; i++) {
        InsertNode(&G, ids[i], 4, &P);
    }
    
    /* Menambahkan busur-busur pada graph sehingga list seperti berikut:
        Node  Trail
        [C1]-->[C2]-->[C5]
        [C2]-->[C5]-->[C3]-->[C4]
        [C3]-->[C2]-->[C4]
        [C4]-->[C2]-->[C5]-->[C3]
        [C5]-->[C4]-->[C2]
    */
    InsertEdge(&G, "C1", "C2"); //Artinya: menambahkan busur berarah dari C1 KE C2
    InsertEdge(&G, "C1", "C5");
    InsertEdge(&G, "C2", "C5");
    InsertEdge(&G, "C2", "C3");
    InsertEdge(&G, "C2", "C4");
    InsertEdge(&G, "C3", "C2");
    InsertEdge(&G, "C3", "C4");
    InsertEdge(&G, "C4", "C2");
    InsertEdge(&G, "C4", "C5");
    InsertEdge(&G, "C4", "C3");
    InsertEdge(&G, "C5", "C4");
    InsertEdge(&G, "C5", "C2");
    DeleteNode(&G, "C1");

    /* Output keterangan graph */
    adrNode cP = First(G);
    while (cP != NULL) {
        cout << "Terdapat " << NPred(cP) << " busur terhubung ke node dengan Id = " << Id(cP) << endl;
        cP = Next(cP);
    }
    
    return 0;
}