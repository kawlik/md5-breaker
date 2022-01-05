#include "../inc/work.hpp"


/*  solutions
/*   *   *   *   *   *   *   *   *   *   */

void producer( mutex &mtx, solution_vect &solutions, set_t &set_hash, set_t &set_word, void ( *callback )( string &str ), bool reverseNotation ) {


    uint num_before = 0;
    uint num_after = 0;

    string str_clear = "";

    string str_before;
    string str_after;

    for( num_before = 0; num_before < MAX_NUM_CHECK; num_before++ ) {
        for( num_after = 0; num_after < MAX_NUM_CHECK; num_after++ ) {
            
            str_after = to_string( num_after );
            str_before = to_string( num_before );

            //  additional run without leading and closing 0
            if( num_after == 0 && num_before == 0 ) { doWork( str_clear, str_clear, mtx, solutions, set_hash, set_word, callback ); }

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

            if( solutions.hasResult[j] ) continue;

            if( str_hash == set_hash.array[j] ) {

                cout << "> Found! hash: | " << str_hash << " | word: | " << str_word << " |" << endl;

                mtx.lock();

                solutions.hasResult[j] = true;
                solutions.word[j] = str_word;
                solutions.left--;

                mtx.unlock();
            }
        }
    }
}