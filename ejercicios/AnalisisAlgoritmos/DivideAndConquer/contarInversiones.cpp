#include <bits/stdc++.h>
#define MAX 500010

int arrayx[MAX];
int dummyArray[MAX];

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
        if (arrayx[i] < arrayx[j]) dummyArray[k++] = arrayx[i++];
        else
        {
            ret3 += (mid - i) + 1;
            dummyArray[k++] = arrayx[j++];
        }
    }
    while(i <= mid)
    {
        dummyArray[k++] = arrayx[i++];
    }
    while(j <= endt)
    {
        dummyArray[k++] = arrayx[j++];
    }

    memcpy(arrayx+start,dummyArray+start,sizeof(arrayx[0])*(endt-start+1));
    return (ret1 + ret2 + ret3);
}

using namespace std;
int main()
{
    int  n;
    scanf("%d",&n);
    //while(n--) scanf("%d",&arrayx[++i]);

    for(int i = 0; i < n; i++) scanf("%d", &arrayx[i]);
    printf("%lld\n", mergesort(0, n - 1));


    return 0;
}
