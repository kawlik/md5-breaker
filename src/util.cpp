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

bool nextPremutation( char *array, uint index ) {

    if( index >= CHARARR_LEN ) return true;

    if( array[index] < ASCI_MIN )   {
        array[index] = ASCI_MIN;
        return false;
    }

    if( array[index] < ASCI_MAX ) {
        array[index]++;
        return false;
    }

    array[index] = ASCI_MIN;
    return nextPremutation( array, index + 1 );
}