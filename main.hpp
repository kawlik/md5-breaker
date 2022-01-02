#ifndef MAIN_HPP
#define MAIN_HPP

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */


//  regular libs
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstring>
#include <vector>
#include <thread>
#include <mutex>

//  hash utilities
#include <openssl/md5.h>
#include <crypt.h>

//  std namespace
using namespace std;


/*  macros
/*   *   *   *   *   *   *   *   *   *   */

#define MAX_NUM_CHECK 10000


/*  aliases
/*   *   *   *   *   *   *   *   *   *   */

/**
 * @brief Utility aliases
 * 
 */
typedef string md5_hash;
typedef string solution;

/**
 * @brief Pair of md5 hash and resolving word
 * 
 */
typedef pair<md5_hash, solution> association;

/**
 * @brief Vector of hash & solution pairs
 * 
 */
typedef vector<association> association_vect;

/**
 * @brief Describes dynamic string array and it size
 * 
 */
typedef struct {
    string *array;
    size_t size;
} set_t;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif