#include "C:\Users\hp\Documents\gtk\Les Sdd\Fixed.h"


Fixed* Create_Fixed(gchar* Id)
{
    if(!Id)
    {
        printf("\nMacro :Create_Fixed\n");
        printf("-->Erreur :child Id est vide");
        exit(-1);
    }
    Fixed* f=(Fixed*)malloc(sizeof(Fixed));
    if(!f)
    {
        printf("\nMacro :Create_Fixed\n");
        printf("-->Erreur d'allocation de memire pour la stucture fixed");
        return(Fixed*)NULL;
    }
    f->Id=g_strdup(Id);
    f->fix=gtk_fixed_new();
    return(Fixed*)f;
}


int Set_At_Fixed(Fixed* f,GtkWidget* Child,gchar* Id,Position P)
{
    /*
      Test d'existance pour le child
    */
    if(!Child)
    {
        printf("\nMacro :Set_At_Fixed\n");
        printf("-->Erreur d'existence de child a ajouter");
        return(int)-2;
    }
    /*
      Test d'existance pour la structure fixed
    */
    if(!f)
    {
      printf("\nMacro :Set_At_Fixed\n");
      printf("-->Erreur d'existence de la structure fixed");
      return(int)-1;
    }
    if(!Id)
    {
        printf("\nMacro :Set_At_Fixed\n");
        printf("-->Erreur :child Id est vide");
        return(int)0;
    }
    /*
      Affectation du child pour box
    */
    f->Childs=Insert_Childs(f->Childs,Child,Id);
    /*
      Ajouter l'objet dans le container
    */
    gtk_fixed_put(GTK_FIXED(f->fix),Child,P.X,P.Y);
    return(int)1;
}


int Move_Fixed_Child(Fixed* f,GtkWidget* Child,gchar* Id,Position P)
{
    /*
      Test d'existance pour le child
    */
    if(!Child)
    {
        printf("\nMacro :Move_Fixed_Child\n");
        printf("-->Erreur d'existence de child");
        return(int)-3;
    }
    /*
      Test d'existance pour la structure fixed
    */
    if(!f)
    {
      printf("\nMacro :Move_Fixed_Child\n");
      printf("-->Erreur d'existence de la structure fixed");
      return(int)-2;
    }
    if(!Id)
    {
        printf("\nMacro :Move_Fixed_Child\n");
        printf("-->Erreur :child Id est vide");
        return(int)-1;
    }
    if(!Recherche_Child(f->Childs,Id))
    {
        printf("\nMacro :Move_Fixed_Child\n");
        printf("-->Child n'exist pas dans le box");
        return(int)0;
    }
    gtk_fixed_move(GTK_FIXED(f->fix),Child,P.X,P.Y);
    return(int)1;
}
