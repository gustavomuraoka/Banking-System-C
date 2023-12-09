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
            User curr_user = account_Query(user_login);
            printf("\n---------------------------------------");
            printf("\nHello, %s! \t %d$", curr_user.name, curr_user.money_amount);
            printf("\n---------------------------------------");
            printf("\nWhat would you like to do today?\n \t1. Transfer Money\n \t2. Withdraw Money");
        }  
        else {
            printf("Your login has failed!");
        }
       
    }

}