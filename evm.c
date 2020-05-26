
/*ELECTRONIC VOTING MACHINE (EVM)*/
#include <stdio.h>
#include <stdlib.h>

struct candidate {

    char name[50];
    char symbol[1];
    int votes;
};

int main() {

    struct candidate c[10];
    int n, n2, i, finish;
    int voters = 0;
    char vote[1], filename[10];


    printf("\n========== Add candidates ==========\n");

    do {
        printf("\nEnter the number of candidates (Maximum 10): ");
        scanf("%d", &n);
        /*minimum 2 candidates require for voting and max 10 mentioned in question*/
    } while (n < 2 || n > 10); 

    n2 = n;

    for (i = 0; i < n; i++) {

        printf("\n********** Enter Data of Candidate %d ***********\n", i + 1);
        printf("\nName of the candidate : ");
        scanf("%s", c[i].name);
        printf("\nSymbol of the candidate : ");
        scanf("%s", c[i].symbol);
        c[i].votes = 0;

    }
    printf("\n");
    printf("You added %d candidates..\n\n", n);

      do{

        for (i = 0; i < n; i++) {

            printf("\t%s ( %s )\n", c[i].name, c[i].symbol);
        }

        vote[0] = getchar();

        for (i = 0; i < n2; i++) {
            if (c[i].symbol[0] == vote[0]) {

                c[i].votes = c[i].votes + 1;
                printf("Thank You! Your vote has been casted to\n");
                printf("\t%s ( %s ) ", c[i].name, c[i].symbol);
                printf("\n");
            }
        }
        printf("\n============================_=_===========================\n\n");

        voters++;

        printf("\nFinish Voting? (Press 1 for Results, 2 to continue voting..) : ");
        printf("\n");
        printf("\n========== Please press the symbol to cast vote ==========\n");
        scanf("%d", &finish);

        if (finish == 1 || voters == 100) {
              finish = 1;
        }
        else {
            finish = 2;
        }


    } while (finish == 2);

    printf("\n========== Result Candidate Wise ==========\n", i + 1);

    for (i = 0; i < n; i++) {
        /* File name for storing Candidate details */
        sprintf(filename, "%s.dat", c[i].name);
        FILE* fPtr;

        /* If above operation is failed print error and exit */
        if (fPtr == NULL) {

            /* File not created hence exit */
            
            printf("Unable to create file.\n");
            exit(EXIT_FAILURE);
        }

        /* Writing data in the file */
        fPtr = fopen(filename, "w");
        printf("Candidate : %s", c[i].name);

        fprintf(fPtr, "Candidate : %s\n", c[i].name);

        printf("\t Symbol : %s", c[i].symbol);
        fprintf(fPtr, "Symbol : %s\n", c[i].symbol);

        printf("\t Votes : %d\n", c[i].votes);

        fprintf(fPtr, "Votes : %d\n", c[i].votes);

        /* Closing the file */
        fclose(fPtr);
    }   
    return 0;
}