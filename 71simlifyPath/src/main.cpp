#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    static string simplifyPath(string path) {
        vector<string> stk;
        string res = "/";
        int cnt;
        int count;
        for(int i = 0; i < path.length();){
            if(path[i] == '/'){
                string tmp = "";
                i++;
                continue;
            }
            else {
                string tmp = "";
                cnt = 0;
                count = 0;
                while(path[i]!= '/' && i < path.length()){
                    count ++;
                    if(path[i] == '.') {
                        cnt++;
                        //cout << cnt << endl;
                    }
                    tmp.push_back(path[i]);
                    i++;
                }
                if(cnt == 2 && !stk.empty() && count == 2){
                    //cout << "suc" << endl;
                    stk.pop_back();
                    continue;
                }
                else if(cnt == 2 && stk.empty() && count == 2){
                    continue;
                }
                else if(cnt == 1 && count == 1){
                    tmp = "";
                    cnt = 0;

                }
                else{
                    //cout << tmp <<endl;
                    stk.push_back(tmp);
                }

            }
        }
        if(stk.empty()){
            return "/";
        }
        for(string& ch:stk){
            res += ch;
            if(!(&ch == &stk.back())){
                res += '/';
            }
        }
        return res;

    }
};
int main(int argc, char** argv)
{
    //cout << "hello world!" << endl;
    string res = Solution::simplifyPath("/.hidden");
    cout << res <<endl;
    return 0;
}
