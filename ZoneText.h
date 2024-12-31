#include "C:\Users\hp\Documents\gtk\Les Sdd\ZoneText.h"




/*
    Le Macro Cree_Text_View permet de creer une zone de texte
    Les Entrees: -Rien
    Les Sortis : -pointure sur la structure Text_View
*/
Text_View* Cree_Text_View()
{
    //Allocation de memoire pour la structure Text_View
    Text_View* T_View=(Text_View*)malloc(sizeof(Text_View));
    //Test d'allocation
    if(!T_View)
    {
        printf("\nMacro : Cree_Text_View\n");
        printf("-->Erreur d'allocation de memoire pour la structure Text_View\n");
        exit(-1);
    }
    //Initialisation de la structure
    T_View->Zone_Buff=Init_Text_Buffer();
    //Creation de la zone de texte
    T_View->View=gtk_text_view_new();
    //Initialisation de la visibilite du curseur
    T_View->Zone_Buff->Buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(T_View->View));
    return(Text_View*)T_View;
}



/*
    Le Macro Cree_Text_View permet de creer une zone de texte avec une buffer
    Les Entrees: -pointure sur la structure Text_Buffer
    Les Sortis : -pointure sur la structure Text_View
*/
Text_View* Create_Text_View_With_Buffer(Text_Buffer* T_Buffer)
{
    //Test d'existance de la structure Text_Buffer
    if(!T_Buffer)
    {
        printf("\nMacro : Create_Text_View_With_Buffer\n");
        printf("-->Erreur d'existance de la structure Text_Buffer\n");
        exit(-1);
    }
    //Test d'existance de la buffer
    if(!T_Buffer->Buffer)
    {
        printf("\nMacro : Create_Text_View_With_Buffer\n");
        printf("-->Erreur d'existance de la buffer\n");
        exit(-1);
    }
    //Allocation de memoire pour la structure Text_View
    Text_View* T_View=(Text_View*)malloc(sizeof(Text_View));
    //Test d'allocation
    if(!T_View)
    {
        printf("\nMacro : Create_Text_View_With_Buffer\n");
        printf("-->Erreur d'allocation de memoire pour la structure Text_View\n");
        exit(-1);
    }
    //Initialisation de la structure
    T_View->Zone_Buff=T_Buffer;
    //Creation de la zone de texte
    T_View->View=gtk_text_view_new_with_buffer(T_Buffer->Buffer);
    return(Text_View*)T_View;
}



/*
    Le Macro Set_Buffer_To_TextView permet de modifier la buffer de la zone de texte
    Les Entrees: -pointure sur la structure Text_View
                 -pointure sur la structure Text_Buffer
    Les Sortis : - 0 si la modification est effectue
                 - (-1) si la structure Text_Buffer n'exist pas
                 - (-2) si la structure Text_View n'exist pas
*/
int Set_Buffer_To_TextView(Text_View* T_View,Text_Buffer* T_Buffer)
{
    //Test d'existance de la structure Text_View
    if(!T_View)
    {
        printf("\nMacro : Set_Buffer_To_TextView\n");
        printf("-->Erreur d'existance de la structure Text_View\n");
        return(int)-2;
    }
    //Test d'existance de la structure Text_Buffer
    if(!T_Buffer)
    {
        printf("\nMacro : Set_Buffer_To_TextView\n");
        printf("-->Erreur d'existance de la structure Text_Buffer\n");
        return(int)-1;
    }
    //Affectation de la buffer a la zone de texte
    T_View->Zone_Buff=T_Buffer;
    //Modification de la buffer
    gtk_text_view_set_buffer(GTK_TEXT_VIEW(T_View->View),T_Buffer->Buffer);
    return(int)0;
}



/*
    Le Macro Set_Buffer_TagTable permet de modifier le tableau des balises de la buffer
    Les Entrees: -pointure sur la structure Text_View
    Les Sortis : - 0 si la modification est effectue
                 - (-1) si la structure Text_View n'exist pas
*/
int Set_Cursor_Visibility_Text_View(Text_View* T_View,gboolean visible)
{
    //Test d'existance de la structure Text_View
    if(!T_View)
    {
        printf("\nMacro : Set_Cursor_Visibility_Text_View\n");
        printf("-->Erreur d'existance de la structure Text_View\n");
        return(int)-1;
    }
    //Test d'existance de la zone de texte
    if(!T_View->View)
    {
        printf("\nMacro : Set_Cursor_Visibility_Text_View\n");
        printf("-->Erreur d'existance de la zone de texte\n");
        return(int)-2;
    }
    //Affectation de la visibilite du curseur
    T_View->cursor_visible=visible;
    //Modification de la visibilite du curseur
    gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(T_View->View),visible);
    return(int)0;
}



/*
    Le Macro Set_Editable_Text_View permet de modifier la possibilite de modifier le texte
    Les Entrees: -pointure sur la structure Text_View
                 -la possibilite de modifier le texte
    Les Sortis : - 0 si la modification est effectue
                 - (-1) si la structure Text_View n'exist pas
                 - (-2) si la zone de texte n'exist pas
*/
int Set_Editable_Text_View(Text_View* T_View,gboolean editable)
{
    //Test d'existance de la structure Text_View
    if(!T_View)
    {
        printf("\nMacro : Set_Editable_Text_View\n");
        printf("-->Erreur d'existance de la structure Text_View\n");
        return(int)-1;
    }
    //Test d'existance de la zone de texte
    if(!T_View->View)
    {
        printf("\nMacro : Set_Editable_Text_View\n");
        printf("-->Erreur d'existance de la zone de texte\n");
        return(int)-2;
    }
    //Affectation de la possibilite de modifier le texte
    T_View->editable=editable;
    //Modification de la possibilite de modifier le texte
    Set_Editable_Buffer(T_View->Zone_Buff,editable);
    //Modification de la possibilite de modifier le texte
    gtk_text_view_set_editable(GTK_TEXT_VIEW(T_View->View),editable);
    return(int)0;
}


/*
    Le Macro Set_Left_Margin_TextView permet de modifier la marge gauche de la zone de texte
    Les Entrees: -pointure sur la structure Text_View
                 -la marge gauche
    Les Sortis : - 0 si la modification est effectue
                 - (-1) si la structure Text_View n'exist pas
*/
int Set_Left_Margin_TextView(Text_View* T_View,gint left_margin)
{
    //Test d'existance de la structure Text_View
    if(!T_View)
    {
        printf("\nMacro : Set_Left_Margin_TextView\n");
        printf("-->Erreur d'existance de la structure Text_View\n");
        return(int)-1;
    }
    //Test de la positivite de la marge
    if(left_margin<0)
    {
        printf("\nMacro : Set_Left_Margin_TextView\n");
        printf("-->La margin doit etre positif\n");
        return(int)0;
    }
    //Affectation de la marge gauche
    T_View->left_margin=left_margin;
    //Modification de la marge gauche
    gtk_text_view_set_left_margin(GTK_TEXT_VIEW(T_View->View),left_margin);
    return(int)0;
}


/*
    Le Macro Set_Right_Margin_TextView permet de modifier la marge droite de la zone de texte
    Les Entrees: -pointure sur la structure Text_View
                 -la marge droite
    Les Sortis : - 0 si la modification est effectue
                 - (-1) si la structure Text_View n'exist pas
*/
int Set_Right_Margin_TextView(Text_View* T_View,gint right_margin)
{
    //Test d'existance de la structure Text_View
    if(!T_View)
    {
        printf("\nMacro : Set_Right_Margin_TextView\n");
        printf("-->Erreur d'existance de la structure Text_View\n");
        return(int)-1;
    }
    //Test de la positivite de la marge
    if(right_margin<0)
    {
        printf("\nMacro : Set_Right_Margin_TextView\n");
        printf("-->La margin doit etre positif\n");
        return(int)0;
    }
    //Affectation de la marge droite
    T_View->right_margin=right_margin;
    //Modification de la marge droite
    gtk_text_view_set_right_margin(GTK_TEXT_VIEW(T_View->View),right_margin);
    return(int)0;
}


/*
    Le Macro Set_Zone_Text_To_Fenetre permet d'ajouter la zone de texte a la fenetre
    Les Entrees: -pointure sur la structure Fenetre
                 -pointure sur la structure Text_View
    Les Sortis : - 1 si l'ajout est effectue
                 - 0 si la structure Fenetre n'exist pas
                 - (-1) si la structure Text_View n'exist pas
*/
int Set_Zone_Text_To_Fenetre(Fenetre* F,Text_View* T_View)
{
    //Test d'existance de la structure Fenetre
    if(!F)
    {
        printf("\nMacro : Set_Zone_Text_To_Fenetre\n");
        printf("-->Erreur d'existance de la structure Fenetre\n");
        return(int)0;
    }
    //Test d'existance de la structure Text_View
    if(!T_View)
    {
        printf("\nMacro : Set_Zone_Text_To_Fenetre\n");
        printf("-->Erreur d'existance de la structure Text_View\n");
        return(int)-1;
    }
    //Ajout de la zone de texte a la fenetre
    gtk_container_add(GTK_CONTAINER(F->Wind),T_View->View);
    return(int)1;
}

/*
    Le Macro Set_Zone_Text_To_ScrollWindow permet d'ajouter la zone de texte a la ScrollBar
    Les Entrees: -pointure sur la structure ScrollBar
                 -pointure sur la structure Text_View
    Les Sortis : - 1 si l'ajout est effectue
                 - (-1) si la structure ScrollBar n'exist pas
                 - (-2) si la structure Text_View n'exist pas
*/
// int Set_Zone_Text_To_ScrollWindow(ScrollBar* S_B,Text_View* T_View)
// {
//     //Test d'existance de la structure ScrollBar
//     if(!S_B)
//     {
//         printf("\nMacro : Set_Zone_Text_To_ScrollWindow\n");
//         printf("-->Erreur d'existance de la structure ScrollBar\n");
//         return(int)-1;
//     }
//     //Test d'existance de la structure Text_View
//     if(!T_View)
//     {
//         printf("\nMacro : Set_Zone_Text_To_ScrollWindow\n");
//         printf("-->Erreur d'existance de la structure Text_View\n");
//         return(int)-2;
//     }

//     //Ajout de la zone de texte a la ScrollBar
//     gtk_container_add(GTK_CONTAINER(S_B->scrolled_window),T_View->View);
//     return(int)1;
// }

/*
    Le Macro Set_Zone_Text_To_Box permet d'ajouter la zone de texte a la box
    Les Entrees: -pointure sur la structure box
                 -pointure sur la structure Text_View
    Les Sortis : - 0 si la box n'exist pas
                 - (-1) si la structute de text_view
                 - 1    si l'ajout est effectue
*/
int Set_Zone_Text_To_Box(GtkWidget* Box,Text_View* T_View)
{
    //Test d'existance de la box
    if(!Box)
    {
        printf("Erreur d'existance de la structure Box\n");
        return(int)0;
    }
    //Test d'existance de la structure Text_View
    if(!T_View)
    {
        printf("Erreur d'existance de la structure Text_View\n");
        return(int)-1;
    }
    //Ajout de la zone de texte a la box
    gtk_box_pack_start(GTK_BOX(Box),T_View->View,TRUE,TRUE,0);
    
    return(int)1;
}