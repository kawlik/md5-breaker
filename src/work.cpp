#include "../inc/work.hpp"


/*  solutions
/*   *   *   *   *   *   *   *   *   *   */

void producer( mutex &mtx, solution_vect &solutions, set_t &set_hash, set_t &set_word, void ( *callback )( string &str ), bool reverseNotation ) {

    uint num_before = 0;
    uint num_after = 0;

    string str_clear = "";

    string str_after;
    string str_before;

    for( num_before = 0; num_before < MAX_NUM_CHECK; num_before++ ) {
        for( num_after = num_before; num_after < MAX_NUM_CHECK; num_after++ ) {
            
            str_after = to_string( num_after );
            str_before = to_string( num_before );
            

            //  additional run without closing 0
            if( !reverseNotation && num_after == 0 && num_before != 0 ) { doWork( str_before, str_clear, mtx, solutions, set_hash, set_word, callback ); }
            if( reverseNotation && num_after == 0 && num_before != 0 ) { doWork( str_clear, str_before, mtx, solutions, set_hash, set_word, callback ); }

            //  additional run without leading 0
            if( !reverseNotation && num_before == 0 && num_after != 0 ) { doWork( str_clear, str_after, mtx, solutions, set_hash, set_word, callback ); }
            if( reverseNotation && num_before == 0 && num_after != 0 ) { doWork( str_after, str_clear, mtx, solutions, set_hash, set_word, callback ); }

            //  conditional swap
            if( reverseNotation ) swap( str_before, str_after );

            //  regular run
            doWork( str_before, str_after, mtx, solutions, set_hash, set_word, callback );

            //  end thread
            if( solutions.left == 0 ) return;
        }
    }
}

void producer_chararr( mutex &mtx, solution_vect &solutions, set_t &set_hash, set_t &set_word, void ( *callback )( string &str ), bool reverseNotation ) {

    string str_clear = "";

    char chararr_before[ CHARARR_LEN ];
    char chararr_after[ CHARARR_LEN ];

    for( uint i = 0; i < CHARARR_LEN; i++ ) {
        chararr_before[i] = 0;
        chararr_after[i] = 0;
    }

    do {

        for( uint i = 0; i < CHARARR_LEN; i++ ) {
            chararr_after[i] = 0;
        }

        do {

            string str_after = chararr_after;
            string str_before = chararr_before;

            //  conditional swap
            if( reverseNotation ) swap( str_before, str_after );

            //  regular run
            doWork( str_before, str_after, mtx, solutions, set_hash, set_word, callback );

            //  end thread
            if( solutions.left == 0 ) return;

        } while( nextPremutation( chararr_after, 0 ));

    } while( nextPremutation( chararr_before, 0 ));
}


/*  solutions of utility functions
/*   *   *   *   *   *   *   *   *   *   */

void doWork( string &str_before, string &str_after, mutex &mtx, solution_vect &solutions, set_t &set_hash, set_t &set_word, void ( *callback )( string &str ) ) {

    string str_hash;
    string str_word;

    for( size_t i = 0; i < set_word.size; i++ ) {

            str_word = set_word.array[i];

            callback( str_word );

            str_word = str_before + str_word + str_after;

            str_hash = md5from( str_word );

        for( size_t j = 0; j < set_hash.size; j++ ) {

            if( str_hash == set_hash.array[j] ) {

                mtx.lock();

                if( !solutions.hasResult[j] ) {

                    cout << "> Found! hash: | " << str_hash << " | word: | " << str_word << " |" << endl;

                    solutions.hasResult[j] = true;
                    solutions.word[j] = str_word;
                    solutions.left--;
                }

                mtx.unlock();
            }
        }
    }
}