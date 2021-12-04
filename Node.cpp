#include "Node.hpp"


Node::Node(char val, int freq)
{
    this->value = val;
	this->frequency = freq;
	this->leftside = nullptr;
	this->rightside = nullptr;
}

char Node::getvalue()
{
	return this->value;
}

int Node::getfrequency()
{
	return this->frequency;
}