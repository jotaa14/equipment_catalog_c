/**
 * @file main.c
 * @author João Ribeiro
 * @date 30-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2024. All Rights MIT Licensed.
 *
 * @brief This C program allows you to track an organization's technology park.
 *
 * It consists of admitting all existing equipment in the company, 
 * and cataloging them.
 * 
 * This application allows you to manage the catalog of all equipment, 
 * user management, view equipment history, list free equipment 
 * and equipment for recycling and search for equipment by identifier and name.
 */

#include "structs.h"
#include "design.h"
#include "functions.h"
#include "consts.h"

int main() {
    int choice_menu;
    Equipment_Count *equipment;
    equipment = NULL;
    
    if (equipment == NULL){
        equipment = malloc(1 * sizeof(Equipment_Count));
        equipment->counter = 0;
    }

    User_Count *user;
    user=NULL;
    if(user == NULL){
        user = malloc(1 * sizeof(User_Count));
        user->counter = 0;
    }
    do{
        puts(LINE);
        puts(MENU);
        puts(LINE);
        puts(EQUIPMENT_MENU);
        puts(USER_MENU);
        puts(LIST_MENU);
        puts(SEARCH_MENU);
        puts(MAINTANCE_MENU);
        puts(SAVE);
        puts(LOAD);
        puts(EXIT);
        scanf("%d", &choice_menu);
        cleanInputBuffer();
        switch (choice_menu){
            case 0:
                break;
            case 1:
                equipment_menu(equipment, user);
                break;
            case 2:
                user_menu(equipment, user);
                break;
            case 3:
                list_menu(equipment, user);
                break;
            case 4:
                search_menu(equipment);
                break;
            case 5:
                maintance_menu(equipment);
                break;
            case 6:
                equipment = save_equipments (equipment, FILE_NAME_EQUIPMENTS);
                user = save_user(user, FILE_NAME_USERS);
                puts(SAVED);
                break;
            case 7:
                equipment = load_equipments (equipment, FILE_NAME_EQUIPMENTS);
                user = load_user(user, FILE_NAME_USERS);
                puts(LOADED);
                break;
            default:
                puts(ERROR_OPTION);
                break;     
        }
    }while(choice_menu != 0);

    free_equipment(equipment);
    free_user(user);
    return (EXIT_SUCCESS);
}

