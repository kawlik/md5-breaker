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


/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#endif