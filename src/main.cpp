#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <files...>" << endl;
        cerr << "Example: " << argv[0] << " *.txt" << endl;
        return 1;
    }
    
    cout << "Hello World!" << endl;
    return 0;
}
