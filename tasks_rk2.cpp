#include <map>
#include <list>


#include "tasks_rk2.h"

//task1
Node::Node() {}
Node::Node(int nameNode) {}
Node::~Node() {}

Graph::Graph() {}
Graph::Graph(int countNodes) {}
Graph::~Graph() {}
int Graph::buildTreeBFS(int countNodes) {}
int Graph::buildTreeDFS(int countNodes) {}
void Graph::BFS() {}
void Graph::DFS() {}
std::pair<bool, list<int>> Graph::searchDFS(int nameNode)	 {}
std::pair<bool, list<int>> Graph::searchBFS(int nameNode)	{}	

//task2
pair<int/*index el*/,int /*count call*/> binSearch(int* ar, int sizeAr, int el) {
    int halfOfAr = sizeAr / 2;
        if(sizeAr%2==1){
            halfOfAr++;
        }
        static int countCall;
        static int index=halfOfAr;
        if (ar[halfOfAr-1] != el && halfOfAr!=0) {
            if (ar[halfOfAr-1] > el) {

                if((halfOfAr-1)%2==0){
                    index--;
                }
                index-=halfOfAr/2;
                countCall++;
                binSearch(ar, halfOfAr-1, el);
            }
            if (ar[halfOfAr-1] < el) {
                if((sizeAr-halfOfAr)%2==1){
                    index++;
                }
                index+=halfOfAr/2;
                countCall++;
                binSearch(ar + halfOfAr, sizeAr - halfOfAr, el);
            }
        }
        if(ar[halfOfAr-1]==el){
            countCall++;
            index--;
        }
        std::pair<int, int> pairForReturn;
        pairForReturn.first=index;
        pairForReturn.second=countCall;

        return pairForReturn;
}


//task3
//task4
//task5
