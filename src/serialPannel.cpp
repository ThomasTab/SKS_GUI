#include <SKS_GUI/serialPannel.h>

SerialPannel::SerialPannel(const std::string port, const QSerialPort::BaudRate baudRate)
{
	_port = port;
	_autoPort = false;
	_baudRate = baudRate;
	_serial = new QSerialPort;
}

SerialPannel::SerialPannel(const QSerialPort::BaudRate baudRate)
{
	_port = "COM0";
	_autoPort = true;
	_baudRate = baudRate;
	_serial = new QSerialPort;
}

SerialPannel::~SerialPannel(void)
{
	delete _serial;
}

void SerialPannel::setPort(const std::string port)
{
	_port = port;
}

void SerialPannel::setBaudRate(const QSerialPort::BaudRate baudRate)
{
	_baudRate = baudRate;
}

bool SerialPannel::connectSerial(void)
{
	// Serial port setup
	_serial->setBaudRate(_baudRate);
	_serial->setPortName(QString::fromStdString(_port));

	if (_serial->open(QIODevice::ReadOnly)) // Try to open serial connection read-only
	{
		//connect(_serial, &QSerialPort::readyRead, this, &SerialPannel::stateChanged); //Passage du signal readyRead (reception de données serial) de _serial au signal stateChanged de cet objet
		return true;
	}
	else
		return false;
}

void SerialPannel::disconnectSerial(void)
{
	_serial->close();
}

int SerialPannel::getSwitched(void)
{
	return(std::stoi(_serial->readAll().toStdString())); // Return the first value received on the serial port converted from a char to an int ("0"-48 -> 0 | "1"-48 -> 1 ...)
	_serial->clear();
}

QSerialPort* SerialPannel::getQSerialPort(void) {
	return _serial;
}