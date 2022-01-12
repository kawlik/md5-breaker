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
solution_vect solutions;

//  sets of hashes and words
set_t set_hash;
set_t set_word;


/*  main executor
/*   *   *   *   *   *   *   *   *   *   */

int main( int argc, char **argv ) {

    if( !readFromFile( "dat/hash.dat", set_hash )) { throw runtime_error( "Hash!" ); }
    if( !readFromFile( "dat/word.dat", set_word )) { throw runtime_error( "Word!" ); }

    initSolutionVect( solutions, set_hash );


    thread t0_a ( producer_0a, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
    thread t0_b ( producer_0b, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
    thread t1_a ( producer_1a, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
    thread t1_b ( producer_1b, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
    thread t2_a ( producer_2a, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
    thread t2_b ( producer_2b, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
    thread t3_a ( producer_3a, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
    thread t3_b ( producer_3b, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
    thread t4_a ( producer_4a, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
    thread t4_b ( producer_4b, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
    thread t5_a ( producer_5a, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
    thread t5_b ( producer_5b, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));

    t0_a.join();
    t0_b.join();
    t1_a.join();
    t1_b.join();
    t2_a.join();
    t2_b.join();
    t3_a.join();
    t3_b.join();
    t4_a.join();
    t4_b.join();
    t5_a.join();
    t5_b.join();


    printSolutionVect( solutions );
}