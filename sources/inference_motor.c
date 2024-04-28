#include "inference_motor.h"
#include "fact_basis.h"
#include "knowledge_basis.h"
#include "rules.h"
#include "colors.h"

BC search(const BC knowledge_basis, const BF fact_basis) {
	BC knowledge_buffer = createBasis();
	BC known_fact       = createBasis();
	BF fact_buffer      = createFactBasis();

	knowledge_buffer = knowledge_basis;
	fact_buffer      = fact_basis;

	while (!isEmptyFactBasis(fact_buffer)) {
		while (!isEmptyKnowledgeBasis(knowledge_buffer)) {
			Premisse premisse_buffer = knowledge_buffer->next->head.premisse;
			while (premisse_buffer != NULL) {
				
				if (strcmp(premisse_buffer->content, fact_buffer->content) == 0 ) {
					known_fact = addRuleBasis(known_fact, knowledge_buffer->next->head);
				}
				premisse_buffer = premisse_buffer->next;
			}
			knowledge_buffer = knowledge_buffer->next;
    }
    fact_buffer = fact_buffer->next;
	}

	return known_fact;
}

void inference_motor(BC knowledge_basis, BF fact_basis) {
	if(isEmptyKnowledgeBasis(knowledge_basis)) printf(RED("La base de connaissance est vide\n"));
	else {
		BC knowledge_buffer = createBasis();
		BF fact_buffer      = createFactBasis();

		knowledge_buffer    = knowledge_basis;
		fact_buffer         = fact_basis;

		while(fact_buffer != NULL) {
			knowledge_buffer = search(knowledge_buffer, fact_buffer);
			//printf("%s",fact_buffer->content); //DEBUG
			fact_buffer = fact_buffer->next;
		}

		if (isEmptyKnowledgeBasis(knowledge_buffer)) {
			printf(YELLOW("\n==> Aucune maladie ne correspond!\n"));
			// Affichez d'autres informations si nécessaire
		} else if (knowledge_buffer->next == NULL) {
			// Une seule maladie correspond
			printf(GREEN("\n==> maladie : %s\n\n"), knowledge_buffer->head.conclusion);
			// Affichez d'autres informations si nécessaire
		} else {
			// Plusieurs maladies correspondent
			printf(GREEN("\n==> Maladies correspondantes :\n"));

			// Parcours de la liste des maladies
			BC maladie_buffer = knowledge_buffer;
			while (maladie_buffer != NULL) {
				printf("%s\n", maladie_buffer->head.conclusion);
				maladie_buffer = maladie_buffer->next;
			}

			// Affichez d'autres informations si nécessaire
		}

	}
}
