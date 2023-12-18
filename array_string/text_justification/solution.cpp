#include <vector>
#include <string>
#include <iostream>
using namespace std;
/**
 * Approach:
 * for each world in list count the size and add 1 to size to account for space between words
 * if the size goes past max width, then we need to discount the current word and fill up the 
 * row with the previous words and spaces distributed between the words.
*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> output;
        int i = 0;
        int count;
        int start;
        string row;
        int word_count;
        int length_of_words;
        int num_spaces;
        int remainder;
        bool single_word_entry;

        while(i < words.size()){
            single_word_entry = false;
            num_spaces = 0;
            length_of_words = 0;
            word_count = 0;
            row = "";
            start = i;
            count = 0;

            // determine how many words we can add to the row
            while(count < maxWidth+1){
                count += words[i].size() + 1;
                word_count++;
                length_of_words += words[i].size();
                if(count > maxWidth+1){
                    length_of_words -= words[i].size();
                    i--;
                    word_count--;
                    break;
                } else if(count==maxWidth+1 || i==words.size()-1){
                    break;
                } else {
                    i++;
                }
            }
            // handle edge case of word_count == 1
            if (word_count==1)
                single_word_entry = true;
                
            // determine how many spaces we need to add to the row
            num_spaces = (maxWidth - length_of_words) / max(1, (word_count - 1));
            remainder = (maxWidth - length_of_words) % max(1, (word_count - 1));
            // add words and spaces
            for(int j = start; j <= i; j++){
                if(i==words.size()-1){ // check if we are at the last line in which case we left justify
                    // add word and space
                    row += words[j];
                    if(j==i){
                        int n = row.size();
                        // fill up rest of row with spaces
                        for(int x = 0; x < maxWidth - n; x++){
                            row += ' ';
                        }
                    } else {
                        row += ' ';
                    }
                    continue;
                }
                row += words[j];
                if(j==i && !single_word_entry)
                    break;
                // add spaces for string
                for(int n = 0; n < num_spaces; n++){
                    row += ' ';
                }
                if(remainder > 0){
                    row += ' ';
                    remainder--;
                }
            }
            //append row to result
            output.push_back(row);
            i++;
        }
        return output;   
    }
};

int main(){
    Solution solution;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    vector<string> result = solution.fullJustify(words, maxWidth);
    for(const auto el : result){
        cout<<el<<endl;
    }
}