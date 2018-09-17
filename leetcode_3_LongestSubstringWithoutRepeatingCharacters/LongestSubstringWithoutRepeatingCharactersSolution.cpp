class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.size(); 
        
        map<char, int> position;
        for ( int i = 0; i < length; ++i ) position[s[i]] = -1;
        
        int prev_length = 0;
        if ( length >= 1 ) {
            prev_length = 1; position[s[0]] = 0;
        }
        
        int curr_length = 0, max_length = prev_length;
        
        for ( int i = 1; i < length; ++i ) {
            int prevPosition;
            if ( position.count(s[i]) ) prevPosition = position[s[i]];
            else prevPosition = -1;

            int dist = i - prevPosition;
            if ( dist <= prev_length ) {
                curr_length = dist;
            } else {
                curr_length = prev_length + 1;
            }
            
            if ( curr_length > max_length ) max_length = curr_length;
            
            position[s[i]] = i;
            prev_length = curr_length;
        }
        
        return max_length;
    }
};