#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

using namespace std;

namespace FileOps{
    // 判断是否为字母
    bool isCharacter(char c){
        return  (c<='z' && c>='a')|| (c<='Z' && c>='A');
    }
    // 首字母的索引
    int firstCharacterIndex(const string &s, int start){
        for(int i = start;i<s.length();i++){
            if(isCharacter(s[i])){
                return i;
            }
        }
        return s.length();
    }
    // 将单词的字母全部变成小写
    string lowerS(const string &s){
        string ret = "";
        for(int i=0;i<s.length();i++){
            assert(isCharacter(s[i]));
            ret += tolower(s[i]);
        }
        return ret;
    }
    // 读文件并将单词全部写入words中
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
            cout <<"Can not open" << filename << "!!!" <<endl;
            return false;
        }

        int start = firstCharacterIndex(contents, 0);
        int i;
        // 遍历每个字符
        for(int i = start + 1; i<= contents.length();){
            // 若到了最后一个字母或者不是字母
            if(i == contents.length() || !isalpha(contents[i])){
                words.push_back(lowerS(contents.substr(start, i-start)));
                start = firstCharacterIndex(contents, i);
                i = start +1;
            }
            else{
                i++;
            }
        }
        return true;
    }
}
#endif // FILEOPERATIONS_H