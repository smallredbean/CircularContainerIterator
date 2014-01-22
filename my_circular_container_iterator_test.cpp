#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include "my_circular_container_iterator.h"


int main(int argc, char **argv)
{
	vector<int> v({1, 2, 3, 4, 5});
	MyCircularContainerIterator<vector<int>, vector<int>::iterator> vIt(v, v.begin());

	for(auto i=0; i<6; ++i, ++vIt)
		cout << *vIt << ", ";
	cout << endl; // "1, 2, 3, 4, 5, 1, "
	for(auto i=0; i<6; ++i, --vIt)
		cout << *vIt << ", ";
	cout << endl; // "2, 1, 5, 4, 3, 2, "
	cout << *vIt << *(vIt+3) << *(vIt+5) << *(vIt+7) << endl; // "1413"
	cout << *vIt << *(vIt-3) << *(vIt-5) << *(vIt-7) << endl; // "1314"

	return 0;
}
