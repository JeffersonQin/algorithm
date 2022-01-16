// 补码乘法分配律

#include <iostream>
#include <limits>

using namespace std;

int main() {
	int32_t x = 1000000000;
	int32_t y = 1000;
	int32_t y1 = INT32_MIN;
	int32_t y2 = INT32_MIN + 1000;
	cout << "x: " << x << endl;
	cout << "y1: " << y1 << ", y2: " << y2 << endl;
	cout << "y: " << y << ", y1 + y2: " << y1 + y2 << endl;
	cout << "x * y: " << x * y << endl;
	cout << "x * y1 + x * y2: " << x * y1 + x * y2 << endl;
	return 0;
}
