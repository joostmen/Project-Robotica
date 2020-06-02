
#include <iostream>
#include <fstream> //file reading lib
#include <string>

using namespace std;

int main()
{
    string line = "340.0";
    int lineOld;
    int lineNew;
    string lineTemp;
    int idletimer = 0;
    ifstream bufferInc("buffer.txt");       //import buffer van python bestand
    getline(bufferInc,  lineTemp); 
    lineOld = stoi(lineTemp);
    while(true){
        bufferInc.open("buffer.txt");       //opent buffer
        if(bufferInc.is_open()){
            
            getline(bufferInc, line);       //verkrijg line van buffer
            lineNew = stoi(line);           //maak variabele voor personen niet doorelkaar te halen
            if ( ((lineNew > (30+ lineOld )) || (lineNew < (30 - lineOld ))) && idletimer < 3)      //wanneer er meerdere personen zijn zal de coordinaten heen een weer gaan springen, 
            {                                                                                       // hier wordt 3 keer op gecontroleerd voordat ie een nieuwe variabele erbij pakt als het de onjuiste is
                idletimer++;                                                                        // max 3 keer zodat een te snel lopend persoon een grotere kan heeft om achtervolgt te worden.
                cout << " Verkeerde persoon gezien, nog " << idletimer << " mogelijkheden" << '\n';
            }
            else
            {
            idletimer = 0;
            cout << line << '\n';
            lineOld = stoi(line);
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