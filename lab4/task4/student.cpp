#include <iostream>
#include <string>
#include "LinkedList.h"
#include "student.h"
#include "Stack.h"
using namespace std;

// test file for stack
template <typename T>
T getMax(const T &a, const T &b)
{
    return (a < b) ? b : a;
}

int main()
{
    cout << "\n--- Stack Demo ---\n";
    Stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    st.display(); // 30 20 10
    cout << "Peek: " << st.peek() << endl;

    st.pop();
    st.display(); // 20 10

    st.pop();
    st.pop();
    st.pop(); // underflow

    return 0;

}
