#include<iostream>

using namespace std;

template<typename T>
class SharedPtr {

	T* address;
	
	size_t* count;

public:

	SharedPtr() :address(nullptr), count(nullptr) {}

	SharedPtr(T*address):address(address),count(new size_t(1)){}

	SharedPtr(const SharedPtr& other) :address(other.address), count(other.count) { ++(*count); }
	
	SharedPtr& operator=(const SharedPtr& other) {
		if (count != nullptr) {
			(*count)--;
			if (*count == 0) { delete address, delete count; }
		}
		count = other.count;
		address = other.address;
		++(*count);
		return *this;
	}

	T* Get() { return address; }

	T* operator->() { return address; }

	T& operator *() { return *address; }

	~SharedPtr() {
		if (count != nullptr) {
			--(*count);
			if (*count == 0) {
				delete address;
				delete count;
			}
		}
	}
};


template<typename T>
class UniquePtr {
	T* adress;
public:
	UniquePtr() :adress(nullptr) {};

	UniquePtr(T* adress) :adress(adress) {};

	UniquePtr(const UniquePtr& other) = delete;

	UniquePtr& operator =(const UniquePtr& other) = delete;

	Get() { return adress; }

	T* operator->() { return adress; }

	T& operator *() { return *adress; }



	~UniquePtr() {
		delete ptr;
	}
};

void main() {

	SharedPtr<int>myPtr(new int(100));
	
	SharedPtr<int>myPtr2(new int(22));

	SharedPtr<int>ptr2(myPtr);

	myPtr = myPtr2;

}