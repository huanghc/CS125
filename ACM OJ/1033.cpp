#include <iostream>
#include <stack>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;
struct Token
{	enum token_type{   
        NUMBER = 1, 
		OP=2
    }type_;
    long long num;
    string str;
    int fir;
};

vector<Token> tokens;
stack<long long> number_;
stack<Token> str_sta;
bool calc(Token str);
bool build();
int main(){ 
    string input;  
    getline(cin,input);
    string xpr = "";
    for (int i = 0; i < input.length(); ++i) {
        if(input[i]!=' ') xpr+=input[i];
    }
    Token tmp;
    for (int i = 0; i < xpr.length(); ++i){    
        switch(xpr[i]){
            case ' ':
                continue;
                break;
            case '+':
                tmp.type_ = Token::OP;
                tmp.str = "+";
                tmp.fir = 1;
                break;
            case '-':
                if(i>=1 and (xpr[i-1]==')' or isdigit(xpr[i-1])))
                {
                    tmp.type_ = Token::OP;
                    tmp.str = "-";
                    tmp.fir = 1;
                }else{ 
                    tmp.type_ = Token::OP;
                    tmp.str = "$";
                    tmp.fir = 10;
                }
                break;
            case '*':
                tmp.type_ = Token::OP;
                tmp.str = "*";
                tmp.fir = 2;
                break;
            case '/':
                tmp.type_ = Token::OP;
                tmp.str = "/";
                tmp.fir = 2;
                break;
            case '^'://
                tmp.type_ = Token::OP;
                tmp.str = "^";
                tmp.fir = 3;
                break;
            case '(':
                tmp.type_ = Token::OP;
                tmp.str = "(";
                tmp.fir = 0;
                break;
            case ')':
                tmp.type_ = Token::OP;
                tmp.str = ")";
                tmp.fir = 4;
                break;
            default: 
                string num = "";
                while( i < xpr.length() and isdigit(xpr[i]))
                    num += xpr[i++];
                --i;
                stringstream ss;
                ss<<num;
                ss>>tmp.num;
                tmp.type_ = Token::NUMBER;
                tmp.str = "";
                break;
        }
        tokens.push_back(tmp);
    }
    if(build()) cout<<number_.top()<<endl;   
    else cout<<"Error"<<endl;
}

bool calc(Token str){
    long long a , b;
    if((str.str=="$" and number_.empty()) or (str.str!="$" and number_.size()<2))
        return false;
    if(str.str == "$"){
        a = number_.top();number_.pop();
        number_.push(-1*a);
    }else if(str.str=="+"){
        a = number_.top();number_.pop();
        b = number_.top();number_.pop();
        number_.push(b+a);
    }else if(str.str=="-"){
        a = number_.top();number_.pop();
        b = number_.top();number_.pop();
        number_.push(b-a);
    }else if(str.str=="*"){
        a = number_.top();number_.pop();
        b = number_.top();number_.pop();
        number_.push(b*a);
    }else if(str.str=="/"){
        a = number_.top();number_.pop();
        b = number_.top();number_.pop();
        if(a==0)
            return false;
        number_.push(b/a);
    }else if(str.str=="^"){
      
        a = number_.top();number_.pop();
        b = number_.top();number_.pop();
        number_.push((long long)pow(b, a));
    }
    return true;
}

bool build(){
    for (int i = 0; i < tokens.size() ; ++i) {
        if(tokens[i].type_ == Token::OP){
            if(tokens[i].str=="(") str_sta.push(tokens[i]);                
            else if(tokens[i].str==")"){                
                while( !str_sta.empty() and str_sta.top().str != "("){
                    if(!calc(str_sta.top()))   return false;
                    str_sta.pop();
                }                
                if(str_sta.empty()) return false;
                if(str_sta.top().str == "(") str_sta.pop();
            }else{                 
                if(str_sta.empty()) str_sta.push(tokens[i]);
                else{
                    int top_pr = str_sta.top().fir;
                    int cur_pr = tokens[i].fir;
                    if( cur_pr > top_pr or (tokens[i].str =="^" and str_sta.top().str=="^")){
                        str_sta.push(tokens[i]);
                    }else{
                        while(cur_pr <= top_pr){
                            if(!calc(str_sta.top()))   return false;
                            str_sta.pop();
                            if(str_sta.empty())
                                break;
                            top_pr = str_sta.top().fir;
                        }                       
                        str_sta.push(tokens[i]);
                    }
                }               
            }
        }else if(tokens[i].type_==Token::NUMBER) number_.push(tokens[i].num);
    }

    while (!str_sta.empty()){
        if(str_sta.top().str=="(")
            return false;
        if(!calc(str_sta.top()))
            return false;
        str_sta.pop();
    }
    return (number_.size()==1);
}


