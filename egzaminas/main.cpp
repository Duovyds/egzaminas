#include <iostream>
#include "header.h"

// Pirma uzduotis
// ---------------------------------------------------------------------------------------------------------------

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



void tikrinimas(unordered_map<string, int > &hm) {
    
    for (auto it = hm.begin(); it != hm.end(); ) {
            if (it->second <= 1) {
                it = hm.erase(it);
            } else {
                ++it;
            }
        }
    
    
}



void irasymas_i_faila(unordered_map<string, int > &hm, string pav){
    
    string failo_pav = string("/Users/dovydaskr/Documents/C++/egzaminas/egzaminas/" + pav + ".txt");
    ofstream rez;
    rez.open(failo_pav);
    
    for (const auto &x : hm) {
            rez << x.first << ": " << x.second << endl;
        }
    rez.close();
}

// ---------------------------------------------------------------------------------------------------------------



// Antra uzduotis
// ---------------------------------------------------------------------------------------------------------------

unordered_map<string, vector<int>> cross_reference_lentele(unordered_map<string, int > &hm){
    
    std::unordered_map<string, vector<int>> hm2;
    string failo_pav = string("/Users/dovydaskr/Documents/C++/egzaminas/egzaminas/input.txt");
    ifstream failas;
    failas.open(failo_pav);
    string eilute;
    string zodis;
    int eilutes_counter = 0;
    vector<string> zodziu_eilute;
    
    if (!failas) {
        throw runtime_error("Problemos su failo atidarymu");
    }
    
    while (getline(failas, eilute)){
        stringstream stream(eilute);
        eilutes_counter++;
        zodziu_eilute.clear();
        
        while(stream >> zodis){
            zodziu_eilute.push_back(zodis);
            
            if (hm2.find(zodis) == hm2.end()) {
                // If the word is not already in the map, initialize it with the current line
                hm2[zodis] = {eilutes_counter};
            } else {
                // If the word is already in the map, ensure the line number is not duplicated
                if (hm2[zodis].back() != eilutes_counter) {
                    hm2[zodis].push_back(eilutes_counter);
                }
            }
        }
    }
    failas.close();
    
    string failo_pav2 = string("/Users/dovydaskr/Documents/C++/egzaminas/egzaminas/rez2.txt");
    ofstream rez;
    rez.open(failo_pav2);
    
    for (const auto& pair : hm2) {
            rez << pair.first << ": ";
            for (int line : pair.second) {
                rez << line << " ";
            }
            rez << endl;
        }
    
    return hm2;
};



int main(int argc, const char * argv[]) {
    
    
    std::unordered_map<string, int> hm = skaitymas_is_failo();
    tikrinimas(hm);
    irasymas_i_faila(hm, "rez1");
    std::unordered_map<string, vector<int>> hm2 = cross_reference_lentele(hm);
    
    
    
    

    return 0;
}
