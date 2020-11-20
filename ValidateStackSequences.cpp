 /*
 Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.
 Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
 Output: true
 Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
 Output: false
 
 Solution - 
 create stack and push from pushed list till popped first element is found.
 when stack top and popped first elements match, pop from stack as well as 
 erase first element from popped. if they do not match then return false.
 */
 
 bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;

        while (!popped.empty())
        {
            while (i<pushed.size() && (s.empty() || s.top() != popped[0]))
                s.push(pushed[i++]);

            if (s.top() == popped[0])
            {
                popped.erase(popped.begin());
                s.pop();
            }
            else
                break;
        }

        return (s.empty());
    }
