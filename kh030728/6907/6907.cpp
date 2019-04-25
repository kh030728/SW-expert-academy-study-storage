#include <iostream>
#include <string>

using namespace std;
enum { SUF_NON, SUF_YOTTA, SUF_ZETTA, SUF_EXA, SUF_PETA, 
    SUF_TERA, SUF_GIGA, SUF_MEGA, SUF_KILO, SUF_HECTO, 
    SUF_DECA, SUF_CENTI, SUF_MILLI, SUF_MICRO, SUF_NANO, 
    SUF_PICO, SUF_FEMTO, SUF_ATO, SUF_ZEPTO, SUF_YOCTO, SUF_DECI };

static string num="";
string PrefixUnit="";
string SuffixUnit="";

void print(string s, int SUF, int PP)
{
    if(SUF == SUF_YOCTO) PP -= 24; else if(SUF == SUF_ZEPTO) PP -=21; else if(SUF == SUF_ATO) PP -=18;
        else if(SUF == SUF_FEMTO) PP -=15; else if(SUF == SUF_PICO) PP -=12; else if(SUF == SUF_NANO) PP -=9;
        else if(SUF == SUF_MICRO) PP -=6; else if(SUF == SUF_MILLI) PP -=3; else if(SUF == SUF_CENTI) PP -=2;
        else if(SUF == SUF_DECI) PP -=1; else if(SUF == SUF_DECA) PP +=1; else if(SUF == SUF_HECTO) PP +=2;
        else if(SUF == SUF_KILO) PP +=3; else if(SUF == SUF_MEGA) PP +=6; else if(SUF == SUF_GIGA) PP +=9;
        else if(SUF == SUF_TERA) PP +=12; else if(SUF == SUF_PETA) PP +=15; else if(SUF == SUF_EXA) PP +=18;
        else if(SUF == SUF_ZETTA) PP +=21; else if(SUF == SUF_YOTTA) PP +=24; else if(SUF == SUF_NON) PP +=0;
        cout << s << " * 10^" << PP <<" " << SuffixUnit << endl;
}

void exec(string _num, int SUF, int Pp = 0)
{
    int PP = Pp;
    int dotPos = 0;
    string result = _num;
    if( (dotPos = _num.find(".") ) == std::string::npos )
    { // 못찾은경우
        PP = _num.length()-1;
        string tmp = _num.substr(0,1);
        _num.erase(0,1);
        result =  tmp +"."+_num;
        exec(result,SUF,PP);
    }
    else if(dotPos +1 == _num.length())
    {//맨 끝에 "."이 있는 경우
        _num.erase(dotPos,1);
        print(_num,SUF,PP);
    }
    else if(dotPos != 1)
    { // 소수점이 존재하지만 2번째 자리에 없는 경우
        PP = PP + (dotPos -1);
        _num.erase(dotPos,1);
        string t = _num.substr(0,1);
        _num.erase(0,1);
        result = t +"."+_num;
        exec(result,SUF,PP);
    }
    else if((_num[2] == '0') && (_num[0] == '0') )
    { // "."이 있고 다음이 0인 경우
        _num.erase(2,1); // 소수점 뒤의 0 제거
        result = _num;
        PP--;
        exec(result,SUF,PP);
    }
    else if((_num[2] != '0') && (_num[0] == '0') )
    { // "."이 있고 다음이 0인 경우 0.12 같은경우
        _num.erase(0,2); // "0." 제거 
        string tmp = _num.substr(0,1); // 1 저장
        _num.erase(0,1); // 1 제거 현재 2
        result = tmp+"."+_num; // 1 + . + 2 --> 1.2
        PP--;
        exec(result,SUF,PP);
    }
    else
    {
        print(result, SUF, PP);
    }
}



int ReadInput()
{
    int SUF = SUF_NON;
     cin >> num;
     cin >> PrefixUnit;
    if( !(PrefixUnit == "yotta" || PrefixUnit =="zetta" || PrefixUnit == "exa" 
         || PrefixUnit =="peta" || PrefixUnit == "tera" || PrefixUnit == "giga"
         || PrefixUnit =="mega" || PrefixUnit == "kilo" ||PrefixUnit =="hecto" ||PrefixUnit == "deci"
         || PrefixUnit == "deca" || PrefixUnit == "centi" || PrefixUnit =="milli"
         || PrefixUnit == "micro" || PrefixUnit == "nano" || PrefixUnit == "pico"
         || PrefixUnit == "femto" || PrefixUnit == "ato" || PrefixUnit == "zepto"
         || PrefixUnit == "yocto"))
    {
        SuffixUnit = PrefixUnit;
        PrefixUnit = "";
        SUF = SUF_NON;
    }
    else 
    { 
        cin >> SuffixUnit;
        if(PrefixUnit == "yotta") SUF= SUF_YOTTA; else if(PrefixUnit == "zetta") SUF= SUF_ZETTA; else if(PrefixUnit == "exa") SUF= SUF_EXA;
        else if(PrefixUnit == "peta") SUF= SUF_PETA; else if(PrefixUnit == "tera") SUF= SUF_TERA; else if(PrefixUnit == "giga") SUF= SUF_GIGA;
        else if(PrefixUnit == "mega") SUF= SUF_MEGA; else if(PrefixUnit == "kilo") SUF= SUF_KILO; else if(PrefixUnit == "hecto") SUF= SUF_HECTO;
        else if(PrefixUnit == "deca") SUF= SUF_DECA; else if(PrefixUnit == "centi") SUF= SUF_CENTI; else if(PrefixUnit == "milli") SUF= SUF_MILLI;
        else if(PrefixUnit == "micro") SUF= SUF_MICRO; else if(PrefixUnit == "nano") SUF= SUF_NANO; else if(PrefixUnit == "pico") SUF= SUF_PICO;
        else if(PrefixUnit == "femto") SUF= SUF_FEMTO; else if(PrefixUnit == "ato") SUF= SUF_ATO; else if(PrefixUnit == "zepto") SUF= SUF_ZEPTO;
        else if(PrefixUnit == "yocto") SUF= SUF_YOCTO; else if(PrefixUnit == "deci") SUF = SUF_DECI;
        
    }
    return SUF;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    int power = 0;
    int SUF = SUF_NON;
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cout << "#"<< test_case << " ";
        SUF = ReadInput();
        exec(num,SUF);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}