/**
 * @file functions.h
 * @author João Ribeiro
 * @date 30-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2024. All Rights MIT Licensed.
 *
 * @brief Contains functions.
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * @brief This function cleans buffer.
 */
void cleanInputBuffer();

/**
 * @brief This function prompts the user to input an integer within a specified range and displays a custom message.
 * @param minValue The minimum valid integer value.
 * @param maxValue The maximum valid integer value.
 * @param msg A custom message to prompt the user for input.
 * @return The user-provided integer value within the specified range.
 */
int getInt(int minValue, int maxValue, char *msg);

/**
 * @brief This function reads a string of characters from the user with a specified maximum length and displays a custom message.
 * @param string A character array to store the user-provided string.
 * @param size The maximum number of characters that can be read (including null terminator).
 * @param msg A custom message to prompt the user for input.
 * @return This function does not return a value. It populates the string parameter with the user's input.
 */
void readString(char *string, unsigned int size, char *msg);

/**
 * @brief This function made a Manage Equipment Menu.
 * @param equipment Data of the Equipment_Count struct.
 * @param user Data of the User_Count struct.
 */
void equipment_menu (Equipment_Count *equipment, User_Count *user);

/**
 * @brief This function allows you get the equipment position.
 * @param equipment Data of the Equipment_Count struct.
 * @param number Number of the equipment
 * @return Equipment position
 */
int get_equipment_position(Equipment_Count equipment, int number);

/**
 * @brief This funtion allow you insert a new equipment.
 * @param equipment Data of the Equipment_Count struct.
 * @param user Data of the User_Count struct.
 */
Equipment_Count *insert_equipment(Equipment_Count *equipment, User_Count *user);

/**
 * @brief This function allow you edit the equipment.
 * @param equipment Data of the Equipment_Count struct.
 * @param user Data of the User_Count struct.
 */
void edit_equipments(Equipment_Count *equipment, User_Count *user);

/**
 * @brief This function allow clean data about the equipment.
 * @param equipments Data of the Equipment struct.
 */
void clean_data_equipment(Equipment *equipments);

/**
 * @brief This fuction allow you remove a equipment if don't have maintance history.
 * @param equipment Data of the Equipment_Count struct.
 */
void remove_equipments (Equipment_Count *equipment);

/**
 * @brief This function allow load you last input about the equipments.
 * @param equipment Data from Equipment_Count struct.
 * @param filename Name of the file.
 */
Equipment_Count *load_equipments(Equipment_Count *equipment, char *filename);

/**
 * @brief This function allow save your input about the equipments.
 * @param equipment Data from Equipment_Count struct.
 * @param filename Name of the file.
 */
Equipment_Count *save_equipments(Equipment_Count *equipment, char *filename);

/**
 * @brief This function allow load you last input about the categories.
 * @param category Data from Category_Count struct.
 * @param filename Name of the file.
 */
Category_Count *load_category(Category_Count *category, char *filename);

/**
 * @brief This function allow save your input about the categories.
 * @param category Data from Category_Count struct.
 * @param filename Name of the file.
 */
Category_Count *save_category(Category_Count *category, char *filename);

/**
 * @brief This function allow load you last input about the users.
 * @param user Data from User_Count struct.
 * @param filename Name of the file.
 */
User_Count *load_user(User_Count *user, char *filename);

/**
 * @brief This function allow save your input about the users.
 * @param user Data from User_Count struct.
 * @param filename Name of the file.
 */
User_Count *save_user(User_Count *user, char *filename);

/**
 * @brief This function allow free your memory abot the equipments.
 * @param equipment Data from Equipment_Count struct.
 */
void free_equipment(Equipment_Count *equipment);

/**
 * @brief This function allow free your memory abot the categories.
 * @param category Data from Category_Count struct.
 */
void free_category(Category_Count *category);

/**
 * @brief This function allow free your memory abot the users.
 * @param user Data from User_Count struct.
 */
void free_user(User_Count *user);

Maintenance *alloc_in_array (int size);

/**
 * @brief This function made a Manage Category Menu.
 * @param equipment Data of the Equipment_Count struct.
 * @param category Data of the Category_Count struct.
 */
void category_menu (Equipment_Count *equipment, Category_Count *category);

/**
 * @brief This function allows you get the category position.
 * @param category Data of the Category_Count struct.
 * @param number Number of the equipment
 * @return Category position
 */
int get_category_position(Category_Count *category, int number);

/**
 * @brief This funtion allow you insert a new category.
 * @param category Data of the Category_Count struct.
 */
Category_Count *insert_category(Category_Count *category);

/**
 * @brief This function allow you choose what category you want.
 * @param category Data of the Category_Count struct.
 * @return Category choiced.
 */
int choose_category(Equipment_Count *equipment);

/**
 * @brief This function allow you edit the category.
 * @param category Data of the Category_Count struct.
 */
void edit_category(Category_Count *category);

/**
 * @brief This fuction allow you remove a category if don't have any equipment associated.
 * @param equipment Data of the Equipment_Count struct.
 * @param category Data of the Category_Count struct.
 */
void remove_category(Equipment_Count *equipment, Category_Count *category);

/**
 * @brief This function made a Manage User Menu.
 * @param equipment Data of the Equipment_Count struct.
 * @param user Data of the User_Count struct.
 */
void user_menu (Equipment_Count *equipment,User_Count *user);

/**
 * @brief This function allows you get the user position.
 * @param user Data of the User_Count struct.
 * @param number Number of the equipment
 * @return User position
 */
int get_user_position (User_Count *user, int number);

/**
 * @brief This funtion allow you insert a new user.
 * @param user Data of the User_Count struct.
 */
User_Count *insert_user(User_Count *user);

/**
 * @brief This function allow you choose what user you want.
 * @param user Data of the User_Count struct.
 * @return User choiced.
 */
int choose_user(User_Count *user);

/**
 * @brief This function allow you edit the user.
 * @param user Data of the User_Count struct.
 */
void edit_user (User_Count *user);

/**
 * @brief This fuction allow you remove a user if don't have any equipment associated.
 * @param equipment Data of the Equipment_Count struct.
 * @param user Data of the User_Count struct.
 */
void remove_user(Equipment_Count *equipment,User_Count *user);

/**
 * This function made a Search Menu.
 * @param equipment Data of the Equipment_Count struct.
 */
void search_menu (Equipment_Count *equipment);

/**
 * @brief This function allow you get equipment position by name.
 * @param equipment Data of the Equipment_count struct.
 * @param get_name Name of the equipment.
 * @return Position of the equipment.
 */
int get_name_position(Equipment_Count *equipment, const char *get_name);

/**
 * @brief This function allow search the equipment by name.
 * @param equipment Data of the Equipment_Count struct.
 */
void search_name (Equipment_Count *equipment);

/**
 * @brief This function allow search the equipment by number.
 * @param equipment Data of the Equipment_Count struct.
 */
void search_identifier (Equipment_Count *equipment);

/**
 * This function made a Maintance Menu.
 * @param equipment Data of the Equipment_Count struct.
 */
void maintance_menu (Equipment_Count *equipment);

/**
 * @brief This funtion allow you insert a new maintance.
 * @param equipment Data from of Maintance struct inserted in Equipment_Count struct.
 */
Equipment_Count *insert_maintance(Equipment_Count *equipment);

/**
 * @brief This function allow clean data about the maintance.
 * @param equipments Data from of Maintance struct inserted in Equipment_Count struct.
 */
void clean_maintance (Maintenance *maintance);

/**
 * @brief This function confirm if the equipment has maintance_history.
 * @param equipments Data from of Maintance struct inserted in Equipment struct.
 * @return This function returns a True value if the equipment has maintance_history.
 */
bool equipment_has_maintance(Equipment *equipments);

/**
 * @brief This function allow's delete maintance.
 * @param companies Data from of Maintance struct inserted in Equipment_Count struct.
 * @param maintance_id Id from maintance to delete.
 */
Equipment_Count *delete_maintance (Equipment_Count *equipment, int maintance_id);

/**
 * This function made a List Menu.
 * @param equipment Data of the Equipment_Count struct.
 * @param user Data of the User_Count struct.
 */
void list_menu (Equipment_Count *equipment, User_Count *user);

/**
 * @brief This function allows print the equipment details.
 * @param equipments Data of the Equipment struct.
 */
void print_equipment(Equipment equipments);

/**
 * @brief This function allows list all equipments.
 * @param equipment Data of the Equipment_Count struct.
 */
void list_equipments(Equipment_Count *equipment);

/**
 * @brief This function allows list all free equipments.
 * @param equipment Data of the Equipment_Count struct.
 */
void list_equipments_free (Equipment_Count *equipment);

/**
 * @brief This function allows list all to recycle equipments.
 * @param equipment Data of the Equipment_Count struct.
 */
void list_equipments_to_recycle(Equipment_Count equipment);

/**
 * @brief This function allows list all categories.
 * @param category Data of the Category_Count struct.
 */
//void list_category(Category_Count *category);

/**
 * @brief This function allows print the user details.
 * @param users Data of the User struct.
 */
void print_user (User users);

/**
 * @brief This function allows list all users.
 * @param user Data of the User_Count struct.
 */
void list_user (User_Count *user);

/**
 * @brief This function allows list maintance history about a determinated equipment.
 * @param equipment Data of the Equipment_Count struct.
 */
Equipment_Count *list_maintance_equipment(Equipment_Count *equipment);


const char* printCategory(listCategories category);


void list_category_sorted(Equipment_Count equipment);

void swapEquipments(Equipment *equipment1, Equipment *equipment2);


#endif /* FUNCTIONS_H */

