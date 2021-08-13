#include <iostream>

#include <fstream>

#include <string>

#include <regex>

using namespace std;

int main() {
    cout << "文件操作演示" << endl;
    wifstream file("src/file/demo.conf");
    wstring temp,name,group,phone;
    wsmatch result;
    wregex split_pattern(L"(.*?),(.*?),(.*?)");
    
    if(!file.is_open())
        cout << "文件不存在或打开失败" << endl;
    getline(file, temp);
    regex_match(temp.cbegin(), temp.cend(), result, split_pattern);
  
    while (getline(file,temp)) {
        regex_match(temp.cbegin(), temp.cend(), result, split_pattern);
        name = result[1].str();
        group = result[2].str();
        phone = result[3].str();
        name = name.erase(0, name.find_first_not_of(' ')).erase(name.find_last_not_of(' ')+1);
        group = group.erase(0, group.find_first_not_of(' ')).erase(group.find_last_not_of(' ')+1);
        phone = phone.erase(0, phone.find_first_not_of(' ')).erase(phone.find_last_not_of(' ')+1);

        wcout << name << '\t' << group << '\t' << phone << endl;
    
    }
    file.close();
}

