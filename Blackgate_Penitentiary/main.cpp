#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< string > list[ 255 ];

int main( void ) {
    int N;
    cin>> N;
    for( int i = 0; i < N; i++ ) {
        string a;
        int b;
        cin >> a >> b;
        list[ b ].push_back( a );
    }
    int val = 1;
    for( int i = 0; i < 255; i++ ) {
        if( !list[ i ].size() ) continue;
        sort( list[ i ].begin(), list[ i ].end() );
        for( int j = 0; j < list[ i ].size(); j++ ) {
            cout << list[ i ][ j ] << " ";
        }
        cout << val << " " <<  val + list[ i ].size() - 1 << endl;
        val += list[ i ].size();
    }
    return 0;
}