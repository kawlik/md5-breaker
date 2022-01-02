#include "../inc/hash.hpp"


/*  solutions
/*   *   *   *   *   *   *   *   *   *   */

string md5from( string &str ) {

    unsigned char digest[ MD5_DIGEST_LENGTH ];

    MD5_CTX ctx;

    MD5_Init( &ctx );
    MD5_Update( &ctx, str.c_str(), str.size() );
    MD5_Final( digest, &ctx );

    char result[33];

    for( uint i = 0; i < 16; ++i ) {
        sprintf( &result[ i*2 ], "%02x", ( unsigned int ) digest[i] );
    }

    return result;
}