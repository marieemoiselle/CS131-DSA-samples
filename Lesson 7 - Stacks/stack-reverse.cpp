#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    string input;
    cout<<"Enter a string: "; 
    getline(cin, input);
    
    stack<char>stack;
    
    for (char ch : input){
        stack.push(ch);
        cout<<"Top of stack: " <<stack.top() <<"\n";
    }
        string reversed;
        
        while (!stack.empty()){
            reversed += stack.top();
            stack.pop();
        }
        
        cout<<"Reversed string: " <<reversed <<"\n";
        
    return 0;
}