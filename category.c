/**
 * @file category.c
 * @author João Ribeiro
 * @date 31-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2024. All Rights MIT Licensed.
 *
 * @brief Contains functions related with categories.
 */

#include "structs.h"
#include "design.h"
#include "functions.h"

void category_menu (Equipment_Count *equipment, Category_Count *category){
    int menu_choice;
    do{
        puts(LINE);
        puts(MENU_CATEGORY_DISPLAY);
        puts(LINE);
        puts(INSERT_CATEGORY_MENU);
        puts(EDIT_CATEGORY);
        puts(REMOVE_CATEGORY);
        puts(EXIT);
        scanf("%d", &menu_choice);
        cleanInputBuffer();
        switch(menu_choice){
            case 1:
                category=insert_category(category);
                break;
            case 2:
                edit_category(category);
                break;
            case 3:
                remove_category(equipment, category); 
                break;
            case 0:
                break;
            default:
                puts(ERROR_OPTION);
                break;
        }
    }while (menu_choice != 0);
}

int get_category_position(Category_Count *category, int number){
    int i;
    for (i = 0; i < category->counter ; i++) {
        if (category->categories[i].number == number) {
            return i;
        }
    }
    return -1;
}

Category_Count *new_list_category (Category_Count *category, int size){
    if (category->counter == 0){
        category->categories = malloc(1 * sizeof(Category));
    }
    
    if(category->counter != 0){        
        category->categories = realloc(category->categories, size * sizeof(Category));
        if(category->categories == NULL){
            puts("No memory.");
            return NULL;
        }       
    }
    return category;
}

Category_Count *insert_category(Category_Count *category){
    
    category = new_list_category(category, category->counter+1);
    
    puts(INSERT_CATEGORY);
    
    int number = getInt(MIN_CATEGORIES, MAX_CATEGORIES, MSG_GET_NUMBER_CATEGORY);
    
    if (get_category_position(category, number) != -1){
        puts(ERROR_CATEGORY_EXISTS);
        return category;
    }
    category->categories[category->counter].number = number;
    
    readString(category->categories[category->counter].category, CATEGORY_SIZE, MSG_GET_CATEGORY_NAME);
    
    strcpy(category->categories[category->counter].status, "Active");
    
    category->counter++;
    
    puts(CATEGORY_ADDED);
    return category;
}

int choose_category(Equipment_Count *equipment) {
    puts("\n");
    puts("0 - Printer");
    puts("1 - Computer");
    puts("2 - PC");
    puts("3 - Monitor");
    puts("4 - Router");
    puts("5 - Switch");
    puts("6 - TV");
    puts("7 - Projector");
    puts("8 - Access Control");
    puts("9 - Mouse");
    puts("10 - Accessory");
    puts("11 - Other");

    int category_choice = getInt(0, 11, MSG_GET_NUMBER_CATEGORY);

    return category_choice;
}

void edit_category(Category_Count *category){
    int edit_menu;
    //list_category(category);
    
    int position = get_category_position(category, getInt(MIN_CATEGORIES, MAX_CATEGORIES, MSG_GET_NUMBER_CATEGORY));
    
    if (position == -1) {
        puts(ERROR_CATEGORY_DO_NOT_EXIST);
        return;
    }
    do{
        puts(DISPLAY_EDIT);
        puts(EDIT_CATEGORY_NAME);
        puts(EDIT_CATEGORY_STATUS);
        puts(EXIT);
        scanf("%d", &edit_menu); 
        cleanInputBuffer();
        char new_status[STATUS_ACT_INACT_SIZE];
        switch (edit_menu){
            case 1:
                readString(category->categories[position].category, CATEGORY_SIZE, MSG_GET_CATEGORY_NAME);
                break;
            case 2:
                printf(MSG_CURRENT_STATUS, category->categories[position].status);
                readString(new_status, STATUS_ACT_INACT_SIZE, NEW_STATUS_CATEGORY_MSG);
                strcpy(category->categories[position].status, new_status);
                break;
            case 0: 
                break;
            default:
                puts(ERROR_OPTION);
                break;
        }
    }while (edit_menu!=0);
}

void remove_category(Equipment_Count *equipment, Category_Count *category){
    int number = get_category_position(category, getInt(MIN_CATEGORIES, MAX_CATEGORIES, MSG_GET_NUMBER_CATEGORY));
    if(number ==-1){
        puts(ERROR_CATEGORY_DO_NOT_EXIST);
        return;
    }
    if (equipment[number].used_by_equipment == 0){
        category->categories[number].number = 0;
        strcpy(category->categories[number].category, "");
        strcpy(category->categories[number].status, "");
        
        for (int i = number; i < category->counter -1; i++){
            category->categories[i] = category->categories[i+1];
        }
        category->counter--;
        puts(CATEGORY_REMOVED);
    } else{
        puts(CATEGORY_CANT_BE_REMOVED);
    }
}

