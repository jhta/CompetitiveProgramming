#include<bits/stdc++.h>

using namespace std;

//este es un mergesrtcon ua sola funcion, la unica duda que tengo es la condicion de parada
void mergesort(int *a, int *b,int ini, int fin){


    if(ini<fin){
        int piv= (fin+ini)/2;
        mergesort(a,b,ini,piv);
        mergesort(a,b,piv+1,fin);

        int j=piv+1,i=ini,h=ini;
        //este while hace lo de los 2 primero condicionales en el merge de clase
        //es el que hace el intercambio cuando aun no se a recorrido todo h  o todo j
        //por decirlo asi, el h recorre el primer pedazo de la izquierda y el j el pedazo de la derecha
        while((h<=piv)&&(j<=fin)){
            if(a[h]<=a[j]){
                b[i]=a[h];
                h++;
            }else{
                b[i]=a[j];
                j++;
            }
            i++;
        }

        //los siguientes tienen como unico objetivo rellenar
        //este es para rellenar cuando ya se uzaron todos los de la izquierda
        if(h>piv){
            for(int k=j;k<=fin;k++ ){
                b[i]=a[k];
                i++;
            }
        }else{
            for(int k=h;k<=piv;k++){
                b[i]=a[k];
                i++;
            }
        }
        //simplemente relleno a con el proceso hecho
        for(int k=ini;k<=fin;k++)
            a[k]=b[k];

    }
}


int main()
{
    int a[] = {12,10,43,23,-78,45,123,56,98,41,90,24};
    int num;

    num = sizeof(a)/sizeof(int);

    int b[num];

    mergesort(a,b,0,num-1);

    for(int i=0; i<num; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
