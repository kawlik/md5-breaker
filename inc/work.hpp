#ifndef THRD_HPP
#define THRD_HPP

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include "../main.hpp"

#include "hash.hpp"     //  hash operations
#include "util.hpp"     //  utility operations


/*  declarations
/*   *   *   *   *   *   *   *   *   *   */

/**
 * @brief General producer function of type 0 1 2
 * 
 * @param mtx refrence to mutex
 * @param solutions refrence to solutions vector
 * @param set_hash refrence to set of hashes
 * @param set_word refrence to set of words
 * @param callback pointer to callback function
 */
void producer( mutex &mtx, solution_vect &solutions, set_t &set_hash, set_t &set_word, void ( *callback )( string &str ), bool reverseNotation );


/**
 * @brief General producer function of type 3 ( character increment )
 * 
 * @param mtx refrence to mutex
 * @param solutions refrence to solutions vector
 * @param set_hash refrence to set of hashes
 * @param set_word refrence to set of words
 * @param callback pointer to callback function
 */
void producer_chararr( mutex &mtx, solution_vect &solutions, set_t &set_hash, set_t &set_word, void ( *callback )( string &str ), bool reverseNotation );


/*  utility aliases
/*   *   *   *   *   *   *   *   *   *   */

/**
 * @brief Producer function of type 0 1 2 with regular notation
 * 
 * @param mtx refrence to mutex
 * @param solutions refrence to solutions vector
 * @param set_hash refrence to set of hashes
 * @param set_word refrence to set of words
 * @param callback pointer to callback function
 */
inline void producer_a( mutex &mtx, solution_vect &solutions, set_t &set_hash, set_t &set_word, void ( *callback )( string &str ) ) {
    producer( mtx, solutions, set_hash, set_word, callback, false );
}


/**
 * @brief Producer function of type 0 1 2 with reverse notation
 * 
 * @param mtx refrence to mutex
 * @param solutions refrence to solutions vector
 * @param set_hash refrence to set of hashes
 * @param set_word refrence to set of words
 * @param callback pointer to callback function
 */
inline void producer_b( mutex &mtx, solution_vect &solutions, set_t &set_hash, set_t &set_word, void ( *callback )( string &str ) ) {
    producer( mtx, solutions, set_hash, set_word, callback, true );
}


/**
 * @brief Producer type 0 - all letters in lower case
 * 
 * @param mtx 
 * @param solutions refrence to solutions vector
 * @param set_hash refrence to set of hashes
 * @param set_word refrence to set of words
 */
inline void producer_0a( mutex &mtx, solution_vect &solutions, set_t &set_hash, set_t &set_word ) {
    producer_a( mtx, solutions, set_hash, set_word, toLowerCase );
}

inline void producer_0b( mutex &mtx, solution_vect &solutions, set_t &set_hash, set_t &set_word ) {
    producer_b( mtx, solutions, set_hash, set_word, toLowerCase );
}

/**
 * @brief Producer type 1 - all letters in upper case
 * 
 * @param mtx 
 * @param solutions refrence to solutions vector
 * @param set_hash refrence to set of hashes
 * @param set_word refrence to set of words
 */
inline void producer_1a( mutex &mtx, solution_vect &solutions, set_t &set_hash, set_t &set_word ) {
    producer_a( mtx, solutions, set_hash, set_word, toUpperCase );
}

inline void producer_1b( mutex &mtx, solution_vect &solutions, set_t &set_hash, set_t &set_word ) {
    producer_b( mtx, solutions, set_hash, set_word, toUpperCase );
}

/**
 * @brief Producer type 2 - first letter in upper case, rest letters in lowwer case
 * 
 * @param mtx 
 * @param solutions refrence to solutions vector
 * @param set_hash refrence to set of hashes
 * @param set_word refrence to set of words
 */
inline void producer_2a( mutex &mtx, solution_vect &solutions, set_t &set_hash, set_t &set_word ) {
    producer_a( mtx, solutions, set_hash, set_word, toStartCase );
}

inline void producer_2b( mutex &mtx, solution_vect &solutions, set_t &set_hash, set_t &set_word ) {
    producer_b( mtx, solutions, set_hash, set_word, toStartCase );
}


/*  declarations of utility functions
/*   *   *   *   *   *   *   *   *   *   */

/**
 * @brief Procedures work inside a thread
 * 
 * @param str_before string before tested word
 * @param str_after string after tested word
 * @param mtx thread refrence to mutex
 * @param solutions thread refrence to solutions vector
 * @param set_hash thread refrence to set of hashes
 * @param set_word thread refrence to set of words
 * @param callback thread pointer to callback function
 */
void doWork( string &str_before, string &str_after, mutex &mtx, solution_vect &solutions, set_t &set_hash, set_t &set_word, void ( *callback )( string &str ) );


/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif