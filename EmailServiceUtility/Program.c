#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SUBJECT_LENGTH 255
#define MAX_BODY_LENGTH 1024
#define MAX_EMAIL_LENGTH 1279

typedef struct Email
{
        char sender[MAX_EMAIL_LENGTH];
        char to[MAX_EMAIL_LENGTH];
        char subject[MAX_SUBJECT_LENGTH];
        char body[MAX_BODY_LENGTH];
}Email;



void registerUser()

{
        char username[20], email[20], password[20],str[50];
        int i, flag=0, usertype;
        printf("choose 1: user 2: admin");
        scanf("%d",&usertype);
        FILE *fp;
        if(usertype==1)
        {
                fp=fopen("db.txt","r");
        }
        else if(usertype==2)
        {
                fp=fopen("ad.txt","r");
        }
        else
        {
                return;
        }
        printf("\nEnter Username:");
        scanf("%s", username);
        printf("\nEnter Email:");
        scanf("%s",email);
        if(fp==NULL){
                printf("file not exist\n");
        }
        while(fgets(str, 50,fp)!=NULL){
                int count=1;
                char *token=strtok(str," ");
                while(token!=NULL)
                {
                        if(strcmp(token,email)==0){
                                if(count==2){
                                        printf("the following userid %s exist",token);
                                        fclose(fp);
                                        return;
                                }
                                        }
                token=strtok(NULL," ");
                count=count+1;
                }
        }
        fclose(fp);
        if(usertype==1)
        {
                fp=fopen("db.txt","a+");
        }
        else if(usertype==2)
        {
                fp=fopen("ad.txt","a+");
        }
        else
        {
                return;
        }
        printf("\nEnter password: ");
        scanf("%s", password);

        if(strlen(password) >= 8)
        {
                for (i=0; i < strlen(password); i++)
                {
                        if((password[i]>='A' && password[i]<='Z') || (password[i]>='a' && password[i]<='z') || (password[i]>='0' && password[i]<='9') || (password[i] =='#' || password[i] == '$' || password[i] == '@' || password[i] == '&' || password[i] == '!'))
                {
                        flag = 1;
                }
                else
                {
                        flag = 0;
                        break;
                }
        }
        if (flag == 1)
        {
                fprintf(fp, "%s %s %s \n", username, email, password);
                printf("\nUser Registered Successfully !");
        }
        else
        {
                printf("\nPassword must contain minimum 8 characters with at least one character in uppercase,one character in lowercase,one digit and one special character");
                }
}
else
{
        printf("\nPassword must contain minimum 8 characters with at least one character in uppercase, one character in lowercase, one digit and one special character");
}
fclose(fp);
}
void loginUser()
{
        char username[20],email[20],password[20],user[20],mail[20],pass[20];
        int flag = 0;
        FILE *fp = fopen("db.txt", "r");

        printf("\nEnter Username:");
        scanf("%s", username);
        printf("\nEnter Email:");
        scanf("%s", email);
        printf("\nEnter Password:");
        scanf("%s",password);

        while(fscanf(fp,"%s %s %s",user,mail,pass) != EOF)
        {
                if(strcmp(username, user) == 0 && strcmp(email, mail) == 0 && strcmp(password, pass) == 0)
                {
                        flag = 1;
                        break;
                }
        }
        if (flag == 1)
        {
                printf("\nUser Logged in sucessfully !");
        }
        else
        {
                printf("\nInvalid credentials !");
        }

        fclose(fp);
}
void getEmail(Email *email)
{
        printf("Enter sender:");
        fgets(email->sender, MAX_EMAIL_LENGTH, stdin);
        printf("Enter recipient:");
        fgets(email->to, MAX_EMAIL_LENGTH, stdin);
        printf("Enter subject:");
        fgets(email->subject,MAX_SUBJECT_LENGTH, stdin);
        printf("Enter body:");
        fgets(email->body, MAX_BODY_LENGTH, stdin);
}
void receiveEmail()
{
        Email email;
        getEmail(&email);
        printf("Sender:\t%s\n", email.sender);
        printf("To:\t%s\n",email.to);
        printf("subject:\t%s\n", email.subject);
        printf("Body:\t\%s\n",email.body);
}


void composeMail()
{
        char from[20], to[20], subject[20], body[100];
        FILE *fp = fopen("db.txt","w");

        printf("Sender Email:\n");
        scanf("%s", from);
        fprintf(fp,"from: %s", from);
        printf("\n Enter Receiver Email:");
        scanf("%s", to);
        fprintf(fp, " to: %s \n", from);
        printf("\n Enter subject");
        scanf("%s",subject);
        fprintf(fp,"subject: %s \n",subject);
        printf("\nEnter Body:");
        scanf("%s", body);
        fprintf(fp, "body: %s\n", body);

        printf("\nEmail Sent Successfully!");
fclose(fp);
}
void updateUserDetails()
{
        char user[20], mail[20], pass[20],username[20], email[20],password[20];
        int i, flag = 0;
        FILE *fp1 = fopen("db.txt", "r");
        FILE *fp2 = fopen("temp.txt","w");
        printf("\nEnter Username:");
        scanf("%s",username);
        printf("\nEnter Email:");
        scanf("%s",email);
        printf("\nEnter password:");
        scanf("%s",password);
        if(strlen(password) >= 8)
        {
                for(i=0;i<strlen(password);i++)
                {
                        if((password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= 'a' && password[i] <= 'z') || (password[i] >='0' && password[i] <= '9') || (password[i] == '#' || password[i] =='@' || password[i] == '&' || password[i] == '!'))
                        {
                                flag = 1;
                        }
                        else
                        {
                                flag = 0;
                                break;
                           }
                }
                if(flag == 1)
                {
                        while(fscanf(fp1,"%s %s %s",user,mail,pass) != EOF)
                        {
                                if(strcmp(username,user)== 0 && strcmp(email,mail)== 0)
                                {
                                        fprintf(fp2,"%s %s%s\n",username,email,password);
                                }
                                else
                                {
                                        fprintf(fp2,"%s %s %s\n",user,email,pass);
                                }
                        }
                        printf("\nuser Details updated successfully !");
                }
                else
                {
                        printf("\npassword must contain minimum 8 character with at least one character in uppercase ,one character in lowercase,one digit and one special character");
                }
        }
        else
        {
                printf("\nPassword must contain minimum 8 characters with at least one characters with atleast one character in uppercase, one character in lowercase, one digit and one special character");
        }
        fclose(fp1);
        fclose(fp2);

        remove("db.txt");
        rename("temp.txt","db.txt");
}

void listUser()
{
        char user[20], mail[20], pass[20];
        FILE *fp = fopen("db.txt","r");
        printf("\n List of users\n");
        printf("\tUser\tEmail\tPassword\n");
        while(fscanf(fp, "%s %s %s",user,mail,pass)!=EOF)
        {
                printf("\n %s\t%s\t%s",user,mail,pass);
        }
        fclose(fp);
}
void searchUser()
{
        char user[20], mail[20],pass[20],key[20];
        int flag=0;
        FILE *fp = fopen("db.txt","r");

        printf("\nEnter search key:");
        scanf("%s",key);

        while(fscanf(fp,"%s %s %s",user,mail,pass)!=EOF)
        {
                if(strcmp(key,user)==0 || strcmp(key, mail) == 0)
                {
                        flag = 1;
                        printf("\nUser found:");
                        printf("\nusername: %s \nEmail: %s\npassword: %s",user, mail, pass);
                        break;
                }
        }
        if(flag == 0)
        {
                printf("\nNo User Found !");
        }
        fclose(fp);
}

void changePassword()
{
        char user[20], mail[20], pass[20], email[20], oldPass[20], newPass[20], reNewPass[20];
        int i, flag=0;
        FILE *fp1 = fopen("db.txt","r");
        FILE *fp2 = fopen("temp.txt","w");
        printf("\nEnter Email:");
        scanf("%s", email);
        printf("\nEnter oldPassword:");
        scanf("%s",oldPass);
        printf("\nEnter New Password:");
        scanf("%s",newPass);
        printf("\nRe-enter New Password:");
        scanf("%s",reNewPass);

        if(strlen(newPass) >= 8)
        {
              for(i=0;i<strlen(newPass); i++)
              {
        if((newPass[i] >= 'A' &&  newPass[i] <= 'Z') ||(newPass[i] >='a' && newPass [i] <= 'Z')|| (newPass[i] >='0' && newPass[i] <= '9'))
        {
                flag =1;
        }
        else
        {
                flag=0;
                break;
        }
              }
              if(flag == 1 && strcmp(newPass, reNewPass) == 0)
              {
                      while(fscanf(fp1," %s %s %s ",user,mail,pass) != EOF)
                      {
                             if(strcmp(email,mail) == 0 && strcmp(oldPass,pass) == 0)
                             {
                                    fprintf(fp2,"%s %s %s\n",user,mail,newPass);
                                    }
                             else
                             {
                                    fprintf(fp2, "%s %s %s\n",user, mail, pass);
                             }
                      }
                     printf("\nPassword changed successfully !");
              }
              else
              {
                      printf("\nPassword must contain minimum 8 character with atleast one character in uppercase, one character in lowercase, one digit and one special character and both new passwords must match");
              }
        }
        else
        {
                printf("\nPassword must contain minimum 8 characters with atleast ");
        }
        {
                printf("\nvalid sender Email and subject line must be entered !");
        }
        fclose(fp2);
}
void createFilter()
{
        char sender[50], subject[50];
        int i, flag = 0;
        FILE *fp = fopen("db.txt","r");
        printf("Enter senders email:");
        scanf("%s",&sender);
        printf("Enter subject:");
        scanf("%s",&subject);

        char filter[100];
        strcpy(filter, "from:");
        strcat(filter, sender);
        strcat(filter, "subject:");
        strcat(filter,subject);

        printf("Filter: %s\n", filter);
}
int main()
{
        int choice;
        do
        {
        printf("\n\nMENU\n");
        printf("1.Register user\n");
        printf("2.Login User\n");
        printf("3.Receive Email\n");
        printf("4.compose mail\n");
        printf("5.Updated user Details\n");
        printf("6. List Users\n");
        printf("7.Search User\n");
        printf("8.change Password\n");
        printf("9.create Filter\n");
        printf("10.Exit\n");
        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch(choice)
        {
                case 1 : registerUser();
                        break;
                case 2 : loginUser();
                        break;
                case 3 : receiveEmail();
                        break;
                case 4 : composeMail();
                         break;
                case 5 : updateUserDetails();
                         break;
                case 6 : listUser();
                        break;
                case 7 : searchUser();
                        break;
                case 8 : changePassword();
                        break;
                case 9 : createFilter();
                        break;
                case 10 :break;
                default : printf("\nInvalid choice");
        }
        }
        while(choice != 10);
        return 0;
}
