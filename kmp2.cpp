#include <vector>
#include <string>
#include <iostream>
#include <map>

/*����ƥ��*/
class MultiMatch
{
public:
    typedef std::string AnsiString;
    typedef std::map<AnsiString, AnsiString> StringMap;
    typedef std::vector<AnsiString> StringArray;
    typedef struct
    {
        int j;
        int markpos;// ��ǣ���ʾ���е����λ����
    } MatchState;
    typedef std::vector< MatchState > MatchStates;
    typedef struct
    {
        int pos;
        int item;   // ƥ���������
    } MatchResult;
    // -----------------------------------------------
    /*template < unsigned int M, unsigned int N >
    MultiMatch( AnsiString (&matches)[M], AnsiString (&replaces)[N] )
    {
    	this->initialize( matches, replaces );
    }*/
    MultiMatch( StringArray const & matches, StringArray const & replaces )
    {
        this->initialize( matches, replaces );
    }
    MultiMatch( void )
    {
    }
    /*template < unsigned int M, unsigned int N >
    bool initialize( AnsiString (&matches)[M], AnsiString (&replaces)[N] )
    {
    	return this->initialize( StringArray( matches, matches + M ), StringArray( replaces, replaces + N ) );
    }*/
    bool initialize( StringArray const & matches, StringArray const & replaces );
    // ��������һ��ƥ�� str:�ַ���, offset:ƫ��,��ʾ���ĸ�λ�ÿ�ʼ��
    // ���ص�λ�ð���offsetֵ
    MatchResult search( char const * str, int offset = 0 ) const;
    // �滻
    AnsiString replace( char const * str ) const;
    // ̰��ģʽ
    //MatchResult greedSearch( char const * str, int offset = 0 ) const;
private:
    std::vector< std::vector<short> > nextVals;
    StringArray matchItems;
    StringArray replaceItems;
};

/* KMP�ַ���ƥ���㷨 nextֵ */
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
// class MultiMatch
bool MultiMatch::initialize( StringArray const & matches, StringArray const & replaces )
{
    this->matchItems = matches;
    this->replaceItems = replaces;
    for ( StringArray::const_iterator it = this->matchItems.begin(); it != this->matchItems.end(); it++ )
    {
        this->nextVals.push_back( kmpCalcNext< short >( it->c_str() ) );
    }
    return true;
}

MultiMatch::MatchResult MultiMatch::search( char const * str, int offset ) const
{
    MatchResult res = { -1, -1 };
    int count = this->matchItems.size();
    MatchState * states = new MatchState[count];
    char const * mainStr = str + offset;
    int i;
    bool nomove = false;
    memset( states, 0, count * sizeof( MatchState ) );
    i = 0;
    while ( mainStr[i] != '\0' )
    {
        // kmp�㷨������pָ�벻�û�˷
        for ( int curr = 0; curr < count; curr++ )
        {
            if ( i < states[curr].markpos )
            {
            }
            else
            {
                AnsiString const & currItem = this->matchItems[curr];
                int currItemLen = ( int )currItem.length();
                if ( states[curr].j < currItemLen )
                {
                    if ( states[curr].j == -1 || mainStr[i] == currItem[states[curr].j] )
                    {
                        states[curr].j++;
                        states[curr].markpos = i + 1;
                        if ( states[curr].j == currItemLen ) // ��ʾ�Ѿ�ƥ��ɹ�
                        {
                            res.item = curr;
                            res.pos = i + 1 - currItemLen + offset;
                            goto RETURN;
                        }
                    }
                    else
                    {
                        states[curr].j = this->nextVals[curr][states[curr].j];
                        nomove = true;
                    }
                }
                else // ��ʾ�Ѿ�ƥ��ɹ�
                {
                    res.item = curr;
                    res.pos = i - currItemLen + offset;
                    goto RETURN;
                }
            }
        }
        if ( nomove )
        {
            nomove = false;
        }
        else
        {
            i++;
        }
    }
    delete [] states;
RETURN:
    return res;
}
// �滻
MultiMatch::AnsiString MultiMatch::replace( char const * str ) const
{
    AnsiString s = "";
    int offset = 0;
    int length = ( int )strlen( str );
    MatchResult r;
    r = this->search( str + offset );
    while ( r.pos != -1 )
    {
        s += AnsiString( str + offset, str + offset + r.pos );
        s += this->replaceItems[r.item];
        offset += r.pos + this->matchItems[r.item].size();
        r = this->search( str + offset );
    }
    s += str + offset;
    return s;
}


int main( void )
{
    MultiMatch::AnsiString mat[] = { "abc", "xyz", "lmn" };
    MultiMatch::AnsiString rep[] = { "<123>", "!789!", "-456-" };
    MultiMatch::StringArray matArr( mat, mat + sizeof(mat) / sizeof(MultiMatch::AnsiString) );
    MultiMatch::StringArray repArr( rep, rep + sizeof(rep) / sizeof(MultiMatch::AnsiString) );

    MultiMatch mm( matArr, repArr );

    char const * str = "ccc abc lmn xyz aaa";
    // ����ƥ��
    MultiMatch::MatchResult r = mm.search( str, 0 );
    if ( r.item != -1 )
    {
        std::cout << "\"" << str << "\"��" << r.pos << "λ����ƥ��\"" << mat[r.item] << "\"\n";
    }
    // ִ���滻�����滻����ƥ����Ϊ��Ӧ���滻���û��ƥ�䣬���滻
    std::cout << mm.replace(str) << "\n";

    return 0;
}
