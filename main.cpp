/* 
 * File:   main.cpp
 * Author: hell
 *
 * Created on 31. květen 2016, 14:36
 */

#include "Graph.h"
#include "BarPlot.h"
#include "LinePlot.h"
#include "Histogram.h"
#include "PieChart.h"

using namespace std;

bool whatToPrint(ifstream& conf){
    string line;
    getline(conf, line);
    stringstream ss(line);
    string tmp;
    for(int i = 0; i < 2; i++)
        getline(ss, tmp, ':');  
    if(stoi(tmp) == 1){
        return true;
    }
    else {
        return false;
    }
}

int main(int argc, char** argv) {
    vector<Graph *> graphs;
    vector<char> filling;
    
    
    ofstream outfile;
    outfile.open("out",  ios::out);
    if (outfile.fail()){ return false;}
    
    ifstream infile;
    infile.open("testData/grades.csv",  ios::in);
    if (infile.fail()){ cout << "Cannot open file" << endl;
    return -1;
    }
    
    ifstream conf;
    conf.open("config",  ios::in);
    if (conf.fail()){ 
        cout << "Cannot open configuration file" << endl; 
        return -1;
    }
    string line, tmp;
    for(int i = 0; i < 4; i++)
        getline(conf, line); /**The first 5 lines of the configuration file just specifies the format.*/
    
    stringstream ss(line);
    while (getline(ss, tmp, ' ')) {
       // cout << tmp << endl;
            filling.push_back(tmp[0]);        
    }
    getline(conf, line);
    /**BarPlot*/    
    if(whatToPrint(conf) == true){
        cout << "BarPlot " << endl;
       getline(conf, line);
       stringstream ss(line);
       getline(ss, tmp, ',');
       int col1 = stoi(tmp);
       getline(ss, tmp, ',');
       int col2 = stoi(tmp);
       
       graphs.push_back(new BarPlot (infile,col1,col2, filling));
       
    }else
        getline(conf, line);
    
       /**LinePlot*/    
    if(whatToPrint(conf) == true){
        cout << "LinePlot " << endl;
       getline(conf, line);
       stringstream ss(line);
       getline(ss, tmp, ',');
       int col1 = stoi(tmp);
       getline(ss, tmp, ',');
       int col2 = stoi(tmp);
       
       graphs.push_back(new LinePlot (infile,col1,col2, filling));
       
    }else
        getline(conf, line);
        
       /**PieChart*/    
    if(whatToPrint(conf) == true){
        cout << "PieChart" << endl;
       getline(conf, line);
       stringstream ss(line);
       getline(ss, tmp, ',');
       int col1 = stoi(tmp);
       getline(ss, tmp, ',');
       int col2 = stoi(tmp);
       
       graphs.push_back(new PieChart (infile,col1,col2, filling));
       
    }else
        getline(conf, line);
    
    
     /**Histogram*/    
    if(whatToPrint(conf) == true){
        cout << "Histogram" << endl;
       getline(conf, line);
       int col1 = stoi(line);
       
       graphs.push_back(new Histogram (infile,col1, col1, filling));
       
    }else
        getline(conf, line);
    
//    PieChart p(infile,0,1);
//    p.print(outfile);
//    
//    //Histogram h(infile,12);
//    //h.print(outfile);
//    
//    //LinePlot l(infile,1, 2);
//    //l.print(outfile);
//    
//    BarPlot b(infile,0,1);
//    b.print(outfile);
    for(size_t i = 0; i < graphs.size(); i++){
        //cout << "printing " << i << endl;
        graphs[i]->print(outfile);
    }
    
    
    infile.close();
    conf.close();
    outfile.close();
    
    for(size_t i = 0; i < graphs.size(); i++)
        delete graphs[i];
    
    
    return 0;
}

