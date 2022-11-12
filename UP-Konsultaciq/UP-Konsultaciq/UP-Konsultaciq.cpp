// UP-Konsultaciq.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

//Zad 3
void read(char arr[], size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}
void rotate(char arr[], size_t size) {

	for (int i = size-1; i >0; i--)
	{
		char temp = arr[i];
		arr[i] = arr[i - 1];
		arr[i - 1] = temp;
	}
}



//Zad 2

//Съседни ли са -  върща true или false (bool)
bool isAdjecent(int n) {
	//unsigned = unsigned int като запис - т.е. става въпрос за цяло число от 0 нагоре 
	// int обхваща от 


	unsigned last_digit = n % 10; //записвм последната цифра в променлива (пример: 123 % 10 = 3, защото това е остатъка от 123 / 10 = 12.3 
	n /= 10; //махам последната цифра и понеже е тип int числото ми става примерно от 1234 -> 123, защото int не пази дробна част
	while (n>0)  // 10/10 -> 1  1/10 -> 0   0/10 -> 0 т.е. докато стигнем най-първото число 
	{
		if (last_digit==n%10)  // ако последната цифра е същата като тази вляво на нея числото не е съседно и директно връщаме false 
							  // при 1234 last_digit ще е 4, а тук когато сме направили n=n/10 (36 ред) n%10 ще е 3
		{
			return false;
		}
		last_digit = n % 10;   // вече запазвам последната цифра на 123 и след това я махаме с n/=10 и логика за всяка итерация (завъртане) на цикъла е една и съща
		n /= 10;
	}
	return true;
}
int Result(int a, int b) {
	//ако А не е съседно и а<=б (редицата е сортирана и вместо да я обхождаме с for можем просто да прибавяме 1 докато не стигнем б)
	while (!isAdjecent(a) && a <= b)
	{
		++a;


	}
	//логиката е същата
	while (!isAdjecent(b) && a <= b)
	{
		--b;

	}

	return b - a;
}

//Zad 1

//връща броя на цифрите  (за n/=10 виж isAdjecent)
unsigned sizeOfNumber(unsigned num) {
	unsigned int counter = 0;  //запазвам си брояч който почва от 0  (реално дали ще кажа unsigned или не няма значение просто асистентите
							  //									посъветваха ако знаем че рабтим със строго положителни числа да го пишем така)
	while (num>0)
	{
		num /= 10;
		counter++;
	}
	return counter;
}
bool isKInsideN(unsigned n, unsigned k) {
	
	n /= 10;  // понеже К не може да е част от първата или последната цифра, просто махам последната и не мисля повече за нея

	int kSize = sizeOfNumber(k);  // за да знам колко цифри е К

	const unsigned K_VALUE = k; // (1)
	//докато не проверя всички цифри от N или докато не намеря съвпадение за К
	while (n != 0 && kSize>0)
	{ 
		const unsigned N_DIGIT = n % 10;  //последните цифра от N и К
		const unsigned K_DIGIT = k % 10; 
		

		if (N_DIGIT != K_DIGIT) //ако са различни пропускаме кода след if-a и проверяваме за следващите цифри
		{
			if (kSize<sizeOfNumber(K_VALUE)) // при 12334 търсейки 23 стигаме до 123 където вече сме взели едната 3ка от N, но и 3-ката от К и въреки че има 23 няма да го намерим, затова
											//  ако бр. циф. на К < оригиналният им брой, не режи цифра от N, a възстанови К  (1)
										   //  така стигаме до N=123 и до К=23 вместо N=123 и К=2
			{
				k = K_VALUE;
				continue;
			}
			n /= 10;
			continue;  // нищо под continue не се изпълнява, просто се започва нова итерация на цикъла
		}
		n /= 10;    // тук стигаме ако последните цифри са съвпаднали затова и от двете числа пак махаме последните им цифри за да може да продължим сравнението
		k /= 10;
		--kSize;
	}
	return (kSize==0 && n/10*sizeOfNumber(n)); //този израз връща true или false (ако в К не са останали числа и ако не сме стигнали до първото число от N)
}

int main()
{
	
	//Zadacha 1
	/*unsigned n, k;
	cin >> n >> k;
	cout << boolalpha << isKInsideN(n, k);*/

	//Zadacha 2
	/*unsigned a, b;
	cin >> a >> b;
	cout << Result(a, b);*/

	//Zadacha 3
	/*char arr[] = "hello";
	rotate(arr, 5);*/



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

