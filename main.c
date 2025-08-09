#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STUDENTS 5
#define TESTS 13

int main() {
    char names[STUDENTS][11];      // max 10 tecken + null
    int scores[STUDENTS][TESTS];
    double averages[STUDENTS];
    double sum_all = 0.0;
    int i, j;

    // Läs in data
    for (i = 0; i < STUDENTS; i++) {
        scanf("%10s", names[i]);
        for (j = 0; j < TESTS; j++) {
            scanf("%d", &scores[i][j]);
        }
    }

    // Räkna medel för varje elev
    for (i = 0; i < STUDENTS; i++) {
        int sum = 0;
        for (j = 0; j < TESTS; j++) {
            sum += scores[i][j];
        }
        averages[i] = sum / (double)TESTS;
        sum_all += averages[i];
    }

    
    int best_index = 0;
    for (i = 1; i < STUDENTS; i++) {
        if (averages[i] > averages[best_index]) {
            best_index = i;
        }
    }

    
    names[best_index][0] = toupper(names[best_index][0]);
    printf("%s\n", names[best_index]);
    names[best_index][0] = tolower(names[best_index][0]); // återställ om behövs senare

    
    double group_avg = sum_all / STUDENTS;

    
    for (i = 0; i < STUDENTS; i++) {
        if (averages[i] < group_avg) {
            names[i][0] = toupper(names[i][0]);
            printf("%s\n", names[i]);
        }
    }

    return 0;
}


