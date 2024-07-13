#include <iostream>
#include <bitset>
using namespace std;
int main(){
    char ch = 'A';
    bitset<8> bits(ch);
    cout << stoi(bits.to_string(),nullptr,10);
}