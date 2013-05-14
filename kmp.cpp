#include <vector>
#include <stdio.h>
/*
	KMP◊÷∑˚¥Æ∆•≈‰À„∑® µœ÷
*/
/* next÷µ */
template < typename IndexType >
std::vector< IndexType > kmpCalcNext( char const * substr )
{
    IndexType length = ( IndexType )strlen( substr );
    std::vector< IndexType > next( length + 1 );
    IndexType j = 0, k = -1;
    next[0] = -1;
    while ( j < length )
    {
        if ( k == -1 || substr[j] == substr[k] )
        {
            j++;
            k++;
            if ( substr[j] != substr[k] )
                next[j] = k;
            else
                next[j] = next[k];
        }
        else
        {
            k = next[k];
        }
    }
    return next;
}
/* KMP∆•≈‰ */
template < typename IndexType >
IndexType kmpMatchEx( char const * str, char const * substr, int pos, std::vector< IndexType > const & next )
{
    IndexType length = ( IndexType )strlen( str );
    IndexType sublen = ( IndexType )strlen( substr );
    IndexType i, j;
    i = pos;
    j = 0;
    while( i < length && j < sublen )
    {
        if( j == -1 || str[i] == substr[j] )
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    return j == sublen ? i - sublen : -1;
}
template < typename IndexType >
IndexType kmpMatch( char const * str, char const * substr, int pos )
{
    return kmpMatchEx( str, substr, pos, kmpCalcNext< IndexType >( substr ) );
}



int main( void )
{
    short pos = kmpMatch<short>( "abcvvcfbcsdsdasfbvscfghgfb", "fb", 0 );
    printf( "%d", pos );
    return 0;
}
