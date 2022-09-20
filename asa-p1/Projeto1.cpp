#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include <unordered_map>
using namespace std;
using namespace std::chrono;

unordered_map<int, int> map;

void problema_1(vector<int> vec){
    int vec1 ,array1, array2, max=1, n_max=0;
    int len = vec.size();
    int arr_len[len];
    int arr_num[len];
    arr_len[0] = 1;
    arr_num[0] = 1;
    for(int i = 1; i < len; i++){
        vec1=vec[i];
        array1=1;
        array2=1;
        for(int j = 0; j < i; j++){
            if(vec1 > vec[j] && array1 <= arr_len[j]){
                array1 = arr_len[j] + 1;
                array2 = arr_num[j];
            }
            else if(arr_len[j] + 1 == array1 && vec1 > vec[j])
                array2 += arr_num[j];
        }
        arr_len[i]=array1;
        arr_num[i]=array2;
        if(array1 > max)
            max = array1;
    }

    for(int i = 0; i < len; i++){
        if(arr_len[i] == max)
            n_max += arr_num[i];
    }
    cout << max << " " << n_max << "\n";
}



void problema_2(vector<int> vec1, vector<int> vec2){
    int max = 0;
    int len1 = vec1.size();
    int len2 = vec2.size();
    int aux_array[len1];
    for(int i=0; i<len1; i++)
        aux_array[i] = 0;

    for(int i=0; i<len2; i++){
        int current = 0;
        for(int j=0; j<len1; j++){
            if(vec2[i] == vec1[j] && current >= aux_array[j]){
                aux_array[j] = current+1;
                if(aux_array[j] > max){
                    max = aux_array[j];
                }
            }
            else if(vec2[i] > vec1[j] && aux_array[j] > current){
                    current = aux_array[j];
            }
        }
    }
    cout << max << "\n";
    
}

vector<int> read_input_array(){
    char i;
    int j;
    vector<int> vec;
    cin >> j;
    vec.push_back(j);
    while((i = cin.get()) != '\n' && i != '\t' && i != EOF){
        cin >> j;
        vec.push_back(j);
    }
    return vec;
}


vector<int> read_and_insert(){
    char i;
    int k;
    vector<int> vec;
    cin >> k;
    vec.push_back(k);
    map[k]=1; 
    while((i = cin.get()) != '\n' && i != '\t' && i != EOF){
        cin >> k;
        vec.push_back(k);
        map[k]=1;
    }
    return vec; 
}

vector<int> read_and_process(){
    char i;
    int k;
    vector<int> vec;
    cin >> k;
    if(map.find(k) != map.end())
        vec.push_back(k);
    while((i = cin.get()) != '\n' && i != '\t' && i != EOF){
        cin >> k;
        if(map.find(k) != map.end())
            vec.push_back(k);
        
    }
    return vec;
}


int main(){
    auto start = high_resolution_clock::now();
    int problem;
    cin >> problem;
    cin.get();
    if(problem == 1){
        vector<int> vec = read_input_array();
        problema_1(vec);
    }
    else if(problem == 2){
        vector<int> vec2 = read_and_insert();
        vector<int> vec1 = read_and_process();
        problema_2(vec1, vec2);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count();
    return 0;

}
