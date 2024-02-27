/**
 * @file consts.h
 * @author João Ribeiro
 * @date 30-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2024. All Rights MIT Licensed.
 *
 * @brief Contains consts.
 */

#ifndef CONSTS_H
#define CONSTS_H

/**
 * @brief A integrer constant representing a equipment designation size.
 *
 * This constant is used to define a equipment designation size limit.
 */
#define DESIGNATION_SIZE 40

/**
 * @brief A integrer constant representing a equipment status size.
 *
 * This constant is used to define a equipment status size limit.
 * The following states are proposed: Operational, Under Maintenance, 
 * Non-Operational and For Recycling.
 */
#define STATUS_SIZE 16        

/**
 * @brief A integrer constant representing a user and category status size.
 *
 * This constant is used to define a user and category status size limit.
 * The following states are proposed: Active and Inactive.
 */
#define STATUS_ACT_INACT_SIZE 8

/**
 * @brief A integrer constant representing a category designation size.
 *
 * This constant is used to define a category designation size limit.
 */
#define CATEGORY_SIZE 30

/**
 * @brief A integrer constant representing a maintance type size.
 *
 * This constant is used to define a maintance type size limit.
 */
#define MAINTANCE_TYPE_SIZE 100

/**
 * @brief A integrer constant representing a maintance note size.
 *
 * This constant is used to define a maintance note size limit.
 */
#define NOTE_SIZE 300

/**
 * @brief A integrer constant representing a user acronym size.
 *
 * This constant is used to define a user acronym size limit.
 */
#define ACRONYM_SIZE 5

/**
 * @brief A integrer constant representing a user name size.
 *
 * This constant is used to define a user name size limit.
 */
#define NAME_SIZE 50

/**
 * @brief A integrer constant representing a user office size.
 *
 * This constant is used to define a user office size limit.
 */
#define OFFICE_SIZE 30




/**
 * @brief A integrer constant representing the maximum equipments allowed.
 *
 * This constant is used to define the maximum equipments allowed.
 */
#define MAX_EQUIPMENTS 100

/**
 * @brief A integrer constant representing the maximum categories allowed.
 *
 * This constant is used to define the maximum categories allowed.
 */
#define MAX_CATEGORIES 40

/**
 * @brief A integrer constant representing the minimum categories number allowed.
 *
 * This constant is used to define the minimum categories number allowed.
 */
#define MIN_CATEGORIES 1

/**
 * @brief A integrer constant representing the minimum equipments number allowed.
 *
 * This constant is used to define the minimum equipments number allowed.
 */
#define MIN_NUMBER_EQUIPMENT 1

/**
 * @brief A integrer constant representing the maximum equipments number allowed.
 *
 * This constant is used to define the maximum equipments number allowed.
 */
#define MAX_NUMBER_EQUIPMENT 100

/**
 * @brief A integrer constant representing the minimum days of all months allowed.
 *
 * This constant is used to define the minimum days of all months allowed.
 */
#define MIN_DATE_DAY 1

/**
 * @brief A integrer constant representing the maximum days of all months allowed.
 *
 * This constant is used to define the maximum days of all months allowed.
 */
#define MAX_DATE_DAY 31

/**
 * @brief A integrer constant representing the minimum number of month allowed.
 *
 * This constant is used to define the minimum number of month allowed.
 */
#define MIN_DATE_MONTH 1

/**
 * @brief A integrer constant representing the maximum number of month allowed.
 *
 * This constant is used to define the maximum number of month allowed.
 */
#define MAX_DATE_MONTH 12

/**
 * @brief A integrer constant representing the minimum number of year allowed.
 *
 * This constant is used to define the minimum number of year allowed.
 */
#define MIN_DATE_YEAR 2023

/**
 * @brief A integrer constant representing the maximum number of year allowed.
 *
 * This constant is used to define the maximum number of year allowed.
 */
#define MAX_DATE_YEAR 2100

/**
 * @brief A integrer constant representing the minimum user number/code allowed.
 *
 * This constant is used to define the minimum user number/code allowed.
 */
#define MIN_USER 0

/**
 * @brief A integrer constant representing the maximum user number/code allowed.
 *
 * This constant is used to define the maximum user number/code allowed.
 */
#define MAX_USER 9999

/**
 * @brief A integrer constant representing the minimum maintance number allowed.
 *
 * This constant is used to define the minimum maintance number allowed.
 */
#define MIN_NUMBER_MAINTANCE 1

/**
 * @brief A integrer constant representing the maximum maintance number allowed.
 *
 * This constant is used to define the maximum maintance number allowed.
 */
#define MAX_NUMBER_MAINTANCE 30

#endif /* CONSTS_H */

