#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
class LRUCache {
  private:
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap; // key,iterator
    list<pair<int, int>> cacheList; // key,value                      // value
    int capacity;

  public:
    LRUCache( int capacity )
        : capacity( capacity ) {}

    int get( int key ) {

        if ( cacheMap.find( key ) == cacheMap.end() ) return -1;
        pair<int, int> newNode( *cacheMap[ key ] );
        cacheList.push_front( newNode );
        cacheList.erase( cacheMap[ key ] );
        cacheMap[ key ] = cacheList.begin();

        int value = cacheMap[ key ]->second;
        return value;
    }

    void put( int key, int value ) {
        if ( cacheMap.find( key ) != cacheMap.end() ) {
            auto it = cacheMap[ key ];

            pair<int, int> node( key, value );

            cacheList.push_front( node );

            cacheList.erase( it );
            cacheMap[ key ] = cacheList.begin();
            return;
        }
        if ( cacheList.size() == capacity ) {
            auto it = cacheList.back();

            cacheMap.erase( it.first );

            cacheList.pop_back();
        }

        pair<int, int> node( key, value );

        cacheList.push_front( node );
        cacheMap[ key ] = cacheList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main( int argc, char **argv ) {
    cout << "hello world!" << endl;
    return 0;
}
