#include "rules.h"
#include "knowledge_basis.h"
#include "fact_basis.h"
#include "compatibility.h"
#include "inference_motor.h"

#include "colors.h"
#include "menu.h"

int main(void){
	// Utilisé pour l'interprétation des accents, etc.. sous windows
	ASCII;

	// Création des règles et de leurs prémisses & conclusion
	Regle Regle1 = createRule();
	Regle1 = addProposition(Regle1, "Fievre");
	Regle1 = addProposition(Regle1, "Toux");
	Regle1 = addProposition(Regle1, "Essoufflement");
	Regle1 = addProposition(Regle1, "Maux de tête");
	Regle1 = createConclusion(Regle1, "COVID-19");

	Regle Regle2 = createRule();
	Regle2 = addProposition(Regle2, "Fievre");
	Regle2 = addProposition(Regle2, "Maux de gorge");
	Regle2 = addProposition(Regle2, "Ganglions enflés");
	Regle2 = addProposition(Regle2, "Fatigue");
	Regle2 = createConclusion(Regle2, "Angine");

	Regle Regle3 = createRule();
	Regle3 = addProposition(Regle3, "Fievre");
	Regle3 = addProposition(Regle3, "Douleurs articulaires");
	Regle3 = addProposition(Regle3, "Eruption cutanée");
	Regle3 = addProposition(Regle3, "Fatigue intense");
	Regle3 = createConclusion(Regle3, "Dengue");

	Regle Regle4 = createRule();
	Regle4 = addProposition(Regle4, "Fievre");
	Regle4 = addProposition(Regle4, "Maux de tête");
	Regle4 = addProposition(Regle4, "Raideur de la nuque");
	Regle4 = addProposition(Regle4, "Photophobie");
	Regle4 = createConclusion(Regle4, "Meningite");

	Regle Regle5 = createRule();
	Regle5 = addProposition(Regle5, "Fievre");
	Regle5 = addProposition(Regle5, "Frissons");
	Regle5 = addProposition(Regle5, "Sueurs nocturnes");
	Regle5 = addProposition(Regle5, "Maux de tête");
	Regle5 = addProposition(Regle5, "Nausées");
	Regle5 = createConclusion(Regle5, "Paludisme");

	Regle Regle6 = createRule();
	Regle6 = addProposition(Regle6, "Fievre");
	Regle6 = addProposition(Regle6, "Vomissements");
	Regle6 = addProposition(Regle6, "Diarrhée");
	Regle6 = addProposition(Regle6, "Douleurs abdominales");
	Regle6 = createConclusion(Regle6, "Gastro-enterite");

	Regle Regle7 = createRule();
	Regle7 = addProposition(Regle7, "Fievre");
	Regle7 = addProposition(Regle7, "Douleurs abdominales");
	Regle7 = addProposition(Regle7, "Perte d'appétit");
	Regle7 = addProposition(Regle7, "Nausées");
	Regle7 = addProposition(Regle7, "Vomissements");
	Regle7 = createConclusion(Regle7, "Appendicite");

	Regle Regle8 = createRule();
	Regle8 = addProposition(Regle8, "Fievre");
	Regle8 = addProposition(Regle8, "Ecoulement nasal");
	Regle8 = addProposition(Regle8, "Eternuements");
	Regle8 = addProposition(Regle8, "Mal de gorge");
	Regle8 = addProposition(Regle8, "Fatigue");
	Regle8 = createConclusion(Regle8, "Rhume");

	Regle Regle9 = createRule();
	Regle9 = addProposition(Regle9, "Fievre");
	Regle9 = addProposition(Regle9, "Douleurs musculaires");
	Regle9 = addProposition(Regle9, "Fatigue");
	Regle9 = addProposition(Regle9, "Maux de tête");
	Regle9 = addProposition(Regle9, "Congestion nasale");
	Regle9 = createConclusion(Regle9, "Grippe");

	Regle Regle10 = createRule();
	Regle10 = addProposition(Regle10, "Fievre");
	Regle10 = addProposition(Regle10, "Perte de poids");
	Regle10 = addProposition(Regle10, "Toux avec sang");
	Regle10 = addProposition(Regle10, "Sueurs nocturnes");
	Regle10 = addProposition(Regle10, "Essoufflement");
	Regle10 = addProposition(Regle10, "Douleurs thoraciques");
	Regle10 = createConclusion(Regle10, "Tuberculose");


	// Création de la base de connaissance & ajout des règles dedans
	BC knowledge_basis = createBasis();
	knowledge_basis = addRuleBasis(knowledge_basis, Regle1);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle2);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle3);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle4);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle5);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle6);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle7);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle8);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle9);
	knowledge_basis = addRuleBasis(knowledge_basis, Regle10);

	// Mettre sous commentaire pour laisser les informations du compilateurs <!>
	CLEAR;
	
	header();
	printf("Bienvenue, que souhaitez-vous faire ?\n");
	menu(knowledge_basis);
  
	return 0;
}
