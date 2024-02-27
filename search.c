/**
 * @file search.c
 * @author João Ribeiro
 * @date 31-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2024. All Rights MIT Licensed.
 *
 * @brief Contains functions related with search equipments.
 */

#include "structs.h"
#include "design.h"
#include "functions.h"

void search_menu (Equipment_Count *equipment){
    int menu_choice;
    do{
        puts(LINE);
        puts(MENU_SEARCH_DISPLAY);
        puts(LINE);
        puts(SEARCH_IDENTIFIER);
        puts(SEARCH_NAME);
        puts(EXIT);
        scanf("%d", &menu_choice);
        cleanInputBuffer();
        switch(menu_choice){
            case 1:
                search_identifier(equipment);
                break;
            case 2:
                search_name(equipment);
                break;
            case 0:
                break;
            default:
                puts(ERROR_OPTION);
                break;
        }
    }while (menu_choice != 0);
}

int get_name_position(Equipment_Count *equipment, const char *get_name){
    int i;
    for (i=0; i<equipment->counter; i++){
        if(strcmp(equipment->equipments[i].designation, get_name) == 0){
            return i;
        }
    }
    return -1;
}

void search_name (Equipment_Count *equipment){
    char name[DESIGNATION_SIZE];
    int number;
    puts(MSG_GET_EQUIPMENT_DESIGNATION);
    scanf("%s", name);
    
    cleanInputBuffer();
    
    number = get_name_position(equipment, name);
    
    if (number != -1){
        if(strcmp (equipment->equipments[number].status, "For Recycling") != 0){
            print_equipment(equipment->equipments[number]);
        }else{
            puts(ERROR_EQUIPMENT_FOR_RECYCLING);
        }
    }else {
        puts(ERROR_EQUIPMENT_DO_NOT_EXIST);
    }
}

void search_identifier (Equipment_Count *equipment){
    int number = get_equipment_position(*equipment, getInt(MIN_NUMBER_EQUIPMENT, MAX_NUMBER_EQUIPMENT, MSG_GET_NUMBER_EQUIPMENT));
    if (number != -1){
        if(strcmp (equipment->equipments[number].status, "For Recycling") != 0){
            print_equipment(equipment->equipments[number]);
        }else{
            puts(ERROR_EQUIPMENT_FOR_RECYCLING);
        }
    }else {
        puts(ERROR_EQUIPMENT_DO_NOT_EXIST);
    }
}