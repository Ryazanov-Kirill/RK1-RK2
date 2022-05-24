#pragma once

#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <vector>
#include <utility>
#include <functional>
#include <iterator>
#include <string>
#include <cstring>

using namespace std;

//task1
struct Node {
	Node();
	Node(int nameNode);
	~Node();
	
	Node* parent;
	std::list<Node*> listChilds;
	int name;
	static int countNodes;
};

class Graph {
	private :
		Node* head;
		//здесь можно писать любые функции, которые могут понадобиться
	public :
		Graph();			
		Graph(int countNodes);
        ~Graph();
		/*
			output		:	-1 - если функция не реализована
						:	положительное число -- число узлов
			author		:
			date		:
			version		:
		*/
		int buildTreeBFS(int countNodes);
		/*
			output		:	-1 - если функция не реализована
						:	положительное число -- число узлов
			author		:
			date		:
			version		:
		*/			
		int buildTreeDFS(int countNodes);
		/*
			description	:	обход графа и записи вершин в файл
			input		:
			output		:
			author		:
			date		:
			version		:
		*/
		void BFS();
		void DFS();
		/*
			description	:	функция поиска узла по его имени,
							DFS - № студ билет чётный
							BSD - № студ билет нечётный
			input 		:	nameNode -- имя узла
			output		:	{bool -- узел найде, list<int> -- список имён узлов до необходимого}
			description	:	приставка DFS -- поиск в глубину, BSF -- поиск в ширину
			author		:
			date		:
			version		:
		*/
		std::pair<bool, list<int>> searchDFS(int nameNode);		
		std::pair<bool, list<int>> searchBFS(int nameNode);
};

//task2
pair<int/*index el*/,int /*count call*/> binSearch(int* ar, int sizeAr, int el);

//task3
template<class T>
class Filo {
	private :
		T* ar;	//массив
		int size;	//размер массива
		int countData;	//число элементов в массиве
	public :
		Filo() {}
		Filo(int _size) {}
		~Filo() {}
		/*
			input		:	элемент который надо добавить
			output		:	1 - элемент добавлен, 0 - элемент не добавлен
			description	:	добавление элемента в конец массива				
		*/
		int push_back(T el) {}
		/*
			input		:	элемент который надо добавить
			output		:	пара 
							значение первого аргумента пары
								1 - элемент успешно извлечён, 0 - элементов в массиве нет
							значение второго аргумента пары -- это извлечённый элемент
			description	:	извлечение элемента из массива
		*/
		pair<int,T> pop_back() {}
		/*
			input		:	элемент который надо добавить
			output		:	пара 
							значение первого аргумента пары
								1 - элемент успешно извлечён, 0 - элементов в массиве нет
							значение второго аргумента пары -- это извлечённый элемент
			description	:	извлечение элемента из массива
		*/
		void returnAr() {}
};

template<typename  T>
Filo<T>::Filo() {
	this->size = 256;
	this->countData = 0;
	this->ar = new T[this->size];
}
template<typename  T>
Filo<T>::Filo(int _size) {
	size = _size;
	countData = 0;
	ar = new T[_size];
}
template<typename  T>
Filo<T>::~Filo<T>() {
	delete[] ar;
}
template<typename  T>
int Filo<T>::push_back(T el) {
	if (countData >= size || countData < 0) {
		return 0;
	}
	if (countData == 0) {
		ar[0] = el;
		countData++;
	}
	else {
		ar[countData++] = el;
		return 1;
	}
}
template<typename  T>
std::pair<int, T> Filo<T>::pop_back() {
	if (countData == 0) {
		std::pair<int, T> pairForReturn;
		pairForReturn.first = 0;
		return pairForReturn;
	}
	else {
		std::pair<int, T> pairForReturn;
		pairForReturn.first = 1;
		pairForReturn.second = ar[countData - 1];
		countData--;
		return pairForReturn;
	}
}
//task4
template <typename T>
std::ostream& operator << (std::ostream& ostr, const std::pair<int, T> t) {
	ostr << "(" << t.first << ", " << t.second << ")\n";
	return ostr;
}
//task5
template<class T>
class CheckBrackets : public Filo<char> {
private:
    //можно объявляеть любые переменные и функции
public :
    CheckBrackets() : Filo<char>() { }
	~CheckBrackets() = default;
	/*
		input		:	строка со скобками
		output		:	0 - всё хорошо, -1 - скобок не хватает
		description	:	проверка скобок
	*/
    int checkBrackets(const char* strBrackets) {}
};
template<typename T>
int CheckBrackets<T>::checkBrackets(const char* strBrackets) {
	Filo<char> tempArray;
	int counter = 0;
	for (int i = 0; strBrackets[i] != NULL; i++) {
		switch (strBrackets[i]) {
		case '(': {

			tempArray.push_back('(');
		}
				break;
		case '{': {
			tempArray.push_back('{');

		}
				break;
		case '[': {
			tempArray.push_back('[');
		}
				break;
		case ')': {

			if (tempArray.pop_back().second != '(') {
				return -1;
			}
		}
				break;
		case '}': {
			if (tempArray.pop_back().second != '{') {
				return -1;
			}

		}
				break;
		case ']': {
			if (tempArray.pop_back().second != '[') {
				return -1;
			}

		}
				break;
		}
		counter++;
	}
	if (tempArray.pop_back().second != NULL) {
		return -1;
	}
	return 0;
}
