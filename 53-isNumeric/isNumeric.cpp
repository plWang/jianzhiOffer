#include <iostream>
#include <string>

using namespace std;

// rules:
// 1. 只能出现数字，+，-，.，e, E这些字符
// 2. 除数字外其他字符不能连续出现， 小数点、e、E只能出现一次
// 3. 科学计数法，e或E之后必须有数字，且不能有小数点
// 4. 

// 例如，
// 字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
// 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3","1+23"都不是。

bool isNumeric(char* string) {
    bool sign = false; // if (+, -) appeared
    bool sci = false; // if (e, E) appeared
    bool decimal = false; // if . appeared
    bool head = true;
    bool num = false;
    bool require_num = false;
    while (*string != '\0') {
        if (*string == '+' || *string == '-') {

            if (head) {
                head = false;
            }
            else {
                if ((*(string-1) != 'e' && *(string-1) != 'E'))
                    return false;

                if (*(string-1) == '+' || *(string-1) == '-')
                    return false;
            }
            sign =true;
            string++;
        }
        else if (*string == 'e' || *string == 'E') {
            sci = true;
            require_num = true;
            string++;
            if (head) head=false;
        }
        else if (*string == '.') {
            if (sci || decimal) return false;
            decimal = true;
            string++;
            if (head) head=false;
        }
        else if (*string >= '0' && *string <= '9') {
            num = true;
            if (require_num) require_num=false;
            string++;
            if (head) head=false;
        }
        else return false;
    }

    if (num && !require_num) return true;
    else return false;
}

int main() {
    string str;
    cin >> str;
    char ss[str.size()+1];
    char* s = ss;
    for (int i=0; i<str.size(); i++) {
        *(s++) = str[i];
    }
    *s = '\0';
    if (isNumeric(ss))
        cout << "True" << endl;
    else 
        cout << "False" << endl;
    return 0;
}