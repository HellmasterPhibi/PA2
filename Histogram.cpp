/* 
 * File:   Histogram.cpp
 * Author: hell
 * 
 * Created on 9. červen 2016, 14:26
 */

#include "Histogram.h"

Histogram::Histogram(ifstream& infile, int col, int col2,  vector<char>& fillWith): Graph(infile,col, col2, fillWith) {
   width = 10;
   int colNum = 7;
   maxCount = 0;
   initialize(colNum + 1);
   range = ((max - max/5 ) - min)/colNum;
   //cout << range << endl;
   for(size_t i = 0; i < cathegories.size();i++){
       int indx = (cathegories[i].count - min) / range; 
       //cout << cathegories[i].count << " spada pod indx " << indx << endl;
       histoRanks[indx]++;
       
       if(maxCount < histoRanks[indx])
           maxCount = histoRanks[indx];
           
   
   }
}
void Histogram::initialize(int colNum){
    for (int i = 0; i < colNum; i ++){
        histoRanks.push_back(0);
    }
}

void Histogram::printAxisY(int i,ofstream& out)const{
    int val = -1;
        for(int k = 0; k < maxCount; k++){
            if(k == i){
                val = k + 1;
                out << val;
                break;
            }
        }
        for(int k = digits(val); k < digits(maxCount); k++)
            out << " ";
        out << "| ";
}

void Histogram::printAxisX(ofstream& out)const{
    for(int k = 0; k < digits(maxCount) + 2; k++)
            out << " ";
    
    for(size_t j = 0; j < histoRanks.size(); j++ ){
        out << roundInt(int(j * range + min)) << "-" << roundInt(int(j * range + range + min));
        
        for( int k = digits(j * range + min)+ digits(j * range + range + min)+1; k < width + 2; k++)
            out << " ";
    }

}

void Histogram::printRow(ofstream& out, char sides, char fill)const{
    out << sides;
        for(int k = 0; k < width; k++) 
            out <<  fill;
    out << sides;

}

void Histogram::print(ofstream& out){
    out << "frequency" << endl;
    
     /**for every row **/
    for(int i = maxCount; i >= 0; i--){   
        printAxisY(i, out);
        
        /**for every column **/
        for(size_t j = 0; j < histoRanks.size(); j++ ){
            if(histoRanks[j] == i){
                printRow(out, ' ', '_');
            } 
            else if(histoRanks[j] > i){
                printRow(out, '|', fill[j]);
            } 
            else{
                printRow(out, ' ', ' ');
            }
        }
        out << endl;
    }
    printAxisX(out);
    
    out << endl;
}

Histogram::~Histogram() {
}

