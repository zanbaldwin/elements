#pragma once
#include "Jetsam.h"
#include "Flotsam.h"
#include "Console.h"
#include "RandomNumber.h"
#include "Element.h"
#include "vector"
#include <list>

using namespace std;

#define NUMBER 10

// This solution demonstrates the use of a STL vector and list in addition to using arrays.

int main()
{
	Console console;
	RandomNumber rnd;

    // ++++++++++++++++++++++++++++++++++++++++++++++
    // +          TEST CUSTOM CLASSES               +
    // ++++++++++++++++++++++++++++++++++++++++++++++
    Flotsam flotsam(rnd, console);
    Jetsam jetsam(rnd, console);

	// ++++++++++++++++++++++++++++++++++++++++++++++
	// +                 ARRAY                      +
	// ++++++++++++++++++++++++++++++++++++++++++++++
	Element elements[4] = {
        Element(rnd, console),
        Element(rnd, console),
        Element(rnd, console),
        Element(rnd, console)
    };
	
	for(int i = 0; i< 4; i++)
	{
		elements[i].printAt();
	}
	Sleep(1000);
	console.clear();

	// ++++++++++++++++++++++++++++++++++++++++++++++
	// +                VECTOR                      +
	// ++++++++++++++++++++++++++++++++++++++++++++++
	// create an empty STL vector called flotsam that will hold elements.
	vector<Element> flotsam;

	// use a loop to add elements to flotsam
	for(int i = 0; i < NUMBER; i++)
	{
		flotsam.push_back(Element(rnd, console));
	}

	// declare an Element iterator - an iterator is a special kind of pointer
	vector<Element>::iterator ptr;
	// set the iterator to the first element
	ptr = flotsam.begin();
	// use a loop and the iterator to output the flotsam
	while(ptr!=flotsam.end())
	{
		ptr->printAt();
		ptr++; // moves the pointer to the next object
	}
	Sleep(1000);
	console.clear();

	// you can also treat a vector like an array as follows
	for(int i = 0; i < NUMBER; i++)
	{
		flotsam[i].printAt();
	}
	Sleep(1000);
	console.clear();
	
	// ++++++++++++++++++++++++++++++++++++++++++++++
	// +                  LIST                      +
	// ++++++++++++++++++++++++++++++++++++++++++++++

	// create an empty STL list called jetsam that will hold elements.
	list<Element> jetsam;

	// use a loop to add elements to jetsam
	for(int i = 0; i<NUMBER; i++)
	{
		jetsam.push_back(Element(rnd, console));
	}

	// declare an Element iterator
	list<Element>::iterator itr;
	// set the iterator to the first element
	itr = jetsam.begin();
	// use a loop and the iterator to output the jetsam
	while(itr!=jetsam.end())
	{
		itr->printAt();
		itr++;
	}
	Sleep(1000);
	console.clear();

	// let's remove an object from the list
	jetsam.pop_back();
	// and output the remaining objects

	// set the iterator to the first element
	itr = jetsam.begin();
	// use a loop and the iterator to output the jetsam
	while(itr!=jetsam.end())
	{
		itr->printAt();
		itr++;
	}

	// ++++++++++++++++++++++++++++++++++++++++++++++
	// +             LIST OF POINTERS               +
	// ++++++++++++++++++++++++++++++++++++++++++++++

	// create an empty STL list called jetsam that will hold elements.
	list<Element*> objects;

	// use a loop to add elements to flotsam
	for(int i = 0; i<NUMBER; i++)
	{
		objects.push_back(new Element(rnd, console));
	}

	// declare an Element iterator
	list<Element*>::iterator obj;
	// set the iterator to the first element of the list
	obj = objects.begin();
	// use a loop and the iterator to output the flotsam
	while(obj!=objects.end())
	{
		// special syntax needed to dereference list pointers
		(*obj)->printAt();
		obj++;
	}
	Sleep(1000);
	console.clear();

	// remember that we can store any derived class pointer in a container of base class pointers
}