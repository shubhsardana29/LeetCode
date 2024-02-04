class Solution {
public:
    string minWindow(string s, string t) {
        vector toBeFound(128, 0);
        for (auto c : t) toBeFound[c]++;

        int counter = t.size(); 
        int start = 0;
        int end = 0;
        int minLen = INT_MAX;
        int head = 0;
        while (end < s.size()) {
	        if (toBeFound[s[end]] > 0) {
		        counter--;
	        }
	        toBeFound[s[end]]--;
	        end++;

	    while (counter == 0) { //valid
		    if (end - start < minLen) {
			    minLen = end - start;
			    head = start;
		}

		toBeFound[s[start]]++;
		    if (toBeFound[s[start]] > 0) {
			    counter++;
		    }
		    start++;
	    }
        }
    return minLen == INT_MAX ? "" : s.substr(head, minLen); 
    }
};


// template for substrings problems



//         vector<int> map(128,0);
//         int counter; // check whether the substring is valid
//         int begin=0, end=0; //two pointers, one point to tail and one  head
//         int d; //the length of substring

//         for() { /* initialize the hash map here */ }

//         while(end<s.size()){

//             if(map[s[end++]]-- ?){  /* modify counter here */ }

//             while(/* counter condition */){ 
                 
//                  /* update d here if finding minimum*/

//                 //increase begin to make it invalid/valid again
                
//                 if(map[s[begin++]]++ ?){ /*modify counter here*/ }
//             }  

//             /* update d here if finding maximum*/
//         }
//         return d;