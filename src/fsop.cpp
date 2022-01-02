#include "../inc/fsop.hpp"


/*  solutions
/*   *   *   *   *   *   *   *   *   *   */

bool readFromFile( const string filename, set_t &set ) {

    delete [] set.array;

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

        //  operaion was successful
        return true;
    }

    //  operaion was unsuccessful
    return false;
}