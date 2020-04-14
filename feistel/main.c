#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int string_length(char *str)
{
    char cond = 'a';
    int index = 0;
    while (cond != '\0')
    {
        cond = (char)str[index];
        ++index;
    }
    return index - 1;
}

int crypto_function(char* input, char* key){
    char curr = 'a';
    int index = 0;
    while(curr != '\0'){

    }
}

int is_uneven(int length){
    if (length % 2 == 0){
        return 1;
    }
    return 0; 
}

int split_string(int length, char *input, char *left, char *right)
{
    // Split in half
    strncpy(left, input, length/2);
    strcpy(right, input+(length/2));

    // Pad if uneven 
    if (0 == is_uneven(length)){
        left[length/2] = 'A';
    }

    return 0;
}



int feistel(char *input, char* output)
{
    char *left;
    char *right;

    int length = string_length(input);
    left = malloc(sizeof(char)*length/2);
    right = malloc(sizeof(char)*length/2);

    int err = split_string(length, input, left, right);
    if (err < 0)
    {
        return err;
    }

    printf("LEFT %s\n", left);
    printf("RIGHT %s\n", right);

    // XOR left and right
    for(int i=0; i<strlen(left); i++){
        char temp = left[i] ^ right[i];
        left[i] = temp;
    };

    // Swap left and right
    for(int i=0; i<strlen(left); i++){
        char temp_l = left[i];
        char temp_r = right[i];
        left[i] = temp_r;
        right[i] = temp_l;
    };

    printf("LEFT %s\n", left);
    printf("RIGHT %s\n", right);

    strcpy(output, right);
    strcat(output, left);

    free(left);
    free(right);
}

int main(int argc, char *argv[])
{
    char* input = "Hello";
    char* output = malloc(strlen(input));
    feistel(input, output);

    printf("HELLOO %s\n", output);

    free(output);
    return 0;
}