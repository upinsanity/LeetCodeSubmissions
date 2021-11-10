#include<stack>
#include<string>
using namespace std;

 /*
 Leetcode #151
 Input: s = "the sky is blue"
 Output: "blue is sky the"
 
 Solution - 
 traverse the string
 at each whitespace, put each word in a stack
 repeat till end of string
 pop stack elements in a string separated by whitespaces
 */

bool isNotWhiteSpace(string s)
    {
        return (s!=" "&&s!="\t"&& s!="");
    }

    string reverseWords(string s) {
        stack<string> st;
        string out;
                
        size_t pos = s.find(" ");
        while (pos != string::npos)
        {
            string sub = s.substr(0, pos);
            s = s.substr(pos+1);
            if( isNotWhiteSpace(sub) )
                st.push(sub);
            pos = s.find(" ");
        }
        
        if(isNotWhiteSpace(s))
            st.push(s);
        
        while(!st.empty())
        {
            string str = st.top();
             st.pop();
            
            out += str;
           
            if(!st.empty())
               out += " ";  
        }
        return out;
    }
