class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        // see abbr and check if it is a digit or alphabet 
        int p1 = 0; 
        int p2 = 0; 
        while (p1 < word.size() && p2 < abbr.size()){
            if (word[p1] == abbr[p2]){
                p1++; 
                p2++; 
                continue; 
            }
            if (word[p1] != abbr[p2] && isdigit(abbr[p2])){
                if (abbr[p2] == '0' && !isdigit(abbr[p2-1]))
                    return false;
                int p3 = p2; 
                while (isdigit(abbr[p3])){
                    p3++; 
                }
                //now p2 points to start of digit and p3-1 to the end 
                string numb = abbr.substr(p2, p3-p2); 
                int num = stoi (numb); 
                if (num > word.size() - p1)
                    return false; 
                p1 = p1 + num ; 
                p2 = p3; 
                continue;      
            }
            else
                return false; 
        }
        return p1 == word.size() && p2 == abbr.size();
    }
};