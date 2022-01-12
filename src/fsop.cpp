#include "../inc/fsop.hpp"


/*  solutions
/*   *   *   *   *   *   *   *   *   *   */

bool readFromFile( const string filename, set_t &set ) {

    // delete [] set.array;

    fstream file;

    string buffer_read;
    vector<string> buffer_store;

    file.open( filename );

    if( file.good()) {

        while( file >> buffer_read ) {

            buffer_store.push_back( buffer_read );
        }

        file.close();


        size_t size = buffer_store.size();

        set.size = size;
        set.array = new string [ size ];

        for( size_t i = 0; i < size; i++ ) {
            set.array[i] = buffer_store[i];
        }

        cout << "New hash set has been loaded! ( size: " << size << " ) " << endl;

        //  operaion was successful
        return true;
    }

    cout << "Selected hash set has not been loaded!" << endl;

    //  operaion was unsuccessful
    return false;
}

void initSolutionVect( solution_vect &vect, set_t &set_hash ) {

    // delete [] vect.hasResult;
    // delete [] vect.hash;
    // delete [] vect.word;

    size_t size = set_hash.size;

    vect.size = size;
    vect.left = size;
    vect.hash = set_hash.array;
    vect.word = new string [ size ];
    vect.hasResult = new bool [ size ];

    for( size_t i = 0; i < size; i++ ) {
        vect.hasResult[i] = false;
    }
}