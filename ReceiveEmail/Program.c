#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<termios.h>
#include<unistd.h>
#include<fcntl.h>

// define constants to be used for program
#define MAX_SUBJECT_LENGTH 255
#define MAX_BODY_LENGTH 1024
#define MAX_EMAIL_LENGTH (MAX_SUBJECT_LENGTH + MAX_BODY_LENGTH)

//defiine struct to store email details
typedef struct Email
{
        char sender[MAX_EMAIL_LENGTH];
        char to[MAX_EMAIL_LENGTH];
        char subject[MAX_SUBJECT_LENGTH];
        char body[MAX_BODY_LENGTH];
}Email;

//function prototype

void getEmail(Email *email);

int main()
{
        //declare email struct
        Email email;

        //get details from user
        getEmail(&email);

        //print out details
        printf("Sender : sample@gmail.com\n");
        printf("To:\t\t%s\n", email.to);
        printf("Subject:\t%s\n", email.subject);
        printf("Body:\t\t%s\n", email.body);

        return 0;
}

//get details from user
void getEmail(Email *email)
{
        //get sender
        printf("Sender : sample@gmail.com\n");

        //get to
        printf("Enter recipient: ");
        fgets(email->to, MAX_SUBJECT_LENGTH, stdin);

        //gets subject
        printf("Enter subject: ");
        fgets(email->subject, MAX_SUBJECT_LENGTH, stdin);

        //get body
        printf("Enter body: ");
        fgets(email->body, MAX_BODY_LENGTH, stdin);
}