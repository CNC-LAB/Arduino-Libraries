/**
 *  \file Vector_Basic.ino
 *  \brief 
 *  This example shows how to use Vector library to manipulate a byte array easily
 */

#include <Vector.h>

Vector myData(10);

void setup() 
{
	Serial.begin(9600);
	myData.Clear();
	
	for(int i = 0; i < 10; i++)
		myData.buffer[i] = i;
		
	Serial.println("Initial Array Content");
	printVector(myData);
	
	testPassByRefrenceFunction(myData);	//Zero-out element 5 of myData by sending Vector by reference
	Serial.println("\n\nVector content after passing by reference to a function that zeroes out element 5");
	printVector(myData);
    Serial.println("Vector element 5 has been zeroed out after passing by refrence");
	
	testPassByValueFunction(myData); // Does not Zero-out element 6 because it is passed by value
	Serial.println("\n\nVector content after passing by value to a function that zeroes out element 6");
	printVector(myData);
    Serial.println("Vector element 6 has NOT been zeroed out after passing by value");
}

void loop()
{
	
}

//Function that takes a Vector input by reference
//This function zeroes out element 5 of the vector
void testPassByRefrenceFunction(Vector &v)
{
	v.buffer[5] = 0;
}

//Function that takes a Vector input by value
//This function zeroes out element 6 of the vector
void testPassByValueFunction(Vector v)
{
	v.buffer[6] = 0;
}

//Function that prints a Vector content
void printVector(Vector v)
{
	Serial.print("Idx:\t");
	for(int i = 0; i < v.length; i++)
	{
		Serial.print(i);
		Serial.print("\t");
	}
	Serial.print("\nVal:\t");
	for(int i = 0; i < v.length; i++)
	{
		Serial.print(v.buffer[i]);
		Serial.print("\t");
	}
	Serial.println();
}