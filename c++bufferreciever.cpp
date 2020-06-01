
#include <iostream>
#include <fstream> //file reading lib
#include <string>

using namespace std;

int main()
{
    string line;
    ifstream bufferInc("buffer.txt");
    while(true){
        bufferInc.open("buffer.txt");
        if(bufferInc.is_open()){
            
            getline(bufferInc, line);
            cout << line << '\n';
            if(bufferInc.bad())
            {
                cout << "bad" << '\n';
            }
            bufferInc.close();
        }
        else
        {
            cout << "Unable to open file"; 
        }
        
    }
    return 0;
}