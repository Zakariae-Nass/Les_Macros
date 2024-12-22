#include "C:\Users\hp\Documents\gtk\Les Sdd\Fenetre.h"

/*
  definiton des positions
*/
#define Aucune_Pos              GTK_WIN_POS_NONE
#define Pos_Centre              GTK_WIN_POS_CENTER
#define Pos_du_curseur          GTK_WIN_POS_MOUSE
#define Pos_Tjrs_centrer        GTK_WIN_POS_CENTER_ALWAYS
#define Pos_Centrer_parent      GTK_WIN_POS_CENTER_ON_PARENT



/*
    Le Macro Cree_Fenetre Pour alloue la memoire pour un fenetre
    Les Entres : 
                    Rien 
    Les Sorties :
                    Pointeur De Type Fenetre
*/
Fenetre* Cree_Fenetre()
{
    /*
       Allocation de memoire
    */
    Fenetre* fen=(Fenetre*)malloc(sizeof(Fenetre));
    /*
      Test d'existance
    */
    if(!fen)
    {
        printf("Erreur dans la fenetre");
        exit(-1);
    }
    /*
      Test d'existance
    */
    if(!fen->Wind)
    {
        printf("Erruer dans la fenetre");
        exit(-1);
    }
    /*
      Retourne de la Fenetre
    */
    return (Fenetre*)fen;
}



/*
    Le Macro Afficher_Fenetre Pour Afficher sur l'ecran un Fenetre
    Les Entres : 
                    Pointeur De Type Fenetre 
    Les Sorties :
                    Rien
*/
void Afficher_Fenetre(Fenetre* fen)
{
    /*
      Test d'existance
    */
    if(!fen)
    {
        printf("Erreur dans la fenetre");
        exit(-1);
    }
    /*
      Test d'existance
    */
    if(!fen->Wind)
    {
        printf("Erruer dans la fenetre");
        exit(-1);
    }
    /*
       L'affichage de Fenetre et tous les widgets qui contient
    */
    gtk_widget_show_all(fen->Wind);
}






/*
    Le Macro Set_Window_Type Pour definir le type de la Fenetre
    Types       :   *TOPLEVEL(TRUE)
                    *POPUP(FALSE)
    Les Entres  : 
                    *Pointeur De Type Fenetre 
                    *Variable de type boolean qui indique le type de fenetre
    Les Sorties :
                    Rien
*/
void Set_Window_Type(Fenetre* fen,gboolean type)
{
    /*
      Test d'existance
    */
    if(!fen)
    {
        printf("Erreur dans la fenetre");
        exit(-1);
    }
    /*
      Test d'existance
    */
    if(!fen->Wind)
    {
        printf("Erruer dans la fenetre");
        exit(-1);
    }
    /*
      Definir le type pour la fenetre
    */
    if(type)
        fen->Wind=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    else
        fen->Wind=gtk_window_new(GTK_WINDOW_POPUP);
    /*
      Recuperation de type dans la structure
    */
    fen->Type=type;
}





/*
    Le Macro Set_Window_Decorate Pour effectue la barre la Fenetre ou non 
    Types       :   *avec Headbar(TRUE)
                    *sans Headbar(FALSE)
    Les Entres  : 
                    *Pointeur De Type Fenetre 
                    *Variable de type boolean indique l'existance de headbar
    Les Sorties :
                    Rien
*/
void Set_Window_Decorate(Fenetre *fen,gboolean Headbar)
{
    /*
      Test d'existance
    */
    if(!fen)
    {
        printf("Erreur dans l'adresse fenetre");
        exit(-1);
    }
    /*
      Test d'existance
    */
    if(!fen->Wind)
    {
        printf("Erruer dans la fenetre");
        exit(-1);
    }
    /*
      Applique la décoration en fonction du paramètre Headbar
    */ 
    gtk_window_set_decorated(GTK_WINDOW(fen->Wind), Headbar);
    /*
      Recuperer le parametre
    */
    fen->Headbar = Headbar;
}




/***************size******************/

/*
    La Fonction Definir_Taille Pour donner une taille a la fentre
    Les Entres : 
                    Pointeur De Type Fenetre, cordonnee x , cordonne y 
    Les Sorties :
                    Rien
*/
void Definir_Taille(Fenetre *f, gint x, gint y) 
{
    /*
      Test d'existance
    */
    if(!f)
    {
        printf("Erreur dans la fenetre");
        exit(-1);
    }

    f->Size.X = x;
    f->Size.Y = y;

    gtk_window_set_default_size(GTK_WINDOW(f->Wind), x, y);//donner a la fentre une taille de x et y
}







/*
    La Fonction Recuperer_Taille pour récupérer la taille actuelle de la fenêtre.
    Les Entrées : 
                    Pointeur de type Fenetre
    Les Sorties :
                    Largeur et hauteur via une variable Taille .
*/
Taille Recuperer_Taille(Fenetre *f) 
{
   Taille T;
   /*
      Test d'existance
   */
    if(!f)
    {
    printf("la fentre n'exsite pas");
    exit(-1);
    }

    T.X = f->Size.X;
    T.Y = f->Size.Y;

    return (Taille)T;
}







/********rezizable*******/
/*
    La Fonction Definir_Redimensionnable pour définir si une fenêtre peut être redimensionnée ou non.
    Les Entrées :
                    Pointeur de type Fenetre, valeur booléenne (TRUE ou FALSE).
    Les Sorties :
                    Rien.
*/
void Definir_Redimensionnable(Fenetre *f, gboolean resizable) 
{
     if(!f)
    {
    printf("la fentre n'exsite pas");
    exit(-1);
    }

    f->Resizable = resizable;

    gtk_window_set_resizable(GTK_WINDOW(f->Wind), resizable); // donner ala fenetre cette propriétés
}


/******pos*********/
/*
    La Fonction Definir_Position pour positionner la fenêtre aux coordonnées données.
    Les Entrées :
                    Pointeur de type Fenetre, coordonnées x et y.
    Les Sorties :
                    Rien.
*/
void Definir_Position(Fenetre *f, gint x, gint y) 
{
     if(!f)
      {
      printf("la fentre n'exsite pas");
      exit(-1);
      }

    f->Position.X = x;
    f->Position.Y = y;

    gtk_window_move(GTK_WINDOW(f->Wind), x, y);
}





/*
    La Fonction Recuperer_Position pour récupérer la position actuelle de la fenêtre.
    Les Entrées :
                    Pointeur de type Fenetre.
    Les Sorties :
                    Une structure Position contenant les coordonnées x et y.
*/
Position Recuperer_Position(Fenetre *f) 
{
     Position pos;

     if(!f)
       {
         printf("la fentre n'exsite pas");
         exit(-1);
       }

    gtk_window_get_position(GTK_WINDOW(f->Wind), &pos.X, &pos.Y);

    return pos;
}





/*
    La Fonction Definir_Position_Connu pour définir la position connue d'une fenêtre.
    Les Entrées :
                    Pointeur de type Fenetre, valeur entière correspondant à la position.
    Les Sorties :
                    Rien.
*/
void Definir_Position_Connu(Fenetre *f, gint position) 
{
    if(!f)
       {
        printf("la fentre n'exsite pas");
        exit(-1);
       }
    switch (position) {
        case 0:
            gtk_window_set_position(GTK_WINDOW(f->Wind), Aucune_Pos);
            break;
        case 1:
            gtk_window_set_position(GTK_WINDOW(f->Wind), Pos_Centre);
            break;
        case 2:
            gtk_window_set_position(GTK_WINDOW(f->Wind), Pos_du_curseur);
            break;
        case 3:
            gtk_window_set_position(GTK_WINDOW(f->Wind), Pos_Tjrs_centrer);
            break;
        case 4:
            gtk_window_set_position(GTK_WINDOW(f->Wind), Pos_Centrer_parent);
            break;
        default:
            // Gestion de l'erreur ou position par défaut si nécessaire
            break;
    }
}






/*
    La Fonction mettre_en_plein_ecran pour mettre la fenêtre en plein écran.
    Les Entrées :
                    Pointeur de type Fenetre.
    Les Sorties :
                    Rien.
*/
void mettre_en_plein_ecran(Fenetre *f) 
{
    if(!f)
      {
       printf("la fentre n'exsite pas");
       exit(-1);
      }

    gtk_window_fullscreen(GTK_WINDOW(f->Wind));
}




/*
    La Fonction quitter_plein_ecran pour quitter le mode plein écran.
    Les Entrées :
                    Pointeur de type Fenetre.
    Les Sorties :
                    Rien.
*/
void quitter_plein_ecran(Fenetre *f) 
{
    if(!f)
     {
      printf("la fentre n'exsite pas");
      exit(-1);
     }

    gtk_window_unfullscreen(GTK_WINDOW(f->Wind));
}






/*
    La Fonction Fenetre_Set_BackGround_Image Pour Ajoute Un Image Comme BackGround D'une Window
    Les Entres : 
                    Pointeur De Type Fenetre, Chaine De Caracteres 
    Les Sorties :
                    Rien
*/
void Fenetre_Set_BackGround_Image(Fenetre *F_Ptr,gchar *BackGroundPath)                
{
    /*
        Test D'Exsitance
    */
    if (!F_Ptr)
    {
        printf("Erreur Dans L'Adress Fenetre. ");
        exit(0);
    }

    /*
        Test D'Exsitance
    */
    if(!F_Ptr->Wind)
    {
        printf("Erruer Dans L'Adress Wind.");
        exit(0);
    }

    /*
        Création D'un Conteneur GtkOverlay Joue Le Role Comme Box Ou Fixed Pour Encapsule L'image
    */
    GtkWidget *overlay = gtk_overlay_new();
    /*
        Affecter Notre Overlay Cree A Notre Fenetre Pass En Parametres 
    */
    gtk_container_add(GTK_CONTAINER(F_Ptr->Wind), overlay);

    F_Ptr->BackGround = BackGroundPath;

    /* 
        Chargement L'image A Traiter
    */
    GtkWidget *Image = gtk_image_new_from_file(F_Ptr->BackGround);

    F_Ptr->BackGround = BackGroundPath;
    /*
        Ajout de l'image au conteneur GtkOverlay
    */
    gtk_overlay_add_overlay(GTK_OVERLAY(overlay),Image);

}



/*
    La Fonction Fenetre_Set_BackGround_Color Pour Ajoute Une Color Comme BackGround D'une Window
    Les Entres : 
                    Pointeur De Type Fenetre, Chaine De Caracteres 
    Les Sorties :
                    Rien
*/


void Fenetre_Set_BackGround_Color(Fenetre *F_Ptr,char *ColorBg)
{
    /*
        Test D'Exsitance
    */
    if (!F_Ptr)
    {
        printf("Erreur Dans L'Adress Fenetre. ");
        exit(0);
    }
    /*
        Test D'Exsitance
    */
    if(!F_Ptr->Wind)
    {
        printf("Erruer Dans L'Adress Wind.");
        exit(0);
    }   

    /*
        Initailiser Un Objet De Type Color  
    */

    GdkColor Color;
    /*
        Affecter Le Color A Notre Objet Initailiser 
    */
    //gdk_color_parse(ColorBg, &Color); gdk_rgba_parse();gdk_color_parse()

    /*
        Affecter Le Color Au Window
    */

    //gtk_widget_modify_bg(F_Ptr->Wind, GTK_STATE_NORMAL, &Color);

    F_Ptr->ColorBg = ColorBg;

}




/*********************************************************************
 * Description: Récupère la valeur du champ Icon de la structure Fenetre.
 * Entrées: fen Pointeur vers la structure Fenetre.
 * Sorties: const gchar* La valeur actuelle de l'icône ou NULL si la structure est invalide.
 **********************************************************************/
gchar* get_fenetre_icon(Fenetre *fen)
{
    // Vérifie si le pointeur vers la structure Fenetre est NULL
    if (!fen)
    {
        // Affiche un message d'avertissement dans la console si la structure est invalide
        g_warning("get_fenetre_icon: Structure Fenetre invalide (NULL).");
        return NULL;  // Retourne NULL car la structure est invalide
    }
    // Retourne la valeur actuelle du champ Icon
    return fen->Icon;
}//Fin de la fonction


/********************************************************************
 * Description: Définit une nouvelle valeur pour le champ Icon.
 * Entrées: -fen Pointeur vers la structure Fenetre.
 *	    -new_icon Nouvelle valeur (chemin) pour le champ Icon.
 *******************************************************************/
void set_fenetre_icon(Fenetre *fen, const gchar *new_icon)
{
    // Vérifie si le pointeur vers la structure Fenetre est NULL
    if (!fen) 
    {
        // Affiche un message d'avertissement dans la console si la structure est invalide
        g_warning("set_fenetre_icon: Structure Fenetre invalide (NULL).");
        exit(-1);  // quitte immédiatement car il n'y a rien à modifier
    }

    // Libère la mémoire de l'ancienne valeur du champ Icon si elle existe
    if (fen->Icon) g_free(fen->Icon);

    // Duplique la nouvelle chaîne pour garantir qu'elle est indépendante de l'entrée
    fen->Icon = g_strdup(new_icon);
    // `g_strdup` alloue une nouvelle zone mémoire et copie le contenu de `new_icon` dedans
}//Fin de la fonction



/********************************************************************
 * Description: Vérifie si le champ Icon est vide (NULL ou chaîne vide).
 *
 * Entrées: fen Pointeur vers la structure Fenetre.
 * Sorties: gboolean TRUE si le champ est vide, FALSE sinon.
 *********************************************************************/
gboolean is_icon_empty(const Fenetre *fen)
{
    if (!fen)
    {
        g_warning("is_icon_empty: Structure Fenetre invalide (NULL).");
        return TRUE; // Considère comme "vide" si la structure est NULL
    }
    return (fen->Icon == NULL || strlen(fen->Icon) == 0);
}




/**
 * Description: Met à jour l'icône de la fenêtre associée avec un fichier image.
 *
 * Cette fonction utilise le chemin déjà initialisé dans le champ Icon
 * pour charger et définir l'icône de la fenêtre.
 *
 * Entrées: fen Pointeur vers la structure Fenetre.
 */
void update_fenetre_icon_from_file(Fenetre *fen) 
{
    if (!fen || !fen->Wind || !fen->Icon) 
    {
        g_warning("update_fenetre_icon_from_file: Paramètres invalides ou champ Icon non initialisé.");
        exit(-1);
    }

    // Charge l'image depuis le fichier indiqué dans Icon
    GError *error = NULL;
    GdkPixbuf *icon = gdk_pixbuf_new_from_file(fen->Icon, &error);
    if (!icon) 
    {
        g_warning("Erreur lors du chargement de l'icône (%s) : %s",fen->Icon,error->message);
        g_error_free(error);
        exit(-1);
    }

    // Définit l'icône de la fenêtre
    gtk_window_set_icon(GTK_WINDOW(fen->Wind), icon);

    // Libère la mémoire associée à l'objet GdkPixbuf
    g_object_unref(icon);
}



/*
 * Description: Réinitialise l'icône de la fenêtre avec une valeur par défaut.
 *
 * Entrées:- fen Pointeur vers la structure Fenetre.
 *         - default_value Valeur par défaut (chemin ou nom d'icône thématique).
 *         - is_theme Indique si la valeur par défaut est un nom thématique.
 */
/*void reset_fenetre_icon(Fenetre *fen, const gchar *default_value, gboolean is_theme) 
{
    if (!fen || !default_value) {
        g_warning("reset_fenetre_icon: Paramètres invalides.");
        exit(-1);
    }

    // Applique la nouvelle icône en fonction du type (thématique ou fichier)
    if (is_theme) 
    {
        update_fenetre_icon_from_theme(fen, default_value);
    }
    else 
    {
        set_fenetre_icon(fen, default_value);

        update_fenetre_icon_from_file(fen);
    }
}*/





/****************************************************************
 * Description: Récupère la valeur du champ Title de la structure Fenetre.
 *
 * Entrées: fen Pointeur vers la structure Fenetre.
 * Sorties: const gchar* La valeur actuelle du titre ou NULL si la structure est invalide.
 *******************************************************************/
gchar* get_fenetre_title(Fenetre *fen)
{
    // Vérifie si le pointeur vers la structure Fenetre est NULL
    if (!fen)
    {
        // Affiche un message d'avertissement dans la console si la structure est invalide
        g_warning("get_fenetre_title: Structure Fenetre invalide (NULL).");
        return (gchar*)(NULL);  // Retourne NULL car la structure est invalide
    }
    // Retourne la valeur actuelle du champ Title
    return (gchar*)(fen->Title);
}//Fin de la fonction





/*************************************************************
 * Description: Définit une nouvelle valeur pour le champ Title.
 * Entrées:-fen Pointeur vers la structure Fenetre.
 *  	  -new_title Nouvelle valeur pour le champ Title.
 *************************************************************/
void set_fenetre_title(Fenetre *fen, const gchar *new_title)
{
    // Vérifie si le pointeur vers la structure Fenetre est NULL
    if (fen == NULL)
    {
        // Affiche un message d'avertissement dans la console si la structure est invalide
        g_warning("set_fenetre_title: Structure Fenetre invalide (NULL).");
        exit(-1);  // quitte immédiatement car il n'y a rien à modifier
    }

    // Libère la mémoire de l'ancienne valeur du champ Title si elle existe
    //if (fen->Title)        g_free(fen->Title);
    // Duplique la nouvelle chaîne pour garantir qu'elle est indépendante de l'entrée
    fen->Title = g_strdup(new_title);
}//Fin de la fonction




/*********************************************************************
 * Description: Vérifie si le champ Title est vide (NULL ou chaîne vide).
 * Entrées: fen Pointeur vers la structure Fenetre.
 * Sorties: gboolean TRUE si le champ est vide, FALSE sinon.
 *********************************************************************/
gboolean is_title_empty(const Fenetre *fen)
{
    if (!fen)
    {
        g_warning("is_title_empty: Structure Fenetre invalide (NULL).");
        return TRUE; // Considère comme "vide" si la structure est NULL
    }
    return (!fen->Title || strlen(fen->Title) == 0);
}//Fin de la fonction


/**
 * Description: Met à jour le titre affiché de la fenêtre GTK.
 *
 * Cette fonction utilise la valeur actuelle du champ `Title` pour mettre à jour
 * le titre affiché de la fenêtre associée.
 *
 * Entrées: fen Pointeur vers la structure Fenetre.
 */
void update_fenetre_title(Fenetre *fen)
{
    if (!fen || !fen->Wind || !fen->Title)
    {
        g_warning("update_fenetre_title: Paramètres invalides ou champ Title non initialisé.");
        return;
    }

    // Met à jour le titre affiché dans la fenêtre GTK
    gtk_window_set_title(GTK_WINDOW(fen->Wind), fen->Title);

}
