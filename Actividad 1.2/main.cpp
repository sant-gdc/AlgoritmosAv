#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits>

using namespace std;

vector<int> merge(vector<int> vect1, vector<int> vect2){
    vector<int> output;
    int i = 0, j = 0;
    int vect1_size = vect1.size();
    int vect2_size = vect2.size();

    while(i < vect1_size and j < vect2_size){
        if(vect1[i] > vect2[j]){
            output.push_back(vect1[i]);
            i++;
        }else{
            output.push_back(vect2[j]);
            j++;
        }
    }

    while(i < vect1_size){
        output.push_back(vect1[i]);
        i++;
    }

    while(j < vect2_size){
        output.push_back(vect2[j]);
        j++;
    }

    return output;
}

vector<int> mergeSort(vector<int> vect){
    if(vect.size() == 1)
        return vect;
    
    int middle = vect.size() / 2;

    vector<int> left_side = vector<int>(vect.begin(), vect.begin() + middle);
    vector<int> right_side = vector<int>(vect.begin()+ middle, vect.end());

    vector<int> vect1 = mergeSort(left_side);
    vector<int> vect2 = mergeSort(right_side);
    
    return merge(vect1, vect2);
}

void coinInsertion(map<int, vector<int>> &calculated_changes, vector<int> new_calculated_change, int amount, int num_of_coins){
    
    auto current_value = calculated_changes.find(amount);

    if(current_value != calculated_changes.end()){
        int prev_num_coins = 0;
        for(auto& it: current_value->second){
            prev_num_coins += it;
        }
        if(prev_num_coins > num_of_coins){
            calculated_changes.insert_or_assign(amount, new_calculated_change);
        }
    }else{
        calculated_changes.insert_or_assign(amount, new_calculated_change);
    }
}

int getCoinsSum(int size, vector<int>new_calculated_change){
    int num_of_coins = 0;
    
    for(int i= 0; i<size; i++){
        num_of_coins += new_calculated_change[i];
    }

    return num_of_coins;
}

vector<int> getCoinChangeD_recursive(vector<int> coins, int amount,  map<int, vector<int>> &calculated_changes){

    if(amount == 0){
        vector<int> default_change(coins.size(), 0);
        return default_change;
    }

    if(amount < coins[coins.size()-1]){
        vector<int> default_change(coins.size(), -1);
        return default_change;
    }

    auto previous_calculated_change = calculated_changes.find(amount);

    if (previous_calculated_change != calculated_changes.end()){
        return previous_calculated_change->second;
    } 

    int best_solution = numeric_limits<int>::max();
    vector<int> new_calculated_change;

    for(int i = 0; i<coins.size(); i++){
        new_calculated_change = getCoinChangeD_recursive(coins, amount-coins[i], calculated_changes);
        
        int num_of_coins = getCoinsSum(coins.size(), new_calculated_change);

        if (0 <= num_of_coins && num_of_coins <= best_solution){
            best_solution = num_of_coins + 1;
            new_calculated_change[i] += 1; 
            
            coinInsertion(calculated_changes, new_calculated_change, amount, num_of_coins);

        } 
    }

    if (best_solution == numeric_limits<int>::max()){
        vector<int> default_change(coins.size(), -1);
        return default_change;
    }

    auto change = calculated_changes.find(amount);
    return change->second;
}


vector<int> getCoinChangeD(vector<int> coins, int amount){
    int minimun_change = coins[coins.size()-1];

    if(amount < minimun_change){
        vector<int> default_change(coins.size(), -1);
        return default_change;
    }

    map<int, vector<int>> calculated_changes;
    return getCoinChangeD_recursive(coins, amount, calculated_changes);
}

vector<int> getCoinChangeG(vector<int> coins, int amount){
    if(amount < coins[coins.size()-1]){
        vector<int> default_change(coins.size(), -1);
        return default_change;
    }

    int num_coins;
    vector<int> change(coins.size());

    for(int i = 0; i<coins.size(); i++){
        num_coins = 0;
        if (amount / coins[i] > 0){
            num_coins = amount / coins[i];
            amount = amount % coins[i];
            change[i] = num_coins;
        }
    }
    return change;
}

vector<int> createVector(int tam){
    vector<int> coins(tam);
    int x;

    for(int i = 0; i<tam; i++){
        cin >> x;
        coins[i] = x;
    }

    return coins;
}

void printChange(vector<int> coins, vector<int> change){
    for(int i; i < coins.size(); i++){
        cout << coins[i] << ": " << change[i] << endl;
    }
}


int main(){

    int tam;
    cin >> tam;
    vector<int> coins(tam);
    coins = createVector(tam);
    
    vector<int> coins_arranged = mergeSort(coins);
    
    int price;
    cin >> price;
    int payment;
    cin >> payment;

    int change = payment - price;

    vector<int> calculated_changesD = getCoinChangeD(coins_arranged, change);
    vector<int> calculated_changesG = getCoinChangeG(coins_arranged, change);
    
    cout << "Cambio calculado en programacion dinamica" << endl;
    printChange(coins_arranged, calculated_changesD);

    cout<< "Cambio calculado en algoritmo avaro" << endl;
    printChange(coins_arranged, calculated_changesG);

    return 0;
}