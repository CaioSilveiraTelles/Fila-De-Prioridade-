#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include  "malloc.h"


//cCAIO SILVEIRA TELLES RA:588199
typedef struct Pessoa
{
    int age;
    char name[30];
    char Pessoa_id[7];
    struct Pessoa *next;
} Pessoa;


Pessoa *head = NULL;
Pessoa *tail = NULL;
Pessoa *temp;

char *generateIDForNewPessoa(int age,int opc)
{
	
    static int ID1_COUNT = 1000;
    static int Id1_COUNT = 0;
    static int ID2_COUNT = 1000;
    static int Id2_COUNT = 0;
    static int ID3_COUNT = 1000;
    static int Id3_COUNT = 0;
    static int ID4_COUNT = 1000;
    static int Id4_COUNT = 0;
    char ageString[1];
    char idString[5];
    char * Pessoa_id = malloc(7);

   
    if (opc == 1){
		
	    sprintf(idString, "%d", ID1_COUNT++);
    	sprintf(ageString, "%d",Id1_COUNT++);

    	strcpy(Pessoa_id, idString);
    	strcat(Pessoa_id, ageString);
    	Pessoa_id[0]='N';
	    Pessoa_id[1]='1';
	    Pessoa_id[3]='0';
	}
	if (opc == 2){
		sprintf(idString, "%d", ID2_COUNT++);
    	sprintf(ageString, "%d",Id2_COUNT++);

    	strcpy(Pessoa_id, idString);
    	strcat(Pessoa_id, ageString);
		Pessoa_id[0]='G';
	    Pessoa_id[1]='4';
	    Pessoa_id[3]='0';
	}
	if (opc == 3){
		sprintf(idString, "%d", ID3_COUNT++);
    	sprintf(ageString, "%d",Id3_COUNT++);

    	strcpy(Pessoa_id, idString);
    	strcat(Pessoa_id, ageString);
		Pessoa_id[0]='I';
	    Pessoa_id[1]='2';
	    Pessoa_id[3]='0';
	}
	if (opc == 4){
		sprintf(idString, "%d", ID4_COUNT++);
    	sprintf(ageString, "%d",Id4_COUNT++);

    	strcpy(Pessoa_id, idString);
    	strcat(Pessoa_id, ageString);
		Pessoa_id[0]='D';
	    Pessoa_id[1]='3';
	    Pessoa_id[3]='0';
	}
	
    return Pessoa_id;
}


struct Pessoa *createPessoa(char name[30], int age ,char *Pessoa_id)
{
    struct Pessoa *Cadastro = (struct Pessoa *)malloc(sizeof(struct Pessoa));
    strcpy(Cadastro->name, name);
    strcpy(Cadastro->Pessoa_id, Pessoa_id);
    Cadastro->age = age;
    Cadastro->next = NULL;
    return Cadastro;
}


void addPessoa(Pessoa *new_Pessoa)
{

    if (head == NULL && tail == NULL)
    {
        head = new_Pessoa;
        tail = new_Pessoa;
    }
    else
    {

        if (new_Pessoa->age >= head->age)
        {
            temp = head;
            head = new_Pessoa;
            new_Pessoa->next = temp;
            return;
        }
       
        if (new_Pessoa->age <= tail->age)
        {
            tail->next = new_Pessoa;
            tail = new_Pessoa;
        }
        
        temp = head;
        while (temp->next != NULL)
        {
            if (new_Pessoa->age > temp->next->age)
            {
                struct Pessoa *newy;
                newy = temp->next;
                temp->next = new_Pessoa;
                new_Pessoa->next = newy;
                break;
            }
            temp = temp->next;
        }
    }
}


void removePrioridadePessoa()
{
    temp = head;
    if (head == NULL)
    {
        printf("Pessoa List EMPTY.\n");
        return;
    }

    if (head == tail)
    {
        head = NULL;
        tail = NULL;
        return;
    }

    head = temp->next;
    free(temp);
}


struct Pessoa *callPrioridadePessoa()
{
    if (head != NULL)
        return head;
    else
        printf("Lista de Espera Vazia.\n");
    return NULL;
}


void printWaitingList()
{
    if (head == NULL)
    {
        printf("Lista de Espera Vazia.\n");
        return;
    }
    else
    {
        
		printf("\n----------------------------------\n");
		printf("%5s\t%10s\t%5s","senha","     nome");
        printf("\n----------------------------------\n");
		temp = head;
        while (temp->next != NULL)
        {
            printf(" %-7s\t%-15s\n", temp->Pessoa_id, temp->name);
            temp = temp->next;
        }
        printf(" %-7s\t%-15s\n", temp->Pessoa_id, temp->name);
    }
}


void printMenu()
{
    printf("\n--------------------------\n");
    printf("1. Retirar Senha sem Preferencia. \n");
    printf("2. Retirar Senha Gestante. \n");
    printf("3. Retirar senha Idoso \n");
    printf("4. Retirar senha Deficiencia \n");
    printf("5. Chamar Senha\n");
    printf("6. Mostrar Fila De Senhas\n");
    printf("7. Fechar.\n");
    printf("--------------------------\n");
    printf("Escolha uma opcao: ");
}

char *registerPessoa(char name[30], int age,int opc)
{
    char *new_Pessoa_id = malloc(7);
    Pessoa *newPessoa;

    strcpy(new_Pessoa_id, generateIDForNewPessoa(age,opc));
    newPessoa = createPessoa(name,age, new_Pessoa_id);
    addPessoa(newPessoa);

    return new_Pessoa_id;
}


void nextPessoa()
{
    
    Pessoa *PrioridadePessoa = callPrioridadePessoa();
    if(PrioridadePessoa!=NULL){
        printf("Senha Chamada = %s: \n", PrioridadePessoa->Pessoa_id);
        removePrioridadePessoa();
    }
}



int main()
{
	int opc=0 ;
    int choice = 0;
    char name[30];
    int age;
    char pri[30];
    char *Pessoa_id;
    printf("*******************************************\n");
    printf("    TRABALHO PO  CAIO RA:588199           \n");
    printf("******************************************");

    while (choice != 7)
    {
        printMenu();
        scanf("%d", &choice);
		

        switch (choice)
        {
        case 1:
        	opc= 1 ;
 
            printf("\nDigite o nome da pessoa: ");
            scanf("%s", name);
            age=0;
            
           

            Pessoa_id = registerPessoa(name,age,opc);
            printf("\nPessoa: \"%s\" registrada com senha: |%s|\n", name, Pessoa_id);
            break;
          
		   
		case 2:
		  	 opc=2;
            
            printf("\nDigite o nome da pessoa: ");
            scanf("%s", name);
            age=10;
     
            Pessoa_id = registerPessoa(name,age,opc);
            printf("\nPessoa: \"%s\" registrada com senha: |%s|\n", name, Pessoa_id);
            break;
		case 3:
				opc=3;
				

            printf("\nDigite o nome da pessoa: ");
            scanf("%s", name);
            
            
            age=30;
            
            Pessoa_id = registerPessoa(name,age,opc);
            printf("\nPessoa: \"%s\" registrada com senha: |%s|\n", name, Pessoa_id);
            break;
		case 4:
				opc=4;
				

            printf("\nDigite o nome da pessoa: ");
            scanf("%s", name);
           
            
            age=40;

            Pessoa_id = registerPessoa(name,age,opc);
            printf("\nPessoa: \"%s\" registrada com senha: |%s|\n", name, Pessoa_id);
            break;
			
        case 6:
            printWaitingList();
            break;
        case 5:
            nextPessoa();
            break;
        case 7:
            printf("Fechando A aplicacao.\n");
            break;
        default:
           
            printf("Opcao invalida ,tente novamente\n\n");
            break;
        }
    }
    return 0;
}
