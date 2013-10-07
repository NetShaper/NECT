#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
//pH34r-pH
//NECT emulator
 
char* lowerCase(char word[]);//init. function
 
struct user//basic user datatype
{
    char name[20];
    char *item;
    char *arg0;
    char *arg1;
    char *optn;
 
};
 
void main(){
    srand(time(NULL));
 
    //This will be used to add a chance of failure to actions, possibly even a reason why
    //E.x. "you didn't focus well enough"
    int randomNumber = (rand()%100)+1;
    //hasn't actually been used yet
 
    struct user User;
 
    char *line = "***********************************************";//just to keep even lines, use this
    printf("%s", line);
    printf("\nLoading interface...\nEnter User Name: ");
    scanf("%s", &User.name);
    printf("Loading user profile...\n");//its actually loading stuff! kinda
    User.item = "";
    User.arg0 = "";
    User.arg1 = "";
    User.optn = "";
    printf("Welcome back %s!", &User.name);//certain user names can make this funny
 
    int run = 1;//keeps the while loop going
    int skip = 1;//skips the while loop for help prompts, also for any other standalone commands
    while(run == 1){//main loop
        char command[100];//new blank command
        char *output;//new blank output variable
        output = malloc(sizeof(char)*100+1);//it is very large, might be larger later
        output[0]='\0';//keep it nice and empty
        char *outtemp;//ended up needing this for multi-line outputs
        outtemp = malloc(sizeof(char)*50);
        outtemp[0]='\0';
        printf("\nC:\\user\\%s\\mem: ", &User.name);
        scanf("%s", &command);
        lowerCase(command);//keeps it from being dumb with mismatched case
        //command char pointers
        char *temp;
        char *comm;
        char *arg0;
        char *arg1;
        char *optn;
        char *endstrip;
        
        //Begin interpretation!
        //Expected format-
        //Command :: arg0 : arg1 :: option
 
        if(strcmp(command, "exit") == 0) {
            output = "Exiting terminal.\n***********************************************";
            run = 0;
        }
        if(strcmp(command, "help") == 0){
            skip = 0;
            printf("Need some help?\n\nBasic command format:\n  Command::Argument1:Argument2::END\n");
            printf("  Command::Argument1:Argument2:Option::END\n");
            printf("Standalone commands:\n");
            printf("  exit - Exits terminal\nCommand Arguments:\n  LOAD: - Select Item\n  SET: - Set target of Item\n");
            printf("  FIRE: - Fire a weapon Item\nArgument one and two options:\n  LOAD - Weapon:Ammunition\n");
            printf("  SET - target:source\n  FIRE - weapon:target\nOption Arguments:\n  END - Do nothing\n");
            printf("  RELOAD - Reloads last fired weapon");
        }
 
        if(run == 1 && skip == 1){//this splits up the command into useful inputs
            temp = strtok (command,":");
            comm = malloc(strlen(temp)+1);
            strcpy(comm, temp);
 
            temp = strtok (NULL, ":");
            arg0 = malloc(strlen(temp)+1);
            strcpy(arg0, temp);
 
            temp = strtok (NULL, ":");
            arg1 = malloc(strlen(temp)+1);
            strcpy(arg1, temp);
 
            temp = strtok (NULL, ":");
            optn = malloc(strlen(temp)+1);
            strcpy(optn, temp);
 
            //this allows optn to be end, or to have end after it
            if(strcmp(optn, "end") != 0)
                temp = strtok (NULL, ":");
                endstrip = malloc(strlen(temp)+1);
                strcpy(endstrip, temp);
 
            //Actual interpretation time
            if(strcmp(comm, "load")==0){//for all load commands
                if(strcmp(arg0, User.item)==0){
                    sprintf(output, "> Loading... \n> %s already initialized!", arg0);//if you already did this
                }else{
                    sprintf(output, "> Loading...\n> %s.initialize successful!", arg0);//if you havent yet
                    User.item = arg0;
                }
                if(strcmp(arg1, User.arg1)==0 && strcmp(arg0, User.item)==0){//if you called this module from the same class
                    sprintf(outtemp, "\n> %s.%s already initialized!", arg0, arg1);
                    strcat(output, outtemp);
                }else{
                    sprintf(outtemp, "\n> %s.%s.initialize successful!", arg0, arg1);//this is where failure might be added
                    strcat(output, outtemp);
                    User.arg1 = arg1;
                }
            }
            if(strcmp(comm, "set")==0){//same thing but for set format
                if(strcmp(arg0, User.arg0)==0){
                    sprintf(output, "> Already set to %s module!", arg0);
                }else{
                    sprintf(output, "> Loading...\n> %s.initialize successful!", arg0);
                    User.arg0 = arg0;
                }
                if(strcmp(arg1, User.arg1)==0 && strcmp(arg0, User.arg0)==0){
                    sprintf(outtemp, "\n> %s.%s already initialized!", arg0, arg1);
                    strcat(output, outtemp);
                }else{
                    sprintf(outtemp, "\n> %s set to input from %s module!", arg0, arg1);
                    strcat(output, outtemp);
                    User.arg1 = arg1;
                }
            }
            if(strcmp(comm, "fire")==0){//fire is intentionally generic, but requires accurate commands. 
                int fired = 0;
                if(strcmp(arg0, User.item)==0 && strcmp(arg1, "target")==0){
                    sprintf(output, "> %s.state: Fire successful!", User.item);
                    fired = 1;
                }
                if(strcmp(arg0, User.item)!=0)
                    sprintf(output, "> Error! %s not loaded; %s currently loaded!", arg0, User.item);
                if(strcmp(arg1, "target")!=0){
                    if(strcmp(arg0, User.item)!=0)
                        sprintf(outtemp, "\n> Error! Must designate \"target\" in arg1!");
                    else if(strcmp(arg0, User.item)==0)
                        sprintf(outtemp, "> Error! Must designate \"target\" in arg1!");
                    strcat(output, outtemp);
                }
                if(strcmp(optn, "reload")==0){
                    if(fired == 1)
                        sprintf(outtemp, "\n> %s.reload.LastUsed successful!", User.item);
                    else if(fired == 0)
                        sprintf(outtemp, "\n> %s.reload.LastUsed failed!", User.item);
                    strcat(output, outtemp);
                }
            }
        }
        if(skip == 1)
            printf("C:\\user\\%s\\mem: %s", &User.name, output);
        skip = 1;
    }
}
 
char* lowerCase(char word[]){
    int i = strlen(word);
    int j;
    for(j=0;j<i;j++){
        word[j]=tolower(word[j]);
    }
    return word;
}
