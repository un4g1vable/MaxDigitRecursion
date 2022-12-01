#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    int digit,degree;
    cout << "\n" "Введите число:" << endl;
    cin >> digit;
    cout << "\n" "Введите необходимую систему:" << endl;
    cin >> degree;

    vector <int> converted;
    while (digit>0){
        converted.push_back(digit%degree);
        digit = digit / degree;
    }
    // ^ Записали остатки от деления на [систему счисления] в массив
    reverse(converted.begin(),converted.end());
    // ^ Развернули массив в правильное направление

    string convertedstr;
    string Numbers[] = {"0","1","2","3","4","5","6","7","8","9"};
    string Letters[] = {"A","B","C","D","E","F"};

    for(int i = 0; i < converted.size(); i++){
        if(converted[i] < 10)
            convertedstr += Numbers[converted[i]];
        else
            convertedstr += Letters[converted[i]%10];
    }
    // ^ Поскольку остаток может оказаться >= 10, нам необходимо перевести его в эквивалентное 
    // буквенное значение. Поэтому мы записываем итоговое значение с учётом этого в новую строку

    cout << "\n" "Число в системе счисления " << *&degree << ": " "\n" << convertedstr << endl;


}