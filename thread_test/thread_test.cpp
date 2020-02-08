// thread_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <ctime>  
#include <thread>

int PocetOpakovani = 500000000;


void t1()
{
	for (int i = 0; i < PocetOpakovani / 4; i++)
	{
		sin(0.707);
		cos(0.707);
	}
}

void t2()
{
	for (int i = 0; i < PocetOpakovani / 4; i++)
	{
		sin(0.707);
		cos(0.707);
	}
}

void t3()
{
	for (int i = 0; i < PocetOpakovani / 4; i++)
	{
		sin(0.707);
		cos(0.707);
	}
}

void t4()
{
	for (int i = 0; i < PocetOpakovani / 4; i++)
	{
		sin(0.707);
		cos(0.707);
	}
}

int main()
{
	
	int count = 0;
	std::cout << "Single Thread vs Multithread!\n";
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	for (int i = 0; i < PocetOpakovani; i++)
	{
		sin(0.707);
		cos(0.707);
	}

	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	std::cout << "Time difference 1 thread = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

	std::thread thread1(t1);
	std::thread thread2(t2);
	std::thread thread3(t3);
	std::thread thread4(t4);

	begin = std::chrono::steady_clock::now();

	thread1.join();
	thread2.join();
	thread3.join();
	thread4.join();
	
	end = std::chrono::steady_clock::now();
	std::cout << "Time difference 4 thread = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
	int n;
	std::cout << "Push any key: "; // no flush needed
	std::cin >> n;
}