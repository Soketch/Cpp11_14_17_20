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


//ʹ���ഴ���̶߳���


#include<iostream>
#include<thread>

class Th
{
public:
	int& m_i;
	Th(int &temp):m_i(temp){
		std::cout << "Ta���캯��" << std::endl;
	}
	Th(const Th& ta) :m_i(ta.m_i) {
		std::cout << "Ta�������캯��" << std::endl;
	}
	void operator()() {
		std::cout << "��ʼִ�����߳�" << std::endl;
		std::cout << "Th::m_i=" << this->m_i << std::endl;
		std::cout << "ִ��������߳�" << std::endl;
	}
	~Th() {
		std::cout << "Ta��������" << std::endl;
	}
};


int main()
{
	std::cout << "���߳̿�ʼ" << std::endl;

	int n = 10;
	Th Ta(n);
	std::thread myThread(Ta);   // ����ʵ��ʹ�õ��ǿ������캯��
	
	//myThread.join();

	myThread.detach();

	std::cout << "Ta.m_i=" << Ta.m_i << std::endl;

	std::cout << "���߳̽���" << std::endl;
	system("pause");
	return 0;
}