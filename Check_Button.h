#include "C:\Users\hp\Documents\gtk\Les Sdd\Check_Button.h"



/*
  La fonction Set_CheckButton_In_Grid permet d'ajouter un check button dans un container de type Grid
  Les Entrees: -pointure sur le check button
               -pointure sur le container Grid
               -les coordonnees de la position du check button dans le container
               -la largeur et la hauteur du check button
  Les Sortis : -1 si l'ajout est effectue
               -0 si le container n'exist pas
               -(-1) si le check button n'exist pas
*/
int Set_CheckButton_In_Grid(Check_Button* CB,GtkWidget* Grid,gint left,gint top,gint width,gint height)
{
    /*
      Test d'existance
    */
    if(!CB)
    {
        printf("Check Button n'exist pas");
        return(int)-1;
    }
    /*
      Test d'existance
    */
    if(!Grid)
    {
      printf("Le container Grid n'exist pas");
      return(int)0;
    }
    /*
      Affectation du parent
    */
    CB->Parent=Grid;
    /*
      Ajouter le check button dans le container
    */
    gtk_grid_attach(GTK_GRID(Grid),CB->Check,left,top,width,height);
    return(int)1;
}

/*
  La fonction Set_CheckButton_Label permet de modifier le texte de la check button
  Les Entrees: -pointure sur le check button
               -le texte a afficher
  Les Sortis : -1 si la modification est effectue
               -0 si le check button n'exist pas
*/
int Set_CheckButton_Lable(Check_Button* CB,gchar* label)
{
  /*
    Test d'existance
  */
  if(!CB)
  {
    printf("\nMacro :Set_CheckButton_Lable\n");
    printf("-->Erreur d'existence de Check Button");
    return(int)0;
  }
  /*
    Modification du texte
  */
  CB->Label=g_strdup(label);
  gtk_button_set_label(GTK_BUTTON(CB->Check),CB->Label);

  return(int)1;
}


/*
  La fonction Set_CheckButton_State permet de modifier l'etat de la check button
  Les Entrees: -pointure sur le check button
               -l'etat a afficher
  Les Sortis : -1 si la modification est effectue
               -0 si le check button n'exist pas
*/
int Set_CheckButton_State(Check_Button* CB,gboolean state)
{
  /*
    Test d'existance
  */
  if(!CB)
  {
    printf("\nMacro :Set_CheckButton_State\n");
    printf("-->Erreur d'existence de Check Button");
    return(int)0;
  }
  /*
    Modification de l'etat
  */
  CB->state=state;
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(CB->Check),CB->state);

  return(int)1;
}

/*
  La fonction Set_CheckButton_Active permet de modifier l'etat de la check button
  Les Entrees: -pointure sur le check button
               -l'etat a afficher
  Les Sortis : -1 si la modification est effectue
               -0 si le check button n'exist pas
*/
int Set_CheckButton_Active(Check_Button* CB,gboolean active)
{
  /*
    Test d'existance
  */
  if(!CB)
  {
    printf("\nMacro :Set_CheckButton_Active\n");
    printf("-->Erreur d'existence de Check Button");
    return(int)0;
  }
  /*
    Modification de l'etat
  */
  CB->active=active;
  gtk_widget_set_sensitive(CB->Check,CB->active);

  return(int)1;
}

/*
  La fonction Set_CheckButton_Position permet de modifier la position de la check button
  Les Entrees: -pointure sur le check button
               -les coordonnees de la position du check button
  Les Sortis : -1 si la modification est effectue
               -0 si le check button n'exist pas
*/
int Set_CheckButton_Position(Check_Button* CB,Position pos)
{
  /*
    Test d'existance
  */
  if(!CB)
  {
    printf("\nMacro :Set_CheckButton_Position\n");
    printf("-->Erreur d'existence de Check Button");
    return(int)0;
  }
  /*
    Modification de la position
  */
  CB->position.X=pos.X;
  CB->position.Y=pos.Y;

  return(int)1;
}

/*
  La fonction Set_CheckButton_ID permet de modifier l'ID de la check button
  Les Entrees: -pointure sur le check button
               -l'ID a afficher
  Les Sortis : -1 si la modification est effectue
                -0 si le check button n'exist pas
*/
int Set_CheckButton_ID(Check_Button* CB,gchar* ID)
{
  /*
    Test d'existance
  */
  if(!CB)
  {
    printf("\nMacro :Set_CheckButton_ID\n");
    printf("-->Erreur d'existence de Check Button");
    return(int)0;
  }
  /*
    Modification de l'ID
  */
  CB->Id=g_strdup(ID);
  gtk_widget_set_name(CB->Check,CB->Id);

  return(int)1;
}

/*
  La fonction Get_CheckButton_Label permet de recuperer le texte de la check button
  Les Entrees: -pointure sur le check button
  Les Sortis : -le texte de la check button
               -NULL si le check button n'exist pas
*/
gboolean Get_Etat_CheckButton(Check_Button *cb) 
{
    // Vérifier si le pointeur est NULL
    if(cb->Check)
        return(gboolean)gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cb->Check));
    return(gboolean)FALSE;
}


/*
  La fonction Create_Check_Button permet de creer un check button
  Les Entrees: -le texte a afficher
               -l'etat de la check button
               -l'etat de l'interaction
               -la position de la check button
               -l'ID de la check button
  Les Sortis : -pointure sur le check button
*/
Check_Button* Create_Check_Button(gchar* label,gboolean state,gboolean active,Position pos,gchar* ID)
{
    Check_Button* ch_button;
    // Allocation de memoire pour le check button
    ch_button=(Check_Button*)malloc(sizeof(Check_Button));
    /*
      Test d'allocation
    */
    if(!ch_button)
    {
      printf("\nMacro :Create_Check_Button\n");
      printf("-->Erreur d'allocation de memoire pour le check button");
      exit(-1);
    }
    
    // Creation du check button
    ch_button->Check=gtk_check_button_new();

    /*
      Affectation des parametres
    */
    Set_CheckButton_Lable(ch_button,label);

    Set_CheckButton_Active(ch_button,active);

    Set_CheckButton_State(ch_button,state);

    Set_CheckButton_ID(ch_button,ID);

    return(Check_Button*)ch_button;
}



Check_Button* Create_Check_Button_With_Mnemonique(gchar* label)
{
    Check_Button* ch_button;
    // Allocation de memoire pour le check button
    ch_button=(Check_Button*)malloc(sizeof(Check_Button));
    /*
      Test d'allocation
    */
    if(!ch_button)
    {
      printf("\nMacro :Create_Check_Button_With_Mnemonique\n");
      printf("-->Erreur d'allocation de memoire pour le check button");
      exit(-1);
    }
    ch_button->Label=g_strdup(label);

    ch_button->Check=gtk_check_button_new_with_mnemonic(label);
    return(Check_Button*)ch_button;
}



Check_Button* Initialise_Check_Button()
{
  //Allocation de memoire pour la structure check_button
  Check_Button* CB=(Check_Button*)malloc(sizeof(Check_Button));
  //Test d'allocation
  if (!CB)
  {
    printf("\nMacro :Initialise_Check_Button\n");
    printf("-->Erreur d'allocation pout la structure check_button");
    exit(-1);
  }
  //Creation du check button
  CB->Check=gtk_check_button_new();
  return(Check_Button*)CB;
}

/*
  La fonction Unique_CheckButton_ID permet de verifier si l'ID de check button est unique
  Les Entrees: -pointure sur la liste des check buttons
               -l'ID de check button a verifier
  Les Sortis : -1 si l'ID est unique
               -0 si l'ID n'est pas unique
*/
int Unique_CheckButton_ID(Check_Button_Liste* liste,gchar* ID)
{
    
    Check_Button_Liste* tmp;
    tmp=liste;
    /*
      Parcourir la liste des check buttons
      en cherchant si l'ID existe deja
    */
    while(tmp)
    {
        // Si l'ID existe deja
        if(strcmp(tmp->Head->Id,ID)==0)
        {
            return(int)0;
        }
        // Passer au check button suivant
        tmp=tmp->next;
    }
    // Si l'ID n'existe pas
    return(int)1;
}


/*
  La fonction Add_Check_Button permet d'ajouter un check button a une liste des check buttons
  Les Entrees: -pointure sur la liste des check buttons
               -pointure sur le check button a ajouter
  Les Sortis : -la liste des check buttons apres l'ajout
*/
Check_Button_Liste* Add_Check_Button(Check_Button_Liste* liste,Check_Button* CB)
{
    /*
      Allocation de memoire pour le check button
    */
    Check_Button_Liste* tmp;
    tmp=(Check_Button_Liste*)malloc(sizeof(Check_Button_Liste));
    /*
      Test d'allocation
    */
    if(!tmp)
    {
      printf("\nMacro :Add_Check_Button\n");
      printf("Erreur d'allocation de memoire pour la liste des check buttons");
      exit(-1);
    }
    /*
      Test d'existance
    */
    if(!CB)
    {
      printf("\nMacro :Add_Check_Button\n");
      printf("Check Button n'exist pas");
      return(Check_Button_Liste*)liste;
    }
    /*
      Test d'unicite de l'ID
    */
    if(!Unique_CheckButton_ID(liste,CB->Id))
    {
      printf("\nMacro :Add_Check_Button\n");
      printf("L'ID de check button n'est pas unique");
      return(Check_Button_Liste*)liste;
    }
    /*
      Ajout du check button
    */
    tmp->Head=CB;
    tmp->next=liste;
    return(Check_Button_Liste*)tmp;
}



/*
  La fonction Remove_Check_Button permet de supprimer un check button de la liste des check buttons
  Les Entrees: -pointure sur la liste des check buttons
               -l'ID de check button a supprimer
  Les Sortis : -la liste des check buttons apres la suppression
*/
Check_Button_Liste* Remove_Check_Button(Check_Button_Liste* liste,gchar* ID)
{
    //pointure pour parcourir la liste
    Check_Button_Liste* tmp;
    //pointure pour garder le check button precedent
    Check_Button_Liste* prev;

    tmp=liste;
    prev=NULL;
    /*
      Parcourir la liste des check buttons
      en cherchant le check button a supprimer
    */
    while(tmp)
    {
        // Si le check button a supprimer est trouve
        if(strcmp(tmp->Head->Id,ID)==0)
        {   
            // Si le check button a supprimer est le premier
            if(prev)
            {
                prev->next=tmp->next;
                free(tmp);
                return(Check_Button_Liste*)liste;
            }
            else// Si le check button a supprimer est a l'intrieur de la liste
            {
                liste=tmp->next;
                free(tmp);
                return(Check_Button_Liste*)liste;
            }
        }
        /*
          Passer au check button suivant
          en restant le check button precedent
        */
        prev=tmp;
        tmp=tmp->next;
    }
    return(Check_Button_Liste*)liste;
}