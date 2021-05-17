#include <SKS_GUI/vKey.h>

vKey::vKey(int hwScanCode)
{
	_hwScanCode = hwScanCode;

	if (_hwScanCode > 0xA6) //Highest scancode
		_hwScanCode = 0xA6;

	_vKeyboard = new INPUT;
	_vKeyboard->type = INPUT_KEYBOARD; //Virtual input set on keyboard mode
	_vKeyboard->ki.time = 0; //Timestamp, 0 to leave it for the OS to take care of
	_vKeyboard->ki.wVk = 0; //Virtual-key code, 0 to use the hardware code (scancode)
	_vKeyboard->ki.dwExtraInfo = 0; //No extra infos
	_vKeyboard->ki.dwFlags = KEYEVENTF_SCANCODE; //wScan set the scancode and wVk is ignored
	_vKeyboard->ki.wScan = _hwScanCode; //Set the scancode

}

vKey::vKey()
{
	_hwScanCode = 0;
	_vKeyboard = new INPUT;
	_vKeyboard->type = INPUT_KEYBOARD; //Virtual input set on keyboard mode
	_vKeyboard->ki.time = 0; //Timestamp, 0 to leave it for the OS to take care of
	_vKeyboard->ki.wVk = 0; //Virtual-key code, 0 to use the hardware code (scancode)
	_vKeyboard->ki.dwExtraInfo = 0; //No extra infos
	_vKeyboard->ki.dwFlags = KEYEVENTF_SCANCODE; //wScan set the scancode and wVk is ignored
	_vKeyboard->ki.wScan = _hwScanCode; //Set the scancode to 0, which is an error code (in case the user didn't set the hw scancode)
}

vKey::~vKey()
{
	delete _vKeyboard;
}

void vKey::hold(void)
{
	SendInput(1, _vKeyboard, sizeof(INPUT));
}

void vKey::release(void)
{
	_vKeyboard->ki.dwFlags |= KEYEVENTF_KEYUP; //Set the action to release the key
	SendInput(1, _vKeyboard, sizeof(INPUT));
	_vKeyboard->ki.dwFlags = KEYEVENTF_SCANCODE; //Reset dwFlag to only the scancode, if KEYEVENTF_KEYUP isn't set, then the action will be to press the key
}

void vKey::press(void)
{
	hold();
	release();
}

int vKey::getKey(void)
{
	return _hwScanCode;
}

void vKey::setKey(int hwScanCode)
{
	_hwScanCode = hwScanCode;
	_vKeyboard->ki.wScan = _hwScanCode; //Set the scancode the simulate
}
