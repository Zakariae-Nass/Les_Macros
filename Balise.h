#include "C:\Users\hp\Documents\gtk\Les Sdd\Balise.h"




/*
  La Macro Create_Balise permet de creer une balise
  Les Entrees: -le nom de la balise
  Les Sortis : -pointure sur la balise cree
*/
Balise* Create_Balise(gchar* nom)
{
    //Allocation de memoire pour la balise
    Balise* B=(Balise*)malloc(sizeof(Balise));
    /*
      Test d'allocation
    */
    if(!B)
    {
        printf("Erreur d'allocation de memoire pour la balise\n");
        exit(-1);
    }
    //Creation de la balise avec le nom
    B->Tag=gtk_text_tag_new(nom);
    //Affectation du nom au structure
    B->nom=nom;
    return(Balise*)B;
}




/*
  La fonction Set_Balise_TextColor permet de modifier la couleur du texte
  Les Entrees: -pointure sur la balise
               -la couleur du texte le nom de la couleur (ex: "red")
  Les Sortis : - 1 si la modification est effectue
               - 0 si la balise n'exist pas
               - (-1) si la couleur n'exist pas
*/
int Set_Balise_TextColor(Balise* B,gchar* color)
{
    //Test d'existance pour la balise
    if(!B)
    {
        printf("Macro : Set_Balise_TextColor\n");
        printf("-->Erreur d'existance de la structure Balise\n");
        return(int)-2;
    }
    //Test d'existance de la couleur
    if(!color)
    {
        printf("Macro : Set_Balise_TextColor\n");
        printf("-->Erreur d'existance de la couleur\n");
        return(int)-3;
    }
    //Affectation de la couleur
    B->text_color=color;
    //Modification de la couleur
    g_object_set(B->Tag,"foreground",color,NULL);
    return(int)0;
}



/*
  La fonction Set_Balise_BackgroundColor permet de modifier la couleur de fond
  Les Entrees: -pointure sur la balise
               -la couleur de fond le nom de la couleur (ex: "red")
  Les Sortis : - 1 si la modification est effectue
               - 0 si la balise n'exist pas
               - (-1) si la couleur n'exist pas
*/
int Set_Balise_BackgroundColor(Balise* B,gchar* color)
{

    //Test d'existance pour la balise
    if(!B)
    {
        printf("\nMacro : Set_Balise_BackgroundColor\n");
        printf("-->Erreur d'existance de la structure Balise\n");
        return(int)0;
    }
    //Test d'existance de la couleur
    if(!color)
    {
        printf("\nMacro : Set_Balise_BackgroundColor\n");
        printf("-->Erreur d'existance de la couleur\n");
        return(int)-1;
    }
    //Affectation de la couleur
    B->background_color=color;
    //Modification de la couleur
    g_object_set(G_OBJECT(B->Tag),"background",color,NULL);
    return(int)1;
}

/*
  La fonction Set_Balise_Weight permet de modifier la police du texte
  Les Entrees: -pointure sur la balise
               -la police du texte/* 
                                    les valeur possible sont:
                                    - BOLD
                                    - NORMAL_BOLD
                                    - THIN
                                    - ULTRABOLD
                                    - HEAVY
                                    - LIGHT
                                    - SEMIBOLD
                       
  Les Sortis : - 1 si la modification est effectue
               - 0 si la balise n exist pas
*/
int Set_Balise_Weight(Balise* B,PangoWeight weight)
{
    //Test d'existance pour la balise
    if(!B)
    {
        printf("\nMacro : Set_Balise_Weight\n");
        printf("-->Erreur d'existance de la structure Balise\n");
        return(int)0;
    }
    //Affectation de la police
    B->weight=weight;
    //Modification de la police
    g_object_set(G_OBJECT(B->Tag),"weight",weight,NULL);
    return(int)1;
}


/*
  La fonction Set_Balise_Style permet de modifier le style du texte
  Les Entrees: -pointure sur la balise
               -le style du texte/* 
                                    les valeur possible sont:
                                    - ITALIC
                                    - NORMAL
                                    - OBLIQUE
  Les Sortis : - 1 si la modification est effectue
               - 0 si la balise n exist pas
*/
int Set_Balise_Style(Balise* B,PangoStyle style)
{
    //Test d'existance pour la balise
    if(!B)
    {
        printf("\nMacro : Set_Balise_Style\n");
        printf("-->Erreur d'existance de la structure Balise\n");
        return(int)0;
    }
    //Affectation du style
    B->style=style;
    //Modification du style
    g_object_set(G_OBJECT(B->Tag),"style",style,NULL);
    return(int)1;
}



/*
  La fonction Set_Balise_Underline permet de modifier le soulignement du texte
  Les Entrees: -pointure sur la balise
               -le soulignement du texte/* 
                                    les valeur possible sont:
                                    - NONE_LINE
                                    - SINGLE_LINE
                                    - DOUBLE_LINE
                                    
  Les Sortis : - 1 si la modification est effectue
               - 0 si la balise n exist pas
*/
int Set_Balise_Underline(Balise* B,PangoUnderline underline)
{
    //Test d'existance pour la balise
    if(!B)
    {
        printf("\nMacro : Set_Balise_Underline\n");
        printf("-->Erreur d'existance de la structure Balise\n");
        return(int)0;
    }
    //Affectation du soulignement
    B->underline=underline;
    g_object_set(G_OBJECT(B->Tag),"underline",underline,NULL);
    return(int)1;
}


/*
  La fonction Set_Balise_Size permet de modifier la taille du texte
  Les Entrees: -pointure sur la balise
               -la taille du texte/* 
                                    les valeur possible sont:
                                    - 10
                                    - 12
                                    - 14
                                    ...
                                    
  Les Sortis : - 1 si la modification est effectue
               - 0 si la balise n exist pas
*/
int Set_Balise_Size(Balise* B,gint size)
{
    //Test d'existance pour la balise
    if(!B)
    {
        printf("\nMacro : Set_Balise_Size\n");
        printf("-->Erreur d'existance de la structure Balise\n");
        return(int)0;
    }
    //Affectation de la taille
    B->size=size;
    //Modification de la taille
    g_object_set(G_OBJECT(B->Tag),"size",size,NULL);
    return(int)1;
}


/*
  La fonction Set_Balise_LineSpace permet de modifier l'espacement entre les lignes
  Les Entrees: -pointure sur la balise
               -l'espacement entre les lignes(int)
  Les Sortis : - 1 si la modification est effectue
               - 0 si la balise n exist pas
*/
int Set_Balise_LineSpace(Balise* B,gint line_space)
{
    //Test d'existance pour la balise
    if(!B)
    {
        printf("\nMacro : Set_Balise_LineSpace\n");
        printf("-->Erreur d'existance de la structure Balise\n");
        return(int)0;
    }
    //Affectation de l'espacement
    B->line_space=line_space;

    //mettre l'espacement entre les lignes
    g_object_set(G_OBJECT(B->Tag), "pixels-below-lines", line_space, NULL);
    return(int)1;
}

/*
  La fonction Set_Balise_LetterSpace permet de modifier l'espacement entre les lettres
  Les Entrees: -pointure sur la balise
               -l'espacement entre les lettres(int)
  Les Sortis : - 1 si la modification est effectue
               - 0 si la balise n exist pas
*/
int Set_Balise_LetterSpace(Balise* B,gint letter_space)
{
    //Test d'existance pour la balise
    if(!B)
    {
        printf("\nMacro : Set_Balise_LetterSpace\n");
        printf("-->Erreur d'existance de la structure Balise\n");
        return(int)0;
    }
    //Affectation de l'espacement
    B->letter_space=letter_space;
    //Modification de l'espacement
    g_object_set(B->Tag,"letter-spacing",letter_space,NULL);
    return(int)1;
}


/*
  La fonction Set_Balise_Line_Retour permet de modifier le retour a la ligne
  Les Entrees: -pointure sur la balise
               -le retour a la ligne/* 
                                    les valeur possible sont:
                                    - WORD
                                    - CHAR
                                    - BOTH_W_C
                                    - NONE
                                    
  Les Sortis : - 1 si la modification est effectue
               - 0 si la balise n exist pas
*/
int Set_Balise_Line_Retour(Balise* B,GtkWrapMode Line_Return)
{
    //Test d'existance pour la balise
    if(!B)
    {
        printf("\nMacro : Set_Balise_Line_Retour\n");
        printf("-->Erreur d'existance de la structure Balise\n");
        return(int)0;
    }
    //Affectation du retour a la ligne
    B->Line_Return=Line_Return;
    //Modification du retour a la ligne
    g_object_set(G_OBJECT(B->Tag),"wrap-mode",Line_Return,NULL);
    return(int)1;
}


/*
  La fonction Set_Balise_Alignment permet de modifier l'alignement du texte
  Les Entrees: -pointure sur la balise
               -l'alignement du texte/* 
                                    les valeur possible sont:
                                    - LEFT
                                    - RIGHT
                                    - CENTER
                                    - FILL
                                    
  Les Sortis : - 1 si la modification est effectue
               - 0 si la balise n exist pas
*/
int Set_Balise_Alignment(Balise* B,GtkJustification Alignment)
{
    //Test d'existance pour la balise
    if(!B)
    {
        printf("\nMacro : Set_Balise_Alignment\n");
        printf("-->Erreur d'existance de la structure Balise\n");
        return(int)0;
    }
    //Affectation de l'alignement
    B->Alignement=Alignment;
    //Modification de l'alignement
    g_object_set(G_OBJECT(B->Tag),"justification",Alignment,NULL);
    return(int)1;
}