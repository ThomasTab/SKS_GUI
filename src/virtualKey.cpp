#include <SKS_GUI/virtualKey.h>

VirtualKey::VirtualKey(int hwScanCode)
{
	_hwScanCode = hwScanCode;

	if (_hwScanCode > 0xA6) // Highest scancode
		_hwScanCode = 0xA6;

	_virtualKeyboard = new INPUT;
	_virtualKeyboard->type = INPUT_KEYBOARD; // Virtual input set on keyboard mode
	_virtualKeyboard->ki.time = 0; // Timestamp, 0 to leave it for the OS to take care of
	_virtualKeyboard->ki.wVk = 0; // Virtual-key code, 0 to use the hardware code (scancode)
	_virtualKeyboard->ki.dwExtraInfo = 0; // No extra infos
	_virtualKeyboard->ki.dwFlags = KEYEVENTF_SCANCODE; // wScan set the scancode and wVk is ignored
	_virtualKeyboard->ki.wScan = _hwScanCode; // Set the scancode

}

VirtualKey::VirtualKey()
{
	_hwScanCode = 0;
	_virtualKeyboard = new INPUT;
	_virtualKeyboard->type = INPUT_KEYBOARD; // Virtual input set on keyboard mode
	_virtualKeyboard->ki.time = 0; // Timestamp, 0 to leave it for the OS to take care of
	_virtualKeyboard->ki.wVk = 0; // Virtual-key code, 0 to use the hardware code (scancode)
	_virtualKeyboard->ki.dwExtraInfo = 0; // No extra infos
	_virtualKeyboard->ki.dwFlags = KEYEVENTF_SCANCODE; // wScan set the scancode and wVk is ignored
	_virtualKeyboard->ki.wScan = _hwScanCode; // Set the scancode to 0, which is an error code (in case the user didn't set the hw scancode)
}

VirtualKey::~VirtualKey()
{
	delete _virtualKeyboard;
}

void VirtualKey::hold(void)
{
	SendInput(1, _virtualKeyboard, sizeof(INPUT));
}

void VirtualKey::release(void)
{
	_virtualKeyboard->ki.dwFlags |= KEYEVENTF_KEYUP; // Set the action to release the key
	SendInput(1, _virtualKeyboard, sizeof(INPUT));
	_virtualKeyboard->ki.dwFlags = KEYEVENTF_SCANCODE; // Reset dwFlag to only the scancode, if KEYEVENTF_KEYUP isn't set, then the action will be to press the key
}

void VirtualKey::press(void)
{
	hold();
	release();
}

int VirtualKey::getKey(void)
{
	return _hwScanCode;
}

void VirtualKey::setKey(int hwScanCode)
{
	_hwScanCode = hwScanCode;
	_virtualKeyboard->ki.wScan = _hwScanCode; // Set the scancode the simulate
}
