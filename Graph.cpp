/* 
 * File:   Graph.cpp
 * Author: hell
 * 
 * Created on 31. květen 2016, 17:20
 */

#include "Graph.h"


Graph::Graph(ifstream& infile) {
     height = 30;
     column = 1;
     max = 0;
    
     string line, tmp;
     if (infile.is_open()){
         getline (infile,line);
         stringstream names(line);
            while(getline(names, tmp,','))
                cathegoryNames.push_back(tmp);
         
        while ( getline (infile,line) ){
            stringstream ss(line);
            vector<string> tmpVec;
            while(getline(ss, tmp,','))
                tmpVec.push_back(tmp);
            
            TCathegory cath(tmpVec[0],stoi(tmpVec[column]));
            cathegories.push_back(cath);
        }
         setRanks();
        infile.close();
    }
}

    /**set ranks for the vector cathegories*/
void Graph::setRanks(){
    /**find the max value*/
    for(auto i: cathegories){
        if (max < i.count)
            max = i.count;
    }
    max += max/5; /** the max variable will be later used to determine the height, therefore it is better to have it a bit bigger than the actual maximum count*/
    for(size_t i = 0;i < cathegories.size();i++){
        cathegories[i].rank = (cathegories[i].count * height) / max; /**linear transformation to new range that is printable in rows*/
    }
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


Graph::Graph(const Graph& orig) {
}

Graph::~Graph() {
}

