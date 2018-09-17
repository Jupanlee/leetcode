class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int size = nums.size(); vector<string> str_nums;
        
        for ( int i = 0; i < size; ++i ) str_nums.push_back(to_string(nums[i]));
    
        quick_sort(str_nums, 0, size-1);
        
        string rst = ""; int i = 0;
        while ( i < ( size - 1 ) && str_nums[i] == "0" ) {
            ++i;
        }
        
        for ( int j = i; j < size; ++j ) {
            rst += str_nums[j];
        }       
        
        return rst;    
    }
    
    void quick_sort(vector<string> &str_nums, int lo, int hi) {
        
        if ( hi <= lo ) return;
        int t = partition(str_nums, lo, hi);
        
        quick_sort(str_nums, lo, t);
        quick_sort(str_nums, t+1, hi);
    }
    
    int partition(vector<string> &str_nums, int lo, int hi) {
        int size = hi - lo + 1;
        string t = str_nums[lo];
        while ( lo < hi ) {
            while ( lo < hi && compare(t, str_nums[hi])) --hi;
            str_nums[lo] = str_nums[hi];
            while ( lo < hi && compare(str_nums[lo], t)) ++lo;
            str_nums[hi] = str_nums[lo];
        }
        str_nums[lo] = t;
        return lo;
    }
    
    bool compare(const string &str1, const string &str2) {
        string combine_str1 = str1 + str2, combine_str2 = str2 + str1;
        if ( combine_str1 >= combine_str2 ) return true;
        else return false;
    }
};