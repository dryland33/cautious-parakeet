#ifndef SOME_NAME_FOR_A_STACK_H
#define SOME_NAME_FOR_A_STACK_H

class Stack{
private:
	char* dat_ptr;          //points to the first address in the stack
	int the_top;            //keeps track of the top of the stack   
	int size;               //maximum number of elements the stack can hold

public:
	Stack(const int&);      //makes a stack and sets the size  
	bool push(const char&); //how we get our chars in
	bool pop(char&);        //how we get our chars out 
	bool top(char&);        //see what's on the top
	bool is_full();         //is the stack full?
	bool is_empty();        //is the stack empty?
};

#endif
/*

/)
VK                                 '  \
/    \
/'    o \
/'         \
_.-'      /`-.   )
__.-'"""""'         /    `-'
/'                   (  _._
/       __      (       ___ \
/'          \      \.____/   \_)
/             \   \  |
/   __          |   \_)
|   /  \_        |  _/
|  /     )      / /'
.' |    _/      /_/
|  |  /'     __/'
------|  |  \    /'------------------------------------http://www.chris.com/ascii/index.php?art=animals/other%20(land)
|  |   \   \
/  /     \   \
__/' _/        \  `----.
(___/'           `------'


*/
