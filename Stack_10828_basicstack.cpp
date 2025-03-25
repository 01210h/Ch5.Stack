
#include<iostream>
#include<string>
using namespace std;
class Stack;
class Node{
private:
    Node* next;
    int data;
public:
    Node(int d):data(d),next(nullptr){}
    friend class Stack;
};

class Stack{
private:
    Node* top_node;
    int N;
public:
    Stack();
    void push(int X);
    void pop();
    void size();
    bool emp();
    void top();
    void empty();
};
int main(){
    int n,num;
    string str;
    cin>>n;
    Stack stk;
    for(int i=0;i<n;i++) {
        cin >> str;
        if (str == "push") {
            cin >> num;
            stk.push(num);
        } else if (str == "top") {
            stk.top();
        } else if (str == "size") {
            stk.size();
        } else if (str == "pop") {
            stk.pop();
        } else if (str == "empty") {
            stk.empty();
        }
    }
    return 0;
}
Stack::Stack():N(0),top_node(nullptr){}
void Stack::push(int X){
    Node* new_node=new Node(X);//새로운 노드 생성
    new_node->next=top_node;//새로운 노드의 넥스트 포인터에 탑노드 연결.
    top_node=new_node;//탑노드에 뉴노드 값 넣기.(스택은 Last in First out)
    N++;
}
void Stack::pop(){
    if(emp()){
        cout<<"-1\n";
        return;
    }
    Node* erase_node=top_node;//지우려는 노드 주소 저장
    top_node=top_node->next;//탑노드는 이후에도 쓰이므로 자리 옮기기
    cout<<erase_node->data<<"\n";
    delete erase_node;//노드 지우기
    N--;
}
void Stack::empty(){
    if(emp()){
        cout<<"1\n";
    }else{
        cout<<"0\n";
    }
}
void Stack::size(){cout<<N<<"\n";}
bool Stack::emp(){if(N==0){return true;}else{return false;}}
void Stack::top(){
    if(emp()){
        cout<<"-1\n";
        return;
    }
    cout<<top_node->data<<"\n";
}
 

