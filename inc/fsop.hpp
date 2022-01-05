#ifndef FSOP_HPP
#define FSOP_HPP

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include "../main.hpp"


/*  declarations
/*   *   *   *   *   *   *   *   *   *   */

/**
 * @brief Reads data from file and allocates it
 * 
 * @param filename system file name
 * @param set refrence to destination set
 * @return bool
 */
bool readFromFile( const string filename, set_t &set );

/**
 * @brief Inits the solutions vector
 * 
 * @param vect refrence to initialized solution vector
 * @param set refrence to base set hash
 */
void initSolutionVect( solution_vect &vect, set_t &set_hash );


/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif