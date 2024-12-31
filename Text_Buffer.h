#include "C:\Users\hp\Documents\gtk\Les Sdd\Text_Buffer.h"




/*
  Le Macro Init_Text_Buffer permet d'initialiser la structure Text_Buffer
  Les Entrees: - Rien
  Les Sortis : -pointure sur la structure Text_Buffer
*/
Text_Buffer* Init_Text_Buffer()
{
    //Allocation de memoire pour la structure Text_Buffer
    Text_Buffer* T_Buffer;
    T_Buffer=(Text_Buffer*)malloc(sizeof(Text_Buffer));
    //Test d'allocation
    if(!T_Buffer)
    {
        printf("\nMacro : Init_Text_Buffer\n");
        printf("-->Erreur d'allocation de memoire pour la structure Text_Buffer\n");
        exit(-1);
    }
    //creation de la buffer
    T_Buffer->Buffer=gtk_text_buffer_new(NULL);
    //initialisation de nom de la buffer
    T_Buffer->Text=g_strdup("NULL");
    //initialisation des position du curseur
    gtk_text_buffer_get_start_iter(T_Buffer->Buffer,&T_Buffer->Start);
    gtk_text_buffer_get_end_iter(T_Buffer->Buffer,&T_Buffer->End);
    return(Text_Buffer*)T_Buffer;
}



/*
    Le Macro Set_Buffer_Text permet de modifier le texte de la buffer
    Les Entrees: -pointure sur la structure Text_Buffer
                    -le texte a ajouter
    Les Sortis : - 1 si la modification est effectue
                 - 0 si la buffer n'exist pas
                 - (-1) si le texte n'exist pas
*/
int Set_Buffer_TagTable(Text_Buffer* TB)
{
    //Test d'existance de la structure Text_Buffer
    if(!TB)
    {
        printf("\nMacro : Get_Buffer_TagTable\n");
        printf("-->Erreur d'existance de Structure Buffer dans la fonction Get_Buffer_TagTable");
        return(int)-1;
    }
    //Recuperation du tableau des balises
    if(!TB->Buffer)
    {
        printf("\nMacro : Get_Buffer_TagTable\n");
        printf("-->Erreur d'existance de la buffer dans la fonction Get_Buffer_TagTable");
        return(int)0;
    }
    //Recuperation du tableau des balises
    TB->Tag_Table=gtk_text_buffer_get_tag_table(TB->Buffer);
    return(int)1;
}


/*
  Le Macro Set_Tag_To_Buffer permet d'ajouter une balise a la buffer
  Les Entrees: -pointure sur la structure Text_Buffer
                -pointure sur la balise
  Les Sortis : - 1 si l'ajout est effectue
               - 0 si la balise n'exist pas
               - (-1) si la structure Text_Buffer n'exist pas
*/
int Set_Tag_To_Buffer(Text_Buffer* T_Buffer,Balise* B)
{
    //Test d'existance de la structure Text_Buffer
    if(!T_Buffer)
    {
        printf("\nMacro : Set_Tag_To_Buffer\n");
        printf("-->Erreur d'existance de la structure Text_Buffer\n");
        return(int)-1;
    }
    //Test d'existance de la balise
    if(!B)
    {
        printf("\nMacro : Set_Tag_To_Buffer\n");
        printf("-->Erreur d'existance de la structure Balise\n");
        return(int)0;
    }
    //Ajout de la balise dans le tableau des balises
    gtk_text_tag_table_add(T_Buffer->Tag_Table,B->Tag);
    //Affectation de la balise a la buffer
    gtk_text_buffer_apply_tag(T_Buffer->Buffer,B->Tag,&T_Buffer->Start,&T_Buffer->End);
    return(int)1;
}

/*
  Le Macro Set_Tag_At_Position permet d'ajouter une balise a une position donnee (position par rapport au caractere)
  Les Entrees: -pointure sur la structure Text_Buffer
                -pointure sur la balise
                -la position de debut
                -la position de fin
  Les Sortis : - 1 si l'ajout est effectue
               - 0 si la balise n'exist pas
               - (-1) si la structure Text_Buffer n'exist pas
*/
int Set_Tag_At_Position(Text_Buffer* T_Buffer,Balise* B,int start,int end)
{
    //Test d'existance de la structure Text_Buffer
    if(!T_Buffer)
    {
        printf("\nMacro : Set_Tag_At_Position\n");
        printf("-->Erreur d'existance de la structure Text_Buffer\n");
        return(int)-1;
    }
    //Test d'existance de la balise
    if(!B)
    {
        printf("\nMacro : Set_Tag_At_Position\n");
        printf("-->Erreur d'existance de la structure Balise\n");
        return(int)0;
    }
    //Ajout de la balise dans le tableau des balises
    gtk_text_tag_table_add(T_Buffer->Tag_Table,B->Tag);
    //recuperation des positions
    GtkTextIter Debut,Fin;
    //recuperer la debut du curseur
    gtk_text_buffer_get_iter_at_offset(T_Buffer->Buffer,&Debut,start);
    //recuperer la fin du curseur
    gtk_text_buffer_get_iter_at_offset(T_Buffer->Buffer,&Fin,end);
    //Affectation de la balise a la buffer
    gtk_text_buffer_apply_tag(T_Buffer->Buffer,B->Tag,&Debut,&Fin);
    return(int)1;
}


/*
  Le Macro Insert_Into_Buffer_Cursor permet d'ajouter un texte a la position du curseur
  Les Entrees: -pointure sur la structure Text_Buffer
                -le texte a ajouter
  Les Sortis : - 1 si l'ajout est effectue
               - 0 si la balise n'exist pas
               - (-2) si la structure Text_Buffer n'exist pas
               - (-3) si la buffer n'exist pas
               - (-4) si le text a ajouter n'exist pas
               - (-5) si le text ne peut pas etre modifier
*/
int Insert_Into_Buffer_Cursor(Text_Buffer* T_Buffer,const gchar* Text)
{
    //Test d'existance de la structure Text_Buffer
    if(!T_Buffer)
    {
        printf("\nMacro : Insert_Into_Buffer_Cursor\n");
        printf("-->Erreur d'existance de la structure Text_Buffer\n");
        return(int)-2;
    }
    //Test d'existance de la buffer
    if(!T_Buffer->Buffer)
    {
        printf("\nMacro : Insert_Into_Buffer_Cursor\n");
        printf("-->Erreur d'existance de la buffer\n");
        return(int)-3;
    }
    //Test d'existance du texte
    if(!Text)
    {
        printf("\nMacro : Insert_Into_Buffer_Cursor\n");
        printf("-->Erreur de l'existance du texte\n");
        return(int)-4;
    }
    //Test de la possibilite de modifier le texte
    if(!T_Buffer->editable)
    {
        printf("\nMacro : Insert_Into_Buffer_Cursor\n");
        printf("-->Text ne peut pas etre modifier\n");
        return(int)-5;
    }
    //Ajout du texte a la position du curseur
    gtk_text_buffer_insert_at_cursor(T_Buffer->Buffer,Text,-1);
    //Recuperation des positions
    gtk_text_buffer_get_start_iter(T_Buffer->Buffer,&T_Buffer->Start);
    gtk_text_buffer_get_end_iter(T_Buffer->Buffer,&T_Buffer->End);
    //Recuperation du texte
    T_Buffer->Text=gtk_text_buffer_get_text(T_Buffer->Buffer,&T_Buffer->Start,&T_Buffer->End,FALSE);
    return(int)1;
}

/*
    Le Macro Insert_Into_Begginning_Buffer permet d'ajouter un texte au debut de la buffer
    Les Entrees: -pointure sur la structure Text_Buffer
                 -le texte a ajouter
    Les Sortis : - 0 si l'ajout est effectue
                 - (-1) si la structure Text_Buffer n'exist pas
                 - (-2) si la buffer n'exist pas
                 - (-3) si le texte n'exist pas
                 - (-4) si le texte ne peut pas etre modifier
*/
int Insert_Into_Begginning_Buffer(Text_Buffer* T_Buffer,const gchar* Text)
{
    //Test d'existance de la structure Text_Buffer
    if(!T_Buffer)
    {
        printf("\nMacro : Insert_Into_Begginning_Buffer\n");
        printf("-->Erreur d'existance de la structure Text_Buffer\n");
        return(int)-1;
    }
    //Test d'existance de la buffer
    if(!T_Buffer->Buffer)
    {
        printf("Erreur d'existance de la buffer\n");
        return(int)-2;
    }
    //Test d'existance du texte
    if(!Text)
    {
         printf("\nMacro : Insert_Into_Begginning_Buffer\n");
        printf("-->Erreur de l'existance du texte\n");
        return(int)-4;
    }
    //Test de la possibilite de modifier le texte
    if(!T_Buffer->editable)
    {
        printf("Text ne peut pas etre modifier\n");
        return(int)-5;
    }
    //Ajout du texte au debut de la buffer
    gtk_text_buffer_insert(T_Buffer->Buffer,&T_Buffer->Start,Text,-1);
    //Recuperation des positions
    gtk_text_buffer_get_start_iter(T_Buffer->Buffer,&T_Buffer->Start);
    //Recuperation des positions
    gtk_text_buffer_get_end_iter(T_Buffer->Buffer,&T_Buffer->End);
    //Recuperation du texte
    T_Buffer->Text=gtk_text_buffer_get_text(T_Buffer->Buffer,&T_Buffer->Start,&T_Buffer->End,FALSE);
    return(int)0;
}
/*
    Le Macro Insert_Into_End_Buffer permet d'ajouter un texte a la fin de la buffer
    Les Entrees: -pointure sur la structure Text_Buffer
                 -le texte a ajouter
    Les Sortis : - 0 si l'ajout est effectue
                 - (-1) si la structure Text_Buffer n'exist pas
                 - (-2) si la buffer n'exist pas
                 - (-3) si le texte n'exist pas
                 - (-4) si le texte ne peut pas etre modifier
*/
int Insert_Into_End_Buffer(Text_Buffer* T_Buffer,const gchar* Text)
{
    //Test d'existance de la structure Text_Buffer
    if(!T_Buffer)
    {
        printf("\nMacro : Insert_Into_End_Buffer\n");
        printf("-->Erreur d'existance de la structure Text_Buffer\n");
        return(int)-1;
    }
    //Test d'existance de la buffer

    if(!T_Buffer->Buffer)
    {
        printf("Erreur d'existance de la buffer\n");
        return(int)-3;
    }
    //Test d'existance du texte
    if(!Text)
    {
        printf("Erreur de l'existance du texte\n");
        return(int)-4;
    }
    //Test de la possibilite de modifier le texte
    if(!T_Buffer->editable)
    {
        printf("Text ne peut pas etre modifier\n");
        return(int)-5;
    }
    //Ajout du texte a la fin de la buffer
    gtk_text_buffer_insert(T_Buffer->Buffer,&T_Buffer->End,Text,-1);
    //Recuperation des positions
    gtk_text_buffer_get_start_iter(T_Buffer->Buffer,&T_Buffer->Start);
    //Recuperation des positions
    gtk_text_buffer_get_end_iter(T_Buffer->Buffer,&T_Buffer->End);
    //Recuperation du texte
    T_Buffer->Text=gtk_text_buffer_get_text(T_Buffer->Buffer,&T_Buffer->Start,&T_Buffer->End,FALSE);
    return(int)0;
}


/*
    Le Macro Delete_Text_From_Buffer permet de supprimer un texte de la buffer
    Les Entrees: -pointure sur la structure Text_Buffer
                 -la position de debut
                 -la position de fin
    Les Sortis : - 1 si la suppression est effectue
                 - (-2) si la structure Text_Buffer n'exist pas
                 - (-3) si la buffer n'exist pas
                 - (-4) si le texte ne peut pas etre modifier
*/
int Delete_Text_From_Buffer(Text_Buffer* T_Buffer,int start,int end)
{
    //Test d'existance de la structure Text_Buffer
    if(!T_Buffer)
    {
        printf("\nMacro : Delete_Text_From_Buffer\n");
        printf("-->Erreur d'existance de la structure Text_Buffer\n");
        return(int)-2;
    }
    //Test d'existance de la buffer
    if(!T_Buffer->Buffer)
    {
        printf("Erreur d'existance de la buffer\n");
        return(int)-3;
    }
    //Test de la possibilite de modifier le texte
    if(!T_Buffer->editable)
    {
        printf("Text ne peut pas etre modifier\n");
        return(int)-4;
    }
    GtkTextIter Debut,Fin;
    //recuperer la debut du curseur
    gtk_text_buffer_get_iter_at_offset(T_Buffer->Buffer,&Debut,start);
    //recuperer la fin du curseur
    gtk_text_buffer_get_iter_at_offset(T_Buffer->Buffer,&Fin,end);
    //suppression du texte
    gtk_text_buffer_delete(T_Buffer->Buffer,&Debut,&Fin);
    //Recuperation des positions
    gtk_text_buffer_get_start_iter(T_Buffer->Buffer,&T_Buffer->Start);
    //Recuperation des positions
    gtk_text_buffer_get_end_iter(T_Buffer->Buffer,&T_Buffer->End);
    //Recuperation du texte
    T_Buffer->Text=gtk_text_buffer_get_text(T_Buffer->Buffer,&T_Buffer->Start,&T_Buffer->End,FALSE);
    return(int)1;
}
 /*
    Le Macro Get_Text_From_Buffer permet de recuperer le texte de la buffer
    Les Entrees: -pointure sur la structure Text_Buffer
                 -la position de debut
                 -la position de fin
    Les Sortis : -le texte
                 -NULL si la structure Text_Buffer n'exist pas
                 -NULL si la buffer n'exist pas
*/
gchar* Get_Text_From_Buffer(Text_Buffer* T_Buffer,int start,int end)
{
    //Test d'existance de la structure Text_Buffer
    if(!T_Buffer)
    {
        printf("\nMacro : Get_Text_From_Buffer\n");
        printf("-->Erreur d'existance de la structure Text_Buffer\n");
        return(gchar*)"NULL";
    }
    //Test d'existance de la buffer
    if(!T_Buffer->Buffer)
    {
        printf("Erreur d'existance de la buffer\n");
        return(gchar*)"NULL";
    }
    GtkTextIter Debut,Fin;
    //recuperer la debut du curseur
    gtk_text_buffer_get_iter_at_offset(T_Buffer->Buffer,&Debut,start);
    //recuperer la fin du curseur
    gtk_text_buffer_get_iter_at_offset(T_Buffer->Buffer,&Fin,end);
    //recuperation du texte
    return(gchar*)gtk_text_buffer_get_text(T_Buffer->Buffer,&Debut,&Fin,FALSE);
}

/*
    Le Macro Set_Text_To_Buffer permet de modifier le texte de la buffer
    Les Entrees: -pointure sur la structure Text_Buffer
                 -le texte a ajouter
    Les Sortis : - 0 si la modification est effectue
                 - (-2) si la structure Text_Buffer n'exist pas
                 - (-3) si la buffer n'exist pas
                 - (-4) si le texte n'exist pas
                 - (-5) si le texte ne peut pas etre modifier
*/
int Set_Text_To_Buffer(Text_Buffer* T_Buffer,const gchar* Text)
{
    //Test d'existance de la structure Text_Buffer
    if(!T_Buffer)
    {
        printf("\nMacro : Set_Text_To_Buffer\n");
        printf("-->Erreur d'existance de la structure Text_Buffer\n");
        return(int)-2;
    }
    //Test d'existance de la buffer
    if(!T_Buffer->Buffer)
    {
        printf("Erreur d'existance de la buffer\n");
        return(int)-3;
    }
    //Test d'existance du texte
    if(!Text)
    {
        printf("Erreur de l'existance du texte\n");
        return(int)-4;
    }
    //Test de la possibilite de modifier le texte
    if(!T_Buffer->editable)
    {
        printf("Text ne peut pas etre modifier\n");
        return(int)-5;
    }
    //Ajout du texte a la buffer
    gtk_text_buffer_set_text(T_Buffer->Buffer,Text,-1);
    //Recuperation des positions
    gtk_text_buffer_get_start_iter(T_Buffer->Buffer,&T_Buffer->Start);
    gtk_text_buffer_get_end_iter(T_Buffer->Buffer,&T_Buffer->End);
    //Recuperation du texte
    T_Buffer->Text=g_strdup(Text);
    return(int)0;
}


/*
  Le Macro Set_Editable_Buffer permet de modifier la possibilite de modifier le texte
    Les Entrees: -pointure sur la structure Text_Buffer
                 -la possibilite de modifier le texte
    Les Sortis : - 1 si la modification est effectue
                 - 0 si la structure Text_Buffer n'exist pas
*/
int Set_Editable_Buffer(Text_Buffer* T_Buffer,gboolean editable)
{
    //Test d'existance de la structure Text_Buffer
    if(!T_Buffer)
    {
        printf("\nMacro : Set_Editable_Buffer\n");
        printf("-->Erreur d'existance de la structure Text_Buffer\n");
        return(int)0;
    }
    //Test d'existance de la buffer
    T_Buffer->editable=editable;
    return(int)1;
}
