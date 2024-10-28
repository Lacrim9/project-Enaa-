#include <stdio.h>
#include <string.h>

#define MAX_PERSONNES 100  //  la taille maximale

// la structure Adresse
struct Adresse {
    char rue[100];
    char ville[50];
    char code_postal[20];
};

// la structure Personne
struct Personne {
    char nom[50];
    int age;
    struct Adresse adresse;
};

// Tableau global
struct Personne liste_personnes[MAX_PERSONNES];
int nombre_personnes = 0;

// Fonction pour ajouter une nouvelle personne à la liste
void ajout_pers() {
    if (nombre_personnes >= MAX_PERSONNES) {
        printf("La liste est pleine.\n");
        return;
    }

    struct Personne p;  // Déclaration d'une variable locale de type Personne
    getchar();

    printf("Entrez le nom : ");
    scanf(" %[^\n]s", p.nom);
    getchar();

    printf("Entrez l'age : ");
    scanf("%d", &p.age);
    getchar();

    printf("Entrez la rue : ");
    scanf(" %[^\n]s", p.adresse.rue);
    getchar();

    printf("Entrez la ville : ");
    scanf(" %[^\n]s", p.adresse.ville);
    getchar();

    printf("Entrez le code postal : ");
    scanf(" %[^\n]s", p.adresse.code_postal);

    // Ajouter la nouvelle personne à la liste et incrémenter le compteur
    liste_personnes[nombre_personnes] = p;
    nombre_personnes++;
    printf("Personne ajoutee avec succes.\n");
}

// Fonction pour afficher les informations d'une personne à un index donné
void affich_pers(int index) {
    if (index < 0 || index >= nombre_personnes) { // Vérifier l'index valide
        printf("Index invalide.\n");
        return;
    }

    struct Personne p = liste_personnes[index]; // Récupérer la personne de la liste
    printf("\nInformations de la personne %d :\n", index + 1);
    printf("Nom : %s\n", p.nom);
    printf("Age : %d\n", p.age);
    printf("Rue : %s\n", p.adresse.rue);
    printf("Ville : %s\n", p.adresse.ville);
    printf("Code Postal : %s\n", p.adresse.code_postal);
}

// Fonction pour afficher toutes les personnes enregistrées
void affich_tous() {
    if (nombre_personnes == 0) { // Vérifier si la liste est vide
        printf("Aucune personne enregistree.\n");
        return;
    }

    // Boucle pour afficher toutes les personnes
    for (int i = 0; i < nombre_personnes; i++) {
        affich_pers(i);
    }
}

// Fonction pour mettre à jour les informations d'une personne à un index donné
void mettre_a_jour_personne(int index) {
    if (index < 0 || index >= nombre_personnes) { // Vérifier l'index valide
        printf("Index invalide.\n");
        return;
    }

    printf("Entrez les nouvelles informations :\n");
    getchar();

    printf("Nom : ");
    scanf(" %[^\n]s", liste_personnes[index].nom);
    getchar();

    printf("Age : ");
    scanf("%d", &liste_personnes[index].age);
    getchar();

    printf("Rue : ");
    scanf(" %[^\n]s", liste_personnes[index].adresse.rue);
    getchar();

    printf("Ville : ");
    scanf(" %[^\n]s", liste_personnes[index].adresse.ville);
    getchar();

    printf("Code Postal : ");
    scanf(" %[^\n]s", liste_personnes[index].adresse.code_postal);

    printf("Informations mises a jour avec succes.\n");
}

// Fonction pour supprimer une personne à un index donné
void sup_pers(int index) {
    if (index < 0 || index >= nombre_personnes) {
        printf("Index invalide.\n");
        return;
    }

    for (int i = index; i < nombre_personnes - 1; i++) {
        liste_personnes[i] = liste_personnes[i + 1];
    }

    nombre_personnes--;
    printf("Personne supprimée avec succes.\n");
}

// Fonction pour sauvegarder les données dans un fichier texte
void sauvegarder_donnees() {
    FILE *fichier = fopen("personnes.txt", "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    for (int i = 0; i < nombre_personnes; i++) {
        struct Personne p = liste_personnes[i];
        fprintf(fichier, "Personne %d :\n", i + 1);
        fprintf(fichier, "Nom : %s\n", p.nom);
        fprintf(fichier, "Age : %d\n", p.age);
        fprintf(fichier, "Rue : %s\n", p.adresse.rue);
        fprintf(fichier, "Ville : %s\n", p.adresse.ville);
        fprintf(fichier, "Code Postal : %s\n", p.adresse.code_postal);
        fprintf(fichier, "-----------------------------\n");
    }

    fclose(fichier);
    printf("Donnees sauvegardees dans le fichier personnes.txt.\n");
}

int main() {
    int choix, index;

    // Menu principal
    do {
        printf("\n--- Menu ---\n");
        printf("1. Ajouter une personne\n");
        printf("2. Afficher toutes les personnes\n");
        printf("3. Mettre a jour une personne\n");
        printf("4. Supprimer une personne\n");
        printf("5. Sauvegarder les donnees\n");
        printf("6. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        // Gestion du choix de l'utilisateur
        switch (choix) {
            case 1:
                ajout_pers();
                break;
            case 2:
                affich_tous();
                break;
            case 3:
                printf("Entrez l'index de la personne à mettre à jour : ");
                scanf("%d", &index);
                mettre_a_jour_personne(index - 1);
                break;
            case 4:
                printf("Entrez l'index de la personne a supprimer : ");
                scanf("%d", &index);
                sup_pers(index - 1);
                break;
            case 5:
                sauvegarder_donnees();
                break;
            case 6:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 6); // Répéter tant que l'utilisateur ne choisit pas de quitter

    return 0;
}
