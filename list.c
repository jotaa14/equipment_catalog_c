/**
 * @file list.c
 * @author João Ribeiro
 * @date 03-02-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2024. All Rights MIT Licensed.
 *
 * @brief Contains functions related with list functions.
 */

#include "structs.h"
#include "design.h"
#include "functions.h"

void list_menu (Equipment_Count *equipment, User_Count *user){
    int menu_choice;
    do{
        puts(LINE);
        puts(LIST_MENU_DISPLAY);
        puts(LINE);
        puts(LIST_ALL_EQUIPMENTS);
        puts(LIST_FREE_EQUIPMENTS);
        puts(LIST_TO_RECYCLE_EQUIPMENTS);
        puts(LIST_USER);
        puts(EXIT);
        scanf("%d", &menu_choice);
        cleanInputBuffer();
        switch(menu_choice){
            case 1:
                list_equipments(equipment);
                break;
            case 2:
                list_equipments_free(equipment);
                break;
            case 3:
                list_equipments_to_recycle(*equipment);
                break;
            case 4:
                list_user (user);
                break;
            case 0:
                break;
            default:
                puts(ERROR_OPTION);
                break;
        }
    }while (menu_choice != 0);
}

void print_equipment(Equipment equipments){
    puts(LINE);
    puts(EQUIPMENT_DISPLAY);
    puts(LINE);
    printf("\nNumber: %d\nDesignation: %s\nPurchase Date: %d-%d-%d\nCategory: %s\nStatus: %s\nUser Code: %d\n", equipments.number, equipments.designation, equipments.purchase_day, equipments.purchase_month, equipments.purchase_year,
           printCategory(equipments.categories), equipments.status, equipments.users.number);
}

const char* printCategory(listCategories category) {

    switch (category) {
        case Printer:
            return "Printer";
        case Computer:
            return "Computer";
        case PC:
            return "PC";
        case Monitor:
            return "Monitor";
        case Router:
            return "Router";
        case Switch:
            return "Switch";
        case TV:
            return "TV";
        case Projector:
            return "Projector";
        case Access:
            return "Access Control";
        case Mouse:
            return "Mouse";
        case Accessory:
            return "Accessory";
        case Other:
            return "Other";
        default:
            return "Unknown Type!";
    }
}


void list_equipments(Equipment_Count *equipment){
    int i;
    if(equipment->counter > 0){
        for(i=0; i<equipment->counter; i++){
            if(strcmp (equipment->equipments[i].status, "For Recycling") != 0){
                print_equipment(equipment->equipments[i]);
            } else{
                puts(ERROR_EMPTY_LIST);
            }           
        }
    } else{
        puts(ERROR_EMPTY_LIST);
    }
}

void list_equipments_free(Equipment_Count *equipment){
    int i;

    list_category_sorted(*equipment);
    if(equipment->counter > 0){
        for(i=0; i<equipment->counter; i++){
            if(equipment->equipments[i].users.number == 0){
                print_equipment(equipment->equipments[i]);
            }           
        }      
    } else{
        puts(ERROR_EMPTY_LIST);
    }
}

void list_equipments_to_recycle(Equipment_Count equipment){
    int i;
    if(equipment.counter > 0){
        for(i=0; i<equipment.counter; i++){
            if(strcmp(equipment.equipments[i].status, "For Recycling") == 0){
                print_equipment(equipment.equipments[i]);
            }
        }
    }else{
        puts(ERROR_EMPTY_LIST);
    }
}

void print_user (User users){
    puts(LINE);
    puts(USER_DISPLAY);
    puts(LINE);
    printf("Number: %d\nAcronym: %s\nName: %s\nOffice: %s\nStatus: %s\n", users.number, users.acronym, users.name, users.office, users.status);
}

void list_user (User_Count *user){
    int i;
    if(user->counter > 0){
        for(i=0; i<user->counter; i++){
            print_user(user->users[i]);
        }
    }else{
        puts(ERROR_EMPTY_LIST);
    }
}

Equipment_Count *list_maintance_equipment(Equipment_Count *equipment){ //REVER
    int i;
    
    list_equipments(equipment);
    
    int number = get_equipment_position(*equipment, getInt(MIN_NUMBER_EQUIPMENT, MAX_NUMBER_EQUIPMENT, MSG_GET_NUMBER_EQUIPMENT));
    
    if (number == -1) {
        puts(ERROR_EQUIPMENT_DO_NOT_EXIST);
        return equipment;
    }
    
    if (equipment->equipments[number].maintance_counter > 0) {
        for(i = 0; i < equipment->equipments[number].maintance_counter; i++){
            puts(LINE);
            puts(MAINTANCE_DISPLAY);
            puts(LINE);
            printf("\nNumber: %d\nDate: %d-%d-%d\nMaintance Type: %s\nMaintance Note: %s\n", equipment->equipments[number].maintance[i].number, equipment->equipments[number].maintance[i].maintance_day, equipment->equipments[number].maintance[i].maintance_month, equipment->equipments[number].maintance[i].maintance_year, equipment->equipments[number].maintance[i].maintance_type, equipment->equipments[number].maintance[i].maintance_note);
        }
    } else{
        puts(ERROR_EMPTY_LIST);
    }
    return equipment;
}


void list_category_sorted(Equipment_Count equipment){
    int i, j;
    if(equipment.counter > 0){
        for(i = 0; i < equipment.counter; i++) {

            swapEquipments(&equipment.equipments[i], &equipment.equipments[i+1]);
        }
    } else{
        puts(ERROR_EMPTY_LIST);
    }
}

void swapEquipments(Equipment *equipment1, Equipment *equipment2) {
    Equipment temp = *equipment1;
    equipment1 = equipment2;
    *equipment2 = temp;
}