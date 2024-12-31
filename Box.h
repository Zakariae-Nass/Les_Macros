#include "C:\Users\hp\Documents\gtk\Les Sdd\Box.h"
#include <stdio.h>
#include <string.h>


Box* Create_Box(gchar* Id,GtkOrientation Type,guint spacing)
{


    if(!Id)
    {
        printf("\nMacro :Create_Box\n");
        printf("-->Erreur :child Id est vide");
        exit(-1);
    }

    Box* pbox=(Box*)malloc(sizeof(Box));

    if(!pbox)
    {
        printf("\nMacro :Create_Box\n");
        printf("-->Erreur d'allocation de memoiere pour la structure box");
        exit(-1);
    }


    pbox->ID=Id;
    pbox->Type=Type;
    pbox->spacing=spacing;
    pbox->MyBox=gtk_box_new(Type,spacing);

    return(Box*)pbox;
}


int Set_Box_Spacing(Box* pbox,guint spacing)
{
    if(!pbox)
    {
        printf("\nMacro :Set_Box_Spacing\n");
        printf("-->Erreur d'existence de la structure box");
        return(int)0;
    }
    pbox->spacing=spacing;
    gtk_box_set_spacing(GTK_BOX(pbox->MyBox),spacing);
    return(int)1;
}


int Set_Box_Homogeneous(Box* pbox,gboolean homogeneous)
{
    if(!pbox)
    {
        printf("\nMacro :Set_Box_Homogeneous\n");
        printf("-->Erreur d'existence de la structure box");
        return(int)0;
    }

    pbox->homogenoes=homogeneous;
    gtk_box_set_homogeneous(GTK_BOX(pbox->MyBox),homogeneous);
    return(int)1;
}





/*
  La fonction Set_At_Start_Box permet d'ajouter un onjet dans un box
  Les Entrees: -pointure sur le box
               -pointure sur l'onjet
               -l'Id de l'objet
               -une variable expand de type boolean
               -une variable fill de type boolean
               -une variable padding de type guiny
  Les Sortis : - 1 si la modification est effectue
               - 0 si l'Id est vide
               - (-1) si le box n'exist pas
               - (-2) si l'objet n'exist pas
*/
int Set_At_Start_Box(Box* pbox,GtkWidget* Objet,gchar* Id,gboolean expand,gboolean fill,guint padding)
{
    /*
      Test d'existance pour l'objet
    */
    if(!Objet)
    {
        printf("\nMacro :Set_At_Start_Box\n");
        printf("-->Erreur d'existence de l'objet a ajouter");
        return(int)-2;
    }
    /*
      Test d'existance pour la box
    */
    if(!pbox)
    {
      printf("\nMacro :Set_At_Start_Box\n");
      printf("-->Erreur d'existence de la box");
      return(int)-1;
    }
    if(!Id)
    {
        printf("\nMacro :Set_At_Start_Box\n");
        printf("-->Erreur :child Id est vide");
        return(int)0;
    }
    /*
      Affectation du child pour box
    */
    pbox->ChList=Insert_Childs(pbox->ChList,Objet,Id);
    /*
      Ajouter l'objet dans le container
    */
    gtk_box_pack_start(GTK_BOX(pbox->MyBox),Objet,expand,fill,padding);
    return(int)1;
}


/*
  La fonction Set_At_End_Box permet d'ajouter un onjet dans un box
  Les Entrees: -pointure sur le box
               -pointure sur l'onjet
               -l'Id de l'objet
               -une variable expand de type boolean
               -une variable fill de type boolean
               -une variable padding de type guiny
  Les Sortis : - 1 si la modification est effectue
               - 0 si l'Id est vide
               - (-1) si le box n'exist pas
               - (-2) si l'objet n'exist pas
*/
int Set_At_End_Box(Box* pbox,GtkWidget* Objet,gchar* Id,gboolean expand,gboolean fill,guint padding)
{
    /*
      Test d'existance pour l'objet
    */
    if(!Objet)
    {
        printf("\nMacro :Set_At_End_Box\n");
        printf("-->Erreur d'existence de l'objet a ajouter");
        return(int)-2;
    }
    /*
      Test d'existance pour la box
    */
    if(!pbox)
    {
      printf("\nMacro :Set_At_End_Box\n");
      printf("-->Erreur d'existence de la box");
      return(int)-1;
    }
    if(!Id)
    {
        printf("\nMacro :Set_At_End_Box\n");
        printf("-->Erreur :child Id est vide");
        return(int)0;
    }
    /*
      Affectation du child pour box
    */
    pbox->ChList=Insert_Childs(pbox->ChList,Objet,Id);
    /*
      Ajouter l'objet dans le container
    */
    gtk_box_pack_end(GTK_BOX(pbox->MyBox),Objet,expand,fill,padding);
    return(int)1;
}


int Set_Box_HAlignement(Box* pbox,GtkAlign alignement)
{
    /*
      Test d'existance pour la box
    */
    if(!pbox)
    {
      printf("\nMacro :Set_Box_HAlignement\n");
      printf("-->Erreur d'existence de la box");
      return(int)0;
    }

    pbox->HAlignement=alignement;
    gtk_widget_set_halign(GTK_WIDGET(pbox->MyBox),alignement);
    return(int)1;
}




int Set_Box_VAlignement(Box* pbox,GtkAlign alignement)
{
    /*
      Test d'existance pour la box
    */
    if(!pbox)
    {
      printf("\nMacro :Set_Box_HAlignement\n");
      printf("-->Erreur d'existence de la box");
      return(int)0;
    }

    pbox->VAlignement=alignement;
    gtk_widget_set_valign(GTK_WIDGET(pbox->MyBox),alignement);
    return(int)1;
}



int Reorder_Box_Child(Box* pbox,GtkWidget* Child,gchar* Id,gint order)
{
    /*
      Test d'existance pour child
    */
    if(!Child)
    {
        printf("\nMacro :Reorder_Box_Child\n");
        printf("-->Erreur :Child est vide");
        return(int)-3;
    }
    /*
      Test d'existance pour la box
    */
    if(!pbox)
    {
      printf("\nMacro :Reorder_Box_Child\n");
      printf("-->Erreur d'existence de la box");
      return(int)-2;
    }
    if(!Id)
    {
        printf("\nMacro :Reorder_Box_Child\n");
        printf("-->Erreur :child Id est vide");
        return(int)-1;
    }
    if(!Recherche_Child(pbox->ChList,Id))
    {
        printf("\nMacro :Reorder_Box_Child\n");
        printf("-->Child n'exist pas dans le box");
        return(int)0;
    }
    gtk_box_reorder_child(GTK_BOX(pbox->MyBox),Child,order);
    return(int)1;
}



int Remove_Box_Child(Box* pbox,GtkWidget* Child,gchar* Id)
{
    /*
      Test d'existance pour child
    */
    if(!Child)
    {
        printf("\nMacro :Remove_Box_Child\n");
        printf("-->Erreur :child est vide");
        return(int)-3;
    }
    /*
      Test d'existance pour la box
    */
    if(!pbox)
    {
      printf("\nMacro :Remove_Box_Child\n");
      printf("-->Erreur d'existence de la box");
      return(int)-2;
    }
    if(!Id)
    {
        printf("\nMacro :Remove_Box_Child\n");
        printf("-->Erreur :child Id est vide");
        return(int)-1;
    }
    if(!Recherche_Child(pbox->ChList,Id))
    {
        printf("\nMacro :Remove_Box_Child\n");
        printf("-->Child n'exist pas dans le box");
        return(int)0;
    }
    gtk_container_remove(GTK_CONTAINER(pbox->MyBox),Child);
    return(int)1;
}

