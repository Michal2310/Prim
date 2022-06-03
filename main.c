#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 12 // określenie ilości wierszy w grafie

int main(){
    int graf[V][V] = { { 0, 0, 1, 4, 5, 5, 0, 0, 22, 0, 0 },
                        { 0, 0, 16, 0, 0, 0, 0, 0, 3, 30, 0 },
                        { 1, 16, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
                        { 4, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0 },
                        { 5, 0, 0, 1, 0, 12, 0, 0, 0, 0, 0 },
                        { 5, 0, 0, 0, 12, 0, 27, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 27, 0, 5, 0, 10, 18},
                        { 0, 0, 0, 0, 0, 0, 5, 0, 5, 20, 0},
                        { 22, 3, 0, 0, 0, 0, 0, 5, 0, 25, 0},
                        { 0, 30, 0, 0, 0, 0, 10, 20, 25, 3 },
                        { 0, 0, 0, 0, 0, 0, 18, 0, 0, 3, 0}};
    prim(graf);

    return 0;
}

int wynik(int parent[], int graf[V][V])
{
    for (int i = 1; i < V; i++){
        printf("%d - %d \t%d \n", parent[i], i, graf[i][parent[i]]); // wyświetlenie wyniku
    }
}

int minimum(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++){
        if (mstSet[v] == false && key[v] < min){
            min = key[v], min_index = v;            // ustawienie nowej najmniejszej wartości
        }
    }
    return min_index; // zwrócenie najmniejszej wartości
}

void prim(int graf[V][V])
{
    int parent[V], key[V]; // deklaracja zmiennych
    bool mstSet[V];

    for (int i = 0; i < V; i++){
        key[i] = INT_MAX, mstSet[i] = false; // przypisanie nieskończoności dla każdego elementu
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {

        int u = minimum(key, mstSet);   // przypisanie do zmiennej najmniejszej wartości z zakresu badanych wierzchołków
        mstSet[u] = true;

        for (int v = 0; v < V; v++){
                if (graf[u][v] && mstSet[v] == false && graf[u][v] < key[v]){
                parent[v] = u, key[v] = graf[u][v];    // przypisanie wartości pod zmienną u do danego węzła oraz wartość pod danymi współrzędnymi pod zmienną key[v],
                                                        //tylko w przypadku, gdy wartośc w grafie na pozycji [u,v] jest mniejsza od danej wartości klucza i kiedy mstSet jest fałszem
                }
        }
    }
    wynik(parent, graf); // wywołanie funkcji wypisującej wynik
}



