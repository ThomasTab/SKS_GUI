#pragma once
#include <list>
#include <QtSerialPort/qserialport.h>

class PannelCom_Serial : public QObject
{
	Q_OBJECT //Pour pouvoir utiliser les signals/slot
	public:


		PannelCom_Serial(const std::string port,const QSerialPort::BaudRate baudRate);
		PannelCom_Serial(const QSerialPort::BaudRate baudRate);
		~PannelCom_Serial(void);

		/**
		 * Set the serial port of the switch pannel
		 * @port string describing the serial port used ("COM10")
		**/
		void setPort(const std::string port);

		/**
		 * Set the baud rate used for the serial connection
		 * @baudRate QSerialPort::BaudRate describing the serial rate used
		**/
		void setBaudRate(const QSerialPort::BaudRate baudRate);

		/**
		 * Attempt to open a connection to the switch pannel
		 * @Return bool, true if the connection was successfull, false if not
		**/
		bool connectSerial(void);

		/**
		 * Close the connection to the switch pannel
		**/
		void disconnectSerial(void);

		/**
		 * Get the number of the last switched switch
		 * @Return int the number of the last switched switch
		**/
		int getSwitched(void);

		/**
		 * Get the QSerialPort, mainly to link the signal
		 * @Return QSerialPort* the QSerialPort object pointer
		**/
		QSerialPort* getQSerialPort(void);

	signals:
		void stateChanged(void);

	private:
		std::string _port;
		QSerialPort::BaudRate _baudRate;
		bool _autoPort;
		QSerialPort* _serial;
		
};

