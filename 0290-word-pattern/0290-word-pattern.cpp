class Solution {
public:
    bool wordPattern(string pattern, string s) {
        /*
        sabse pehle 2map bna lo :- 
        1. jo char se index me convert kare 
        2. jo string se index me convert kare
        */
        unordered_map<char , int>CharToIndex;
        unordered_map<string , int>WordToIndex;

        //stringstream basically pas krege string 's' into stream buffer.
        stringstream ss(s);
        string token; // variable jisme saare extracted words ko store karana h 
        int countTokens = 0;
        int i=0 ; 
        int n = pattern.size();

        /*
        3. 'ss >> token' extracts the next word separated by space.means ye har words ko alag alag krke input leta rehta h . 
        The loop runs as long as there are words left to read in 's'.
        Example :- 
        If s = "dog cat cat dog":
        1st iteration: ss >> token assigns "dog" to token.
        2nd iteration: ss >> token assigns "cat" to token.
        3rd iteration: ss >> token assigns "cat" to token.
        4th iteration: ss >> token assigns "dog" to token.
        5th iteration: Stream reaches the end of string s, returns false, and the while loop ends.
        */
        while(ss >> token)
        {
            countTokens++;
            if(i == n || CharToIndex[pattern[i]] != WordToIndex[token])
            {
                return false;
            }
            CharToIndex[pattern[i]] = i+1;
            WordToIndex[token]      = i+1;
            i++;
        }
        if(i != n || countTokens != n) 
        {
            return false;
        }
        return true;
    }
};