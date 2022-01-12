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


/*  signals handling
/*   *   *   *   *   *   *   *   *   *   */

void signal_SIGHUP( int signum ) {
    printSolutionVect( solutions );
}


/*  main executor
/*   *   *   *   *   *   *   *   *   *   */

int main( int argc, char **argv ) {

    /*  init basics
    /*   *   *   *   *   *   *   *   */

    signal( SIGHUP, signal_SIGHUP );


    string buffer;

    if( !readFromFile( "dat/hash.dat", set_hash )) { throw runtime_error( "Read from file has failed!" ); }
    if( !readFromFile( "dat/word.dat", set_word )) { throw runtime_error( "Read from file has failed!" ); }

    initSolutionVect( solutions, set_hash );


    /*  init threads
    /*   *   *   *   *   *   *   *   */

    do {

        thread t0_a = thread( producer_0a, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
        thread t0_b = thread( producer_0b, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
        thread t1_a = thread( producer_1a, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
        thread t1_b = thread( producer_1b, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
        thread t2_a = thread( producer_2a, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
        thread t2_b = thread( producer_2b, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
        thread t3_a = thread( producer_3a, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
        thread t3_b = thread( producer_3b, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
        thread t4_a = thread( producer_4a, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
        thread t4_b = thread( producer_4b, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
        thread t5_a = thread( producer_5a, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
        thread t5_b = thread( producer_5b, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
        thread t6_a = thread( producer_6a, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
        thread t6_b = thread( producer_6b, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
        thread t7_a = thread( producer_7a, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
        thread t7_b = thread( producer_7b, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
        thread t8_a = thread( producer_8a, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));
        thread t8_b = thread( producer_8b, ref( mtx ), ref( solutions ), ref( set_hash ), ref( set_word ));


        //  read new file
        cin >> buffer;


        t0_a.detach();
        t0_b.detach();
        t1_a.detach();
        t1_b.detach();
        t2_a.detach();
        t2_b.detach();
        t3_a.detach();
        t3_b.detach();
        t4_a.detach();
        t4_b.detach();
        t5_a.detach();
        t5_b.detach();
        t6_a.detach();
        t6_b.detach();
        t7_a.detach();
        t7_b.detach();
        t8_a.detach();
        t8_b.detach();

        t0_a.~thread();
        t0_b.~thread();
        t1_a.~thread();
        t1_b.~thread();
        t2_a.~thread();
        t2_b.~thread();
        t3_a.~thread();
        t3_b.~thread();
        t4_a.~thread();
        t4_b.~thread();
        t5_a.~thread();
        t5_b.~thread();
        t6_a.~thread();
        t6_b.~thread();
        t7_a.~thread();
        t7_b.~thread();
        t8_a.~thread();
        t8_b.~thread();


        //  prevency
        this_thread::sleep_for( 1000ms );

        if( system( "clear" )) { throw runtime_error( "Console clear has failed!" ); }

        if( buffer != "q" ) {

            cout << "Enter new hash set file name: " << endl;
            cin >> buffer;

            if( !readFromFile( buffer, set_hash )) { throw runtime_error( "Read from file has failed!" ); }
            
            initSolutionVect( solutions, set_hash );
        }

    } while( buffer != "q" );


    /*  join threads
    /*   *   *   *   *   *   *   *   */

    /*
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
    t6_a.join();
    t6_b.join();
    t7_a.join();
    t7_b.join();
    t8_a.join();
    t8_b.join();
    */

    printSolutionVect( solutions );
}