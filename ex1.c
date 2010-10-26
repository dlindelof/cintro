// Serie 3 exo 1 by lukas grenacher

#include <stdio.h>

//beware coments aint worth to read!

void squeeze2(char s1[], char s2[])
{
	int a,b;
	int c=0;

	for (a=0; s1[a]!='\0'; a++)
	{
		if (s2[0] == '\0')// me demander pas
			break;// saute tout la boucle for et la  termine

		for (b=0; s2[b]!=s1[a]; b++) //chercher des occurences entre s[a] et tout la chaine des charachters  s2[] 
		{
			if (s2[b]=='\0') //fine de la chaine s2[]
			{
				s1[c]=s1[a];//si le charachter s1[a] n'etait pas dans la chaine s2[] 
				c++;
			}
		}

	}
	if (s2[0] != '\0')
		s1[c]='\0';
}

/* squeeze: delete each char in s1 which is in s2 */
void squeeze(char s1[], char s2[])
{
  int i, j, k;

  for (i = k = 0; s1[i] != '\0'; i++) {
    for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
      ;
    if (s2[j] == '\0') /* no match */
      s1[k++] = s1[i]; /* s1[i] is a character not in s2 and we copy it*/
  }
  s1[k] = '\0'; /* null-terminate the string */
}


main() 
{
	char name1[]="acceturei"; //modifie name1 et name 2 comme vous voulez
	char name2[]="cet";

//	printf("%s\t%s",name1, name2); // une line, j'ai utilisé pour debugé mes chaines des char
	
	squeeze(name1, name2);// je l'appel la fonction en haut, je la donne mes deux chaines des char

	printf("\n\n\t%s\n",name1);// et la bon, cet le outpout, on veut commeme voir le resultat

	return 0;
}
