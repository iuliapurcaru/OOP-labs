#include <iostream>
#include <list>

using namespace std;

class Component
{
private:
	Component* parent;

public:
	void setParent(Component* parent_input)
	{
		this->parent = parent_input;
	}

	Component* getParent()
	{
		return this->parent;
	}

	virtual void add(Component* component) {}
	virtual void remove(Component* component) {}
	virtual string operation() = 0;
};

class Leaf : public Component
{
public:
	string operation()
	{
		return "Leaf";
	}
};

class Composite : public Component
{
private:
	list<Component*> children;

public:
	void add(Component* component)
	{
		this->children.push_back(component);
		component->setParent(this);
	}

	void remove(Component* component)
	{
		children.remove(component);
		component->setParent(nullptr);
	}

	string operation()
	{
		string result;
		for (Component* child : children)
		{
			if (child == children.back())
			{
				result += child->operation();
			}
			else
			{
				result += child->operation() + " + ";
			}
		}
		return "Branch(" + result + ")";
	}
};

int main()
{
	Component* leaf1 = new Leaf;
	Component* leaf2 = new Leaf;

	Component* branch1 = new Composite;
	Component* branch2 = new Composite;
	Component* branch3 = new Composite;

	Component* tree = new Composite;

	branch1->add(leaf1);
	branch2->add(leaf1);
	branch2->add(leaf2);
	branch3->add(leaf2);
	branch1->add(branch3);

	tree->add(branch1);
	tree->add(branch2);

	cout << "Branch 1: " << branch1->operation() << endl;
	cout << "Branch 2: " << branch2->operation() << endl;

	cout << "Tree: " << tree->operation() << endl;

	delete tree;
	delete branch1;
	delete branch2;
	delete branch3;
	delete leaf1;
	delete leaf2;

	return 0;
}

/*
Avantaje:
- are un numar mai mic de obiecte deci nu ocupa multa memorie
- pot fi introduse usor tipuri de elemente noi

Dezavantaje
- poate fi prea general deoarece devine dificil de restrictionat obiectele care pot fi incluse in grupul format

*/