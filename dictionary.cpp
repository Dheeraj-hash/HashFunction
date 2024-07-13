#include "dictionary.h"
#include "cmath"
#include "cstring"
#include<bitset>
using namespace std;

Dictionary::Dictionary(){
    A = new Entry[DICT_SIZE];
    for(int i=0;i<DICT_SIZE;i++){
        A[i].value=0;
    }
};


int Dictionary::hashValue(char key[]){
    double hashvalue;
    int p=31;
    int index=0;
    double A = (sqrt(5)-1)/2;
    while(key[index]!=0){   
        char ch = key[index];
        bitset<8> binary(ch);
        hashvalue+=stoi(binary.to_string(),nullptr,10)*pow(p,index);
        // cout << hashvalue << endl;
        index++;
    }
    hashvalue = hashvalue*A - floor(hashvalue*A);
    hashvalue= floor(DICT_SIZE*hashvalue);
    return hashvalue;
}

int Dictionary::findFreeIndex(char key[]){
    int start = hashValue(key);
    int index=start;
    if(A[index].key==NULL){return index;}
    index++;index%=DICT_SIZE;
    while(index!=(start)){
        if(A[index].key==NULL){return index;}
        index++;index%=DICT_SIZE;
    }
    return -1;
}

struct Entry* Dictionary::get(char key[]){
    int start = hashValue(key);
    int index=start;
    // cout << index << endl;
    
    while(A[index].key!=NULL || A[index].value==-2){
        
        if(A[index].key==NULL){index++;index%=DICT_SIZE;continue;}
        if(strcmp(A[index].key,key)==0){return A+index;}
        index++;index%=DICT_SIZE;
        if(index==(start)){break;}
    }
    return NULL;
    
}

bool Dictionary::put(Entry e) {
    int pos=findFreeIndex(e.key);
    if(pos==-1){return false;}
    A[pos].key=e.key;A[pos].value = e.value;
    return true;
    // Dummy return
}

bool Dictionary::remove(char key[]){
    if(get(key)==NULL){return false;}
    Entry* pos = get(key);
    pos->key = NULL; pos->value = -2;
    return true; // Dummy return
}
