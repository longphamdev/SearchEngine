#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
using namespace std;
namespace fs = std::filesystem;



int main() {
    string a;
    vector<string> fileName;
    std::string path = "C:/Users/vntua/Documents/GitHub/SearchEngine/searchEngine/searchEngine/Search Engine-Data/Search Engine-Data";
    for (const auto& entry : fs::directory_iterator(path))
    {
        a = entry.path().u8string();
        
    }
    cout << "done...";

        return 0;
}
