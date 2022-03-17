#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int binarySearch(string arr[], int size, string key);

int main()
{
	//Create the matrix based on user input
	int size;
	cout << "How many vertices? ";
	cin >> size;
	cout << endl;
	int** graphMatrix = new int*[size];

	for (int i = 0; i < size; i++)
	{
		graphMatrix[i] = new int[size];
	}

	//set all values to 0
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			graphMatrix[i][j] = 0;
		}
	}

	//Ask the user to set the label names
	string* labels = new string[size];
	int vertexIndex = 1;
	while (vertexIndex <= size)
	{
		string label;
		cout << "What is the label for vertex " << vertexIndex << " ? ";
		cin >> label;
		cout << endl;
		labels[vertexIndex - 1] = label;
		vertexIndex++;
	}

	string edge;
	cout << "Define an edge by listing a pair of vertices, i.e. \"A B\", or -1 to stop" << endl;
	cin.ignore();
	getline(cin, edge);

	while (edge != "-1")
	{
		if (edge != "-1")
		{
			string wordStr;
			stringstream ss(edge);

			string edges[2];

			int i = 0;
			while (getline(ss, wordStr, ' '))
			{
				edges[i] = wordStr;
				i++;
			}

			int startVertice = binarySearch(labels, size-1, edges[0]);
			int endVertice = binarySearch(labels, size-1, edges[1]);

			graphMatrix[startVertice][endVertice]++;
			cout << "Added Edge " << edges[0] << "->" << edges[1] << endl << endl;
		}
		cout << "Define an edge by listing a pair of vertices, i.e. \"A B\", or -1 to stop" << endl;
		getline(cin, edge);
	}

	//print out the matrix
	cout << endl << "---MATRIX---" << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << graphMatrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	//print out all the edges
	cout << "Your edges are: ";
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (graphMatrix[i][j] > 0)
			{
				cout << labels[i] << labels[j] << ", ";
			}
		}
	}
	cout << endl;

	for (int i = 0; i < size; ++i) {
		delete[] graphMatrix[i];
	}
	delete[] graphMatrix;
	delete[] labels;
}

int binarySearch(string arr[], int size, string key)
{
	int lower = 0;
	int upper = size;
	int middle;
	while (lower <= upper)
	{
		middle = (upper + lower) / 2;
		if (key > arr[middle])
		{
			lower = middle + 1;
		}
		else if (key < arr[middle])
		{
			upper = middle - 1;
		}
		else
		{
			return middle;
		}
	}
	return -1;
}
