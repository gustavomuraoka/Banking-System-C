#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define PASSWORD_LENGHT 8

#define MAX_ROW_SIZE 60 // 60 is the number that sums all the info that could be possibly written since users can't get to the 10 billion mark at their accounts
#define FILENAME "User.txt"

int password_Verify(char * row, char * password_given);

char * account_Query(char * user_login) {
    
    char  row[MAX_ROW_SIZE];
    FILE * Database = fopen(FILENAME, "r");

    if ( Database == NULL ) {
       
       printf("Error trying to achive our database, we are sorry for the inconvenience :/ \n");
       return 0;
    }

    while ( fgets( row, MAX_ROW_SIZE, Database ) != NULL ) {

        char * full_row = malloc(sizeof(char) * MAX_ROW_SIZE); // this variable is used since i wasnt able to reuse char row again due to strtok, might find a better solution later...
        strcpy(full_row, row);
        char * token = strtok(row, " ");

        if (strcmp(token, user_login) == 0) { // verify if the login given is equal to any login in database
            
            printf("Password: ");
            char password_given[PASSWORD_LENGHT+1];
            getchar();
            fgets(password_given, PASSWORD_LENGHT+1, stdin);

            password_Verify(row, password_given);

            return full_row;
            /*if (strcmp(password_given, real_password) == 0)
            printf("\n%s\n", password);*/
            
        }
    }

    fclose( Database );
}

int password_Verify(char * row, char * password_given) {

    char * token = strtok(row, " ");
    /*printf("%s\n", row);*/
    

    return 0;
}