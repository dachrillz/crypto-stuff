#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* string_to_binary(char* str) {
    if(str == NULL) return 0; /* no input string */
    size_t len = strlen(str);
    char *binary = malloc(len*sizeof(char) + 1); // each char is one byte (8 bits) and + 1 at the end for null terminator
    binary[0] = '\0';
    for(size_t i = 0; i < len; ++i) {
        char ch = str[i];
        for(int j = 7; j >= 0; --j){
            if(ch & (1 << j)) {
                strcat(binary,"1");
            } else {
                strcat(binary,"0");
            }
        }
    }
    return binary;
}

char* binary_to_string(char* bin) {
    if(bin== NULL) return 0; /* no input string */
    size_t len = strlen(bin);
    char *binary = malloc(len*sizeof(char) + 1); // each char is one byte (8 bits) and + 1 at the end for null terminator
    binary[0] = '\0';
    for(size_t i = 0; i < len; ++i) {
        char ch = bin[i];
        for(int j = 7; j >= 0; --j){
            if(ch & (1 << j)) {
                strcat(binary,"1");
            } else {
                strcat(binary,"0");
            }
        }
    }
    return binary;
}