#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct cita
{
int id;
char nom[50];
char esp[50];
char corr[50];
int cell;
}e;
FILE *fc;

int main(){

    int x;

    while(1){
        system("cls");
        printf("\n\t\t\t   ___________________________________________________________________\n ");
        printf("\n\t\t\t   |                ------SALUD PARA TODOS------                     |\n");
        printf("\n\t\t\t   |        1.- Paciente                                             |\n");
        printf("\n\t\t\t   |        2.- Personal                                             |\n");
        printf("\n\t\t\t   |        0.- Salir                                                |\n");
        printf("\n\t\t\t   |_________________________________________________________________|\n\n");

        printf("\n\n\n");
        printf("Dijite una opcion: ");
        scanf("%d", &x);

        switch(x){
        case 0:
            exit(0);

        case 1:
            agendamiento();
            break;

        case 2:
            contra();
            break;

        default:
            printf("Opcion Invalida, ingrese el numero de nuevo...\n\n");

        }
        printf("\n\nPrecione cualquier tecla para continuar...");
        getch();
    }

    return 0;
}
int contra() {
    system("cls");
	int i, pin;
	for (i=1; i<=3; i++){
        printf("\n\t\t\t   ____________________________________________________________________\n ");
        printf("\n\t\t\t   |                       INGRESO PERSONAL                          |\n");
        printf("\n\t\t\t   |                XX DIJITE SU CODIGO DE INGRESO XX                |\n");
        printf("\n\t\t\t   |_________________________________________________________________|\n\n");
        scanf("\n\t\t\t""%d",&pin);
        if (pin == 1111){
            printf("\n pin es correcto\n");
            menfun();
        }
        else{
         printf("\n\t\t\t El pin es incorrecto\n");

        }
	}
	return 0;
}

void menfun (){
    int x;

    while(1){
        system("cls");
        printf("<== Sistema Gestion de Personal ==>\n");
        printf("1.- Ver lista de pacientes\n");
        printf("2.- Eliminar Paciente\n");
        /*printf("3.- Despachar o Agregar medicacion\n");
        printf("4.- Ver lista de medicinas\n");*/
        printf("0.salir\n\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &x);
        system("cls");

        switch(x){
        case 0:
            main();

        case 1:
            listapac();
            break;
        case 2:
            elimpac();
            break;
        default:
            printf("Opcion no valida...\n\n");

        }
        printf("\n\nPrecione cualquier tecla para continuar...");
        getch();
    }

    return 0;

}
 
void agendamiento(){

    int x;

    while(1){
        system("cls");
        printf("<== Sistema de admiciones ==>\n");
        printf("1.Solicitar cita\n");
        printf("0.salir\n\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &x);

        switch(x){
        case 0:
            main();

        case 1:
            admitPatient();
            break;

        default:
            printf("Opcion no valida...\n\n");

        }
        printf("\n\nPrecione cualquier tecla para continuar...");
        getch();
    }

    return 0;
}

void admitPatient(){
    fc =fopen("citas.txt","ab");

    printf("Ingrece Id: \n");
    scanf("%d", &e.id);
    printf("Ingrese nombre del paciente: \n");
    fflush(stdin);
    gets(e.nom);
    system("cls");
    printf("\n");
    printf("Ingrese la especialidad \n");
    printf("\n");  
    printf("Recuerde que contamos con las siguientes especialidades: \n");
    printf("Cardiologia\n");
    printf("Medicina General\n");
    printf("Traumatologia\n");
    printf("Pediatria\n");
    printf("Especialidad: ");
    fflush(stdin);
    gets(e.esp);
    printf("\n"); 
    printf("==Ingrese su correo electronico==\n"); 
    fflush(stdin);
    gets(e.corr);
    printf("===Ingrece Numero de Celular==== \n");
    scanf("%d", &e.cell);

    fwrite(&e, sizeof(e), 1, fc);
    fclose(fc);
    system("cls");
    printf("\t\t\tLa solicitud de agendamiento de cita sera procesada y\n");
    printf("\t\t\tRecivira yna llamada y un correo electronico indicando\n");
    printf("\t\t\tel dia y la hora para su cita, gracias por preferirnos\n\n");
    printf("=====================SALUD PARA TODOS, DISFRUTA TU VIDA SIN MIEDOS=====================\n\n");
    printf("\nDatos guardados Exitosamente");
}

void listapac(){

    printf("<== Lista de pacientes ==>\n\n");
    printf("%-10s %-30s %-30s %-20s %s \n", "ID", "Nombre","Especialidad","Correo","N.Celular");
    printf("----------------------------------------------------------------------------------------------------------\n");
    fc = fopen("citas.txt", "rb");
    while(fread(&e, sizeof(e), 1, fc) == 1){
        printf("%-10d %-30s %-30s %-20s %d\n",e.id,e.nom,e.esp,e.corr,e.cell);
    }
    fclose(fc); 
}


void elimpac(){
    int id, f=0;
    system("cls");
    printf("<== Eliminar pacientes ==>\n\n");
    printf("Ingrese el ID del paciente que quiere eliminare: ");
    scanf("%d", &id);

    FILE *ft;

    fc = fopen("citas.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while(fread(&e, sizeof(e), 1, fc) == 1){

        if(id == e.id){
            f=1;
        }else{
            fwrite(&e, sizeof(e), 1, ft);
        }
    }

    if(f==1){
        printf("\n\nPaciente eliminado exitosamente.");
    }else{
        printf("\n\nPaciente no encontrado !");
    }

    fclose(fc);
    fclose(ft);

    remove("citas.txt");
    rename("temp.txt", "citas.txt");

}

void med(){

}

