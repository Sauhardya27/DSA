#include <iostream>
#include <queue>
using namespace std;

void showq(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty()) {
        cout << " " << g.front();
        g.pop();
    }
    cout << '\n';
}

int main(){
	queue<int> q;
	q.push(11);
	q.push(13);
	q.push(15);
	q.push(17);

	cout << "Size of the queue is: " << q.size() << endl;
	cout << "Front element: " << q.front() << endl;
	cout << "Rear element: " << q.back() << endl;

	if(q.empty())
		cout << "Queue is empty" << endl;
	else	
		cout << "Queue is not empty" << endl;

	q.pop();
	q.pop();

	cout << "Queue elements are: ";
	showq(q);
	cout << endl;
	return 0;
}