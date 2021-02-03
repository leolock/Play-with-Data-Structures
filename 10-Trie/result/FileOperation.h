#ifndef FILEOPERATION_H
#define FILEOPERATION_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

using namespace std;

namespace FileOps{
    bool isCharacter(char c){
        return isalpha(c);
    }

    int firstCharacterIndex(const string &s, int start){
        for(int i = start; i<s.size();i++){
            if(isCharacter(s[i])){
                return i;
            }
        }
        return s.size();
    }
    
    string lowerS(const string &s){
        string ret = "";
        for(int i = 0;i<s.size();i++){
            assert(isCharacter(s[i]));
            if(isalpha(s[i]) == 1){
                ret += tolower(s[i]);
            }
        }
        return ret;
    }

    bool readFile(const string &filename, vector<string> &words){
        string line;
        string contents = "";
        ifstream file(filename);
        if(file.is_open()){
            while(getline(file, line))
                contents += (line + "\n");
            file.close();
        }
        else{
            cout << "can not open " <<filename<<"!!!"<<endl;
            return false;
        }

        int start = firstCharacterIndex(contents, 0);
        int i = start+1;
        while(i<=contents.size()){
            if(i == contents.size() || !isalpha(contents[i])){
                words.push_back(contents.substr(start, i-start));
                start = firstCharacterIndex(contents, i);
                i = start + 1;
            }
            else i++;
        }
        return true;
    }
}
#endif // FILEOPERATION_H