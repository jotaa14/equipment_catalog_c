/**
 * @file user.c
 * @author João Ribeiro
 * @date 31-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2024. All Rights MIT Licensed.
 *
 * @brief Contains functions related with user's.
 */

#include "structs.h"
#include "design.h"
#include "functions.h"

void user_menu (Equipment_Count *equipment, User_Count *user){
    int menu_choice;
    do{
        puts(LINE);
        puts(USER_OPTIONS);
        puts(LINE);
        puts(INSERT_USER_MENU);
        puts(EDIT_USER);
        puts(REMOVE_USER);
        puts(EXIT);
        scanf("%d", &menu_choice);
        cleanInputBuffer();
        switch(menu_choice){
            case 1:
                user = insert_user(user);
                break;
            case 2:
                edit_user(user);
                break;
            case 3:
                remove_user(equipment, user);
                break;
            case 0:
                break;
            default:
                puts(ERROR_OPTION);
                break;
        }
    }while (menu_choice != 0);
}

int get_user_position (User_Count *user, int number){
    int i;
    for (i = 0; i < user->counter ; i++) {
        if(user->users[i].number == number){
            return i;
        }
    }
    return -1;
}

User_Count *new_list_user (User_Count *user, int size){
    if (user->counter == 0){
        user->users = malloc(1 * sizeof(User));
    }
    
    if(user->counter != 0){        
        user->users = realloc(user->users, size * sizeof(User));
        if(user->users == NULL){
            puts("No memory.");
            return NULL;
        }       
    }
    return user;
}

User_Count *insert_user(User_Count *user){
    
    user = new_list_user(user, user->counter+1);
    
    puts(INSERT_USER);
    int number = getInt(MIN_USER, MAX_USER, MSG_GET_NUMBER_USER);
    
    if (get_user_position(user, number) != -1){
        puts(ERROR_USER_EXISTS);
        return user;
    }
    
    user->users[user->counter].number = number;
    
    readString(user->users[user->counter].acronym, ACRONYM_SIZE, MSG_GET_USER_ACRONYM);
    
    readString(user->users[user->counter].name, NAME_SIZE, MSG_GET_USER_NAME);
    
    readString(user->users[user->counter].office, OFFICE_SIZE, MSG_GET_USER_OFFICE);
    
    strcpy(user->users[user->counter].status, "Active");

    if(number != 0) {
        user->counter++;
        puts(USER_ADDED);
    }

    return user;
}

int choose_user(User_Count *user){
    list_user(user);
    int user_choice = getInt(MIN_USER, MAX_USER, MSG_GET_NUMBER_USER);
    if(user_choice < 0 || user_choice > user->counter){
        puts(ERROR_OPTION);
    }
    return user_choice -1;
}

void edit_user (User_Count *user){
    int edit_menu;
    list_user(user);
    
    int position = get_user_position(user, getInt(MIN_USER, MAX_USER, MSG_GET_NUMBER_USER));
    
    if (position == -1) {
        puts(ERROR_USER_DO_NOT_EXIST);
        return;
    }
    
    do{
        puts(DISPLAY_EDIT);
        puts(EDIT_ACRONYM);
        puts(EDIT_NAME);
        puts(EDIT_OFFICE);
        puts(EDIT_STATUS_USER);
        puts(EXIT);
        scanf("%d", &edit_menu); 
        cleanInputBuffer();
        char new_status[STATUS_ACT_INACT_SIZE];
        switch (edit_menu){
            case 1:
                readString(user->users[position].acronym, ACRONYM_SIZE, MSG_GET_USER_ACRONYM);
                break;
            case 2:
                readString(user->users[position].name, NAME_SIZE, MSG_GET_USER_NAME);
                break;
            case 3:
                readString(user->users[position].office, OFFICE_SIZE, MSG_GET_USER_OFFICE);
                break;
            case 4:
                printf(MSG_CURRENT_STATUS, user->users[position].status);
                readString(new_status, STATUS_ACT_INACT_SIZE, NEW_STATUS_USER_MSG);
                strcpy(user->users[position].status, new_status);
                break;
            case 0:
                break;
            default:
                puts(ERROR_OPTION);
                break;
            
        }
        puts(USER_EDITED);
    }while (edit_menu!=0);
}

void remove_user(Equipment_Count *equipment,User_Count *user){
    int position = get_user_position(user, getInt(MIN_USER, MAX_USER, MSG_GET_NUMBER_USER));
    int j;
    int edit_status_choice;
    if(position ==-1){
        puts(ERROR_USER_DO_NOT_EXIST);
        return;
    }
    
    if(user->users[position].have_equipment == 0){
        user->users[position].number = 0;
        strcpy(user->users[position].acronym, "");
        strcpy(user->users[position].name, "");
        strcpy(user->users[position].office, "");
        strcpy(user->users[position].status, "");

        for (int i = position; i < user->counter-1; i++){
            user->users[i] = user->users[i+1];
        }
        user->counter--;
        puts(USER_REMOVED);
    }else{
        puts(USER_CANT_BE_REMOVED);
        puts("Do you want edit User Status to Inactive?");
        puts("(1) YES");
        puts("(2) NO");
        scanf("%d", &edit_status_choice);
        switch (edit_status_choice){
            case 1:
                strcpy(user->users[position].status, "Inactive");    
                break;
            case 2:
                break;
            default:
                puts(ERROR_OPTION);
                break;
        }
    } 
}