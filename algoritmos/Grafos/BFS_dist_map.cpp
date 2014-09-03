//la unica diferencia es que para este uso mapas con el mismo id, se hace algo ams comodo
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
map<int,vi> grafo;
map<int,int> dis;
void distancia(int a)
{
    map<int, bool> visitado;
    queue<int> q;
    q.push(a);
    dis[a]=0;
    visitado[a]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<grafo[u].size(); i++)
        {
            int x = grafo[u][i];
            if(!visitado[x]){
                dis[x] = dis[u] + 1;
                visitado[x]=true;
                q.push(x);
            }

        }
    }
}

int main()
{
    int c,aux1,aux2,ini,ttl,cont=1;
    cin>>c;
    while(c)
    {
        grafo=map<int,vi>();
        int cc=c;
        while(cc--)
        {
            cin>>aux1>>aux2;
            grafo[aux1].push_back(aux2);
            grafo[aux2].push_back(aux1);

        }
        cin>>ini>>ttl;
        while(ini && ttl)
        {
            dis = map<int,int>();
            distancia(ini);
            int con=0;
               for(map<int,int>::iterator it = dis.begin();it!=dis.end();++it){
                if(it->second>ttl)
                    con++;
               }
            cout<<"Consulta "<<cont<<": No se puede alcanzar "<<con<<" nodos"<<endl;
            cont++;
            cin>>ini>>ttl;
        }
        cin>>c;
    }
}

