/* 
 * File:   Graph.cpp
 * Author: hell
 * 
 * Created on 31. květen 2016, 17:20
 */

#include "Graph.h"


Graph::Graph(ifstream& infile, int col) {
     height = 30;
     column = col;
     max = 0;
     min = INT_MAX;
    
     string line, tmp;
     if (infile.is_open()){
         getline (infile,line);
         stringstream names(line);
            while(getline(names, tmp,','))
                cathegoryNames.push_back(tmp); /**first line of the input document should be the names of cathegories*/
         
        while ( getline (infile,line) ){
            stringstream ss(line);
            vector<string> tmpVec;
            while(getline(ss, tmp,',')){
                tmpVec.push_back(tmp);
               //cout << tmpVec.size() - 1 << ": " << tmp << " ";
            }
            //cout << endl;
            TCathegory cath(tmpVec[0],stoi(tmpVec[column]));
            cathegories.push_back(cath);
        }
         //cout << "soubor nacten" << endl;
         setRanks();
    }
}


    /**set ranks for the vector cathegories*/
void Graph::setRanks(){
    /**find the max value*/
    for(auto i: cathegories){
        if (max < i.count)
            max = i.count;
        if (min > i.count)
            min = i.count;
    }
    max += max/5; /** the max variable will be later used to determine the height, therefore it is better to have it a bit bigger than the actual maximum count*/
    for(size_t i = 0;i < cathegories.size();i++){
        cathegories[i].rank = round ((cathegories[i].count * height) / max); /**linear transformation to new range that is printable in rows*/
    }
}
void Graph::printAxisY(int i,ofstream& out)const{
    int val = -1;
        for(size_t k = 0; k < cathegories.size(); k++){
            if(cathegories[k].rank == i){
                val = cathegories[k].count;
                out << val;
                break;
            }
            else if(i == height){ /**the highest value*/
                val = max;
                out << val;
                break;
            }
        }
        for(int k = digits(val); k < digits(max); k++)
            out << " ";
        out << "| ";
}

/**
 * @param number > 0
 * @return number of digits of the number input, if input == -1, returns 0*/
int Graph::digits(int input) const{ 
    if(input == -1)
        return 0;
    
    string helpString; 
    ostringstream convert;
    convert << input;      
    helpString = convert.str(); 
    int result = helpString.size();
    return result;
    
}

double Graph::round(double d)
{
  return floor(d + 0.5);
}


 int Graph::roundInt(int input) const{
     int divide = 1; 
     for( int  i = 0; i <(digits(input) - 2); i++)
         divide *= 10;
     
     input /= divide ;
     input *= divide;
     return input;
 }

Graph::~Graph() {
}

