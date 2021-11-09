/*
Leetcode #408

A string can be abbreviated by replacing any number of non-adjacent, non-empty substrings with their lengths. The lengths should not have leading zeros.

For example, a string such as "substitution" could be abbreviated as (but not limited to):

"s10n" ("s ubstitutio n")
"sub4u4" ("sub stit u tion")
"12" ("substitution")
"su3i1u2on" ("su bst i t u ti on")
"substitution" (no substrings replaced)
The following are not valid abbreviations:

"s55n" ("s ubsti tutio n", the replaced substrings are adjacent)
"s010n" (has leading zeros)
"s0ubstitution" (replaces an empty substring)
Given a string word and an abbreviation abbr, return whether the string matches the given abbreviation.

A substring is a contiguous non-empty sequence of characters within a string.
*/

bool isAlphabet(char* ch)
{
	if (*ch >= 'a' && *ch <= 'z')
		return true;
	return false;
}
    
bool isDigit(char* ch)
{
	if (*ch >= '0' && *ch <= '9')
		return true;
	return false;
}
    
bool validWordAbbreviation(string word, string abbr) {

        char* wordptr = (char*)word.c_str();
        char* abbrptr = (char*)abbr.c_str();

        while (*wordptr != '\0' && *abbrptr != '\0' )
        {
            while (isAlphabet(abbrptr))
            {
                if (*wordptr != *abbrptr)
                    return false;
                wordptr++;
                abbrptr++;
            }
             
            string numStr = "";
            while (isDigit(abbrptr))
            {
                if(numStr.empty() && *abbrptr == '0')
                    return false;
                numStr += *abbrptr++;
            }

            if (!numStr.empty())
            {
                int num = atoi(numStr.c_str());
                int len = strlen(wordptr);
                if (len >= num)
                    wordptr += num;
                else
                    return false;
            }
        }
    
        if (*wordptr != '\0' || *abbrptr != '\0')
		    return false;
    
        return true;
   }
