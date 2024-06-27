
#include <stdio.h>
#include <string.h>

int main() {
    // Given strings as character arrays
    char S1[] = "Flowers";
    char S2[] = "are beautiful";

    // a) Find the length of S1
    int length_S1 = strlen(S1);
    printf("Length of S1: %d\n", length_S1);

    // b) Concatenate S1 and S2
    char concatenated_string[50]; // Assuming a max size for the result
    strcpy(concatenated_string, S1);
    strcat(concatenated_string, " ");
    strcat(concatenated_string, S2);
    printf("Concatenated string: %s\n", concatenated_string);

    // c) Extract the substring "low" from S1
    char substring[4]; // "low" + '\0'
    strncpy(substring, S1 + 3, 3); // Copy "low" starting from index 3
    substring[3] = '\0'; // Null-terminate the substring
    printf("Substring 'low' from S1: %s\n", substring);

    // d) Find "are" in S2 and replace it with "is"
    char *found = strstr(S2, "are");
    if (found != NULL) {
        strcpy(found, "is");
    }
    printf("Modified string: %s\n", S2);

    return 0;
}

