/**
 * @file maintance.c
 * @author João Ribeiro
 * @date 31-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2024. All Rights MIT Licensed.
 *
 * @brief Contains functions related with equipments maintance.
 */

#include "structs.h"
#include "design.h"
#include "functions.h"

void maintance_menu (Equipment_Count *equipment){
    int menu_choice;
    do{
        puts(LINE);
        puts(MENU_MAINTANCE_DISPLAY);
        puts(LINE);
        puts(EQUIPMENT_MAINTANCE);
        puts(MAINTANCE_HISTORY);
        puts(EXIT);
        scanf("%d", &menu_choice);
        cleanInputBuffer();
        switch(menu_choice){
            case 1:
                equipment= insert_maintance(equipment);
                break;
            case 2:
                equipment=list_maintance_equipment(equipment);
                break;
            case 0:
                break;
            default:
                puts(ERROR_OPTION);
                break;
        }
    }while (menu_choice != 0);
}

Equipment_Count *insert_maintance(Equipment_Count *equipment){
    list_equipments(equipment);
    
    int number = get_equipment_position(*equipment, getInt(MIN_NUMBER_EQUIPMENT, MAX_NUMBER_EQUIPMENT, MSG_GET_NUMBER_EQUIPMENT));
    int maintance_position = equipment->equipments[number].maintance_counter;
    if (number == -1) {
        puts(ERROR_EQUIPMENT_DO_NOT_EXIST);
        return equipment;
    }
    if(equipment->equipments[number].maintance == NULL){
        equipment->equipments[number].maintance = (Maintenance *) malloc(1 * sizeof(Maintenance));
    }
    else{
        equipment->equipments[number].maintance = realloc(equipment->equipments[number].maintance, 5 * sizeof(Maintenance));
    }
    if(equipment->equipments[number].maintance == NULL) {
        puts(ERROR_ALLOCATE_MEMORY);
        return equipment;
    }
    
    equipment->equipments[number].maintance[maintance_position].maintance_day = getInt(MIN_DATE_DAY, MAX_DATE_DAY, MSG_GET_MAINTANCE_DATE_DAY);
    equipment->equipments[number].maintance[maintance_position].maintance_month = getInt(MIN_DATE_MONTH, MAX_DATE_MONTH, MSG_GET_MAINTANCE_DATE_MONTH);
    equipment->equipments[number].maintance[maintance_position].maintance_year = getInt(MIN_DATE_YEAR, MAX_DATE_YEAR, MSG_GET_MAINTANCE_DATE_YEAR);
    readString(equipment->equipments[number].maintance[maintance_position].maintance_type, MAINTANCE_TYPE_SIZE, MSG_GET_MAINTANCE_TYPE);
    readString(equipment->equipments[number].maintance[maintance_position].maintance_note, NOTE_SIZE, MSG_GET_MAINTANCE_NOTE);
    
    equipment->equipments[number].maintance[maintance_position].maintance = true;
    equipment->equipments[number].maintance[maintance_position].number++;
    equipment->equipments[number].maintance_counter++;
    
    return equipment;
}

void clean_maintance (Maintenance *maintance){
    maintance->number = 0;
    maintance->maintance_day = 0;
    maintance->maintance_month = 0;
    maintance->maintance_year = 0;
    strcpy(maintance->maintance_type, "");
    strcpy(maintance->maintance_note, "");
}

bool equipment_has_maintance(Equipment *equipments){
    return equipments->maintance->maintance;
}

Equipment_Count *delete_maintance (Equipment_Count *equipment, int maintance_id){
    list_equipments(equipment);
    
    int number = get_equipment_position(*equipment, getInt(MIN_NUMBER_EQUIPMENT, MAX_NUMBER_EQUIPMENT, MSG_GET_NUMBER_EQUIPMENT));
    
    if (number != -1) {
        puts(ERROR_EQUIPMENT_EXIST);
        return equipment;
    }
    
    list_maintance_equipment(equipment);
    
//    int maintance_id = getInt(MIN_NUMBER_MAINTANCE, MAX_NUMBER_MAINTANCE, MSG_GET_NUMBER_MAINTANCE);
    
    if(equipment_has_maintance(&equipment->equipments[number])){
        equipment->equipments[number].maintance[maintance_id] = equipment->equipments[number].maintance[equipment->equipments[number].maintance_counter -1];
        clean_maintance(&(equipment->equipments[number].maintance[equipment->equipments[number].maintance_counter -1]));
    }
    
    equipment->equipments[number].maintance_counter--;
}
