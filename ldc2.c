#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int Temps ; 
    char Distance[6] ;
    char Termine[4] ;
} Score ;

typedef struct {
    int jours;
    int mois ; 
    int annee ;
} date ;

typedef struct {
    int Code ;
    char NomPrenom[20] ; 
    date DateNaissance ; 
    Score Competition ;
} Athlete ;

typedef struct Element {
    Athlete A;
    struct Element *suivant;
    struct Element *precedent;
} Element;

Element *creer(){
    Element *new = (Element*)malloc(sizeof(Element));
    printf("entrez le code de l'athlete :");
    scanf("%d",&new->A.Code);
    printf("entrez le nom de l'athlete :");
    scanf("%s",&new->A.NomPrenom);
    printf("entrez le temps de l'athlete :");
    scanf("%d",&new->A.Competition.Temps);
    printf("entrez la distance de l'athlete :");
    scanf("%s",&new->A.Competition.Distance);
    printf("entrez le temps termine de l'athlete :");
    scanf("%s",&new->A.Competition.Termine);
    printf("entrez la date de naissance de l'athlete (jj mm aaaa) :");
    scanf("%d %d %d",&new->A.DateNaissance.jours,&new->A.DateNaissance.mois,&new->A.DateNaissance.annee);
    printf("*****************************************************************************\n");
    new->suivant = NULL;
    new->precedent = NULL;  
    return new;
}

int taille(Element *lis){
    Element *temp = lis;
    int i;
    while(temp != NULL){
        temp = temp->suivant;
        i++;
    }
    return i;
}

Element *rech_pos(Element *lis, int pos){
    Element *temp = lis;
    int i;
    for(i=1; i<pos ;i++){
        temp = temp->suivant;
    }
    return temp;
}

Element *insert_debut(Element *lis){
    Element *new = creer();
    if(lis == NULL){
        lis = new;
    }
    else{
        new->suivant = lis;
        lis->precedent = new;
        lis = new; 
    }
    return lis;
}

Element *insert_fin(Element *lis){
    Element *new = creer();
    if(lis == NULL){
        lis = new;
    }else{
        Element *temp = lis;
        while(temp->suivant != NULL){ 
            temp = temp->suivant;
        }
        new->precedent = temp;
        temp->suivant = new;
    }
    return lis;
}


Element *insert_pos(Element *lis, int pos){
    int m = taille(lis); 
    if(pos == 1){
        lis = insert_debut(lis); 
    }else if(pos == m+1){
        lis = insert_fin(lis);
    }else{
        Element *new = creer();
        Element *temp = rech_pos(lis,pos-1);
        new->suivant = temp->suivant;
        temp->suivant->precedent = new;
        temp->suivant = new;
        new ->precedent = temp;
    }
    return lis;
}

Element *creerlist(int n){
    Element *lis = NULL;
    int i;
    for(i=0;i<n;i++){
        lis = insert_fin(lis);
    }
    return lis;
}

Element *sup_debut(Element *lis) {
    if (lis == NULL) {
        exit(1);
    } else {
        Element *temp = lis;
        lis = lis->suivant;
        if (lis != NULL) {
            lis->precedent = NULL;
        }
        free(temp);
    }
    return lis;
}

Element *sup_fin(Element *lis){
    if(lis == NULL){
        exit(1);
    }else{
        Element *temp = lis;
        while(temp->suivant->suivant != NULL){
            temp = temp->suivant;
        }
        free(temp->suivant);
        temp->suivant= NULL;
    }
    return lis;
}


Element *sup_Element(Element *lis){
    Element *temp = lis;
    Element *temp_pre;
    Element *temp_suiv;
    while(temp != NULL){
        if(strcmp(temp->A.Competition.Termine,"non") == 0){
            if(temp == lis){
                lis = sup_debut(lis);
                temp = lis;
            }else if(temp->suivant == NULL){
                temp->precedent->suivant = NULL;
                free(temp);
                temp = NULL;
            }else{
            temp_pre = temp->precedent;
            temp_suiv = temp->suivant;
            temp_pre->suivant = temp_suiv;
            temp_suiv->precedent = temp_pre;
            free(temp);
            temp = temp_suiv;
        }
        }else {
            temp = temp->suivant;
        }
    }return lis;
}

void affiche(Element *lis){
    Element *temp = lis;
    while(temp != NULL){
        printf("le code de l'athlete est : %d \n",temp->A.Code);
        printf("le nom de l'athlete est : %s \n",temp->A.NomPrenom);
        printf("le temps de l'athlete est : %d \n",temp->A.Competition.Temps);
        printf("la distance de l'athlete est : %s \n",temp->A.Competition.Distance);
        printf("le temps termine de l'athlete est : %s \n",temp->A.Competition.Termine);
        printf("la date de naissance de l'athlete (jj mm aaaa) est : %d/%d/%d \n",temp->A.DateNaissance.jours,temp->A.DateNaissance.mois,temp->A.DateNaissance.annee);
        temp = temp->suivant;
    }
}

int main(){
    Element *list = NULL;
    int n;
    
    printf("entrer le nombre des athletes : ");
    scanf("%d",&n);

    list = creerlist(n);
    affiche(list);

    printf("****************************************************************************\n");

    list = insert_fin(list);
    affiche(list);  

}
