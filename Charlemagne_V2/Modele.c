#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct dossieretudiant dossieretudiant;
struct dossieretudiant {
	char nom[41];
	unsigned int age;
	float francais;
	float mathematiques;
};

dossieretudiant etudiants[1000];
float moyennefrancais = 0;
float moyennemathematiques = 0;
void afficher();
void creer() {
	system("cls");
	printf("Creation d'un nouveau dossier\n\n");
	for (int i = 0;i < 1000;i++) { // utilisation d'un while est peut etre plus appropriée
		printf("Saisissez le nom et le prenom de l'etudiant : ");
		scanf(" %[^\n]", &etudiants[i].nom);
		if (strlen(etudiants[i].nom)>=2) {
			printf("\nSaisissez son age : ");
			scanf(" %d", &etudiants[i].age);
			printf("\nSaisissez sa moyenne en francais : ");
			scanf(" %f", &etudiants[i].francais);
			printf("\nSaisissez sa moyenne en mathematiques : ");
			scanf(" %f", &etudiants[i].mathematiques);
			printf("\n\nLe dossier a ete cree !\n");
		}
		else {
			i = 10000;
		}
	}
}

void afficher() {
	system("cls");
	printf("Afficher les dossiers\n");
	printf("N\tNOM ET PRENOM\t\tAGE\tMOYENNE FRANCAIS\tMOYENNE MATHEMATIQUES\n");
	for (int i = 0;i<1000;i++) {
		if (etudiants[i].age != 0) {
			printf("%d\t%s\t\t%d\t%f\t\t%f\n", i, etudiants[i].nom, etudiants[i].age, etudiants[i].francais, etudiants[i].mathematiques);
		}
	}
	system("pause");
}

void calcmoyenne() {
	system("cls");
	printf("Calculer la moyenne de la classe");
	int nb = 0;
	for (int i = 0;i < 1000;i++) {
		if (etudiants[i].age != 0) {
			nb++;
			moyennefrancais += etudiants[i].francais;
			moyennemathematiques += etudiants[i].mathematiques;
		}
	}
	moyennefrancais /= nb;
	moyennemathematiques /= nb;
	printf("\nMoyenne generale en français : %.2f\nMoyenne generale en mathematiques : %.2f\n", moyennefrancais, moyennemathematiques);
	system("pause");
}

void rechercher() {
	system("cls");
	printf("Rechercher un dossier\n\nSaisissez le nom de l'etudiant a rechercher dans les dossiers : ");
	char rechercher[41];
	scanf(" %[^\n]", &rechercher);
	for (int i = 0;i < 1000;i++) {
		if (etudiants[i].age != 0) {
			if (strstr(etudiants[i].nom, rechercher)) {
				printf("N\tNOM ET PRENOM\t\tAGE\tMOYENNE FRANCAIS\tMOYENNE MATHEMATIQUES\n");
				printf("%d\t%s\t\t%d\t%f\t\t%f\n", i, etudiants[i].nom, etudiants[i].age, etudiants[i].francais, etudiants[i].mathematiques);
				system("pause");
			}
			else {
				printf("\nAucun etudiant portant ce nom ou prenom n'a ete trouve !\n");
				system("pause");
			}
		}
	}
}

void supprimer() {
	system("cls");
	printf("Supprimer un dossier\nSaisissez le numéro du dossier à supprimer : ");
	int rechercher=0;
	scanf("%d", &rechercher);
	for (int i = 0;i < 1000;i++) {
		if (i != rechercher) {
			etudiants[i] = etudiants[i];
		}
		else {
			if (etudiants[i].age != 0) {
				etudiants[i].nom = " ";
				etudiants[i].age = 0;
				etudiants[i].francais = 0;
				etudiants[i].mathematiques = 0;
				printf("\nLe dossier portant le numéro %d a bien ete supprime !", rechercher);
				system("pause");
			}
			else {
				printf("\nErreur : Il n'y a pas de dossier portant le numéro %d !", rechercher);
				system("pause");
			}
		}
	}
}

void sauvegarder() {
	system("cls");
	printf("Sauvegarder les dossiers");
}

void quitter() {
	system("cls");
	printf("Quitter le programme\nAU REVOIR !!!!");
	exit(0);
}

void menu() {
	int choix;
	system("cls");
	printf("Bienvenu dans le programme de gestion de dossiers etudiants.\n");
	printf("Que voulez-vous faire :\n");
	printf("1) Creer un nouveau dossier\n");
	printf("2) Afficher les dossiers\n");
	printf("3) Calculer la moyenne de classe\n");
	printf("4) Rechercher un dossier\n");
	printf("5) Supprimer un dossier\n");
	printf("6) Sauvegarder les dossiers\n");
	printf("7) Quitter le programme\n");
	printf("Saisissez le numero de l'action a effectuer et appuyez sur ENTREE : ");
	scanf("%d", &choix);
	switch (choix) {
	case 1:
		creer();
		break;
	case 2:
		afficher();
		break;
	case 3:
		calcmoyenne();
		break;
	case 4:
		rechercher();
		break;
	case 5:
		supprimer();
		break;
	case 6:
		sauvegarder();
		break;
	case 7:
		quitter();
		break;
	}
}
void main() {
	while (1) {
		menu();
	}
}