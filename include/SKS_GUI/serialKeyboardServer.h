#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qmessagebox.h>
#include "ui_serialKeyboardServer.h"
#include "serialPannel.h"
#include <iostream>
#include "virtualKey.h"
#include <qevent.h>
#include "console.h"
#include <string>
#include <iostream>
#include <fstream>

class SerialKeyboardServer : public QMainWindow
{
	Q_OBJECT

public:
	SerialKeyboardServer(QWidget *parent = Q_NULLPTR);

private:
	Ui::SerialKeyboardServerClass ui;

	SerialPannel* pannel;
	bool waitingKeyGrab[6] = { false,false,false,false,false,false };
	VirtualKey keys[6];
	bool hold[6];
	Console* console;

private slots:
	void on_KeyGrab1_clicked();
	void on_KeyGrab2_clicked();
	void on_KeyGrab3_clicked();
	void on_KeyGrab4_clicked();
	void on_KeyGrab5_clicked();
	void on_KeyGrab6_clicked();

	void on_Hold1_stateChanged(int state);
	void on_Hold2_stateChanged(int state);
	void on_Hold3_stateChanged(int state);
	void on_Hold4_stateChanged(int state);
	void on_Hold5_stateChanged(int state);
	void on_Hold6_stateChanged(int state);

	void on_ButtonStart_clicked();
	void on_ButtonStop_clicked();
	void keyPressEvent(QKeyEvent* event);
	void serialData_Received(void);

	void on_actionSave_configuration_triggered();
	void on_actionLoad_configuration_triggered();
	void on_actionQuit_triggered();
	void on_actionHelp_triggered();
	void on_actionAbout_triggered();
};
