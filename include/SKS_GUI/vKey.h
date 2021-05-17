#pragma once

#include <Windows.h>
#include <list>

class vKey
{
	public:
		vKey(int hwScanCode);
		vKey();
		~vKey();

		/**
		 * Simulate the holding of this virtual key
		**/
		void hold(void);

		/**
		 * Simulate the release of the currently held virtual key
		**/
		void release(void);

		/**
		 * Simulate the press of this virtual key
		**/
		void press(void);

		/**
		 * Get the current hardware scancode of this virtual key
		 * @Return int the current hardware scancode of this virtual key
		**/
		int getKey(void);

		/**
		 * Set the hardware scancode of this virtual key
		 * @hwScanCode int hardware scancode of a key
		**/
		void setKey(int hwScanCode);

	private:
		int _hwScanCode;
		INPUT* _vKeyboard;

};

