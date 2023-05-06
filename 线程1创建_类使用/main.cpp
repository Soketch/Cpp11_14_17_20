///****************************************************************************
/// @author  :  soketch  --> sk                                                         
/// @date    :  2023-05-07                                                          
/// @type    :  cpp                                                     
/// @model   :  thread - create - start - end                                                            
///----------------------------------------------------------------------------
///                           Change History                                   
///----------------------------------------------------------------------------
///                              
///****************************************************************************


//使用类创建线程对象


#include<iostream>
#include<thread>

class Th
{
public:
	int& m_i;
	Th(int &temp):m_i(temp){
		std::cout << "Ta构造函数" << std::endl;
	}
	Th(const Th& ta) :m_i(ta.m_i) {
		std::cout << "Ta拷贝构造函数" << std::endl;
	}
	void operator()() {
		std::cout << "开始执行子线程" << std::endl;
		std::cout << "Th::m_i=" << this->m_i << std::endl;
		std::cout << "执行完毕子线程" << std::endl;
	}
	~Th() {
		std::cout << "Ta析构函数" << std::endl;
	}
};


int main()
{
	std::cout << "主线程开始" << std::endl;

	int n = 10;
	Th Ta(n);
	std::thread myThread(Ta);   // 这里实际使用的是拷贝构造函数
	
	//myThread.join();

	myThread.detach();

	std::cout << "Ta.m_i=" << Ta.m_i << std::endl;

	std::cout << "主线程结束" << std::endl;
	system("pause");
	return 0;
}