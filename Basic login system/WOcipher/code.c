#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 50
// ASCII values of these signs
#define ENTER 13
#define TAB 9
#define BCKSPC 8

typedef struct TUser {
    char fullName[MAXLEN];
	char email[MAXLEN];
	char password[MAXLEN];
	char username[MAXLEN];
	char id[MAXLEN];
} TUser;

void beginPrints ( void ) {
    printf("Welcome to my login system.\n\n");
    printf("Choices:\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Exit\n");
    printf("\nPlease choose:\t");
}

void getInput ( char name[MAXLEN] ) {

    fgets(name, MAXLEN, stdin);
    name[strlen(name)-1] = '\0';
}

void generateUsername ( char email[MAXLEN],char username[MAXLEN] ) {

    for(int i = 0; i < strlen( email ); i++ ) {
		if ( email[i] == '@' ) {
            username[i] = '\0';
            break;
        }
		else {
            username[i] = email[i];
        }
	}
}

int main ( void ) {

    int option = 0,
        value = 0;
    FILE *file;
    char psswd2[MAXLEN];

    TUser user;

    beginPrints();

    scanf(" %d", &option);
    fgetc(stdin);

    switch (option) {
        case 1: // Register

            printf("\nEnter your full name:\t");
            getInput( user.fullName );
            printf("\nEnter your email:\t");
            getInput( user.email );
            printf("\nEnter your contact ID:\t");
            getInput( user.id );
            printf("\nEnter your password:\t");
            getInput( user.password );
            printf("\nConfirm your password:\t");
            getInput( psswd2 );

            if ( strcmp(psswd2, user.password) == 0 ) {
                printf("\nCorrect!\n");
                generateUsername( user.email, user.username );
                printf("\nUsername is: %s\n", user.username);
                file = fopen("User.dat", "a+");
                value = fwrite( &user, sizeof( user ) , 1, file );
                if (value != 0) {
                    printf("Succesfully registered!\n");
                    printf("Your user name is: %s\n", user.username);
                }
                else {
                    printf("Something went wrong.\n");
                    return 1;
                }
            }
            else {
                printf("\nPasswords don't match!\n");
            }
            break;
        case 2:

            TUser usr;
            char username[50],psswd[50];
            int usrFound;

            printf("\nEnter your username:\t");
			getInput(username);
			printf("Enter your password:\t");
			getInput(psswd);

            file = fopen("User.dat","r");
            while ( fread( &usr, sizeof( user ) , 1, file) ) {
                if ( !strcmp( usr.username, username ) ) {
					if ( !strcmp( usr.password, psswd ) ) {
						printf("\nWelcome %s\n\n", usr.fullName);
						printf("|Full Name:\t%s\n", usr.fullName);
						printf("|Email:\t\t%s\n", usr.email);
						printf("|Username:\t%s\n", usr.username);
						printf("|Contact no.:\t%s\n\n", usr.id);	
					}
					else {
						printf("\n\nInvalid Password!");
                        return 1;
					}
					usrFound = 1;
				}
			}
			if(!usrFound){
				printf("\n\nUser is not registered!");
			}
			fclose(file);

            break;
        case 3:
            printf("\t\t\tGood bye :)\n");
            break;
        default:
            printf("Wring number.\n");
            return 1;
    }

    return 0;
}
