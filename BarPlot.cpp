/* 
 * File:   BarPlot.cpp
 * Author: hell
 * 
 * Created on 3. červen 2016, 17:59
 */

#include "BarPlot.h"

BarPlot::BarPlot() {//dummy data
    for(int i = 1; i < 6; i ++){
        TCathegory tmp("sth", i);
        cathegories.push_back(tmp);
        
    }
}

BarPlot::BarPlot(const BarPlot& orig) {
}

BarPlot::~BarPlot() {
}

void BarPlot::print(ofstream& out){
    /**for every row **/
    for(int i = 5; i >= 0; i--){  //dummy max val = 5
        
        cout << i << " | ";
         /**for every column **/
        for(int j = cathegories.size()-1; j >= 0; j-- ){
            if(cathegories[j].rank == i){
                cout << " ____ ";
            } 
            else if(cathegories[j].rank > i){
                cout << "|    |";
            } 
            else{
                cout << "      ";
            }
            cout << "  ";
        }
        cout << endl;
    }
    for(int i = (cathegories.size()-1) * 10 + 3; i > 0; i--)
        cout << "-";
    cout << endl;
}