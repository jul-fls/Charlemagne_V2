#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

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
const char * filename = "./data.txt";
#define BLOCK_SIZE 24
#define BLOCK_COUNT 10

char* strcasestr(const char* haystack, const char* needle) {
    if (!needle[0]) return (char*) haystack;
    for (size_t i = 0; haystack[i]; i++) {
        bool matches = true;
        for (size_t j = 0; needle[j]; j++) {
            if (!haystack[i + j]) return NULL;
            if (tolower((unsigned char)needle[j]) != 
                tolower((unsigned char)haystack[i + j])) {
                matches = false;
                break;
            }
        }
        if (matches) return (char *)(haystack + i);
    }
    return NULL;
}

void creer() {
	system("cls");
	printf("Creation d'un nouveau dossier\n\n");
	for (int i = 0;i < 1000;i++) {
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
			printf("%d\t%s\t\t%d\t%.2f\t\t%.2f\n", i, etudiants[i].nom, etudiants[i].age, etudiants[i].francais, etudiants[i].mathematiques);
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
	printf("\nMoyenne generale en francais : %.2f\nMoyenne generale en mathematiques : %.2f\n", moyennefrancais, moyennemathematiques);
	system("pause");
}

void rechercher() {
	system("cls");
	printf("Rechercher un dossier\n\nSaisissez le nom de l'etudiant a rechercher dans les dossiers : ");
	char rechercher[41];
	scanf(" %[^\n]", &rechercher);
	int found=0;
	for (int i = 0;i < 1000;i++) {
		if (etudiants[i].age != 0) {
			if (strcasestr(etudiants[i].nom, rechercher)) {
				found++;
				if(found==1){
					printf("N\tNOM ET PRENOM\t\tAGE\tMOYENNE FRANCAIS\tMOYENNE MATHEMATIQUES\n");
				}
				printf("%d\t%s\t\t%d\t%.2f\t\t%.2f\n", i, etudiants[i].nom, etudiants[i].age, etudiants[i].francais, etudiants[i].mathematiques);
			}
			
		}	
	}
	if(found==0){
		printf("\nAucun etudiant portant ce nom ou prenom n'a ete trouve !\n");
	}	
	system("pause");
}

void supprimer() {
	system("cls");
	printf("Supprimer un dossier\nSaisissez le numero du dossier a supprimer : ");
	int rechercher=0;
	scanf("%d", &rechercher);
	for (int i = 0;i < 1000;i++) {
		if (i != rechercher) {
			etudiants[i] = etudiants[i];
		}
		else {
			if (etudiants[i].age != 0) {
				//etudiants[i].nom = " ";
				etudiants[i].age = 0;
				etudiants[i].francais = 0;
				etudiants[i].mathematiques = 0;
				printf("\nLe dossier portant le numero %d a bien ete supprime !\n", rechercher);
				system("pause");
			}
			else {
				printf("\nErreur : Il n'y a pas de dossier portant le numero %d !\n", rechercher);
				system("pause");
			}
		}
	}
}

void writeFile(const char * filename) {
    char buffer[ BLOCK_SIZE ];
    int returnCode;
    int index;
    FILE * stream = fopen( filename, "w" );
    if ( stream == NULL ) {
        fprintf( stderr, "Cannot open file for writing\n" );
        exit( -1 );
    }
    for( index=0; index<BLOCK_COUNT; index++ ) {
        int value = rand() % 1000;
        sprintf(buffer, "| User %3d | Pass %3d |\n", value, 999-value);
        if (1 != fwrite(buffer, BLOCK_SIZE, 1, stream)) {
            fprintf(stderr, "Cannot write block in file\n");
        }
    }
    returnCode = fclose( stream );
    if (returnCode == EOF) {
        fprintf(stderr, "Cannot close file\n");
        exit(-1);
    }
}

char readFile( const char * filename ) {
    int returnCode;
    int count = 2;
    FILE * stream = fopen(filename, "r");
    if (stream == NULL) {
        fprintf(stderr, "Cannot open file for reading\n");
        exit(-1);
    }
    {
        char buffer[BLOCK_SIZE * count + 1];
		fread(buffer, BLOCK_SIZE, count, stream);
        buffer[BLOCK_SIZE * count] = '\0';
        return(buffer);
    }
    returnCode = fclose( stream );
    if (returnCode == EOF) {
        fprintf(stderr, "Cannot close file\n");
        exit(-1);
    }
	system("pause");
}


void sauvegarder() {
	system("cls");
	printf("Sauvegarder les dossiers\n");
	// for (int i = 0;i < 1000;i++) {
	// 	if (etudiants[i].age != 0) {
	
	// 	}
	// }
	printf("%c\n",readFile(filename));
	system("pause");
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