//Santiago Gonzalez de Cosio Romero - A01640329
//Brandon Josue Magana Mendoza -
//Ruy Guzman Camacho - 

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

string getText(string path){
  
  ifstream lector(path);
  string line;
  string text = "";
  while (getline(lector, line)){
            text += line;
        }
        lector.close();

  return text;
}

vector<int> getPreSufVec(string substring){
  
  int len = 0;
  vector<int> preSuf(substring.length());

  int i = 1;
  while(i < substring.length()){
    
    if (substring[i] == substring[len]) {
            len++;
            preSuf[i] = len;
            i++;
        }
        else 
        {
            if (len != 0) {
                len = substring[len - 1];
            }
            else 
            {
                preSuf[i] = 0;
                i++;
            }
        }
  }

  return preSuf;
}

void KMPAlgorithm(string substring, string text)
{
    int x = substring.length();
    int y = text.length();
 
    vector<int> preSuf(x);

    preSuf = getPreSufVec(substring);
 
    int i = 0;
    int j = 0; 
    bool found; 
    int place;
    while ((y - i) >= (x - j)) {
        if (substring[j] == text[i]) {
            j++;
            i++;
        }
 
        if (j == x) {
            //printf("Found pattern at index %d ", i - j);
            place = i -j;
            found = true;
            j = preSuf[j - 1];
        }
 
        else if (i < y && substring[j] != text[i]) {
            if (j != 0)
                j = preSuf[j - 1];
            else
                i = i + 1;
        }
    }
    if (found == true) {
      cout<<"True"<<" "<<place<<endl;
    }
    else{
      cout<<"False"<<endl;
    }
    
}

void Manacher(string text){
    int R = -1;
    int P = -1;
    

    vector<int> pali_count(text.size() +2);
   
    for(int i = 0; i <= text.size(); i++){
        if( i <= R){
            pali_count[i] = min(pali_count[2*P - i], R-1);
        }
        else{
            pali_count[i] = 0;
        }
        while(text[i-pali_count[i]-1] == text[i+pali_count[i]+1]){
            pali_count[i] = pali_count[i] +1;
        }
        if(i + pali_count[i] > R){
            R = i + pali_count[i];
            P = i;
        }
    }

    int longest_pali = *max_element(pali_count.begin(), pali_count.end());
    int lpIndex = max_element(pali_count.begin(), pali_count.end()) - pali_count.begin();
    
    cout<<lpIndex - longest_pali<<" "<<lpIndex + longest_pali<<endl;
}

int main() {
  //KMP para parte 1
  string mcode1 = getText("mcode1.txt");
  string mcode2 = getText("mcode2.txt");
  string mcode3 = getText("mcode3.txt");
  string tr1 = getText("transmission1.txt");
  string tr2 = getText("transmission2.txt");

  cout<<"Parte 1 - Presencia de codigo maligno dentro de la transmision"<<endl;
  cout<<"transmision 1"<<endl;
  KMPAlgorithm(mcode1, tr1);
  KMPAlgorithm(mcode2, tr1);
  KMPAlgorithm(mcode3, tr1);

  cout<<"transmision 2"<<endl;
  KMPAlgorithm(mcode1, tr2);
  KMPAlgorithm(mcode2, tr2);
  KMPAlgorithm(mcode3, tr2);
  cout<<"------------------------------------------------------------------"<<endl;
  //Manacher para parte 2
  cout<<"Parte 2 - Palindromo mas largo dentro de ambas transmisiones"<<endl;
  cout<<"transmision 1"<<endl;
  Manacher(tr1);
  cout<<"transmision 2"<<endl;
  Manacher(tr2);

  cout<<"------------------------------------------------------------------"<<endl;
  
  //LC substring parte 3


  return 0;
}