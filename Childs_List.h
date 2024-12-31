#include "C:\Users\hp\Documents\gtk\Les Sdd\Childs_List.h"
#include <string.h>

ChildsList* Create_Child(GtkWidget* Child,gchar* Id)
{
    if(!Child)
    {
        printf("\nMacro :Create_Child\n");
        printf("-->Erreur d'existence de Child");
        exit(-1);
    }
    if(!Id)
    {
        printf("\nMacro :Create_Child\n");
        printf("-->Erreur :child Id est vide");
        exit(-1);
    }
    ChildsList* cellule=(ChildsList*)malloc(sizeof(ChildsList));
    if(!cellule)
    {
        printf("\nMacro :Create_Child\n");
        printf("-->Erreur d'allocation de memoiere pour la cellule");
        exit(-1);
    }
    cellule->Children=Child;
    cellule->Child_Id=g_strdup(Id);
    //strcpy(cellule->Child_Id,Id);
    cellule->next=NULL;
    return(ChildsList*)cellule;
}


/*
  La fonction Unique_Child_ID permet de verifier si l'ID de check button est unique
  Les Entrees: -pointure sur la liste des check buttons
               -l'ID de check button a verifier
  Les Sortis : -1 si l'ID est unique
               -0 si l'ID n'est pas unique
*/
int Unique_Child_ID(ChildsList* liste,gchar* Id)
{
    if(!Id)
    {
        printf("\nMacro :Unique_ID\n");
        printf("-->Erreur :child Id est vide");
        exit(-1);
    }
    ChildsList* tmp;
    tmp=liste;
    /*
      Parcourir la liste des childs de la box
      en cherchant si l'ID existe deja
    */
    while(tmp)
    {
        if (tmp->Child_Id == NULL) {
    printf("Erreur : tmp->Child_Id est NULL.\n");
    return -1; // Code d'erreur ou autre gestion
}
        // Si l'ID existe deja
        if(strcmp(tmp->Child_Id,Id)==0)
            return(int)0;
        // Passer au check button suivant
        tmp=tmp->next;
    }
    // Si l'ID n'existe pas
    return(int)1;
}


ChildsList* Insert_Childs(ChildsList* chlist,GtkWidget* Child,gchar* Id)
{
    if(!Child)
    {
        printf("\nMacro :Insert_Childs\n");
        printf("-->Erreur d'existence de Child");
        exit(-1);
    }
    if(!Id)
    {
        printf("\nMacro :Insert_Childs\n");
        printf("-->Erreur :child Id est vide");
        exit(-1);
    }
    if(!Unique_Child_ID(chlist,Id))
    {
        printf("\nMacro :Insert_Childs\n");
        printf("-->Id  %s de child deja exist",Id);
        exit(-1);
    }
    ChildsList* cellule=Create_Child(Child,Id);

    cellule->next=chlist;
    return(ChildsList*)cellule;
}



int Recherche_Child(ChildsList* list,gchar* Id)
{
    if(!list)
    {
        printf("\nMacro : Recherche_Child\n");
        printf("-->List des childs est vide");
        return(int)-1;
    }
    if(!Id)
    {
        printf("\nMacro :Recherche_Child\n");
        printf("-->Erreur :child Id est vide");
        return(int)-2;
    }

    ChildsList* tmp=list;

    while (tmp)
    {
        if(!strcmp(tmp->Child_Id,Id))
           return(int)1;
        tmp=tmp->next;
    }
    return(int)0;
}



/*
  La fonction Remove_Check_Button permet de supprimer un check button de la liste des check buttons
  Les Entrees: -pointure sur la liste des check buttons
               -l'ID de check button a supprimer
  Les Sortis : -la liste des check buttons apres la suppression
*/
ChildsList* Remove_Child(ChildsList* liste,gchar* ID)
{
    //pointure pour parcourir la liste
    ChildsList* tmp;
    //pointure pour garder le child precedent
    ChildsList* prev;

    tmp=liste;
    prev=NULL;
    /*
      Parcourir la liste des child
      en cherchant le child a supprimer
    */
    while(tmp)
    {
        // Si le child a supprimer est trouve
        if(strcmp(tmp->Child_Id,ID)==0)
        {   
            // Si le child a supprimer est le premier
            if(prev)
            {
                prev->next=tmp->next;
                free(tmp);
                return(ChildsList*)liste;
            }
            else// Si le child a supprimer est a l'intrieur de la liste
            {
                liste=tmp->next;
                free(tmp);
                return(ChildsList*)liste;
            }
        }
        /*
          Passer au child suivant
          en restant le child precedent
        */
        prev=tmp;
        tmp=tmp->next;
    }
    return(ChildsList*)liste;
}