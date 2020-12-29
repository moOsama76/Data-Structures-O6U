                                                          // ONLY SINGLE DIGIT NUMBERS
#include <bits/stdc++.h>
using namespace std;

bool isDigit(char c){
    if(c >= '0' && c <= '9')
        return 1;

    return 0;
}

int toInt(char c){
    return c - '0';
}

int evaluate(int n1, int n2, char operatoor){
    if(operatoor == '*')
        return n1 * n2;
    else if(operatoor == '/')
        return n1 / n2;
    else if(operatoor == '+')
        return n1 + n2;
    else if(operatoor == '-')
        return n1 - n2;
}

int main()
{
    string s;
    getline(cin, s);
    stack <int> digits; // Built in stack, replace it with your implemetation if you want
    int res = 0;

    for(int i = 0; i < s.size(); i++){
        int x = 0, y = 0;
        if(isDigit(s[i])){
            digits.push(toInt(s[i]));
        } else if(s[i] != ' '){
            y = digits.top();
            digits.pop();
            x = digits.top();
            digits.pop();
            res = evaluate(x, y, s[i]);
            digits.push(evaluate(x, y, s[i]));
            cout << res << "\n";
        }
    }
    cout << res;
}
