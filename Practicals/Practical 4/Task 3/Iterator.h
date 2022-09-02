#include <exception>
#include <string>
using namespace std;

#ifndef __Iterator_h__
#define __Iterator_h__

// #include "Client.h"

class Client;
class Iterator;

__abstract class Iterator
{
	public: Client* _unnamed_Client_;

	public: virtual void first() = 0;

	public: virtual void next() = 0;

	public: virtual bool hasNext() = 0;

	public: virtual string current() = 0;
};

#endif
