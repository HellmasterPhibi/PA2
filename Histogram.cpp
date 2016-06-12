/* 
 * File:   Histogram.cpp
 * Author: hell
 * 
 * Created on 9. červen 2016, 14:26
 */

#include "Histogram.h"

Histogram::Histogram(ifstream& infile, int col): Graph(infile,col) {
   width = 10;
   int colNum = 7;
   maxCount = 0;
   initialize(colNum + 1);
   range = ((max - max/5 ) - min)/colNum;
   cout << range << endl;
   for(size_t i = 0; i < cathegories.size();i++){
       int indx = (cathegories[i].count - min) / range; 
       cout << cathegories[i].count << " spada pod indx " << indx << endl;
       histoRanks[indx].count++;
       
       if(maxCount < histoRanks[indx].count)
           maxCount = histoRanks[indx].count;
           
       if(histoRanks[indx].localMax < cathegories[i].count)
           histoRanks[indx].localMax = cathegories[i].count;
       if(histoRanks[indx].localMin > cathegories[i].count)
           histoRanks[indx].localMin = cathegories[i].count;
   
   }
}
void Histogram::initialize(int colNum){
    for (int i = 0; i < colNum; i ++){
        THisto tmp;
        histoRanks.push_back(tmp);
    }
}

void Histogram::printAxisY(int i,ofstream& out)const{
    int val = -1;
        for(size_t k = 0; k < histoRanks.size(); k++){
            if(k == unsigned(i)){
                val = k;
                out << val;
                break;
            }
        }
        for(int k = digits(val); k < digits(histoRanks.size()); k++)
            out << " ";
        out << "| ";
}

void Histogram::printAxisX(ofstream& out)const{
    out<< "   ";
    
    for(size_t j = 0; j < histoRanks.size(); j++ ){
        out << j * range + min << "-" << j * range + range + min << " ";
    }

}

void Histogram::printRow(ofstream& out, char sides, char fill)const{
    out << sides;
        for(int k = 0; k < width; k++) 
            out <<  fill;
    out << sides;

}

void Histogram::print(ofstream& out){
     /**for every row **/
    for(int i = maxCount; i >= 0; i--){   
        printAxisY(i, out);
        
        /**for every column **/
        for(size_t j = 0; j < histoRanks.size(); j++ ){
            if(histoRanks[j].count == i){
                printRow(out, ' ', '_');
            } 
            else if(histoRanks[j].count > i){
                printRow(out, '|', ' ');
            } 
            else{
                printRow(out, ' ', ' ');
            }
        }
        out << endl;
    }
    printAxisX(out);
}

Histogram::~Histogram() {
}

