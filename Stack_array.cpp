#include <iostream>
#include <string>
using namespace std;

class Array{
private:
    char* str;
    string s;
    int size;
    int index;
public:
    Array(string,int);
    bool game();
    ~Array();
};

int main() {
    int n,s;
    string st;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>st;
        s=st.length();
        Array arr(st,s);
        if(arr.game()){
            if(i!=n-1) {
                cout << "Yes\n";
            }else{
                cout<<"Yes";
            }
        }else{
            if(i!=n-1) {
                cout << "No\n";
            }else{
                cout<<"No";
            }
        }
    }
    return 0;
}
Array::Array(string STR,int si):s(STR),size(si),index(0){}
bool Array::game(){
    int open{0};
    str=new char[51];//char 배열 생성. 단, null 까지 포함하여 51로 설정
    for(int i=0;i<size;i++){//string 사이즈만큼 반복문 돌리기
        if(s[i]=='(') {//string에 열린괄호가 들어오면
            str[index] = s[i];//배열에 저장
            index++;//인덱스 크기 늘려주기(한 칸)
            open++;
        }else if(s[i]==')'&&open>0){
            index--;//닫힌 괄호가 들어오면 인덱스 크기 줄이기(한 칸)
            open--;
        }else{
            return false;
        }
    }
    if(index==0){
        return true;
    }else{
        return false;
    }
}
Array::~Array(){
    delete [] str;
}