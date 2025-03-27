#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

int main(){
    //The words in the keys.txt are shift words
    //Bob decripts the message by shifting 
    //Need to determine the shift word length, not the word itself
    //The keyword is Brick

    string phrase = "BEBCB DKQEK TYINV CVCUO EWWTZ FRKGP VCXWB QFAGC PETAD IVZGC IRTNL FGZQR JSQVO EZVVO SRTKK BEGOO BJCTO TFNCW JCQVK SPVCD VIMUE DYIUD IVMUD BSTKC IDMPD PWUKV JKITI CRAGC BELHY SKQHS DRBKY OJBJO DRZTI JEOQE UFNOS MZBCB ZDIPO VMMTC BJEGV MRAVR FKMUD JEOQP BEGVI QVWHG FRXQX TEWPO XTTCS NFZGX MRZIO NVVVY GRVGH JJBKX HTTCS NKWVO SIQVY SZINC PMMTO JXVVI JEIPD BIKVS DRAJK MCJGK TJMTD FUEJS MVBJO QIMUO OKBTO BKGKC JENQB DV";
    vector<string> keywords = {"savory", "weary","colorful" ,"ducks" ,"time" ,"slimy" ,"travel","aware","dry","troubled"
                               ,"queue","expect","splendid","unsuitable","workable","middle","evanescent","zephyr","brave"
                               ,"wind","apparatus","sand","complete","disappear","invincible","sedate","test","rustic","steady"
                               ,"rainstorm","foolish","gabby","cherry","daily","heal","rose","boat","reward","trust","tremble"
                               ,"discreet","enormous","settle","fit","vessel","parched","chickens","desire","practice","terrific"
                               ,"imminent","fuzzy","debt","medical","industry","run","tow","raise","juice","plant","range","unusual"
                               ,"breakable","quiet","early","mother","tomatoes","woebegone","psychedelic","shocking","elated","deranged"
                               ,"bouncy","wood","three","deceive","flavor","blind","brick","spray","fretful","hanging","hallowed","hurry"
                            };
    string newPhrase , ucPhrase;
    vector<int> shiftKeyValues;
    vector<int> frequency(26);
    int count;


    for(char letter : phrase){
        if(isalpha(letter)){
            ucPhrase+=letter;
        }
    }
   
    for(int i = 0; i < keywords.size(); i++){
        shiftKeyValues.resize(keywords.at(i).size());
        count = 0;
        newPhrase = "";

        for(int j = 0; j < keywords.at(i).size(); j++){
            shiftKeyValues.at(j) = toupper(keywords.at(i).at(j)) - 'A'; //Added plus 1 so it is within the range
        }

        for(int j = 0; j < ucPhrase.size(); j++){
            newPhrase.push_back((char)(((ucPhrase.at(j) - 'A' - shiftKeyValues.at(count) + 26) % 26) + 'A'));
            count++;
            if(count >= shiftKeyValues.size()){
                count = 0;
            }
        }
        cout << keywords.at(i) << endl;

        cout << newPhrase << "\niteration: " << i << "\n\n\n\n";

    }
    cout << endl;

    return 0;
}