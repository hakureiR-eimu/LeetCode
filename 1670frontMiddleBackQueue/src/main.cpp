#include <iostream>
#include <queue>
using namespace std;

class FrontMiddleBackQueue {
  private:
    int lengthLeft = 0;
    int lengthRight = 0;
    deque<int> left;
    deque<int> right;

  public:
    FrontMiddleBackQueue() {
        this->lengthLeft = 0;
        this->lengthRight = 0;
        left.clear();
        right.clear();
    }
    // lengthLeft==lengthRight||lengthLeft==lengthRight+1
    void pushFront( int val ) {
        left.push_front( val );
        lengthLeft++;
        if ( lengthLeft - lengthRight == 2 ) {
            int temp = left.back();
            left.pop_back();
            lengthLeft--;
            right.push_front( temp );
            lengthRight++;
        }
    }
    void pushMiddle( int val ) {
        if ( lengthLeft == lengthRight ) {
            left.push_back( val );
            lengthLeft++;
        } else {
            int temp = left.back();
            left.pop_back();
            lengthLeft--;
            right.push_front( temp );
            lengthRight++;
            left.push_back( val );
            lengthLeft++;
        }
    }

    void pushBack( int val ) {
        right.push_back( val );
        lengthRight++;
        if ( lengthRight - lengthLeft == 1 ) {
            int temp = right.front();
            right.pop_front();
            lengthRight--;
            left.push_back( temp );
            lengthLeft++;
        }
    }

    int popFront() {
        if ( lengthLeft + lengthRight == 0 ) {
            return -1;
        }
        int res = left.front();
        left.pop_front();
        lengthLeft--;
        if ( lengthLeft < lengthRight ) {
            int temp = right.front();
            right.pop_front();
            lengthRight--;
            left.push_back( temp );
            lengthLeft++;
        }
        return res;
    }

    int popMiddle() {
        if ( lengthLeft + lengthRight == 0 ) {
            return -1;
        }
        int res = left.back();
        left.pop_back();
        lengthLeft--;
        if ( lengthLeft < lengthRight ) {
            int temp = right.front();
            right.pop_front();
            lengthRight--;
            left.push_back( temp );
            lengthLeft++;
        }
        return res;
    }

    int popBack() {
        if ( lengthLeft + lengthRight == 0 ) {
            return -1;
        }
        if ( lengthRight == 0 ) {
            int res = left.back();
            left.pop_back();
            lengthLeft--;
            return res;
        }
        int res = right.back();
        right.pop_back();
        lengthRight--;
        if ( lengthLeft - lengthRight == 2 ) {
            int temp = left.back();
            left.pop_back();
            lengthLeft--;
            right.push_front( temp );
            lengthRight++;
        }
        return res;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
int main( int argc, char **argv ) {
    FrontMiddleBackQueue *p = new FrontMiddleBackQueue();
    p->pushFront( 1 );              // 1
    p->pushBack( 2 );               // 1       2
    p->pushMiddle( 3 );             // 1 3      2
    p->pushMiddle( 4 );             // 1 3     4 2
    cout << p->popFront() << endl;  // 1 4   2
    cout << p->popMiddle() << endl; // 1  2
    cout << p->popMiddle() << endl; //   2
    cout << p->popBack() << endl;   //
    cout << p->popFront() << endl;
    cout << "hello world!" << endl;
    return 0;
}
