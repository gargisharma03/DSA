/*Description:
A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.


Approach:Recursive Backtracking
1.Created a backtracking function that takes the current index,dots placed, current ip string ,original string and the result vector.
2.Base case: If dots==4 and index==s.length() then we have a valid ip address.
3.If dots>4 or index>=s.length() then return as we have placed more than 4 dots or we have reached the end of the string.
4.Iterate for length of the segment from 1 to 3->
   - If index+length>s.length() then break as we have reached the end of the string.
   - Get the segment from the string and convert it to integer.
   - If the integer is greater than 255 or if it has leading zeros then break as it is not a valid segment.
   - Call the backtracking function with updated index, dots, current ip string and result vector.

*/

#include <climits>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    void backtrack(int i,int dots,string curIp,string& s, vector<string>& res){
        if(dots==4 && i==s.length()){
            res.push_back(curIp.substr(0, curIp.length() - 1));
            return;
        }

        if(dots>4 || i>=s.length()){
            return;
        }

        for(int l=1;l<=3;l++){
            if(i+l>s.length()) break;

            string seg=s.substr(i,l);
            int val=stoi(seg);

            if (val > 255 || (seg[0] == '0' && l > 1)) {
                break; 
            }
            backtrack(i + l, dots + 1, curIp + seg + ".", s, res);
        }
    }
public:

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.length() < 4 || s.length() > 12) {
            return res;
        }

        backtrack(0, 0, "", s, res);
        return res;
    }
};