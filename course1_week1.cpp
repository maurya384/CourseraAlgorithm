#include <bits/stdc++.h>
using namespace std;
int getLength(long long int value) {
	int counter = 0;
	while (value != 0) {
		counter++;
		value /= 10;
	}
	return counter;
}

long long int multiply(long long int x, long long int y) {
	int xLength = getLength(x);
	int yLength = getLength(y);

	//  of the two lengths
	int N = max(xLength, yLength);

	// if the max length is small it's faster to just flat out multiply the two numbers
	if (N < 10)
		return x * y;

	//max length divided and rounded off
	N = (N/2) + (N%2);

	long long int multiplier = pow(10, N);

	long long int b = x/multiplier;
	long long int a = x - (b * multiplier);
	long long int d = y / multiplier;
	long long int c = y - (d * N);

	long long int z0 = multiply(a,c);
	long long int z1 = multiply(a + b, c + d);
	long long int z2 = multiply(b, d);


    return z0 + ((z1 - z0 - z2) * multiplier) + (z2 * (long long int)(pow(10, 2 * N)));

}

int main() {

    //faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	// two numbers
	long long int a ,b;
	cin>>a>>b;
	cout << multiply(a,b) << endl;
	return 0;
}
