class Node
{
private:
	char value;
	int frequency;

public:
	Node(char val, int freq);
	Node* leftside;
	Node* rightside;
	char getvalue();
	int getfrequency();
	
};