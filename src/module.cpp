#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Module {
    // file path
    string id;

    // origin js code
    string code;

    // dependency module path
    vector<string> dependencies;

    // import name and module
    unordered_map<string, string> imports;
};