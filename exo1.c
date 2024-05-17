#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct ElementListe{
 int val;
 struct ElementListe *precedent;
 struct ElementListe *suivant;} element;

 element * creerEl(int val){
    element* new = malloc(sizeof(element*));
    new->val = val;
    new->suivant = NULL;
    new->precedent = NULL ;
    return new;
 }
// ajouter liste vide  

element* insert_vide( element * lis,int val){
    element* new = creerEl(val);
    return new;
}

//insert debut  

element * insert_deb(element * lis , int a){
    element* new = creerEl(a);
    if (lis == NULL) lis = new ;
    else {
        new->suivant = lis ;
        lis->precedent = new ; 
         lis = new ;
    } 
    return lis ;
}


// rech fin  

element * rech_fin(element * lis ){
    element * temp = lis ;
    while (temp->suivant != NULL){
        temp = temp->suivant ;
    }
    return temp;
}

// insert fin  

element * insert_fin(element * lis, int val){
    element * new = creerEl(val);
    if (lis == NULL) lis = new ;
    else{
        element* temp = rech_fin(lis);
        new->precedent = temp;
        temp->suivant = new;
      
    }
    return lis ;
}

// recherche position 

element * rech_pos(element* lis , int pos){
    element*temp = lis;
    int i=0;
    while(i<pos){
        temp = temp->suivant;
        i++;
    }
    return temp ;
    }

// insert avant pos

element * insert_avant_pos(element * lis , int val , int pos){
    element * new  = creerEl(val);
    if (lis == NULL) lis = new ;
    if (pos == 1){
        lis = insert_deb(lis,val);
    }
    else {
        element * temp = rech_pos(lis,pos);
        new->suivant = temp;
        new->precedent = temp->precedent;
    }
    return lis;
}


// insert apres







int main(){
   

    return 0;
}
