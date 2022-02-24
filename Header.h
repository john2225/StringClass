#include <iostream>
class string {
public:
	string();
	string(string&);
	string(string&&) noexcept;
	string(const char*);

	~string();

	string& operator+(string&);
	string& operator=(string&);
	string& operator=(string&&) noexcept;
	char operator[](int) const;
	friend std::ostream& operator<<(std::ostream& os, string& st)
	{
		for (int i = 0; i < st.s; ++i) {
			os << st.ptr[i];
		}
		return os;
	}

	int size();
	void push_back(char);
	char pop_back();
	void insert(char, int);
	char at(int) const;
	int find(char) const;

private:
	void copy(char*,int size);
	char* ptr;
	int s;
};

