//
//  main.cpp
//  egzaminas
//
//  Created by Dovydas Krištupas on 23/12/2024.
//

#include <iostream>
#include "header.h"



unordered_map<string, int> skaitymas_is_failo(){
    
    std::unordered_map<string, int> hm;
    string failo_pav = string("/Users/dovydaskr/Documents/C++/egzaminas/egzaminas/input.txt");
    string zodis;
    
    ifstream failas;
    failas.open(failo_pav);
    
    if(!failas){
        throw runtime_error("Problemos su failo atidarymu");
    }
    
    while(failas >> zodis){
        for (char &ch : zodis) {
            if (ispunct(ch)) {
                ch = ' ';
            }
        }
        
        transform(zodis.begin(), zodis.end(), zodis.begin(), ::tolower);
        
        hm[zodis]++;
        
        
    }
    
    failas.close();
    
    
    
    return hm;
}




int main(int argc, const char * argv[]) {
    
    
    std::unordered_map<string, int> hm = skaitymas_is_failo();
    
    
    for (const auto &x : hm) {
            cout << x.first << ": " << x.second << endl;
        }
    
    
    

    return 0;
}
