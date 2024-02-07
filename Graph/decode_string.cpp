//https://leetcode.com/explore/interview/card/google/61/trees-and-graphs/3073/

class Solution {
public:
    enum State{
        ReadingEncoded,
        ReadingRegular,
        ReadingEnded
    };
    
    int toDigit(char c){
        return ((int)c) - '0';
    }
    bool isDigit(char c){
        return c <='9' && c>='0';
    }
    struct DecoderProps{
        State state = ReadingRegular;
        int strPointer = 0;
        string currentSection = "";
        int repeatTime = 0;
        stack<char> bracketsStack;
        bool needsRedecode = false;
        int numberOfBracketsInSection = 0;
    };
    
    void processNumberInRegularText(string s,char currentChar, DecoderProps& props, vector<string>& res){
        props.repeatTime = toDigit(currentChar);
        while(isDigit(s[props.strPointer])){
            currentChar = s[props.strPointer++];
            props.repeatTime = props.repeatTime*10 + toDigit(currentChar);
        }
        props.state = ReadingEncoded;
        if(props.currentSection.length()> 0){
            res.push_back(props.currentSection);
            props.currentSection = "";
        }
    }
    void processNextRegularChar(string s, DecoderProps& props,  vector<string>& res){
        
        char currentChar = s[props.strPointer++];
        if(isDigit(currentChar))
            processNumberInRegularText(s, currentChar, props, res);
        
        else
            props.currentSection+=currentChar;
        
    }
    
    
    void processNextEncodedChar(string s, DecoderProps& props,  vector<string>& res){
        
        char currentChar = s[props.strPointer++];
        if(currentChar == '['){
            props.bracketsStack.push(currentChar);
            props.numberOfBracketsInSection++;
        }
        else if(currentChar == ']')
            props.bracketsStack.pop();
        props.currentSection+=currentChar;
                
        if(props.bracketsStack.empty()){
            props.currentSection = props.currentSection.substr(1,props.currentSection.length() - 2);
            string sectionRepeated = "";
            for(int i = 0; i < props.repeatTime; i++){
                sectionRepeated+=props.currentSection;
            }
            res.push_back(sectionRepeated);
            props.currentSection ="";
            props.state = ReadingRegular;
            props.repeatTime = 0;
            if(props.numberOfBracketsInSection > 1){
                props.needsRedecode = true;
            }
            props.numberOfBracketsInSection = 0;
        }
        
    }
    string decodeStringStep(string s, bool& isDecodedResult){
        vector<string> decodedSections;
        DecoderProps props;
        
        while(props.strPointer< s.length()){
            if(props.state == ReadingRegular)
                processNextRegularChar(s, props, decodedSections);
            
            else if(props.state == ReadingEncoded)
                processNextEncodedChar(s, props, decodedSections);
                
        }
        
        
        if(props.currentSection.length()> 0)
                decodedSections.push_back(props.currentSection);
                       
        
        isDecodedResult = !props.needsRedecode;
        
        string decodedStr = "";
        for(string section : decodedSections)
            decodedStr+=section;
        
        return decodedStr;
        
    }
    string decodeString(string s) {
        
        
        
        bool isDecoded = false;
        string decodedString = s;
        while(!isDecoded)
            decodedString = decodeStringStep(decodedString, isDecoded);
        
        return decodedString;
       
    }
};