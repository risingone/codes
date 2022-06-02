#include <iostream>
using namespace std;


void fun1(int n)
{
	if(n == 0)
		return;

	cout<<n<<endl;

	fun1(n - 1);
	
	cout<<n<<endl;
}

void fun2(int n)
{
	if(n == 0)
		return;

	fun2(n - 1);
	
	cout<<n<<endl;
	
	fun2(n - 1);
}

int fun3(int n)
{
	if(n == 1)
		return 0;
	else
		return 1 + fun3(n / 2);
}

void fun4(int n)
{
	if(n == 0)
		return;
	
	fun4(n / 2);

	cout<<(n % 2)<<endl;
}

int main() {
	cout << "===============Output For fun1===============" << endl;
	fun1(3); // 3 2 1 1 2 3
	cout << "===============Output For fun2===============" << endl;
	fun2(3); // 1 2 1(fun2(1)) 3 1 2 1(fun2(2))
    cout << "===============Output For fun3===============" << endl;
    cout << fun3(16) << endl; // 4
    cout << "===============Output For fun4===============" << endl;
    fun4(7); // 1 1 1
	return 0;
}

