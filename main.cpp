#include<iostream> // why ??? 
#include"Header.h"
int main() {
	string s;
	
	string st("helllo");
	std::cout << st;
	s = st;
	//std::cout << s;
	//s = s + st;
	//std::cout << std::endl<<s;
	////std::cout << std::endl << s[1];
	//std::cout << std::endl <<s.size()<<s.pop_back();
	//std::cout << std::endl << s.size() << s.pop_back();
	s.insert('a', 2);
	std::cout << s.find('a');
}
