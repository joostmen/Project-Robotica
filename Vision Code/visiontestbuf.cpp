#include <iostream>
#include <fstream> //file reading lib
#include <string>

using namespace std;

int main()
{
    string line;
    ifstream bufferInc("buffer.txt");       //import buffer van python bestand

    while(true){
        bufferInc.open("buffer.txt");       //opent buffer
        if(bufferInc.is_open()){
            
            getline(bufferInc, line);       //verkrijg line van buffer
            cout << line << '\n';
            bufferInc.close();
        }
        else
        {
            cout << "Unable to open file"; 
        }  
    }
    return 0;
}