#ifndef UTIL_HPP
#define UTIL_HPP

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include "../main.hpp"


/*  declarations
/*   *   *   *   *   *   *   *   *   *   */

/**
 * @brief Transfors string to lower case
 * 
 * @param str refrence to transformed string
 */
void toLowerCase( string &str );

/**
 * @brief Transfors string to upper case
 * 
 * @param str refrence to transformed string
 */
void toUpperCase( string &str );

/**
 * @brief Transfors first char of string to upper case and rest to lower case
 * 
 * @param str refrence to transformed string
 */
void toStartCase( string &str );

/**
/**
 * @brief Generates next premutation in char array
 * 
 * @param array refrence to modified array
 * @param index index of modified index
 * @return bool
 */
bool nextPremutation( char *array, uint index );

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif