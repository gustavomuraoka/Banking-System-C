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

            if (password_Verify(row, password_given) == 0) {
                printf("Successful Login!");
                return full_row;
            } else {
                return "Wrong Password!";
            }
        }
    }

    fclose( Database );
}

int password_Verify(char * row, char * password_given) {

    char password[9];
    char *password_start = row + 9; //This variable shows where the password starts in the string row. 

    strncpy(password, password_start, 8); //This function sets the var 'password' to have the password value stored in the database 

    if (strcmp(password_given, password) == 0) {
        return 0;
    } else {
        return -1;
    }
}