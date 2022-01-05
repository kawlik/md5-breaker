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


    thread t0 ( producer_0a, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
    thread t1 ( producer_0b, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
    thread t2 ( producer_1a, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
    thread t3 ( producer_1b, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
    thread t4 ( producer_2a, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
    thread t5 ( producer_2b, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));

    t5.join();
    t4.join();
    t3.join();
    t2.join();
    t1.join();
    t0.join();


    for( size_t i = 0; i < solutions.size; i++ ) {

        if( !solutions.hasResult[i] ) continue;

        cout << "> hash: [ " << solutions.hash[i] << " ] | > word: [ " << solutions.word[i] << " ]" << endl;
    }
}