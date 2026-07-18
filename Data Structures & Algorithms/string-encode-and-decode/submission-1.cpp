class Solution {
public:

    string encode(vector<string>& strs) {
        string encode; 
        // so basically if we have a vector of strings like "hi","hello",
        // I need to make it into one string and return that string as encoded string. 
        // However I need to make it in such a way that I can recognize where one string starts
        // and ends, so that it is possible for me to decode it back to a vector of strings. 
        //Approach is to encode strings like this: {"hi","hello"} -> {2#hi5#hello}
        for (string x: strs){
        int length = x.size();
        encode.append(to_string(length));
        encode.push_back('#');
        encode.append(x);
        }
        return encode; 

    }

    vector<string> decode(string s) {
       int len = 0; 
       int i =0;
       int j =0; 
       vector<string> ans; 
       while (i < s.size()){ 
            int j = i; 
            while (s[j]!='#'){  //build up digits of the length till we encounter a #
            len = (len*10) + (s[j] - '0'); 
            j++;
            } //j points to #, so we need to access one letter from that. 
            ans.push_back(s.substr(j+1,len));
            i = j + 1 + len; //j+1 points to the start of the next element and the +len points to the first digit of the next word's length. 
            len = 0; //length of new word is currently unknown hence 0. 
          
       }
       return ans; 


    }
};
