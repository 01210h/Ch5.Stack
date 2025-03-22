#include<iostream>
#include<string>
using namespace std;

class ArrayStack {
private:
    int* elements;
    int capacity;
    int top_index;
public:
    ArrayStack(int N);
    int size();
    bool empty();
    void top();
    void push(int value);
    void pop();
    void pop_all();
};

int main() {
    int test;
    string text;
    cin >> test;
    int num, val;
    for (int i = 0; i < test; i++) {
        ArrayStack arr(10000);
        cin >> num;
        for (int j = 0; j < num; j++) {
            cin >> text;
            if (text == "size") {
                cout << arr.size() << "\n";
            }
            else if (text == "push") {
                cin >> val;
                arr.push(val);
            }
            else if (text == "pop") {
                arr.pop();
            }
            else if (text == "empty") {
                if (arr.empty()) {
                    cout << "1\n";
                }
                else {
                    cout << "0\n";
                }
            }
            else if (text == "pop_all") {
                arr.pop_all();
            }else if(text=="top"){
                arr.top();
            }
        }
    }
    return 0;
}
ArrayStack::ArrayStack(int N) {
    capacity = N;
    top_index = -1;
    elements = new int[N];
}
int ArrayStack::size() {
    return top_index + 1;
}
bool ArrayStack::empty() {
    return size() == 0;
}
void ArrayStack::top() {
    if (empty()) {
        cout << "-1\n";
        return;
    }
    cout << elements[top_index] << "\n";
}
void ArrayStack::push(int value) {
    if (size() >= capacity) {
        cout << "ArrayStack is Full\n";
        return;
    }
    top_index++;
    elements[top_index] = value;
}
void ArrayStack::pop() {
    if (empty()) {
        cout << "-1\n";
        return;
    }
    cout << elements[top_index] << "\n";
    --top_index;
}
void ArrayStack::pop_all() {
    if (empty()) {
        cout << "-1\n";
        return;
    }
    int sum{ 0 };
    for (int i = 0; i <= top_index; i++) {
        sum += elements[i];
    }
    cout << sum << "\n";
    top_index = -1;
}