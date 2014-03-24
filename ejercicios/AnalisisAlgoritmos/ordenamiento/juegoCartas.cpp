#include <bits/stdc++.h>
#define MAX 500010

int arrayx[MAX];
int aux[MAX];

long long mergesort(int start, int endt)
{
    if (start == endt)
        return 0;

    int mid = start + (endt - start) / 2;

    long long ret1 = mergesort(start, mid);
    long long ret2 = mergesort(mid + 1, endt);

    int i = start;
    int j = mid + 1;
    int k = start;
    long long ret3 = 0;

    while(i <= mid && j <= endt)
    {
        if (arrayx[i] < arrayx[j]) aux[k++] = arrayx[i++];
        else
        {
            ret3 += (mid - i) + 1;
            aux[k++] = arrayx[j++];
        }
    }
    while(i <= mid)
    {
        aux[k++] = arrayx[i++];
    }
    while(j <= endt)
    {
        aux[k++] = arrayx[j++];
    }

    memcpy(arrayx+start,aux+start,sizeof(arrayx[0])*(endt-start+1));
    return (ret1 + ret2 + ret3);
}

using namespace std;
int main()
{
    int  n;
    while((scanf("%d",&n))==1){
    //while(n--) scanf("%d",&arrayx[++i]);
    if(n==0)break;
    for(int i = 0; i < n; i++) scanf("%d", &arrayx[i]);
    long long t=(mergesort(0, n - 1));
    cout<<((t%2!=0)?"Susana":"Pedro")<<endl;
    }

    return 0;
}
