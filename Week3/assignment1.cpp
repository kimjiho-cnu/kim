#include <iostream>

int code(){
	return 100;
}

static int data = 0 ;
static int bss;





int main() {
	int stack  = 5 ;
	int* heap = new int[2];
	
	std::cout <<"code\t" << (void*) code << std::endl;
	std::cout << "Rodata\t" << (void*)100 << std::endl;
	std::cout << "data\t" << &data << std::endl;
	std::cout << "BSS\t" << &bss << std::endl;
	std::cout << "HEAP\t" << heap << std::endl;
	std::cout << "Stack\t" << &stack << std::endl;

}   
