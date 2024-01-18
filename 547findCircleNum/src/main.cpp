#include <iostream>
#include <vector>
class UnionFind {
  private:
    std::vector<int> parent;
    std::vector<int> rank;
    int sum;

  public:
    UnionFind( int n ) {
        parent.resize( n );
        rank.resize( n, 1 );
        sum = n;
        for ( int i = 0; i < n; ++i ) {
            parent[ i ] = i;
        }
    }
};
class Solution {
  public:
    class UnionFind {
      private:
        std::vector<int> parent;
        std::vector<int> rank;
        int sum;

      public:
        UnionFind( int n ) {
            parent.resize( n );
            rank.resize( n, 1 );
            sum = n;
            for ( int i = 0; i < n; ++i ) {
                parent[ i ] = i;
            }
        }
        int find( int x ) {
            if ( parent[ x ] != x ) {
                parent[ x ] = find( parent[ x ] );
            }
            return parent[ x ];
        }
        void unite( int x, int y ) {
            int rootX = find( x );
            int rootY = find( y );

            if ( rootX != rootY ) {
                parent[ rootX ] = parent[ rootY ];
                sum--;
            }
        }
        int getSum() { return this->sum; }
    };
    int findCircleNum( std::vector<std::vector<int>> &isConnected ) {
        if ( isConnected.empty() ) {
            return 0;
        }
        int n = isConnected.size();
        UnionFind uf( n );
        for ( int i = 0; i < isConnected.size(); ++i ) {
            for ( int j = 0; j < isConnected.size(); ++j ) {
                if ( isConnected[ i ][ j ] == 1 && i < j ) {
                    uf.unite( i, j );
                }
            }
        }
        return uf.getSum();
    }
};
int main( int argc, char **argv ) { return 0; }
