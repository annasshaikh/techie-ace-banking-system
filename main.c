#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>

/*
- Techie Ace™
- Annas Shaikh
Created: 27 may 2018 - 30 may 2018 | V1.0
Update: 9 Aug 2018 - 14 Aug 2018 | V1.1

*/

FILE * fdata;
FILE * faccdata;
FILE * ftemp;
int verifyi = 0;
COORD coord = {0,0};

int isverify();
void verify(char str[]);
void delay(unsigned int mseconds);
void gotoxy(int x, int y);
void drawRectangle();
void clearWindow();
void title();
void loading();
void makeaccount();
void accountdetails();
void depositmoney();
void takemoney();
void fromtransfer(char id[15],char inputp[25],int takem);
void totransfer(char id[15],int takem);
void transfer();
void modifyaccount();
void startmenu();

int main(){
    system("cls");
    if (isverify()){
        drawRectangle();
        title();
        startmenu();
    }else{
        char password[5];
        printf("Get Product Key From: http://owner.techieace.ml/projects/\nEnter The Product Key To verify :");
        scanf(" %s",password);
        strupr(password);
        verify(password);
        if (verifyi>0)
            main();
        printf("\"Your Product Key is Invalid!\"\a\nPress any key to continue");
        getch();
        exit(0);
        }
}
void verify(char str[]){
    FILE * fverify;
    char input[10];
    fverify = fopen("key.dll","r");
    fgets(input,10,fverify);
    if(strcmp(input,str)==0){
        fclose(fverify);
        verifyi++;
        fverify = fopen("verifyed.dll","w");
        fclose(fverify);
    }
}
int isverify(){
    FILE * fverify;
    fverify = fopen("verifyed.dll","r");
    if (!fverify){
        fclose(fverify);
        return 0;
    }else{
        fclose(fverify);
        return 1;
        }
}
void delay(unsigned int mseconds){
clock_t goal = mseconds + clock();
while (goal > clock());
}
void gotoxy(int x, int y){
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void drawRectangle(){
    int i;
    gotoxy(0,0);
    printf("%c",201);
    for(i = 1; i < 78; i++){
        gotoxy(i, 0);
        printf("%c",205);
    }
    gotoxy(78,0);
    printf("%c",187);
    for(i = 1; i < 25; i++){
        gotoxy(78, i);
        if(i == 6){
            printf("%c",185);
        }else{
            printf("%c",186);
        }
    }
    gotoxy(78, 25);
    printf("%c",188);
    for(i = 77; i > 0; i--){
        gotoxy(i,25);
        if(i == 35){
            printf("%c",202);
        }else{
            printf("%c",205);
        }
    }
    gotoxy(0,25);
    printf("%c",200);
    for(i = 24; i > 0; i--){
        gotoxy(0,i);
        if(i == 6){
            printf("%c",204);
        }else{
            printf("%c",186);
        }
    }

    for(i = 1; i < 78; i++){
        gotoxy(i,6);
        if(i == 35){
            printf("%c",203);
        }else{
            printf("%c",205);
        }
    }

    for(i = 7; i < 25; i++){
        gotoxy(35,i);
        printf("%c",186);
    }

}
void clearWindow(){
    int i,j;
    for(i = 37; i < 78; i++){
        for(j = 7; j < 25; j++){
            gotoxy(i,j);printf(" ");
        }
    }
    return;
}
void title(){
     gotoxy(24,2);printf("Techie Ace Banking System");
     gotoxy(30,4);printf("Version V1.1");
     return;
}
void loading(){
    clearWindow();
    gotoxy(38,8);printf("Loading");
    int i;
    for (i=0;i<5;i++){
        delay(250);
        printf(".");
    }
    clearWindow();
    return;
}
void makeaccount(){
    int age,contactnum,nic,money=0,accnum=0 ;
    char singleline[100],end[2];
    char name[30],email[50], filename[20];
    char password[20], pass2[20];
    char * pfilename = filename;
    fdata = fopen("data.dll", "r");
    while (fgets(singleline,100,fdata)!= NULL){
        ++accnum;
    }
    fclose(fdata);
    fdata = fopen("data.dll", "a");
    int x = 38;
    gotoxy(x,8);printf("Name:"); scanf(" %s", name);
    gotoxy(x,10);printf("age:"); scanf(" %d", &age);
    gotoxy(x,12);printf("Contact Number:"); scanf(" %d", &contactnum);
    gotoxy(x,14);printf("NIC Number:"); scanf(" %d", &nic);
    gotoxy(x,16);printf("Email:"); scanf(" %s", email);
    gotoxy(x,18);printf("Password: "); scanf(" %s", password);
    gotoxy(x,20);printf("Reenter Password: "); scanf(" %s", pass2);
    gotoxy(x,22);printf("The Account Number: %d", accnum);
    gotoxy(x,24);printf("Do you want to continue? [y/n]");scanf(" %s", end);
    if (strcmp(pass2,password)==0){
    name[0]= toupper(name[0]);
    itoa(accnum,pfilename,15);
    strcat(pfilename,".dll");
    faccdata = fopen(pfilename,"a");
    fprintf(fdata,"%d\n",accnum);
    fprintf(faccdata,"%s\n%d\n%d\n%d\n%s\n%s\n%d\n%d", name,age,contactnum,nic,email,password, accnum,money);
    fclose(faccdata);
    fclose(fdata);

    if ((strcmp(end,"y")== 0) || (strcmp(end,"Y")== 0) ){
      clearWindow();
      loading();
      makeaccount();
    }else if ((strcmp(end,"n")== 0 )|| (strcmp(end,"N")== 0)){
    clearWindow();
    return;
    }}else{
    clearWindow();
    gotoxy(x,8);printf("Passwords do not match");
    getch();
    loading();
    makeaccount();
    }

}
void accountdetails(){

    char singleline[50], id[15], inputp[30] , accnum[20];
    char name[25] , age[5] , contactnum[15] , nic[20],password[30],money[10],email[35];
    int i = 0, x = 38;
    gotoxy(x,8); printf("Enter The Account Number: "); scanf(" %s", id);
    gotoxy(x,10);printf("Enter The Password: "); scanf(" %s", inputp);
    strcat(id,".dll");
    faccdata = fopen(id,"r");
    while(fgets(singleline,100,faccdata)!= NULL){
        ++i;
        if (i==1){
            strcpy(name,singleline);
        }else if (i==2){
            strcpy(age,singleline);
        }else if (i==3){
            strcpy(contactnum,singleline);
        }else if (i==4){
           strcpy(nic,singleline);
        }else if (i==5){
            strcpy(email,singleline);
        }else if (i==6){
            strcpy(password,singleline);
        }else if (i==7){
            strcpy(accnum,singleline);
        }else if (i==8){
            strcpy(money,singleline);
        }
    }
    clearWindow();
    fclose(faccdata);
    strcat(inputp,"\n");
    loading();
    if (strcmp(password,inputp) == 0){
    gotoxy(x,8); printf("Account Number: %s", accnum);
    gotoxy(x,10);printf("Name: %s", name);
    gotoxy(x,12);printf("Age: %s", age);
    gotoxy(x,14);printf("Contact Number: %s", contactnum);
    gotoxy(x,16);printf("NIC Number: %s", nic);
    gotoxy(x,18);printf("Email: %s", email);
    gotoxy(x,20);printf("Balance: Rs %s", money);
    getch();
    clearWindow();
    return;
    }else{
    gotoxy(x,8);
    printf("Invalid Password OR Account Number");
    getch();
    clearWindow();
    return;
    }
}
void depositmoney(){
    char singleline[50], id[15], inputp[30] , accnum[20];
    char name[25] , age[5] , contactnum[15] , nic[20],password[30],money[10],email[35];
    int i = 0, x = 38, takem , pmoney ;
    gotoxy(x,8); printf("Enter The Account Number: "); scanf(" %s", id);
    gotoxy(x,10);printf("Reenter The Account Number: "); scanf(" %s", inputp);
    if (strcmp(id,inputp)==0){
    strcat(id,".dll");
    faccdata = fopen(id,"r");
    while(fgets(singleline,100,faccdata)!= NULL){
        ++i;
        if (i==1){
            strcpy(name,singleline);
        }else if (i==2){
            strcpy(age,singleline);
        }else if (i==3){
            strcpy(contactnum,singleline);
        }else if (i==4){
           strcpy(nic,singleline);
        }else if (i==5){
            strcpy(email,singleline);
        }else if (i==6){
            strcpy(password,singleline);
        }else if (i==7){
            strcpy(accnum,singleline);
        }else if (i==8){
            strcpy(money,singleline);
        }
    }
    clearWindow();
    fclose(faccdata);
    strcat(inputp,"\n");
    loading();
            gotoxy(x,8); printf("Enter The Amount of money to deposit:");
            gotoxy(x,10); printf("Rs."); scanf(" %d", &takem);
            clearWindow();
            pmoney = atoi(money);
            pmoney += takem;
            faccdata = fopen(id,"w");
            fprintf(faccdata,"%s%s%s%s%s%s%s%d", name,age,contactnum,nic,email,password, accnum,pmoney);
            fclose(faccdata);
            loading();
    }else{
    gotoxy(x,16);printf("The Account Number do Not Match!");
    getch();
    clearWindow();
    depositmoney();
    }
            return;

}
void takemoney(){
    char singleline[50], id[15], inputp[30], accnum[20];
    char name[25] , age[5] , contactnum[15] , nic[20],password[30],money[10],email[35];
    int i = 0, x = 38, takem , pmoney ;
    gotoxy(x,8); printf("Enter The Account Number: "); scanf(" %s", id);
    gotoxy(x,10);printf("Enter The Password: "); scanf(" %s", inputp);
    strcat(id,".dll");
    faccdata = fopen(id,"r");
    while(fgets(singleline,100,faccdata)!= NULL){
        ++i;
        if (i==1){
            strcpy(name,singleline);
        }else if (i==2){
            strcpy(age,singleline);
        }else if (i==3){
            strcpy(contactnum,singleline);
        }else if (i==4){
           strcpy(nic,singleline);
        }else if (i==5){
            strcpy(email,singleline);
        }else if (i==6){
            strcpy(password,singleline);
        }else if (i==7){
            strcpy(accnum,singleline);
        }else if (i==8){
            strcpy(money,singleline);
        }
    }
    clearWindow();
    fclose(faccdata);
    strcat(inputp,"\n");
    loading();
    if (strcmp(password,inputp)==0){
            gotoxy(x,8); printf("Enter The Amount of money to take:");
            gotoxy(x,10); printf("Rs."); scanf(" %d", &takem);
            clearWindow();
            pmoney = atoi(money);
            if (pmoney < takem){
               gotoxy(x,8);printf("NOT Enough Balance!!!");
               getch();
               clearWindow();
               return;
            }
            pmoney -= takem;
            faccdata = fopen(id,"w");
            fprintf(faccdata,"%s%s%s%s%s%s%s%d", name,age,contactnum,nic,email,password, accnum,pmoney);
            fclose(faccdata);
            }else{
            clearWindow();
            gotoxy(x,8);printf("Invalid Password");
            getch();
            clearWindow();
            takemoney();
            }
            loading();
            return;

}
void fromtransfer(char id[15],char inputp[25],int takem){
    char singleline[50] , accnum[20];
    char name[25] , age[5] , contactnum[15] , nic[20],password[30],money[10],email[35];
    int i = 0, x = 38 , pmoney;
    strcat(id,".dll");
    faccdata = fopen(id,"r");
    while(fgets(singleline,100,faccdata)!= NULL){
        ++i;
        if (i==1){
            strcpy(name,singleline);
        }else if (i==2){
            strcpy(age,singleline);
        }else if (i==3){
            strcpy(contactnum,singleline);
        }else if (i==4){
           strcpy(nic,singleline);
        }else if (i==5){
            strcpy(email,singleline);
        }else if (i==6){
            strcpy(password,singleline);
        }else if (i==7){
            strcpy(accnum,singleline);
        }else if (i==8){
            strcpy(money,singleline);
        }
    }
    clearWindow();
    fclose(faccdata);
    strcat(inputp,"\n");
    if (strcmp(password,inputp)==0){
            pmoney = atoi(money);
            if (pmoney < takem){
               gotoxy(x,8);printf("NOT Enough Balance!!!");
               getch();
               clearWindow();
               return;
            }
            pmoney -= takem;
            faccdata = fopen(id,"w");
            fprintf(faccdata,"%s%s%s%s%s%s%s%d", name,age,contactnum,nic,email,password, accnum,pmoney);
            fclose(faccdata);
            }else{
            clearWindow();
            gotoxy(x,8);printf("Invalid Password");
            getch();
            clearWindow();
            transfer();
            }
            return;

}
void totransfer(char id[15],int takem){
    char singleline[50], accnum[20];
    char name[25] , age[5] , contactnum[15] , nic[20],password[30],money[10],email[35];
    int i = 0 , pmoney;
    strcat(id,".dll");
    ftemp = fopen(id,"r");
    while(fgets(singleline,100,ftemp)!= NULL){
        ++i;
        if (i==1){
            strcpy(name,singleline);
        }else if (i==2){
            strcpy(age,singleline);
        }else if (i==3){
            strcpy(contactnum,singleline);
        }else if (i==4){
           strcpy(nic,singleline);
        }else if (i==5){
            strcpy(email,singleline);
        }else if (i==6){
            strcpy(password,singleline);
        }else if (i==7){
            strcpy(accnum,singleline);
        }else if (i==8){
            strcpy(money,singleline);
        }
    }
    clearWindow();
    fclose(ftemp);
            pmoney = atoi(money);
            pmoney += takem;
            ftemp = fopen(id,"w");
            fprintf(ftemp,"%s%s%s%s%s%s%s%d", name,age,contactnum,nic,email,password, accnum,pmoney);
            fclose(ftemp);
            return;
            }
void transfer(){
    char toaccnum[25], froaccmun[25], password[30];
    int x = 38, ammount;
    gotoxy(x,8);printf("Transfer From:");
    gotoxy(x,10);printf("Enter the Account Number:");scanf(" %s",froaccmun);
    gotoxy(x,12);printf("Enter the Password:");scanf(" %s",password);
    gotoxy(x,15);printf("Transfer To:");
    gotoxy(x,17);printf("Enter the Account Number:");scanf(" %s",toaccnum);
    gotoxy(x,20);printf("Enter the Amount To Transfer:Rs.");scanf(" %d", &ammount);
    totransfer(toaccnum,ammount);
    fromtransfer(froaccmun,password,ammount);
    loading();
    clearWindow();

    return;
}
void modifyaccount(){
    char singleline[50], id[15], inputp[30] , accnum[20];
    char name[25] , age[5] , contactnum[15] , nic[20],password[30],money[10],email[35];
    int i = 0, x = 38 , choice;
    gotoxy(x,8); printf("Enter The Account Number: "); scanf(" %s", id);
    gotoxy(x,10);printf("Enter The Password: "); scanf(" %s", inputp);
    strcat(id,".dll");
    faccdata = fopen(id,"r");
    while(fgets(singleline,100,faccdata)!= NULL){
        ++i;
        if (i==1){
            strcpy(name,singleline);
        }else if (i==2){
            strcpy(age,singleline);
        }else if (i==3){
            strcpy(contactnum,singleline);
        }else if (i==4){
           strcpy(nic,singleline);
        }else if (i==5){
            strcpy(email,singleline);
        }else if (i==6){
            strcpy(password,singleline);
        }else if (i==7){
            strcpy(accnum,singleline);
        }else if (i==8){
            strcpy(money,singleline);
        }
    }
    clearWindow();
    fclose(faccdata);
    strcat(inputp,"\n");
    loading();
    if (strcmp(password,inputp)==0){
            clearWindow();
            gotoxy(x-1,8);printf("Change:");
            gotoxy(x,10);printf("1) Name");
            gotoxy(x,12);printf("2) Age");
            gotoxy(x,14);printf("3) Contact Number");
            gotoxy(x,16);printf("4) NIC Number");
            gotoxy(x,18);printf("5) Email Address");
            gotoxy(x,20);printf("6) Password");
            gotoxy(x,22);printf("  Your Choice:");scanf(" %d", &choice);
            switch (choice){
                case 1 : clearWindow();
                         gotoxy(x,8);printf("Your old name was: %s", name);
                         gotoxy(x,10);printf("Enter The new name:");scanf(" %s", name);
                         name[0]= toupper(name[0]);
                         strcat(name,"\n");
                         clearWindow();
                         break;
                case 2 : clearWindow();
                         gotoxy(x,8);printf("Your old age was: %s" , age);
                         gotoxy(x,10);printf("Enter The new age:");scanf(" %s", age);
                         strcat(age,"\n");
                         clearWindow();
                         break;
                case 3 : clearWindow();
                         gotoxy(x,8);printf("Your old Contact Number was: %s" , contactnum);
                         gotoxy(x,10);printf("Enter The new Contact Number:");scanf(" %s", contactnum);
                         strcat(contactnum,"\n");
                         clearWindow();
                         break;
                case 4 : clearWindow();
                         gotoxy(x,8);printf("Your old NIC Number was: %s" , nic);
                         gotoxy(x,10);printf("Enter The new NIC Number:");scanf(" %s", nic);
                         strcat(nic,"\n");
                         clearWindow();
                         break;
                case 5 : clearWindow();
                         gotoxy(x,8);printf("Your old Email was: %s" , email);
                         gotoxy(x,10);printf("Enter The new Email:");scanf(" %s", email);
                         strcat(email,"\n");
                         clearWindow();
                         break;
                case 6 : clearWindow();
                         gotoxy(x,8);printf("Your old Password was: %s" , password);
                         gotoxy(x,10);printf("Enter The new Password:");scanf(" %s", password);
                         strcat(password,"\n");
                         clearWindow();
                         break;
                default : clearWindow();
                          break;
    }
    faccdata = fopen(id,"w");
    fprintf(faccdata,"%s%s%s%s%s%s%s%s", name,age,contactnum,nic,email,password, accnum,money);
    fclose(faccdata);
    loading();
    char hello[4];
    gotoxy(x,10);printf("Successfully Modified");
    gotoxy(x,14);printf("Press Y to continue Modifying");
    gotoxy(x,16);scanf(" %s", hello);
    if ((strcmp(hello,"y")==0)||(strcmp(hello,"Y")==0)){
        clearWindow();
        modifyaccount();
    }else{
    clearWindow();
    return;
    }
    }else{clearWindow();
            gotoxy(x,8);printf("Invalid Password");
            getch();
            clearWindow();
            return;
            }

}
void startmenu(){
    int x = 3.5 , choice;
    gotoxy(x,8);printf("1) Make Account");
    gotoxy(x,10);printf("2) Account Details");
    gotoxy(x,12);printf("3) Modify Account");
    gotoxy(x,14);printf("4) Transaction");
    gotoxy(x,16);printf("5) Deposit Money");
    gotoxy(x,18);printf("6) Take Money");
    gotoxy(x,20);printf("7) Exit");
    gotoxy(x,23);printf("   Your Choice:");scanf(" %d", &choice);

    switch (choice){
        case 1 : loading();
                 makeaccount();
                 break;
        case 2 : loading();
                 accountdetails();
                 break;
        case 3 : loading();
                 modifyaccount();
                 break;
        case 4 : loading();
                 transfer();
                 break;
        case 6 : loading();
                 takemoney();
                 break;
        case 5 : loading();
                 depositmoney();
                 break;
        case 7 : loading();
                 system("cls");
                 exit(0);
                 break;
        default : system("cls");
                  break;
    }
    clearWindow();
    startmenu();
    }
