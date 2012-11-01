

#include "CPPGravitySubscriber.h"
#include <iostream>

using namespace gravity;

CPPGravitySubscriber::~CPPGravitySubscriber()
{}

void CPPGravitySubscriber::subscriptionFilled(const std::vector< shared_ptr<GravityDataProduct> >& dataProducts)
{
    int* lengths = new int[dataProducts.size()];
    int arrayLength = 0;
    for (int index = 0; index < dataProducts.size(); index++)
    {
        arrayLength += dataProducts[index]->getSize();
        lengths[index] = dataProducts[index]->getSize();
    }
    unsigned char* array = new unsigned char[arrayLength];
    int offset = 0;
    for (int index = 0; index < dataProducts.size(); index++)
    {
        dataProducts[index]->serializeToArray(&array[offset]);
        offset += lengths[index];
    }
    subscriptionFilled((char*)array, arrayLength, lengths, dataProducts.size());
	delete lengths;
	delete array;
}

int CPPGravitySubscriber::subscriptionFilled(char* array, int arrayLength, int* lengths, int length)
{
    return 0;
}

