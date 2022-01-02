#include "main.hpp"         //  common data lib
#include "inc/fsop.hpp"     //  file system operations
#include "inc/hash.hpp"     //  hash operations
#include "inc/util.hpp"     //  utility operations
#include "inc/work.hpp"     //  workers operations


/*  critical section
/*   *   *   *   *   *   *   *   *   *   */

//  primary mutex
mutex mtx;

//  found solutions vector
association_vect solutions;

//  sets of hashes and words
set_t set_hash;
set_t set_word;


/*  main executor
/*   *   *   *   *   *   *   *   *   *   */

int main( int argc, char **argv ) {

    if( !readFromFile( "dat/hash.dat", set_hash )) { throw runtime_error( "Hash!" ); }
    if( !readFromFile( "dat/word.dat", set_word )) { throw runtime_error( "Word!" ); }


    thread t0 ( producer_0, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
    thread t1 ( producer_1, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));

    t1.join();
    t0.join();
}