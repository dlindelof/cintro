#include <stdio.h>
#include <stdlib.h>

double chem_mean(double *table_valeurs, int taille_tableau)
{
  double moy = 0.0;
  double somme = 0.0;
  int i = 0; 
  for (i=0; i < taille_tableau; i++)
    {
      somme = table_valeurs[i] + somme; //somme des valeurs
    }
  printf("La somme est %f \n", somme);//vérification des calculs
  moy = somme / taille_tableau; //moyenne
  printf("La moyenne est %f.\n", moy); 
  return moy;
}

int main ()
{
  int taille_tableau, i = 0;
  double *table_valeurs = NULL;
  //moyenne
  printf("entrer la quantite de nombres dont on veut la moyenne.\n");
  scanf("%d", &taille_tableau);
  table_valeurs = (double*) malloc(taille_tableau * sizeof(double)); //(double*) malloc(...) permet de convertir le void* du malloc en double.
  printf("maintenant entrer les %d nombres . \n", taille_tableau);
  for (i = 0; i < taille_tableau; i++)
    {
      printf("la %d eme valeure est %f \n", i + 1, table_valeurs[i]);//vérifier que des valeurs existent
      scanf("%lg", &table_valeurs[i]);
      printf("la %d eme valeure devient %f \n", i + 1, table_valeurs[i]);//vérifier les valeurs séléctionnées
    }
  chem_mean(table_valeurs, taille_tableau);
  free(table_valeurs);
  return 0;
}

