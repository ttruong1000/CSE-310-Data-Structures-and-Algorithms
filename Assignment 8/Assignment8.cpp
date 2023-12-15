// Assignment #8
// Name: Taman Truong
// ASU Email Address: tvtruon1@asu.edu
// Description: The Assignment8.cpp file is the driver file that takes file input and output to make a graph of publications
//              of edges and vertices. 

#include <iostream> // to use cin and cout
#include <string> // to use strings
#include <cstdlib> // to use string functions
#include <fstream> // file input/output
#include "Graph.h"

using namespace std;

int main(int argc, char** argv) {
    
    std::ifstream inFile1, inFile2, inFile3;
    string fileLine1;
    string fileLine2;
    string fileLine3;
    string commandName;
    string year1;
    string year2;
    string verticesPublicationID;
    string verticesYear;
    int countVertices1 = 0;
    int countVertices2 = 0;
    string edgePublicationID1;
    string edgePublicationID2;
    int countEdges = 0;
    int index1 = 0;
    int index2 = 0;
    Graph* masterGraph = new Graph(0);

    inFile3.open(argv[3]);

    while(inFile3.eof() == false) {
        std::getline(inFile3, fileLine3, '\n');

        if(fileLine3.compare("") == 0) {
            std::cout << "next command: " << fileLine3 << "\n" << std::endl;
        }
        if(fileLine3.compare("out-degree") == 0) {
            masterGraph->outDegree(countVertices1, countEdges);
            for(int i = 0; i < countVertices1; i++) {
                cout << i << " : " << masterGraph->numEdgesAtIndex(i) << "\n" << endl;
            }
        }
        else if(fileLine3.compare("diameter") == 0) {
            masterGraph->FloydWarshall();
        }
        else if(fileLine3.compare("strongly-connected-components") == 0) {
            masterGraph->stronglyConnectedComponents();
        }
        else if(fileLine3.compare("end-graph") == 0) {
            masterGraph->~Graph();
            countVertices1 = 0;
            countVertices2 = 0;
            countEdges = 0;
            index1 = 0;
            index2 = 0;
        }
        else if(fileLine3.compare("exit") == 0) {
            return 0;
        }
        else { // for the command "start-graph year1 year2"
            std::getline(std::cin, fileLine3);
            // Parse the input with the delimiter " "
            commandName = fileLine3.substr(0, fileLine3.find(" "));
            fileLine3.erase(0, fileLine3.find(" ") + 1);
            year1 = fileLine3.substr(0, fileLine3.find(" "));
            fileLine3.erase(0, fileLine3.find(" ") + 1);
            year2 = fileLine3;

            inFile2.open(argv[2]);

            while(inFile2.eof() == false) {
                std::getline(std::cin, fileLine2);
                // Parse the input with the delimiter " "
                verticesPublicationID = fileLine2.substr(0, fileLine2.find(" "));
                fileLine2.erase(0, fileLine2.find(" ") + 1);
                verticesYear = fileLine2;

                if((year1 <= verticesYear) && (verticesYear <= year2)) {
                    countVertices1++;
                }
            }

            inFile2.close();

            Graph* newGraph = new Graph(countVertices1);

            inFile2.open(argv[2]);

            while(inFile2.eof() == false) {
                std::getline(std::cin, fileLine2);
                // Parse the input with the delimiter " "
                verticesPublicationID = fileLine2.substr(0, fileLine2.find(" "));
                fileLine2.erase(0, fileLine2.find(" ") + 1);
                verticesYear = fileLine2;

                if((year1 <= verticesYear) && (verticesYear <= year2)) {
                    newGraph->insertNode(verticesPublicationID, verticesYear, countVertices2);
                    countVertices2++;
                }
            }

            inFile2.close();

            inFile1.open(argv[1]);
            while(inFile1.eof() == false) {
                std::getline(std::cin, fileLine1);
                // Parse the input with the delimiter " "
                edgePublicationID1 = fileLine1.substr(0, fileLine1.find(" "));
                fileLine1.erase(0, fileLine1.find(" ") + 1);
                edgePublicationID2 = fileLine1;

                if(newGraph->checkValidEdge(edgePublicationID1, edgePublicationID2)) {
                    index1 = newGraph->getIndex(edgePublicationID1);
                    index2 = newGraph->getIndex(edgePublicationID2);
                    newGraph->insertEdge(edgePublicationID2, year2, index1, index2);
                    countEdges++;
                }
            }
            masterGraph = newGraph;
            std::cout << "The graph G for the years " << year1 << "-" << year2 << "has:\n" << "|V| = " << countVertices1 << " vertices\n" << "|E| = " << countEdges << "edges\n" << endl;

            inFile1.close();
        }
    }
    inFile3.close();
} 