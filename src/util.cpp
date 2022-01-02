#include "../inc/util.hpp"


/*  solutions
/*   *   *   *   *   *   *   *   *   *   */

void toLowerCase( string &str ) {
    for( size_t i = 0; i < str.size(); i++ ) {
        str[i] = tolower( str[i] );
    }
}

void toUpperCase( string &str ) {
    for( size_t i = 0; i < str.size(); i++ ) {
        str[i] = toupper( str[i] );
    }
}

void toStartCase( string &str ) {
    for( size_t i = 0; i < str.size(); i++ ) {
        ( i == 0 ) ? str[0] = toupper( str[0] ) : str[i] = tolower( str[i] );
    }
}