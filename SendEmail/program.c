#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

// define constants to be used for program
#define MAX_SUBJECT_LENGTH  255
#define MAX_BODY_LENGTH   1024
#define MAX_EMAIL_LENGTH (MAX_SUBJECT_LENGTH + MAX_BODY_LENGTH)

// define struct to store email details
typedef struct Email
{
    char sender[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

// function prototype
void getEmail(Email *email);

int main()
{
    // declare email struct
    Email email;

    // get details from user
    getEmail(&email);

    // print out details
    printf("Sender:\t\t%s\n", email.sender);
    printf("To:\t\t%s\n", email.to);
    printf("Subject:\t%s\n", email.subject);
    printf("Body:\t\t%s\n", email.body);

    return 0;

// get details from user
void getEmail(Email *email)
{
    // get sender
    printf("Enter sender: ");
    fgets(email->sender, MAX_EMAIL_LENGTH, stdin);

    // get to
    printf("Enter recipient: ");
    fgets(email->to, MAX_EMAIL_LENGTH, stdin);

    // get subject
    printf("Enter subject: ");
    fgets(email->subject, MAX_SUBJECT_LENGTH, stdin);

    // get body
    printf("Enter body: ");
    fgets(email->body, MAX_BODY_LENGTH, stdin);
}

    
    // Get the details from user
    printf("ambica@gmail.com: ");
    
    printf("To: ");
    fgets(to_addr, 256, stdin);
    printf("Subject: ");
    fgets(subject, 256, stdin);
    printf("Body: ");
    fgets(body, 256, stdin);
    printf("Attach File: ");
    fgets(file, 256, stdin);
    
    // Create the email
    char command[512];
    sprintf(command, "mail -s '%s' -a '%s' %s < '%s'", subject, file, to_addr, body);
    
    // Send the email
    system(command);
    
    printf("Email sent successfully!\n");
    
    return 0;
}