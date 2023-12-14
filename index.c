#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Signup.c" 
#include "DataValidator.c"
#include "Login.c"
#define LOGIN_LENGHT 8
#define PASSWORD_LENGHT 8

int menuSelection(User user);
int withdrawMoney(User user);

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
            while (true) {
                int option = menuSelection(curr_user);
                switch (option){
                    case 1:
                        printf("Tranfer Money!");
                        break;
                    case 2:
                        curr_user.money_amount = withdrawMoney(curr_user);
                        break;
                    case 9:
                        return 0;
                    default:
                        printf("Invalid option!");
                        option = 0;
                        break;
                }
            }
            
        }  
        else {
            printf("Your login has failed!");
        }
       
    }

}

int menuSelection(User user){
    printf("\n---------------------------------------");
    printf("\nHello, %s! \t %d$", user.name, user.money_amount);
    printf("\n---------------------------------------");
    printf("\nWhat would you like to do today?\n \t1. Transfer Money\n \t2. Withdraw Money\n \t9. Quit");
    printf("\nYour selected option: ");
    int option = 0;
    scanf("%d", &option);
    return option;
}

int withdrawMoney(User user){
    printf("Money amount being taken: ");
    int money_taken;
    scanf("%d", &money_taken);
    return user.money_amount -= money_taken; 
}