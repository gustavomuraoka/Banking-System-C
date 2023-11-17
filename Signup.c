#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define NAME_LENGHT 30
#define FILENAME "User.txt"

int verify_numberonly(char * sequence);

void insertDB(char * user_name, char * password, char * login) {
    FILE *Database = fopen(FILENAME, "a");

    if (Database == NULL) {
        printf("Error while trying to reach our database! Sorry :/ ");

    } else {

        fprintf(Database, "%s %s %s %d\n", login, password, user_name, 0);

    }

    
}

void register_user(){
    
    char user_name[NAME_LENGHT];
    int user_age;
    char password[9];
    char login[9];

    printf("Welcome to the system! Please insert your full name: ");
    fgets(user_name, NAME_LENGHT+1, stdin);
    user_name[strlen(user_name)-1] = '\0';

    printf("Hello %s! Please insert your age: ", user_name);
    scanf("%d", &user_age);

    if (user_age < 18) {

        printf("Sorry! Your are too young to create your own account!");

    }
    else {

        printf("Please, inform your login! NOTE: Logins should be 8-digit-only! \n");
        getchar(); 
        fgets(login, 9, stdin);
        login[strlen(password)-1] = '\0';

        printf("Please, inform your password! NOTE: Passwords should be 8-digit-only! \n");
        getchar(); 
        fgets(password, 9, stdin);
        password[strlen(password)-1] = '\0';

        printf("Your account info is:\n   LOGIN: %s\n   PASSWORD: %s", login, password);
        insertDB(user_name, password, login);

    }

}

