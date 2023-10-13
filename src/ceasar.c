#include "global.h" 

/**
 *  Feel free to use the functions that you made in strPtr.c
 */ 
int encrypt(const char *plaintext, char *ciphertext, int key) {
    if (plaintext == NULL || ciphertext == NULL) {
        return -2;
    }

    int count = 0;

    while (*plaintext != '\0') {
        if ('A' <= *plaintext && *plaintext <= 'Z') {
            *ciphertext = ((*plaintext - 'A' + key) % 26) + 'A';
        } else if ('a' <= *plaintext && *plaintext <= 'z') {
            *ciphertext = ((*plaintext - 'a' + key) % 26) + 'a';
        } else if ('0' <= *plaintext && *plaintext <= '9') {
            *ciphertext = ((*plaintext - '0' + key) % 10) + '0';
        } else {
            *ciphertext = *plaintext;
        }

        plaintext++;
        ciphertext++;
        count++;
    }

    if (strgLen(ciphertext) + 7 > strgLen(ciphertext)) {
        return -1;
    }

    strgCopy("__EOM__", ciphertext);

    return count;
}


int decrypt(const char *ciphertext, char *plaintext, int key) {

    if (plaintext == NULL || ciphertext == NULL) {
        return -2;
    }
    if (!strstr(ciphertext, "__EOM__")) { 
        return -1;
    }

    int count = 0;

    while (*ciphertext != '\0' && count < strgLen(plaintext)) {
        if (strncmp(ciphertext, "__EOM__", 7) == 0) {
            break;
        }

        if ('A' <= *ciphertext && *ciphertext <= 'Z') {
            *plaintext = ((*ciphertext - 'A' - key + 26) % 26) + 'A';
        } else if ('a' <= *ciphertext && *ciphertext <= 'z') {
            *plaintext = ((*ciphertext - 'a' - key + 26) % 26) + 'a';
        } else if ('0' <= *ciphertext && *ciphertext <= '9') {
            *plaintext = ((*ciphertext - '0' - key + 10) % 10) + '0';
        } else {
            *plaintext = *ciphertext;
        }

        ciphertext++;
        plaintext++;
        count++;
    }

    *plaintext = '\0';  

    return count;
}
