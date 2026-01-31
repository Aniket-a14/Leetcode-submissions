class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int mini = INT_MAX;
        for(int i=0;i<letters.size();i++){
            if(letters[i]>target){
                mini = min(mini,letters[i]-'a');
            }
        }

        return mini!=INT_MAX?mini+'a':letters[0];
    }
};