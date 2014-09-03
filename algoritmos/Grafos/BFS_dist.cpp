// test: http://ideone.com/zJ5jrV
#include<bits/stdc++.h>

using namespace std;

//variables globales para impresion
int caso= 1;
bool flag= false;
//structura nodo, tiene un vector de conexiones
struct Node{
    int id;
    bool visited;
    long dist;
    vector<int> edges;
};

//recibe un array de nodos, el id de u nodo inicial y el id del nodo final
void BFS_dist(Node N[], int ini, int fin){
    //Coloco a todos no visitados y con tamaño infinito
    for(int i=0; i<fin; i++){
        N[i].visited=false;
        N[i].dist=INT_MAX;
    }
    //el primero como vistado
    N[ini].visited=true;
    N[ini].dist=0;
    //lo asigno a la cola
    queue<int> Q;
    Q.push(N[ini].id);
    while(!Q.empty()){
        int u= Q.front();
        Q.pop();
        //para cada arista v que sale del nodo u
        for(int j=0; j<N[u].edges.size(); j++){
            int v= N[u].edges[j];
            if(!N[v].visited){
                N[v].visited=true;
                N[v].dist= N[u].dist+1;
                Q.push(N[v].id);
            }
        }
    }
    //Ahora imprimimos
    if(flag) printf("\n\n");
	flag= true;
	printf("Caso %i:\n",(caso++));
	for(int i = 1; i < fin ; i++){
		printf("%i ",N[i].id);
		(N[i].dist == INT_MAX)?printf("INF"):printf("%li",N[i].dist);
		if(i != (fin-1))printf("\n");
	}
}

int main(){
    int cases, nodes_s, edges_s, n1, n2;
    //leo la cantidad de casos
    scanf("%i\n", &cases);
    while(cases--){
        //leo la cantidad de nodos y aristas
        scanf("%i %i\n", &nodes_s, &edges_s);
        //leo las conexiones nodo-arista
        Node N[nodes_s];
        for(int i=0;i<nodes_s;i++) N[i].id=i;
        for(int i=0;i<edges_s;i++){
            scanf("%i %i\n", &n1, &n2);
            //asigno aristas
            N[n1].edges.push_back(n2);
            N[n2].edges.push_back(n1);
        }
        //envio el array, el nodo 0 y el nodo fin
        BFS_dist(N,N[0].id,nodes_s);
    }

    return 0;
}
