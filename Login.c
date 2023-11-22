#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define PASSWORD_LENGHT 8 

#define MAX_ROW_SIZE 60 // 60 is the number that sums all the info that could be possibly written since users can't get to the 10 billion mark at their accounts
#define FILENAME "User.txt"

typedef struct User
{
    char name[15];
    double money_amount;
}User;


int password_Verify(char * row, char * password_given);
struct User set_values (char * row);

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
                set_values(row);
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

struct User set_values (char * row){

    /*This first part is about setting the user name in struct var user.name*/
    struct User new_user;
    int name_lenght = 0;

    for (int i = 0; row[i+18] != ' '; ++i) {
        name_lenght++;
    }
                                                    /*This setup surely is not even close to be the most memory-friendly and runtime-friendly but thats how i could make this work, must solve it better latter*/
    char *name = (char *)malloc(name_lenght + 1);

    for (int i = 0; row[i+18] != ' '; ++i) {
        name[i] = row[i+18];
    }
    name[name_lenght] = '\0';
    
    strcpy(name, new_user.name);

    free(name);

    /*This second part is responsible to set the amount of money user has to user.money_amount*/

    printf("aa %s \n", row);

    int last_index;

    /*for (last_index = strlen(row); row[last_index] != ' '; last_index--){}*/

    char * money_amount_str = (char *)malloc(strlen(row) - last_index + 1);

    printf("%d\n", last_index);

    for (int i = 0; i + last_index < strlen(row); i++) {
        printf("i = %d && row[] = %c", i + last_index, row[i + last_index]);
        money_amount_str[i] = row[i + last_index];
    }

    printf("\n%s\n", money_amount_str);
    printf("\n%s\n", money_amount_str);

    return new_user;

}