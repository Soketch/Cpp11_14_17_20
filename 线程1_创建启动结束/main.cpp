///****************************************************************************
/// @author  :  soketch  --> sk                                                         
/// @date    :  2023-05-06                                                           
/// @type    :  cpp                                                     
/// @model   :  thread - create - start - end                                                            
///----------------------------------------------------------------------------
///                           Change History                                   
///----------------------------------------------------------------------------
///                              
///****************************************************************************



// 一个进程只有一个主线程
// 主线程执行main()
// 线程不是越多越好，线程创建消耗堆栈空间
// 线程影响进度切换/CPU性能状态 --> 耗费本该属于程序运行的时间

// 主线程main()执行完毕-->代表整个线程执行完毕



#include<iostream>
#include<thread>   //c++11 创建线程

void myPrint()
{
	std::cout << "子线程开始执行" << std::endl;
	std::cout << "子线程执行完毕" << std::endl;
}

int main() 
{
	std::cout << "主线程开始" << std::endl;

	std::thread th(myPrint);  //线程类创建对象
	

	//th.detach();  // 这里使用detach 测试下面的joinable(if-else)


	// joinable() 判断是否可以成功使用join()或者detach()    返回 true false
	// 用了detach 后面不能用join, 同理join后不能detach
	if ( th.joinable() ) {
		std::cout << "可以使用join或者detach" << std::endl;

		// thread::join() 阻塞主线程，让主线程等待子线程执行完毕，主线程子线程汇合
		th.join();

		// thread::detach() 分离，主线程不和子线程汇合
		// 主线程不等待子线程，先执行不影响子线程的结束 --> 子线程结束，程序结束
		// 一旦detach()后，与主线程关联的thread对象就会失去这个主线程的关联 
		//th.detach();
	}
	else
	{
		std::cout << "不能使用join或者detach" << std::endl;
	}

	std::cout << "主线程结束" << std::endl;
	system("pause");
	return 0;
}
 