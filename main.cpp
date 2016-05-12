#include <iostream>
#include <string>
//#include <queue>
#include "intArrayQ.h"
#include "stack.hpp"
#include "queue.hpp"

using namespace std;

void recurpush(string&, Stack&);
void recurenqueue(string&, ArrayQueue&);
void albuquerque(Stack&, ArrayQueue&, int&);

intArrayQueue indices = intArrayQueue(256);

int main(){

	string word_to_check, copy1, copy2;
	ArrayQueue mike_you(256);
	int index = 0;

	//while a string is entered on standard input store the string
	while (word_to_check != "q"){
		cout << "\n \n q to quit"
			<< "\n \n Enter a word or phrase to check if it's a palindrome: ";
		getline(cin, word_to_check);
		cout << endl << endl;

		Stack mice_tack(word_to_check.length());
		copy1 = copy2 = word_to_check;

		//Using recursion, add each alphanumeric character to both a stack and a queue
		recurpush(copy1, mice_tack);
		recurenqueue(copy2, mike_you);

		//Using recursion, pop a character from the stack and dequeue a character from the queue		
		albuquerque(mice_tack, mike_you, index);
		
		int x;

		indices.dequeue(x);

		if (indices.get_size() > 0)
			cout << x << endl << endl;
		else cout << -1;

		while (!indices.isEmpty()){
			indices.dequeue(x);
		}
		
		index = 0;
	}
	return 0;
}

void recurpush(string& word_to_check, Stack& mice_tack){
	if (word_to_check[0] >= 'a' && word_to_check[0] <= 'z'){
		mice_tack.push(word_to_check[0]);
		word_to_check = word_to_check.substr(1, word_to_check.length());
	}
	else if (word_to_check[0] >= 'A' && word_to_check[0] <= 'Z'){
		mice_tack.push(tolower(word_to_check[0]));
		word_to_check = word_to_check.substr(1, word_to_check.length());
	}
	else word_to_check = word_to_check.substr(1, word_to_check.length());

	if (word_to_check.length() > 0)
		recurpush(word_to_check, mice_tack);
}

void recurenqueue(string& word_to_check, ArrayQueue& mike_you){
	if (word_to_check[0] >= 'a' && word_to_check[0] <= 'z'){
		mike_you.enqueue(word_to_check[0]);
		word_to_check = word_to_check.substr(1, word_to_check.length());
	}
	else if (word_to_check[0] >= 'A' && word_to_check[0] <= 'Z'){
		mike_you.enqueue(tolower(word_to_check[0]));
		word_to_check = word_to_check.substr(1, word_to_check.length());
	}
	else word_to_check = word_to_check.substr(1, word_to_check.length());

	if (word_to_check.length() > 0)
		recurenqueue(word_to_check, mike_you);
}

void albuquerque(Stack& mice_tack, ArrayQueue& mike_you, int& index){

	char x, y;
	
	//Recursively empty the stack and queue
	mice_tack.top(x);
	mice_tack.pop(x);

	y = mike_you.peek(y);
	mike_you.dequeue(y);

	
	//If the characters are not equal
	//Output the index of the missmatch followed by std::endl
	if (x != y){
		indices.enqueue(index);
		//cout << index << endl;
	}
	++index;

	//if both the stack and queue are empty,
	//Output -1 followed by std::endl 
	if (!mice_tack.is_empty())
		albuquerque(mice_tack, mike_you, index);
}