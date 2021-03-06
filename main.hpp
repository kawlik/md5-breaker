#ifndef MAIN_HPP
#define MAIN_HPP

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */


//  regular libs
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>

//  signals
#include <signal.h>

//  hash utilities
#include <openssl/md5.h>
#include <crypt.h>

//  std namespace
using namespace std;


/*  macros
/*   *   *   *   *   *   *   *   *   *   */

#define MAX_NUM_CHECK   100
#define CHARARR_LEN     3
#define ASCI_MIN        0x21
#define ASCI_MAX        0x7E


/*  aliases
/*   *   *   *   *   *   *   *   *   *   */

/**
 * @brief Describes dynamic string array and it size
 * 
 */
typedef struct {
    string *array;
    size_t size;
} set_t;

/**
 * @brief Describes array of hashes, resolving words and resolved state
 * 
 */
typedef struct {
    bool *hasResult;
    string *hash;
    string *word;
    size_t size;
    size_t left;
} solution_vect;


/*  uitilities
/*   *   *   *   *   *   *   *   *   *   */

inline void printSolutionVect( solution_vect &solutions ) {

    for( size_t i = 0; i < solutions.size; i++ ) {

        if( !solutions.hasResult[i] ) continue;

        cout << "> hash: [ " << solutions.hash[i] << " ] | > word: [ " << solutions.word[i] << " ]" << endl;
    }
}


/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif