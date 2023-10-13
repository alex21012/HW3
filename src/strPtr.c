#include "global.h"

int strgLen(char *s) {
    char *start = s;
    while (*s) {
        s++;
    }
    return s - start;
}

void strgCopy(char *s, char *d) {
    while (*s) {
        *d = *s;
        d++;
        s++;
    }
    *d = '\0'; 
}

void strgChangeCase(char *s) {
    char *current = s;
    while (*current) {
        if (isalpha(*current)) {
            *current = isupper(*current) ? tolower(*current) : toupper(*current);
        }
        current++;
    }
}

int strgDiff(char *s1, char *s2) {
    int idx = 0;
    while (*s1 && *s2) {
        if (*s1 != *s2) {
            return idx;
        }
        idx++;
        s1++;
        s2++;
    }
    if (*s1 != *s2) {
        return idx;
    }
    return -1; // Strings are identical
}

void strgInterleave(char *s1, char *s2, char *d) {
    while (*s1 && *s2) {
        *d++ = *s1++;
        *d++ = *s2++;
    }
    while (*s1) {
        *d++ = *s1++;
    }
    while (*s2) {
        *d++ = *s2++;
    }
    *d = '\0';  // Ensure the destination string is null-terminated
}
