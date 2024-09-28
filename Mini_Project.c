//................................... Mini-Project N: 1 ...................................//

#include <stdio.h>
#include <string.h>

int main() {
    int choix;
    char titre[100][100];
    char auteur[100][100];
    float prix[100];
    int quantite[100];
    int total_livre = 0;

    do {
        printf("\n\n............... Menu Gestion de Stock ...............\n\n");
        printf("1. Ajouter un livre au stock.\n");
        printf("2. Afficher tous les livres disponibles.\n");
        printf("3. Rechercher un livre par son titre.\n");
        printf("4. Mettre à jour la quantite d'un livre.\n");
        printf("5. Supprimer un livre du stock.\n");
        printf("6. Afficher le nombre total de livres en stock.\n");
        printf("0. Quitter.\n");
        printf("Option Menu : ");
        scanf("%d", &choix);
        getchar(); 

        switch (choix) {
            case 1:
                if (total_livre < 100) {
                    printf("\n|............ Ajouter un livre au stock ............|\n"); 
                    printf("Titre de livre : ");
                    scanf(" %[^\n]", titre[total_livre]); 
                    printf("l'auteur de livre : ");
                    scanf(" %[^\n]", auteur[total_livre]); 
                    printf("Prix de livre : ");
                    scanf("%f", &prix[total_livre]);
                    printf("Quantite disponible : ");
                    scanf("%d", &quantite[total_livre]);
                    total_livre++;
                } else {
                    printf("Plein de Stock !!!\n");
                }
                break;

            case 2:
                printf("\n|............ Afficher tous les livres ............|\n");
                for (int i = 0; i < total_livre; i++) {
                    printf("\nTitre: %s\nl'auteur: %s\nPrix: %.2f \nQuantite: %d\n", titre[i], auteur[i], prix[i], quantite[i]);
                    printf("\n|..................................................|\n");
                }
                break;

            case 3:
                char recherche_livre[100];
                int trouve = 0;
                printf("\n|............ Rechercher un livre par son titre ............|\n");
                printf("Nom du livre : ");
                scanf(" %[^\n]", recherche_livre);
                for (int i = 0 ; i < total_livre; i++) {
                    if (strcmp(titre[i], recherche_livre) == 0) {
                        printf("Livre trouve : %s\nLa'uteur : %s\nPrix : %.2f\nQuantite : %d\n", 
                               titre[i], auteur[i], prix[i], quantite[i]);
                        trouve = 1;
                        break;
                    }
                }
                if (!trouve)
                    printf("Livre non trouve\n");
                break;

            case 4:
                char mise_titre[100];
                printf("\n|............ Mettre à jour la quantite d'un livre ............|\n");
                printf("Nom du livre : ");
                scanf(" %[^\n]", mise_titre);
                trouve = 0;
                for (int i = 0; i < total_livre; i++) {
                    if (strcmp(titre[i], mise_titre) == 0) {
                        printf("La quantite actuelle : %d\n", quantite[i]);
                        printf("La nouvelle quantite : ");
                        scanf("%d", &quantite[i]);
                        printf("Quantite mise a jour avec succes.\n");
                        trouve = 1;
                        break;
                    }
                }
                if (!trouve)
                    printf("Livre non trouve\n");
                break;

            case 5:
                char supprimer_titre[100];
                printf("\n|............ Supprimer un livre du stock ............|\n");
                printf("Nom du livre : ");
                scanf(" %[^\n]", supprimer_titre);
                trouve = 0;
                for (int i = 0; i < total_livre; i++) {
                    if (strcmp(titre[i], supprimer_titre) == 0) {
                        for (int j = i; j < total_livre - 1; j++) {
                            strcpy(titre[j], titre[j + 1]);
                            strcpy(auteur[j], auteur[j + 1]);
                            prix[j] = prix[j + 1];
                            quantite[j] = quantite[j + 1];
                        }
                        total_livre--;
                        printf("Livre supprime avec succès.\n");
                        trouve = 1;
                        break;
                    }
                }
                if (!trouve)
                    printf("Livre non trouve\n");
                break;

            case 6:
                printf("\n|............ Afficher le nombre total de livres en stock ............|\n");
                printf("Total des livres en stock : %d\n", total_livre);
                break;

            case 0:
                printf("/\\_/\\*.*.*.* Au revoir, a la prochaine fois! *.*.*.*/\\_/\\ \n");
                break;

            default:
                printf("Choix invalide !!\n");
                break;
        }
    } while (choix != 0);

    return 0;
}
