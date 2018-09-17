class Solution {
public:
    int numDecodings(string s) {
        const int length = s.size(); 
        int decoding_num[length+1]; 
        decoding_num[0] = 1;
        
        if ( length >= 1 && ( '1' <= s[0] && s[1] <= '9' ) ) {
            decoding_num[1] = 1;
        } else {
            decoding_num[1] = 0;
        }
        
        for ( int i = 2; i < length + 1; ++i ) {
            if ( '1' <= s[i-1] && s[i-1] <= '9' ) {
                decoding_num[i] = decoding_num[i-1];
            } else {
                decoding_num[i] = 0;
            }
            
            int number = ( s[i-2] - '0' ) * 10 + ( s[i-1] - '0' );
            if ( 10 <= number && number <= 26 ) {
                decoding_num[i] += decoding_num[i-2];
            } 
        }
        
        return decoding_num[length];      
    }
};