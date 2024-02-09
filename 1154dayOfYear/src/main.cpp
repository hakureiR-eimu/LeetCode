#include <iostream>
#include <string>
class Solution {
  private:
    int months[ 12 ] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    bool isLeapYear( int year ) {
        int isFourLeap = year % 4 == 0 ? 1 : 0;
        int isHundredLaep = year % 100 == 0 ? 1 : 0;
        int isFourHundredLeap = year % 400 == 0 ? 1 : 0;
        if ( isFourLeap && !isHundredLaep ) {
            return true;
        }
        if ( isHundredLaep && isFourHundredLeap ) {
            return true;
        }
        return false;
    }

  public:
    int dayOfYear( std::string date ) {
        // yyyy-mm-dd
        std::string year = date.substr( 0, 4 );
        std::string month = date.substr( 5, 2 );
        std::string day = date.substr( 8, 2 );
        int yearInt = std::stoi( year );
        int monthInt = std::stoi( month );
        int dayInt = std::stoi( day );
        int days = 0;
        if ( isLeapYear( yearInt ) ) {
            months[ 1 ] = 29;
        } else {
            months[ 1 ] = 28;
        }
        for ( int i = 0; i < monthInt - 1; ++i ) {
            days += months[ i ];
        }
        days += dayInt;
        return days;
    }
};
int main( int argc, char **argv ) {
    std::string date = "2003-03-01";
    Solution *p = new Solution;
    int res = p->dayOfYear( date );
    std::cout << res << "\n";
    return 0;
}
