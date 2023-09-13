#include <stdio.h>
#include <ctype.h>
#include <string.h>

void FIRST(char[], char);
void addToResultSet(char[], char);
void computeAllFIRSTSets();

int numOfProductions;
char productionSet[10][10];
char FIRSTSets[26][20]; // Assuming there are at most 26 non-terminals (A-Z).

int main() {
    int i;
    char choice;

    printf("How many number of productions ? :");
    scanf(" %d", &numOfProductions);

    for (i = 0; i < numOfProductions; i++) {
        printf("Enter production %d : ", i + 1);
        scanf(" %s", productionSet[i]);
    }

    computeAllFIRSTSets(); // Compute FIRST sets for all non-terminals

    printf("\nFIRST sets of all non-terminals:\n");
    for (char c = 'A'; c <= 'Z'; c++) {
        if (FIRSTSets[c - 'A'][0] != '\0') {
            printf("FIRST(%c) = { %s }\n", c, FIRSTSets[c - 'A']);
        }
    }

    return 0;
}

void computeAllFIRSTSets() {
    int i;

    // Initialize all FIRST sets as empty
    for (i = 0; i < 26; i++) {
        FIRSTSets[i][0] = '\0';
    }

    for (i = 0; i < numOfProductions; i++) {
        char nonTerminal = productionSet[i][0];
        FIRST(FIRSTSets[nonTerminal - 'A'], nonTerminal);
    }
}

void FIRST(char *Result, char c) {
    int i, j, k;
    char subResult[20];
    int foundEpsilon;
    subResult[0] = '\0';
    Result[0] = '\0';

    if (!(isupper(c))) {
        addToResultSet(Result, c);
        return;
    }

    for (i = 0; i < numOfProductions; i++) {
        if (productionSet[i][0] == c) {
            if (productionSet[i][2] == '$') {
                addToResultSet(Result, '$');
            } else {
                j = 2;
                while (productionSet[i][j] != '\0') {
                    foundEpsilon = 0;
                    FIRST(subResult, productionSet[i][j]);
                    for (k = 0; subResult[k] != '\0'; k++) {
                        addToResultSet(Result, subResult[k]);
                    }
                    for (k = 0; subResult[k] != '\0'; k++) {
                        if (subResult[k] == '$') {
                            foundEpsilon = 1;
                            break;
                        }
                    }
                    if (!foundEpsilon) {
                        break;
                    }
                    j++;
                }
            }
        }
    }
}

void addToResultSet(char Result[], char val) {
    int k;
    for (k = 0; Result[k] != '\0'; k++) {
        if (Result[k] == val) {
            return;
        }
    }
    Result[k] = val;
    Result[k + 1] = '\0';
}
