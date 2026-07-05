#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        vector<vector<string>> ans;
        vector<string> usedOnLevel;

        int level=0;
        usedOnLevel.push_back(beginWord);
        q.push({beginWord});

        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();

            if(vec.size()>level){
                level++;
                for(auto it:usedOnLevel){
                    st.erase(it);
                }
                usedOnLevel.clear();
            }
            string word = vec.back();

            if(word==endWord){
                if(ans.size()==0){
                    ans.push_back(vec);
                }
                else if(ans[0].size()==vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.count(word)>0){
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i]=original;
            }
        }
        return ans;
    }

    void wordListCreater(vector<string>& wordList, string& beginWord, string& endWord){

        int n;
        cout<<"Enter the Number of Words you want in wordList: ";
        cin>>n;

        for(int i=0;i<n;i++){
            string word;
            cout<<"Enter words: ";
            cin>>word;
            wordList.push_back(word);
        }

        cout<<"Enter the beginWord(need not to be in the wordList): ";
        cin>>beginWord;

        cout<<"Displaying you given wordList to select an endWord: ";
        for(int i=0;i<wordList.size();i++){
            cout<<wordList[i]<<" ";
        }
        cout<<endl;

        cout<<"Now Enter an endWord: ";
        cin>>endWord;
    }
};

int main(){
    vector<string> wordList={};
    string beginWord="";
    string endWord="";
    Solution sol;
    sol.wordListCreater(wordList, beginWord, endWord);

    vector<vector<string>> ans = sol.findSequences(beginWord, endWord, wordList);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


}