#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Signup.c" 
#include "DataValidator.c"
#include "Login.c" 
#define LOGIN_LENGHT 8
#define PASSWORD_LENGHT 8

int main () {

    printf("---------------------------------------\n");
    printf("Welcome to the Banking Assistant System\n");
    printf("---------------------------------------\n");

    /*struct User new_user;*/

    char user_login[LOGIN_LENGHT];
    char user_password[PASSWORD_LENGHT];

    printf("Login (Have no account yet? Type 0 to create a new one!): ");
    fgets(user_login, LOGIN_LENGHT+1, stdin);

    if(strlen(user_login) == 2 && user_login[0] == '0'){
        register_user();
    }
    else{
        if (strlen(user_login) == LOGIN_LENGHT+1 || verify_numberonly(user_login)){
            printf("%s\n", account_Query(user_login));
        }  
        else {
            printf("Your login has failed!");
        }
       
    }

}