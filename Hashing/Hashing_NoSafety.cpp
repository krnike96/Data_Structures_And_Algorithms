#include <iostream>
#include <vector>
#include <utility>
using namespace std;

size_t size;
vector<pair<int,string>> hashTable[size];
int hashedIndex(int key){
    return key % size; 
}

void insert(int key, string val){
    int i = hashedIndex(key);
    hashTable[i] = {key,val};
}

string search(int key){
    int i = hashedIndex(key);
    if(hashTable[i].first == key){
        return hashTable[i].second;
    }
    return "Key is not Found!";
}

void display(){
    for(auto keyVal : hashTable){
        cout<<"["<<keyVal.first<<"-"<<keyVal.second<<"]"<<endl;
    }
}

int main(){

    return 0;
}