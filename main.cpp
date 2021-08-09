#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <windows.h>

using namespace std;

//LECTURA DEL VECTOR
void leer_vector(int num[], int tamanio)
{
    //los vectores siempre pasan por referencia
    for (int i=0; i<tamanio; i++)
    {
        cout<<endl<<"Inrese el elemento # " << (i+1)<<" : ";
        cin>>num[i];
    }
}

//impresion del vector
void imprime_vector(int vector[], int tamanio)
{
    cout<<endl<<endl<<"ELEMENTOS DE VECTOR";
    for (int i=0; i<tamanio; i++)
    {
        cout<<endl<<"Ingrese el elemento # " << (i+1)<<" : " <<vector[i];
    }
}

//Funcion que llene el vector con valores aletorios
void  vector_aletorio(int num[], int tamanio)
{
    srand(time(NULL));
    for(int i = 0; i<tamanio; i++)
    {
        num[i] = 1+ rand () % 1000;
    }
}

//1) diseñe la funcion que busque un numero entero en el vector.
//la funcion debe devolver verdadero si el elemento existe en el vector
//o falso en caso contrario.
bool buscar(int array[], int tamanio, int elemento)
{
    for(int i=0; i<tamanio; i++)
    {
        if (array[i]==elemento)
            return true;
    }
    return false;
}

//2) diseñe la funcion que busque un numero entero en el vector.
//la funcion debe devolver la posicion donde el elemento fue encontrado
//Devuelve -1 si no existe
//busqueda secuencial.
bool buscar_pos(int array[], int tamanio, int elemento)
{
    for(int i=0; i<tamanio; i++)
    {
        if (array[i]==elemento)
            return i;
    }
    return -1;
}

//Diseñe la funcion que devuelva la cantidad de veces que
//existe un entero en el vector.
bool cantidad_vectores(int array[], int tamanio, int elemento) {
    int contador = 0;
    {
        for (int i = 0; i < tamanio; i++) {
            if (array[i] == elemento) {
                contador++;
            }
        }
        return contador;
    }
}
//diseñe la funcion que realice el intercambio
void intercambio(int &num1, int &num2)
{
    int temporal = num1;
    num1 = num2;
    num2 = temporal;
}


//Diseñe funcion que devuelva el conteo de forma desendente.
void ordenacion_des(int vector[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        for (int j = 0; j < tamanio; j++) {
            //intercambiear los elementos
            intercambio(vector[i], vector[j]);
           /* if (vector[i] < vector[j]) {
                int aux;
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;*/

            }
        }

    }


double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

//1. Diseñe la funcion que imprima el vector de nombres
void MostrarNombres(char *vector[],const int tamanio){
    int i;
    for(i=0;i<tamanio;i++){
        cout<<endl<<vector[i];
    }
}

//2. Diseñe la funcion que ordene descendentemente (Z-A) el vector de nombres.

void OrdenarNombres(char *vector[],const int tamanio){
    char *temp;
    int i,j;

    for(i=0; i<tamanio-1; i++){
        for(j=i+1; j<tamanio; j++){
            if(strcmp(vector[i], vector[j]) < 0){
                temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
            }
        }
    }
}

//PRESENTAR HASTA EL DOMINGO 8 DE AGOSTO, HASTA LAS 23:00 EN GITHUB.

int main() {
    LARGE_INTEGER t_ini, t_fin;
    double secs;

    int num1, num2;
    intercambio(num1, num2);
    cout<<endl<<"El intercambio de " <<num1<< " es: " <<num2<< " y el intercambio de " <<num2<< " es: " <<num2<<(num1, num2);

    const int MAX = 20;
    int num[MAX];
    vector_aletorio(num, MAX);
    num[11] = 155;


    //captura tiempo inicial del proceso
    QueryPerformanceCounter(&t_ini);
    ordenacion_des(num, MAX);

    //captura el tiempo despues de concluir el proceso
    QueryPerformanceCounter(&t_fin);
    secs = performancecounter_diff(&t_fin, &t_ini);
    cout<<endl<<"ORDENACION SECUENCIAL : TIEMPO EJECUTION EN ms: "<<(secs*1000.0);

    imprime_vector(num, MAX);

    //buscar elemento en el vector
    int x=55;
    if(buscar(num, MAX, x))
        cout<<endl<<"El elemento "<<x<< " SI EXISTE...";
        else
        cout<<endl<<"El elemento "<<x<< " SI EXISTE...";

    int pos=buscar_pos(num, MAX,x);
    if(pos==-1)
        cout<<endl<<"NO EXISTE EL ELEMENTO "<<x <<" en el vector...";
    else
        cout<<endl<<"EL ELEMENTO "<< x <<" EXISTE EN LA POSICION: "<<pos;

    int contador=0;
    int i;
    cout <<endl<< "EL ELEMENTO " << i << " aparece " << contador << " veces.\n";


    //vector de string (nombre de personas)
    int tam=6;
    string nombre[tam] ={"Juan", "Antonio", "Carlos", "Martha", "Pedro", "Amalia"};


    cout<<endl<<endl<<"VECTOR DE NOMBRE";
    for(int k=0; k<tam; k++)
        cout<<endl<<nombre[k];

    //funcion nombres:
    char *nombres[] = {"ELIAN", "STEVEN", "SUGEY", "FRIXON", "CAMILL",
                          "MISHELLA", "RALF", "PAULETTE", "BYRON", "ALEXANDRA"};

    const int Elementos=sizeof(nombres)/sizeof(char*);

    cout<<endl<<"\n Nombres desordenados\n\n" ;
    MostrarNombres(nombres,Elementos);

    OrdenarNombres(nombres,Elementos);

    cout<<endl<<"\n Ordenados alfabeticamente\n\n";
    MostrarNombres(nombres,Elementos);

    return 0;
}
