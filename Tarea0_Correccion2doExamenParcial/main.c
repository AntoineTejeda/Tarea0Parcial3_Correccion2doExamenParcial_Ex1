#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef struct
{
    int CodigoCancion;
    char NombreCancion[50];
    char NombreAlbum[50];
    int NumeroIntepretes;
    char Interpretes[50];
    int NumeroReproducciones;
}TCanciones;


TCanciones CapturaDatos();
void CapturaTodasCanciones(TCanciones Array[], int Canciones);
int EncuentraViral(TCanciones Array[],int Canciones);
int main()
{
    int Canciones,viral;
    TCanciones Array[100]
    ;
    printf("Ingrese el numero de canciones a registrar: ");
    scanf("%d",&Canciones);
    printf("----------------------------\n");
    CapturaTodasCanciones(Array,Canciones);
    viral=EncuentraViral(Array,Canciones);
    printf("----------------------------\n");
    printf("Los datos de la cancion con mayor numero de reproducciones es:\n");
    printf("El codigo de la cancion es: %d \n",Array[viral].CodigoCancion);
    printf("El nombre de la cancion es: %s \n",Array[viral].NombreCancion);
    printf("El nombre del album es: %s \n",Array[viral].NombreAlbum);
    printf("El numero de interpretes es: %d\n",Array[viral].NumeroIntepretes);
    printf("Los interpretes son: %s\n",Array[viral].Interpretes);
    printf("El numero de reproducciones de la cancion es: %d\n",Array[viral].NumeroReproducciones);

}

TCanciones CapturaDatos()
{
    TCanciones C;
    printf("----------------------------\n");
    printf("Ingresa el codigo de cancion; ");
    scanf("%d",&C.CodigoCancion);
    fflush(stdin);
    printf("Ingresa el nombre de la cancion; ");
    gets(C.NombreCancion);
    printf("Ingresa el nombre del album; ");
    fflush(stdin);
    gets(C.NombreAlbum);
    printf("Ingrese el numero de interpretes; ");
    scanf("%d",&C.NumeroIntepretes);
    fflush(stdin);
    printf("Ingrese el o los nombres de los interpretes; ");
    gets(C.Interpretes);
    printf("Ingrese el numero de reproducciones; ");
    scanf("%d",&C.NumeroReproducciones);
    return(C);
}

void CapturaTodasCanciones(TCanciones Array[], int Canciones)
{
    int i;
    for(i=0;i<Canciones;i++)
    {

        Array[i]=CapturaDatos();

    }
}

int EncuentraViral(TCanciones Array[],int Canciones)
{
    int i,aux=0, indViral;
    for(i=0;i<Canciones;i++)
    {
        if(Array[i].NumeroReproducciones>aux)
        {
            aux=Array[i].NumeroReproducciones;
            indViral=i;
        }
    }
    return(indViral);
}
