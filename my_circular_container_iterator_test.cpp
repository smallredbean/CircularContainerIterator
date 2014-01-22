#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;

#include <assert.h>

#include "my_circular_container_iterator.h"

void unit_test_size_1(void)
{
	vector<int> v({1});
	MyCircularContainerIterator<vector<int>, vector<int>::iterator> it(v, v.begin());

    // ++it
	for(auto i=0; i<5; ++i)
        assert(*(++it)==1);

    // it++
    for(auto i=0; i<5; ++i)
        assert(*(it++)==1);

    // --it
    for(auto i=0; i<5; ++i)
        assert(*(--it)==1);

    // it--
    for(auto i=0; i<5; ++i)
        assert(*(it--)==1);

    // it+
	for(auto i=0; i<5; ++i)
        assert(*(it+i)==1);

    // it-
    for(auto i=0; i<5; ++i)
        assert(*(it-i)==1);

    // it+=
    for(auto i=0; i<5; ++i)
        assert(*(it+=i)==1);

    // it-=
    for(auto i=0; i<5; ++i)
        assert(*(it-=i)==1);
}

void unit_test_size_5(void)
{
	vector<int> v({1, 2, 3, 4, 5});
	MyCircularContainerIterator<vector<int>, vector<int>::iterator> vIt(v, v.begin());
    MyCircularContainerIterator<vector<int>, vector<int>::iterator> it(vIt);
    vector<int> output;

    // ++it
	for(auto i=0; i<7; ++i)
        output.push_back(*(++it));
    assert(output==vector<int>({2, 3, 4, 5, 1, 2, 3}));
    it = vIt;
    output.clear();

    // it++
	for(auto i=0; i<7; ++i)
        output.push_back(*(it++));
    assert(output==vector<int>({1, 2, 3, 4, 5, 1, 2}));
    it = vIt;
    output.clear();

    // --it
	for(auto i=0; i<7; ++i)
        output.push_back(*(--it));
    assert(output==vector<int>({5, 4, 3, 2, 1, 5, 4}));
    it = vIt;
    output.clear();

    // it--
	for(auto i=0; i<7; ++i)
        output.push_back(*(it--));
    assert(output==vector<int>({1, 5, 4, 3, 2, 1, 5}));
    it = vIt;
    output.clear();

    // it+
	for(auto i=0; i<7; ++i)
        output.push_back(*(it+i));
    assert(output==vector<int>({1, 2, 3, 4, 5, 1, 2}));
    it = vIt;
    output.clear();

    // it-
	for(auto i=0; i<7; ++i)
        output.push_back(*(it-i));
    assert(output==vector<int>({1, 5, 4, 3, 2, 1, 5}));
    it = vIt;
    output.clear();

    // it+=
	for(auto i=0; i<7; ++i)
        output.push_back(*(it+=i));
    assert(output==vector<int>({1, 2, 4, 2, 1, 1, 2}));
    it = vIt;
    output.clear();

    // it-=
	for(auto i=0; i<7; ++i)
        output.push_back(*(it-=i));
    assert(output==vector<int>({1, 5, 3, 5, 1, 1, 5}));
    it = vIt;
    output.clear();
}

int main(int argc, char **argv)
{
    unit_test_size_1();
    unit_test_size_5();

	return 0;
}
