/**
 * @file save_load.c
 * @author João Ribeiro
 * @date 30-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2023. All Rights MIT Licensed.
 *
 * @brief Contains functions for program files(save, load).
 */

#include "structs.h"
#include "functions.h"

Equipment_Count *load_equipments(Equipment_Count *equipment, char *filename){
    int i, success = 0;
    FILE *fp = fopen(filename, "rb");
    
    fread(&equipment->counter, sizeof (int), 1, fp);
    
    if(equipment->counter > 0){
        equipment->equipments = (Equipment*) calloc(equipment->counter, sizeof (Equipment));
        for (i=0; i < equipment->counter; i++){
            fread(&equipment->equipments[i], sizeof(Equipment), 1, fp);
            if(equipment->equipments[i].maintance_counter>0){
                equipment->equipments[i].maintance = (Maintenance*) alloc_in_array(equipment->equipments[i].maintance_counter);
                fread(equipment->equipments[i].maintance, sizeof(Maintenance),equipment->equipments[i].maintance_counter,fp);
            }
            
        }
        success = 1;
    }
    fclose(fp);
    
    if(!success){
        fp = fopen(filename, "wb");
        if(fp != NULL){
            equipment->equipments = (Equipment*) calloc(equipment->counter, sizeof(Equipment));
            equipment->counter = 0;
            fclose(fp);
        }
    }
    return equipment;
}

Equipment_Count *save_equipments(Equipment_Count *equipment, char *filename){
    int i;
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }
    fwrite(&equipment->counter, sizeof (int), 1, fp);
    for (i=0; i < equipment->counter; i++){
        fwrite(&equipment->equipments[i], sizeof (Equipment), 1, fp);
        if(equipment->equipments[i].maintance_counter > 0 && equipment->equipments[i].maintance!=NULL){
                fwrite(equipment->equipments[i].maintance, sizeof(Maintenance),equipment->equipments[i].maintance_counter,fp);
        }
    }
    fclose(fp);
    return equipment;
}

User_Count *load_user(User_Count *user, char *filename){
    int i, success=0;
    FILE *fp = fopen(filename, "rb");
    fread(&user->counter, sizeof(int),1,fp);
    
    if(user->counter > 0){
        user->users = (User*) calloc(user->counter, sizeof(User));
        for(i=0; i<user->counter;i++){
            fread(&user->users[i],sizeof(User), 1,fp); 
        }
        success=1;
    }
    fclose(fp);
    
    if(!success){
        fp = fopen(filename, "wb");
        if(fp!=NULL){
            user->users = (User*) calloc(user->counter, sizeof(User));
            user->counter = 0;
            fclose(fp);
        }
    }
    return user;
}

User_Count *save_user(User_Count *user, char *filename){
    int i;
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fwrite(&user->counter, sizeof (int), 1, fp);
    for(i=0; i<user->counter; i++){
        fwrite(&user->users[i], sizeof(User), 1, fp);
    }
    fclose(fp);
    return user;
}

void free_equipment(Equipment_Count *equipment) {
    if(equipment->counter != 0){
        free(equipment);
    }
    return;
}

void free_category(Category_Count *category) {
    if(category->counter != 0){
        free(category);
    }
    return;
}

void free_user(User_Count *user) {
    if(user->counter != 0){
        free(user);
    }
    return;
}

Maintenance *alloc_in_array (int size){
    return (Maintenance*) calloc(size, sizeof(Maintenance));
}