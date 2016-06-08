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

void Graph::setRanks(){
    for(auto i: cathegories){
        if (max < i.count)
            max = i.count;
    }
    max += max/5;
    for(size_t i = 0;i < cathegories.size();i++){
        cathegories[i].rank = (cathegories[i].count * height) / max;
    }
}

int Graph::digits(int input) const{
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

