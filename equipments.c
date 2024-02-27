/**
 * @file equipments.c
 * @author João Ribeiro
 * @date 30-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2024. All Rights MIT Licensed.
 *
 * @brief Contains functions related with equipments.
 */

#include "structs.h"
#include "design.h"
#include "functions.h"

void equipment_menu (Equipment_Count *equipment, User_Count *user){
    int menu_choice;
    do{
        puts(LINE);
        puts(EQUIPMENT_MENU_DISPLAY);
        puts(LINE);
        puts(INSERT_EQUIPMENT_MENU);
        puts(EDIT_EQUIPMENT);
        puts(REMOVE_EQUIPMENT);
        puts(EXIT);
        scanf("%d", &menu_choice);
        cleanInputBuffer();
        switch(menu_choice){
            case 1:
                equipment=insert_equipment(equipment, user);
                break;
            case 2:
                edit_equipments(equipment, user);
                break;
            case 3:
                remove_equipments(equipment);
                break;
            case 0:
                break;
            default:
                puts(ERROR_OPTION);
                break;
        }
    }while (menu_choice != 0);
}

int get_equipment_position(Equipment_Count equipment, int number){
    int i;
    for (i=0; i<equipment.counter; i++){
        if(equipment.equipments[i].number == number){
            return i;
        }
    }
    return -1;
}

Equipment_Count *new_list_equipment (Equipment_Count *equipment, int size){
    if (equipment->counter == 0){
        equipment->equipments = malloc(1 * sizeof(Equipment));
    }
    
    if(equipment->counter != 0){
        equipment->equipments = realloc(equipment->equipments, size * sizeof(Equipment));
        if(equipment->equipments == NULL){
            puts("No memory.");
            return NULL;
        }       
    }
    return equipment;
}

Equipment_Count *insert_equipment(Equipment_Count *equipment, User_Count *user){
    
    equipment = new_list_equipment(equipment, equipment->counter+1);
    
    puts(INSERT_EQUIPMENT);
    
    int number = getInt(MIN_NUMBER_EQUIPMENT, MAX_NUMBER_EQUIPMENT, MSG_GET_NUMBER_EQUIPMENT);
    
    if (get_equipment_position(*equipment, number) != -1) {
        puts(ERROR_EQUIPMENT_EXIST);
        return equipment;
    }
    
    equipment->equipments[equipment->counter].number = number;
    readString(equipment->equipments[equipment->counter].designation,DESIGNATION_SIZE, MSG_GET_EQUIPMENT_DESIGNATION);
    equipment->equipments[equipment->counter].purchase_day = getInt(MIN_DATE_DAY, MAX_DATE_DAY, MSG_GET_PURCHASE_DATE_DAY);
    equipment->equipments[equipment->counter].purchase_month = getInt(MIN_DATE_MONTH, MAX_DATE_MONTH, MSG_GET_PURCHASE_DATE_MONTH);
    equipment->equipments[equipment->counter].purchase_year = getInt(MIN_DATE_YEAR, MAX_DATE_YEAR, MSG_GET_PURCHASE_DATE_YEAR);
    strcpy(equipment->equipments[equipment->counter].status, "Operational");

    equipment->equipments[equipment->counter].categories = choose_category(equipment);

    if(user->counter==0){
        user=insert_user(user);
        int user_index = choose_user(user);
        if(user_index == -1){
            equipment->counter++;
            puts(EQUIPMENT_ADDED);
            return equipment;
        }
        equipment->equipments[equipment->counter].users=user->users[user_index];
        equipment[equipment->counter].used_by_user++;
        user->users[user_index].have_equipment++;
    }else{
        int user_index = choose_user(user);
        if(user_index == -1){
            return equipment;
        }
        equipment->equipments[equipment->counter].users=user->users[user_index];  
        equipment[equipment->counter].used_by_user++;
        user->users[user_index].have_equipment++;
    }
    
    equipment[equipment->counter].used_by_equipment++;
    equipment->equipments[equipment->counter].maintance_counter=0;
    if(equipment->equipments[equipment->counter].maintance_counter==0){
        equipment->counter++;
        puts(EQUIPMENT_ADDED);
    }

    return equipment;
}

void edit_equipments(Equipment_Count *equipment, User_Count *user){
    int edit_menu;
    int number = get_equipment_position(*equipment, getInt(MIN_NUMBER_EQUIPMENT, MAX_NUMBER_EQUIPMENT, MSG_GET_NUMBER_EQUIPMENT));
    if (number == -1) {
        puts(ERROR_EQUIPMENT_DO_NOT_EXIST);
        return;
    }
    do{
        puts(LINE);
        puts(DISPLAY_EDIT);
        puts(LINE);
        puts(EDIT_DESIGNATION);
        puts(EDIT_PURCHASE_DAY);
        puts(EDIT_PURCHASE_MONTH);
        puts(EDIT_PURCHASE_YEAR);
        puts(EDIT_USER_CODE);
        puts(EDIT_STATUS);
        puts(EDIT_EQUIPMENT_CATEGORY);
        puts(EXIT);
        scanf("%d", &edit_menu);
        
        cleanInputBuffer();
        int user_index = choose_user(user);
        char new_status[STATUS_SIZE];  

        switch (edit_menu) {
            case 0:
                break;
            case 1:
                readString(equipment->equipments[number].designation,DESIGNATION_SIZE, MSG_GET_EQUIPMENT_DESIGNATION);
                break;
            case 2:
                equipment->equipments[number].purchase_day = getInt(MIN_DATE_DAY, MIN_DATE_DAY, MSG_GET_PURCHASE_DATE_DAY);
                break;
            case 3:
                equipment->equipments[number].purchase_month = getInt(MIN_DATE_MONTH, MIN_DATE_MONTH, MSG_GET_PURCHASE_DATE_MONTH);
                break;
            case 4:
                equipment->equipments[number].purchase_year = getInt(MIN_DATE_YEAR, MIN_DATE_YEAR, MSG_GET_PURCHASE_DATE_YEAR);
                break;
            case 5:
                if(user_index == -1){
                    return;
                }
        equipment->equipments[equipment->counter].users=user->users[user_index];
                break;
            case 6:
                printf(MSG_CURRENT_STATUS, equipment->equipments[number].status);
                readString(new_status, STATUS_SIZE, NEW_STATUS_MSG);
                strcpy(equipment->equipments[number].status, new_status);
                break;
            case 7:
                equipment->equipments[equipment->counter].categories = choose_category(equipment);
                break;
            default:
                puts(ERROR_OPTION);
                break;
        }
        puts(EQUIPMENT_EDITED);
        
    }while (edit_menu != 0);
}

void clean_data_equipment(Equipment *equipments) {
    equipments->number=0;
    equipments->purchase_day=0;
    equipments->purchase_month=0;
    equipments->purchase_year=0;
    //equipments->categories.number=0;
    equipments->users.number=0;
    strcpy(equipments->designation, "");
    strcpy(equipments->status, "");
    //strcpy(equipments->categories.category, "");
    //strcpy(equipments->categories.status, "");
    strcpy(equipments->users.acronym, "");
    strcpy(equipments->users.name, "");
    strcpy(equipments->users.office, "");
    strcpy(equipments->users.status, "");
}

void remove_equipments (Equipment_Count *equipment){
    int i;
    int number = get_equipment_position(*equipment, getInt(MIN_NUMBER_EQUIPMENT, MAX_NUMBER_EQUIPMENT, MSG_GET_NUMBER_EQUIPMENT));
    if (number == -1) {
        puts(ERROR_EQUIPMENT_DO_NOT_EXIST);
        return;
    }
    
    if(strcmp (equipment->equipments[number].status, "For Recycling") == 0){
        if(equipment->equipments[number].users.number == 0){
            equipment->equipments[number] = equipment->equipments[equipment->counter-1];
    
            clean_data_equipment(&equipment->equipments[equipment->counter - 1]);
    
            equipment->counter--;
    
            equipment[number].used_by_equipment--;
            for (i=0; i<equipment->equipments[number].maintance_counter; i++){
                equipment = delete_maintance(equipment, i);
            }
            puts(EQUIPMENT_REMOVED);
        } else{
            puts(ERROR_EQUIPMENT_CANT_BE_REMOVED);
        }  
    } else{
        puts(ERROR_EQUIPMENT_CANT_BE_REMOVED);
    }
    
}