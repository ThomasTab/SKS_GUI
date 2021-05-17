#include <SKS_GUI/PannelCom_Serial.h>

PannelCom_Serial::PannelCom_Serial(const std::string port, const QSerialPort::BaudRate baudRate)
{
	_port = port;
	_autoPort = false;
	_baudRate = baudRate;
	_serial = new QSerialPort;
}

PannelCom_Serial::PannelCom_Serial(const QSerialPort::BaudRate baudRate)
{
	_port = "COM0";
	_autoPort = true;
	_baudRate = baudRate;
	_serial = new QSerialPort;
}

PannelCom_Serial::~PannelCom_Serial(void)
{
	delete _serial;
}

void PannelCom_Serial::setPort(const std::string port)
{
	_port = port;
}

void PannelCom_Serial::setBaudRate(const QSerialPort::BaudRate baudRate)
{
	_baudRate = baudRate;
}

bool PannelCom_Serial::connectSerial(void)
{
	//Config de l'object serial
	_serial->setBaudRate(_baudRate);
	_serial->setPortName(QString::fromStdString(_port));

	if (_serial->open(QIODevice::ReadOnly)) // Ouverture de la connexion en lecture seule
	{
		//connect(_serial, &QSerialPort::readyRead, this, &PannelCom_Serial::stateChanged); //Passage du signal readyRead (reception de données serial) de _serial au signal stateChanged de cet objet
		return true;
	}
	else
		return false;
}

void PannelCom_Serial::disconnectSerial(void)
{
	_serial->close();
}

int PannelCom_Serial::getSwitched(void)
{
	return(std::stoi(_serial->readAll().toStdString())); //Retourne la premiere valeur recu sur le port serie convertit d'un char en int ("0"-48 -> 0 | "1"-48 -> 1 ...)
	_serial->clear();
}

QSerialPort* PannelCom_Serial::getQSerialPort(void) {
	return _serial;
}