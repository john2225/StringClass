#include <iostream>
#include "Header.h"
string::string() {
	s = 1;
	ptr = new char[s];
	ptr[s-1] = '\0';
}
void string::copy(char* st, int size) {
	s = size;
	ptr = new char[s];
	for (int i = 0; i < size; ++i) {
		ptr[i] = st[i];
	}
}
string::string(string& st) {
	copy(st.ptr,st.s);
}
string::string(string&& st) noexcept{
	copy(st.ptr,st.s);
}
string::string(const char* st) {
	int i = 0;
	while (st[i] != '\0') {
		++i;
	}
	s = i+1;
	ptr = new char[s];
	for (int k = 0; k < s; ++k) {
		ptr[k] = st[k];
	}
	ptr[i] = '\0';
	
}
string::~string() {
	delete[]ptr;
	ptr = nullptr;
	s = 0;
}

string& string::operator+(string& st) {
	s -= 1;
	for (int i = 0; i < st.s; ++i) {
		ptr[s] = st.ptr[i];
		++s;

	}
	return *this;
}

string& string::operator=(string& st) {
	copy(st.ptr, st.s);
	return *this;
}

string& string::operator=(string&& st) noexcept {
	copy(st.ptr, st.s);
	return *this;
}

char string::operator[](int i) const{
	if (i < s)	return ptr[i];
	else std::cout << "Out of range" << std::endl;
}


void string::push_back(char elem) {
	char* b = new char[s + 1];
	for (int i = 0; i < s-1; ++i) {
		b[i] = ptr[i];
	}
	delete[] ptr;
	ptr = b;
	ptr[s-1] = elem;
	ptr[s++] = '\0';
}

int string::size() {
	return s;
}

char string::pop_back() {
	char temp= ptr[s-2];
	--s;
	ptr[s] = '\0';
	return temp;
}

char string::at(int i) const {
	return ptr[i];
}

int string::find(char a) const{
	for (int i = 0; i < s; ++i) {
		if (ptr[i] == a)return i;
	}
	std::cout << "not found" << std::endl;
	return-1;
}

void string::insert(char a,int i) {
	if (i > s + 1)std::cout << "You are out of range";
	char* b = new char[s + 1];
	for (int k = 0; k < i; ++k) {
		b[k] = ptr[k];
	}
	b[i] = a;
	for (int k = i + 1; k < s + 1; ++k) {
		b[k] = ptr[k - 1];
	}
	delete[] ptr;
	ptr = b;

}