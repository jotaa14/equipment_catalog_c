/**
 * @file design.h
 * @author João Ribeiro
 * @date 30-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2024. All Rights MIT Licensed.
 *
 * @brief Contains consts about design.
 */

#ifndef DESIGN_H
#define DESIGN_H

/**
 * @brief A string constant representing the file name related with equipments.
 *
 * This constant is used to define the file name related with equipments.
 */
#define FILE_NAME_EQUIPMENTS "equipments.bin"

/**
 * @brief A string constant representing the file name related with categories.
 *
 * This constant is used to define the file name related with categories.
 */
#define FILE_NAME_CATEGORIES "categories.bin"

/**
 * @brief A string constant representing the file name related with users.
 *
 * This constant is used to define the file name related with users.
 */
#define FILE_NAME_USERS "users.bin"




/**
 * @brief A string constant representing one aesthetic line.
 */
#define LINE "-----------------------------------"

/**
 * @brief A string constant representing Menu display.
 */
#define MENU "---------------MENU----------------"

/**
 * @brief A string constant representing first option "equipment menu" about main menu.
 */
#define EQUIPMENT_MENU "(1) EQUIPMENT MENU"

/**
 * @brief A string constant representing second option "category menu" about main menu.
 */
#define CATEGORY_MENU "(2) CATEGORY MENU"

/**
 * @brief A string constant representing third option "user menu" about main menu.
 */
#define USER_MENU "(2) USER MENU"

/**
 * @brief A string constant representing fourth option "list menu" about main menu.
 */
#define LIST_MENU "(3) LIST MENU"

/**
 * @brief A string constant representing fifth option "search menu" about main menu.
 */
#define SEARCH_MENU "(4) SEARCH MENU"

/**
 * @brief A string constant representing sixth option "maintance menu" about main menu.
 */
#define MAINTANCE_MENU "(5) MAINTANCE MENU"

/**
 * @brief A string constant representing seventh option "save" about main menu.
 */
#define SAVE "(6) SAVE"

/**
 * @brief A string constant representing eighth option "load" about main menu.
 */
#define LOAD "(7) LOAD"

/**
 * @brief A string constant representing zero option "exit" some menus.
 */
#define EXIT "\n(0) EXIT"

/**
 * @brief A string constant representing equipment display.
 */
#define EQUIPMENT_DISPLAY "---------EQUIPMENT DISPLAY---------"

/**
 * @brief A string constant representing category display.
 */
#define CATEGORY_DISPLAY "---------CATEGORY DISPLAY----------"

/**
 * @brief A string constant representing edit menu display.
 */
#define DISPLAY_EDIT "------------EDIT MENU--------------"

/**
 * @brief A string constant representing user display.
 */
#define USER_DISPLAY "-----------USER DISPLAY------------"

/**
 * @brief A string constant representing maintance display.
 */
#define MAINTANCE_DISPLAY   "--------MAINTANCE DISPLAY----------"

/**
 * @brief A string constant representing insert user display.
 */
#define INSERT_USER "------------INSERT USER------------"

/**
 * @brief A string constant representing insert category display.
 */
#define INSERT_CATEGORY "----------INSERT CATEGORY----------"

/**
 * @brief A string constant representing insert equipment display.
 */
#define INSERT_EQUIPMENT "---------INSERT EQUIPMENT----------"

/**
 * @brief A string constant representing first option "Edit Equipment Designation" about edit equipment menu.
 */
#define EDIT_DESIGNATION "(1) Edit Equipment Designation"

/**
 * @brief A string constant representing second option "Edit Equipment Purchase Day" about edit equipment menu.
 */
#define EDIT_PURCHASE_DAY "(2) Edit Equipment Purchase Day"

/**
 * @brief A string constant representing third option "Edit Equipment Purchase Month" about edit equipment menu.
 */
#define EDIT_PURCHASE_MONTH "(3) Edit Equipment Purchase Month"

/**
 * @brief A string constant representing fourth option "Edit Equipment Purchase Year" about edit equipment menu.
 */
#define EDIT_PURCHASE_YEAR "(4) Edit Equipment Purchase Year"

/**
 * @brief A string constant representing fifth option "Edit Equipment User Code" about edit equipment menu.
 */
#define EDIT_USER_CODE "(5) Edit Equipment User Code"

/**
 * @brief A string constant representing sixth option "Edit Equipment Status" about edit equipment menu.
 */
#define EDIT_STATUS "(6) Edit Equipment Status"

/**
 * @brief A string constant representing seventh option "Edit Equipment Category" about edit equipment menu.
 */
#define EDIT_EQUIPMENT_CATEGORY "(7) Edit Equipment Category"




/**
 * @brief A string constant representing first option "Edit Category Name" about edit category menu.
 */
#define EDIT_CATEGORY_NAME "(1) Edit Category Name"

/**
 * @brief A string constant representing second option "Edit Category Status" about edit category menu.
 */
#define EDIT_CATEGORY_STATUS "(2) Edit Category Status"




/**
 * @brief A string constant representing first option "Edit User Acronym" about edit user menu.
 */
#define EDIT_ACRONYM "(1) Edit User Acronym"

/**
 * @brief A string constant representing second option "Edit User Name" about edit user menu.
 */
#define EDIT_NAME "(2) Edit User Name"

/**
 * @brief A string constant representing third option "Edit User Office" about edit user menu.
 */
#define EDIT_OFFICE "(3) Edit User Office"

/**
 * @brief A string constant representing fouth option "Edit User Status" about edit user menu.
 */
#define EDIT_STATUS_USER "(4) Edit User Status"




/**
 * @brief A string constant representing equipment menu display.
 */
#define EQUIPMENT_MENU_DISPLAY "---------EQUIPMENT MENU------------"

/**
 * @brief A string constant representing first option "insert equipment" about equipment menu.
 */
#define INSERT_EQUIPMENT_MENU "(1) INSERT EQUIPMENT"

/**
 * @brief A string constant representing second option "edit equipment" about equipment menu.
 */
#define EDIT_EQUIPMENT "(2) EDIT EQUIPMENT"

/**
 * @brief A string constant representing third option "remove equipment" about equipment menu.
 */
#define REMOVE_EQUIPMENT "(3) REMOVE EQUIPMENT"





/**
 * @brief A string constant representing category menu display.
 */
#define MENU_CATEGORY_DISPLAY "----------CATEGORY MENU------------"

/**
 * @brief A string constant representing first option "insert category" about category menu.
 */
#define INSERT_CATEGORY_MENU "(1) INSERT CATEGORY"

/**
 * @brief A string constant representing second option "edit category" about category menu.
 */
#define EDIT_CATEGORY "(2) EDIT CATEGORY"

/**
 * @brief A string constant representing third option "remove category" about category menu.
 */
#define REMOVE_CATEGORY "(3) REMOVE CATEGORY"






/**
 * @brief A string constant representing user menu display.
 */
#define USER_OPTIONS "-----------USER OPTIONS------------"

/**
 * @brief A string constant representing first option "insert user" about user menu.
 */
#define INSERT_USER_MENU "(1) INSERT USER"

/**
 * @brief A string constant representing second option "edit user" about user menu.
 */
#define EDIT_USER "(2) EDIT USER"

/**
 * @brief A string constant representing third option "remove user" about user menu.
 */
#define REMOVE_USER "(3) REMOVE USER"






/**
 * @brief A string constant representing list menu display.
 */
#define LIST_MENU_DISPLAY "-----------LIST OPTIONS------------"

/**
 * @brief A string constant representing first option "list all equipments" about list menu.
 */
#define LIST_ALL_EQUIPMENTS "(1) LIST ALL EQUIPMENTS"

/**
 * @brief A string constant representing second option "list free equipments" about list menu.
 */
#define LIST_FREE_EQUIPMENTS "(2) LIST FREE EQUIPMENTS"

/**
 * @brief A string constant representing third option "list to recycle equipments" about list menu.
 */
#define LIST_TO_RECYCLE_EQUIPMENTS "(3) LIST TO RECYCLE EQUIPMENTS"

/**
 * @brief A string constant representing fifth option "list users" about list menu.
 */
#define LIST_USER "(4) LIST USERS"





/**
 * @brief A string constant representing search equipments menu display.
 */
#define MENU_SEARCH_DISPLAY "----------SEARCH OPTIONS-----------"

/**
 * @brief A string constant representing first option "search equipment by identifier" about search menu.
 */
#define SEARCH_IDENTIFIER "(1) SEARCH EQUIPMENT BY IDENTIFIER"

/**
 * @brief A string constant representing second option "search equipment by name" about search menu.
 */
#define SEARCH_NAME "(2) SEARCH EQUIPMENT BY NAME"





/**
 * @brief A string constant representing maintance menu display.
 */
#define MENU_MAINTANCE_DISPLAY "----------MAINTANCE MENU-----------"

/**
 * @brief A string constant representing first option "maintance equipment" about maintance menu.
 */
#define EQUIPMENT_MAINTANCE "(1) MAINTANCE EQUIPMENT"

/**
 * @brief A string constant representing second option "maintance history" about maintance menu.
 */
#define MAINTANCE_HISTORY "(2) MAINTANCE HISTORY"




/**
 * @brief A string constant representing success message when user add equipment.
 */
#define EQUIPMENT_ADDED "Equipment Added With Success!"

/**
 * @brief A string constant representing success message when user edit equipment.
 */
#define EQUIPMENT_EDITED "Equipment Edited With Success!"

/**
 * @brief A string constant representing success message when user add category.
 */
#define CATEGORY_ADDED "Category Added With Success!"

/**
 * @brief A string constant representing success message when user remove category.
 */
#define CATEGORY_REMOVED "Category Removed With Success!"

/**
 * @brief A string constant representing success message when user remove equipment.
 */
#define EQUIPMENT_REMOVED "Equipment Removed With Success!"

/**
 * @brief A string constant representing success message when user add user.
 */
#define USER_ADDED "User Added With Success!"

/**
 * @brief A string constant representing success message when user remove user.
 */
#define USER_REMOVED "User Removed With Success!"

/**
 * @brief A string constant representing success message when user edit user.
 */
#define USER_EDITED "User Edited With Success!"

/**
 * @brief A string constant representing success message when user save data.
 */
#define SAVED "Program Was Saved With Success!"

/**
 * @brief A string constant representing success message when user load data.
 */
#define LOADED "Program Was Loaded With Success!"




/**
 * @brief A string constant representing error message when user entire a invalid value.
 */
#define ERROR_INVALID_VALUE "ERROR: the value entered is invalid."

/**
 * @brief A string constant representing error message when user try associate a number 
 * already assigned for a equipment to a new equipment.
 */
#define ERROR_EQUIPMENT_EXIST "ERROR: the equipment number is already assigned."

/**
 * @brief A string constant representing error message when list is empty.
 */
#define ERROR_EMPTY_LIST "ERROR: list is empty."

/**
 * @brief A string constant representing error message when user entire a invalid option.
 */
#define ERROR_OPTION "ERROR: insert a valid option."

/**
 * @brief A string constant representing error message when user can't remove equipment.
 */
#define ERROR_EQUIPMENT_CANT_BE_REMOVED "ERROR: equipment can't be removed."

/**
 * @brief A string constant representing error message when user choose a equipment do not exist.
 */
#define ERROR_EQUIPMENT_DO_NOT_EXIST "ERROR: equipment do not exist."

/**
 * @brief A string constant representing error message when user choose a category do not exist.
 */
#define ERROR_CATEGORY_DO_NOT_EXIST "ERROR: category do not exist."

/**
 * @brief A string constant representing error message when user choose a user do not exist.
 */
#define ERROR_USER_DO_NOT_EXIST "ERROR: user do not exist."

/**
 * @brief A string constant representing error message when user try associate a number 
 * already assigned for a category to a new category.
 */
#define ERROR_CATEGORY_EXISTS "ERROR: the category number is already assigned."

/**
 * @brief A string constant representing error message when failed to allocate memory.
 */
#define ERROR_ALLOCATE_MEMORY "ERROR: failed to allocate memory."

/**
 * @brief A string constant representing error message when user can't remove category.
 */
#define CATEGORY_CANT_BE_REMOVED "ERROR: the category can't be removed."

/**
 * @brief A string constant representing error message when user try associate a number 
 * already assigned for a user to a new user.
 */
#define ERROR_USER_EXISTS "ERROR: the user code is already assigned."

/**
 * @brief A string constant representing error message when user can't remove user.
 */
#define USER_CANT_BE_REMOVED "ERROR: the user can't be removed."

/**
 * @brief A string constant representing error message when equipment is designated for recycling.
 */
#define ERROR_EQUIPMENT_FOR_RECYCLING "ERROR: this equipment is designated for recycling."




/**
 * @brief A string constant representing a message to get number of equipment.
 */
#define MSG_GET_NUMBER_EQUIPMENT "Introduce Equipment Number: "

/**
 * @brief A string constant representing a message to get equipment designation.
 */
#define MSG_GET_EQUIPMENT_DESIGNATION "Introduce Equipment Designation: "

/**
 * @brief A string constant representing a message to get equipment purchase day.
 */
#define MSG_GET_PURCHASE_DATE_DAY "Introduce Equipment Purchase Day: "

/**
 * @brief A string constant representing a message to get equipment purchase month.
 */
#define MSG_GET_PURCHASE_DATE_MONTH "Introduce Equipment Purchase Month: "

/**
 * @brief A string constant representing a message to get equipment purchase year.
 */
#define MSG_GET_PURCHASE_DATE_YEAR "Introduce Equipment Purchase Year: "

/**
 * @brief A string constant representing a message to get equipment maintance day.
 */
#define MSG_GET_MAINTANCE_DATE_DAY "Introduce Equipment Maintance Day: "

/**
 * @brief A string constant representing a message to get equipment maintance month.
 */
#define MSG_GET_MAINTANCE_DATE_MONTH "Introduce Equipment Maintance Month: "

/**
 * @brief A string constant representing a message to get equipment maintance year.
 */
#define MSG_GET_MAINTANCE_DATE_YEAR "Introduce Equipment Maintance Year: "

/**
 * @brief A string constant representing a message to get user number.
 */
#define MSG_GET_USER_CODE "Introduce the User Code: "

/**
 * @brief A string constant representing a message to show status.
 */
#define MSG_CURRENT_STATUS "Current Status: %s\n"

/**
 * @brief A string constant representing a message to get new equipment status.
 */
#define NEW_STATUS_MSG "Enter the status of the equipment (Operational / Under Maintenance / Non-Operational / For Recycling): "

/**
 * @brief A string constant representing a message to get new category status.
 */
#define NEW_STATUS_CATEGORY_MSG "Enter the status of the category (Active / Inactive): "

/**
 * @brief A string constant representing a message to get new user status.
 */
#define NEW_STATUS_USER_MSG "Enter the status of the user (Active / Inactive): "

/**
 * @brief A string constant representing a message to get category number.
 */
#define MSG_GET_NUMBER_CATEGORY "Introduce Category Number: "

/**
 * @brief A string constant representing a message to get category name.
 */
#define MSG_GET_CATEGORY_NAME "Introduce Category Name: "

/**
 * @brief A string constant representing a message to get user number.
 */
#define MSG_GET_NUMBER_USER "Introduce User Code: "

/**
 * @brief A string constant representing a message to get user acronym.
 */
#define MSG_GET_USER_ACRONYM "Introduce User Acronym: "

/**
 * @brief A string constant representing a message to get user name.
 */
#define MSG_GET_USER_NAME "Introduce User Name: "

/**
 * @brief A string constant representing a message to get user office.
 */
#define MSG_GET_USER_OFFICE "Introduce User Office: "

/**
 * @brief A string constant representing a message to get maintance type.
 */
#define MSG_GET_MAINTANCE_TYPE "Introduce Maintance Type: "

/**
 * @brief A string constant representing a message to get maintance note.
 */
#define MSG_GET_MAINTANCE_NOTE "Introduce Maintance Note: "

/**
 * @brief A string constant representing a message to get maintance number.
 */
#define MSG_GET_NUMBER_MAINTANCE "Introduce Maintance Number: "


#endif /* DESIGN_H */