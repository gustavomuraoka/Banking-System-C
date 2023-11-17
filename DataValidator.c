#include <stdio.h>
#include <string.h>
#include <ctype.h>

int verify_numberonly(char * sequence) {
    for (int i = 0; i < strlen(sequence); i++){
        if (!isdigit(sequence[i])){
            printf("ERROR: Your login should be an 8-digit sequence containing only numbers! (note the %c at position %d)", sequence[i], i+1);
            return 0;
        }
    }
    return 1;
}

int random_login_generator() {
    
}