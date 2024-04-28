#include "colors.h"
#include "compatibility.h"
#include "fact_basis.h"
#include "inference_motor.h"
#include "knowledge_basis.h"
#include "menu.h"
#include "rules.h"

long entry_num() {
	char entry[MAX_LENGTH];
	// get a user entry & return 0 if NaN
	fgets(entry, MAX_LENGTH+1, stdin);
	return strtol(entry, NULL, 10);
}

/*---------------------------------------------------------*/

char* entry_char() {
	char entry[MAX_LENGTH];

	// get entry from user:
	fgets(entry, MAX_LENGTH+1, stdin);
	// remove \n char
	entry[strlen(entry) - 1] = 0;

	// adjust size to the string itself
	char* result = (char*)malloc(strlen(entry)+1);
	strcpy(result, entry);

	return result;
}

/*---------------------------------------------------------*/

void header() {
      printf(GREEN("88888     88888")YELLOW("    888")RED("         00000       ")BLUE("8888888888     ")WHITE("       8       ")RED("         00000     ")"\n");
      printf(GREEN("888 88  88  888")YELLOW("    888")RED("      888     888    ")BLUE("888     888    ")WHITE("     88 88     ")RED("      888     888  ")"\n");
      printf(GREEN("888   00    888")YELLOW("    8")GREEN("0")YELLOW("8")RED("     888             ")BLUE("888     888    ")WHITE("    88   88    ")RED("     888           ")"\n");
      printf(GREEN("888         888")GREEN("    000")RED("    888              ")BLUE("8888888888     ")WHITE("   88     88   ")RED("    888            ")"\n");
      printf(GREEN("888         888")YELLOW("    8")GREEN("0")YELLOW("8")RED("     888             ")BLUE("888            ")WHITE("  88888888888  ")RED("     888           ")"\n");
      printf(GREEN("888         888")YELLOW("    888")RED("      888     888    ")BLUE("888            ")WHITE(" 888       888 ")RED("      888     888  ")"\n");
      printf(GREEN("888         888")YELLOW("    888")RED("         00000       ")BLUE("888            ")WHITE("888         888")RED("         00000     ")"\n");
}


/*---------------------------------------------------------*/

void menu(BC knowledge_basis){
  long int numeric;

  printf("\n");
  printf(BLUE("1.")" Effectuer un diagnostic\n");
  printf(BLUE("2.")" Accéder à la liste complète des maladies\n");
  printf(BLUE("3.")" Supprimer la base de connaissance\n");
  printf(BLUE("4.")" Ajouter une règle à la base de connaissance\n");
  printf(BLUE("5.")" Quitter le programme\n\n");
  do {
		printf(MAGENTA("Votre choix : "));
		numeric = entry_num();
  } while (numeric > 5 || numeric < 1);

  switch(numeric){
    case 1 :
			/*
			 * RECHERCHE DE MALADIES
			*/
			CLEAR;
			header();

      BF fact_basis = createFactBasis();

			// On évite toute intéraction si la bc est vide : on ne cherche pas dans du "vide"
			if (isEmptyKnowledgeBasis(knowledge_basis)) {
				printf(RED("La base de connaissance est vide!\n"));
				menu(knowledge_basis);
				break;
			}
	printf(BLUE("-------------------- DIAGNOSTIC --------------------\n\n"));
	// Demander à l'utilisateur de saisir le nombre de symptômes
	int num_symptoms;
	printf(MAGENTA("Entrez le nombre de symptômes : "));
	scanf("%d", &num_symptoms);
	// Consommer le caractère de nouvelle ligne restant dans le tampon d'entrée
	getchar();

	// Boucle pour saisir les symptômes
	for (int i = 1; i <= num_symptoms; ++i) {
		printf(MAGENTA("Symptôme %d : "), i);
		fact_basis = addFactFactBasis(fact_basis, entry_char());
	}
         

      inference_motor(knowledge_basis, fact_basis);
			menu(knowledge_basis);
      break;
    case 2 :
			/*
			 * AFFICHAGE DE LA BASE DE CONNAISSANCE
			*/
			CLEAR;
			header();
      printf(GREEN("Voici la liste des maladies et leurs symptômes\n\n"));
      displayKnowledgeBasis(knowledge_basis);
			menu(knowledge_basis);
      break;
    case 3 :
			/*
			 * SUPPRESSION DE LA BASE DE CONNAISSANCE
			*/
			CLEAR;
			header();
      deleteKnowledgeBasis(knowledge_basis);
			menu(knowledge_basis);
      break;
    case 4 : 
			/*
			 * AJOUT D'UNE REGLE A DE LA BASE DE CONNAISSANCE
			*/
      CLEAR;
			header();

			// Création de la nouvelle règle
      Regle ajoutRegle = createRule();

	printf(BLUE("-------------------- AJOUT --------------------\n\n"));
	// Demander à l'utilisateur de saisir le nombre de symptômes
	int numb_symptoms;
	printf(MAGENTA("Entrez le nombre de symptômes : "));
	scanf("%d", &numb_symptoms);
	// Consommer le caractère de nouvelle ligne restant dans le tampon d'entrée
	getchar();

	// Ajout des symptômes
	for (int i = 1; i <= numb_symptoms; ++i) {
		printf(MAGENTA("Symptôme %d : "), i);
		ajoutRegle = addProposition(ajoutRegle, entry_char());
	}
   
			// Ajout de la conclusion
      printf(MAGENTA("Quelle est le nom de la maladie : "));
      ajoutRegle = createConclusion(ajoutRegle, entry_char());
      knowledge_basis = addRuleBasis(knowledge_basis, ajoutRegle);

      menu(knowledge_basis);
      break;
    case 5 :
			/*
			 * FERMER LE PROGRAMME
			*/
			CLEAR;
			header();
			printf("Au revoir et à bientôt!\n");
      exit(0);
      break;
  }
}