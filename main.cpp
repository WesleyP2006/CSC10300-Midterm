#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

int main(){
    //The words in the keys.txt are shift words
    //Bob decripts the message by shifting 
    //Need to determine the shift word length, not the word itself

    vector<string> keywords = {"savory", "weary","colorful" ,"ducks" ,"time" ,"slimy" ,"travel","aware","dry","troubled"
                               ,"queue","expect","splendid","unsuitable","workable","middle","evanescent","zephyr","brave"
                               ,"wind","apparatus","sand","complete","disappear","invincible","sedate","test","rustic","steady"
                               ,"rainstorm","foolish","gabby","cherry","daily","heal","rose","boat","reward","trust","tremble"
                               ,"discreet","enormous","settle","fit","vessel","parched","chickens","desire","practice","terrific"
                               ,"imminent","fuzzy","debt","medical","industry","run","tow","raise","juice","plant","range","unusual"
                               ,"breakable","quiet","early","mother","tomatoes","woebegone","psychedelic","shocking","elated","deranged"
                               ,"bouncy","wood","three","deceive","flavor","blind","brick","spray","fretful","hanging","hallowed","hurry"
                               };
    vector<int> shiftKeyValues;
    vector<int> frequency(26);
    string phrase = "BEBCB DKQEK TYINV CVCUO EWWTZ FRKGP VCXWB QFAGC PETAD IVZGC IRTNL FGZQR JSQVO EZVVO SRTKK BEGOO BJCTO TFNCW JCQVK SPVCD VIMUE DYIUD IVMUD BSTKC IDMPD PWUKV JKITI CRAGC BELHY SKQHS DRBKY OJBJO DRZTI JEOQE UFNOS MZBCB ZDIPO VMMTC BJEGV MRAVR FKMUD JEOQP BEGVI QVWHG FRXQX TEWPO XTTCS NFZGX MRZIO NVVVY GRVGH JJBKX HTTCS NKWVO SIQVY SZINC PMMTO JXVVI JEIPD BIKVS DRAJK MCJGK TJMTD FUEJS MVBJO QIMUO OKBTO BKGKC JENQB DV";
    string lcPhrase , newPhrase;
    int count;


    //This turns the phrase to all lower case for consistent ASCII codes
    for(int i = 0; i < phrase.size(); i++){
        lcPhrase+=(char)tolower(phrase.at(i));
        //Casting char since it outputs ASCII int value
    }
    //formula to find shifted right  is (120 + 100) % 122 given (origin + shift) % 122 (# of ASCII) Maybeeee
    //97+((old_value−97−(shift - 97)) % 26) this is formula to shift to the left (decode)
    // newPhrase = (phrase.at() - shiftChar + 26) % 26 + 'a';
    for(int i = 0; i < keywords.size(); i++){
        shiftKeyValues.resize(keywords.at(i).size());
        count = 0;
        newPhrase = "";
        for(int j = 0; j < keywords.at(i).size(); j++){
            shiftKeyValues.at(j) = (keywords.at(i).at(j)) - 'a';
        }
        for(int j = 0; j < lcPhrase.size(); j++){
            if(isalpha(lcPhrase.at(j))){
                newPhrase += ((lcPhrase.at(j) - 'a' - shiftKeyValues.at(count) + 26) % 26 + 'a');
                count++;
                if(count >= shiftKeyValues.size()){
                    count = 0;
                }
            }else{
                newPhrase+= lcPhrase.at(j);
            }
        }

        cout << newPhrase << "\niteration: " << i << "\n\n\n\n";

    }
    cout << endl;

    return 0;
}