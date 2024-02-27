/**
 * @file structs.h
 * @author João Ribeiro
 * @date 30-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2024. All Rights MIT Licensed.
 *
 * @brief Contains structs.
 */

#ifndef STRUCTS_H
#define STRUCTS_H

#include "consts.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


/**
 * @brief User struct caintain details about a determinated user.
 */
typedef struct{
    int number;
    int have_equipment;
    char acronym[ACRONYM_SIZE];
    char name[NAME_SIZE];
    char office[OFFICE_SIZE];
    char status[STATUS_ACT_INACT_SIZE];
}User;

/**
 * @brief User_Count struct contains User struct and user counter.
 */
typedef struct{
    int counter;
    User *users;
}User_Count;

/**
 * @brief Maintance struct contains details about a determinated maintance.
 */
typedef struct Maintenance{
    int number;
    int maintance_day;
    int maintance_month;
    int maintance_year;
    bool maintance;
    char maintance_type[MAINTANCE_TYPE_SIZE];
    char maintance_note[NOTE_SIZE];
}Maintenance;

/**
 * @brief Category struct contains details about a determinated category.
 */
typedef struct{
    int number;
    char category[CATEGORY_SIZE];
    char status[STATUS_ACT_INACT_SIZE];
}Category;

typedef enum listCategories {
    Printer,
    Computer,
    PC,
    Monitor,
    Router,
    Switch,
    TV,
    Projector,
    Access,
    Mouse,
    Accessory,
    Other
}listCategories;


/**
 * @brief Category_Count struct contains Category struct and category counter.
 */
typedef struct{
    int counter;
    Category *categories;
}Category_Count;

/**
 * @brief Equipment struct contains details about a determinated equipment.
 */
typedef struct{
    int maintance_counter;
    int number;
    int purchase_day;
    int purchase_month;
    int purchase_year;
    char designation[DESIGNATION_SIZE];
    char status[STATUS_SIZE];
    listCategories categories;
    User users;
    Maintenance *maintance;
}Equipment;

/**
 * @brief Equipment_Count struct contains Equipment struct, equipment counter, 
 * used by equipment counter and used by user counter.
 */
typedef struct{
    int counter;
    int used_by_equipment;
    int used_by_user;
    Equipment *equipments;
}Equipment_Count;

#endif /* STRUCTS_H */

