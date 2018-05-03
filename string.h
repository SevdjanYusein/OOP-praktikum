#pragma once
#include <cstring>
#include <iostream>

class String
{
private:
	char* start;

	void copy(const String& other);
	void erase();
public:
	String();
	String(const char* value);
	String(const String& other);
	String& operator= (const String& other);
	void operator= (const char* value);
	void print() const;
	bool operator!=(const String& other);
	bool operator==(const String& other);
	int lenght(const String& other);
	friend std::ostream& operator<< (std::ostream&, const String&);
	friend std::istream& operator>> (std::istream&, String&);

	~String();

};