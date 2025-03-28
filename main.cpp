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
    vector<char> alphaRef = {'A' , 'B' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' ,'K' ,'L' , 'M' , 'N' , 'O' , 'P' , 'Q' , 'R' , 
                            'S' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y' , 'Z'};
    int count;

    for(char letter : phrase){
        if(isalpha(letter)){
            ucPhrase+=letter;
        }
    }

    //Frequency analysis
    for(int i = 0; i < ucPhrase.size(); i++){
        for(int j = 0; j < alphaRef.size(); j++){
            if(ucPhrase.at(i) == alphaRef.at(j)){
                frequency.at(j) = frequency.at(j) + 1;
            }
        }
    }

    cout << "\n\nHere is the Frequency Analysis : " << endl;
    for(int i = 0; i < alphaRef.size(); i++){
        cout << alphaRef.at(i) << ": " << frequency.at(i) << "   "; 
    }
   
    //Decrypting
    for(int i = 0; i < keywords.size(); i++){
        shiftKeyValues.resize(keywords.at(i).size());
        count = 0;
        newPhrase = "";

        //Getting Shift Key Value
        for(int j = 0; j < keywords.at(i).size(); j++){
            shiftKeyValues.at(j) = toupper(keywords.at(i).at(j)) - 'A';//  0-25
        }

        //Adding Decrypted letter to new phrase
        for(int j = 0; j < ucPhrase.size(); j++){
            newPhrase.push_back((char)(((ucPhrase.at(j) - 'A' - shiftKeyValues.at(count) + 26) % 26) + 'A')); // This is just formula to decipher
            count++;
            if(count >= shiftKeyValues.size()){
                count = 0;
            }
        }
        //Outputting found keyword
        if(keywords.at(i) == "brick"){
            cout << endl;
            cout << "\nFound Keyword and Decrypted Phrase: " << endl;
            cout << keywords.at(i) << endl;
            cout << newPhrase << "\niteration: " << i << "\n\n\n\n";
        }

    }
    cout << endl;

    return 0;
}

// second part 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Get message from user
    cout << "Enter your message: ";
    string message;
    getline(cin, message);
    
    // Clean the message (keep only letters)
    string clean;
    for(int i = 0; i < message.size(); i++) {
        if((message[i] >= 'A' && message[i] <= 'Z') || 
           (message[i] >= 'a' && message[i] <= 'z')) {
            clean += toupper(message[i]);
        }
    }
    
    // Create a key from the messsage
    int num = 0;
    for(int i = 0; i < clean.size(); i++) {
        num += clean[i];
    }
    
    string key;
    for(int i = 0; i < 5; i++) {
        num = (num * 6 + 3) % 100;
        key += 'A' + (num % 26);
    }
    
    // Encrypt the message
    string encrypted;
    for(int i = 0; i < clean.size(); i++) {
        char c = clean[i];
        char k = key[i % key.size()];
        char e = ((c - 'A' + k - 'A') % 26) + 'A';
        encrypted += e;
    }
    
    // Print encrypted message in 5-letter groups
    cout << "\nEncrypted message:\n";
    
    for(int i = 0; i < encrypted.size(); i++) {
        if(i > 0 & i % 5 == 0) cout << " ";
        cout << encrypted[i];
    }
    
    // Printt the key
    cout << "\n\nKey: " << key << endl;
    
    return 0;
}

// Final Code 

#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

int main() {
    int choice;
    cout << "Choose an option:" << endl;;
    cout << "1. Decrypt (Type 1)" << endl;;
    cout << "2. Encrypt (Part 2)" << endl;;
    cout << "Enter choice (1 or 2): ";
    cin >> choice;
    // ChatGPT for this line directly under
    cin.ignore(); 

    if (choice == 1) {
        //The words in the keys.txt are shift words
        //Bob decripts the message by shifting 
        //Need to determine the shift word length, not the word itself
        //The keyword is Brick

        string phrase = "BEBCB DKQEK TYINV CVCUO EWWTZ FRKGP VCXWB QFAGC PETAD IVZGC IRTNL FGZQR JSQVO EZVVO SRTKK BEGOO BJCTO TFNCW JCQVK SPVCD VIMUE DYIUD IVMUD BSTKC IDMPD PWUKV JKITI CRAGC BELHY SKQHS DRBKY OJBJO DRZTI JEOQE UFNOS MZBCB ZDIPO VMMTC BJEGV MRAVR FKMUD JEOQP BEGVI QVWHG FRXQX TEWPO XTTCS NFZGX MRZIO NVVVY GRVGH JJBKX HTTCS NKWVO SIQVY SZINC PMMTO JXVVI JEIPD BIKVS DRAJK MCJGK TJMTD FUEJS MVBJO QIMUO OKBTO BKGKC JENQB DV";
        vector<string> keywords = {"savory", "weary","colorful" ,"ducks" ,"time" ,"slimy","travel","aware","dry","troubled","queue","expect","splendid","unsuitable","workable","middle","evanescent","zephyr","brave","wind","apparatus","sand","complete","disappear","invincible","sedate","test","rustic","steady","rainstorm","foolish","gabby","cherry","daily","heal","rose","boat","reward","trust","tremble","discreet","enormous","settle","fit","vessel","parched","chickens","desire","practice","terrific","imminent","fuzzy","debt","medical","industry","run","tow","raise","juice","plant","range","unusual","breakable","quiet","early","mother","tomatoes","woebegone","psychedelic","shocking","elated","deranged","bouncy","wood","three","deceive","flavor","blind","brick","spray","fretful","hanging","hallowed","hurry"
                                };
        string newPhrase , ucPhrase;
        vector<int> shiftKeyValues;
        vector<int> frequency(26);
        vector<char> alphaRef = {'A' , 'B' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' ,'K' ,'L' , 'M' , 'N' , 'O' , 'P' , 'Q' , 'R' , 
                                'S' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y' , 'Z'};
        int count;

        for(char letter : phrase){
            if(isalpha(letter)){
                ucPhrase+=letter;
            }
        }

        //Frequency analysis
        for(int i = 0; i < ucPhrase.size(); i++){
            for(int j = 0; j < alphaRef.size(); j++){
                if(ucPhrase.at(i) == alphaRef.at(j)){
                    frequency.at(j) = frequency.at(j) + 1;
                }
            }
        }

        cout << "\n\nHere is the Frequency Analysis : " << endl;
        for(int i = 0; i < alphaRef.size(); i++){
            cout << alphaRef.at(i) << ": " << frequency.at(i) << "   "; 
        }

        //Decrypting
        for(int i = 0; i < keywords.size(); i++){
            shiftKeyValues.resize(keywords.at(i).size());
            count = 0;
            newPhrase = "";

            //Getting Shift Key Value
            for(int j = 0; j < keywords.at(i).size(); j++){
                shiftKeyValues.at(j) = toupper(keywords.at(i).at(j)) - 'A';//  0-25
            }

            //Adding Decrypted letter to new phrase
            for(int j = 0; j < ucPhrase.size(); j++){
                newPhrase.push_back((char)(((ucPhrase.at(j) - 'A' - shiftKeyValues.at(count) + 26) % 26) + 'A')); // This is just formula to decipher
                count++;
                if(count >= shiftKeyValues.size()){
                    count = 0;
                }
            }
            //Outputting found keyword
            if(keywords.at(i) == "brick"){
                cout << endl;
                cout << "\nFound Keyword and Decrypted Phrase: " << endl;
                cout << keywords.at(i) << endl;
                cout << newPhrase << "\niteration: " << i << "\n\n\n\n";
            }

        }
        cout << endl;

        return 0;
       
    }
    else if (choice == 2) {
            // Get message from user
            cout << "Enter your message: ";
            string message;
            getline(cin, message);

            // Clean the message (keep only letters)
            string clean;
            for(int i = 0; i < message.size(); i++) {
                if((message[i] >= 'A' && message[i] <= 'Z') || 
                   (message[i] >= 'a' && message[i] <= 'z')) {
                    clean += toupper(message[i]);
                }
            }

            // Create a key from the messsage
            int num = 0;
            for(int i = 0; i < clean.size(); i++) {
                num += clean[i];
            }

            string key;
            for(int i = 0; i < 5; i++) {
                num = (num * 6 + 3) % 100;
                key += 'A' + (num % 26);
            }

            // Encrypt the message
            string encrypted;
            for(int i = 0; i < clean.size(); i++) {
                char c = clean[i];
                char k = key[i % key.size()];
                char e = ((c - 'A' + k - 'A') % 26) + 'A';
                encrypted += e;
            }

            // Print encrypted message in 5-letter groups
            cout << "\nEncrypted message:\n";

            for(int i = 0; i < encrypted.size(); i++) {
                if(i > 0 & i % 5 == 0) cout << " ";
                cout << encrypted[i];
            }

            // Printt the key
            cout << "\n\nKey: " << key << endl;

            return 0;
        }

    return 0;
}
