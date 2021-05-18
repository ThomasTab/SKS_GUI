#include <SKS_GUI/SerialKeyboardServer.h>

using namespace std;

SerialKeyboardServer::SerialKeyboardServer(QWidget *parent)
	: QMainWindow(parent)
{
	this->setWindowIcon(QIcon("icon.png"));
	ui.setupUi(this);
	console = new Console;
	ui.LayoutTerm->addWidget(console);

	for (int i = 0; i < 6; i++)
	{
		hold[i] = false;
	}

	pannel = new SerialPannel(QSerialPort::Baud9600);
	// Directly connect to the QSerialPort signal as signal forwarding doesn't seem to work anymore, VERY UGLY as we bypass the stateChanged() signal of SerialPannel
	connect(pannel->getQSerialPort(), &QSerialPort::readyRead, this, &SerialKeyboardServer::serialData_Received);
	on_actionLoad_configuration_triggered();// Auto load settings on startup
}

void SerialKeyboardServer::on_KeyGrab1_clicked()
{
	// Check if other keybind grabber waiting
	bool allFalse = true;
	for (bool b : waitingKeyGrab)
	{
		if (b)
			allFalse = false;
	}

	// If no other keybind grabber triggered
	if (allFalse)
	{
		waitingKeyGrab[0] = true;
		ui.KeyGrab1->setText("En attente d'appui ...");
		ui.KeyGrab2->setDisabled(true);
		ui.KeyGrab3->setDisabled(true);
		ui.KeyGrab4->setDisabled(true);
		ui.KeyGrab5->setDisabled(true);
		ui.KeyGrab6->setDisabled(true);
	}
	else if (waitingKeyGrab[0]) // Else, if this keybind grabber is already waiting reset it
	{
		ui.KeyGrab1->setText("Appuyer pour configurer");
		ui.KeyGrab2->setDisabled(false);
		ui.KeyGrab3->setDisabled(false);
		ui.KeyGrab4->setDisabled(false);
		ui.KeyGrab5->setDisabled(false);
		ui.KeyGrab6->setDisabled(false);
		waitingKeyGrab[0] = false;
	}
	
}

void SerialKeyboardServer::on_KeyGrab2_clicked()
{
	// Check if other keybind grabber waiting
	bool allFalse = true;

	for (bool b : waitingKeyGrab)
	{
		if (b)
			allFalse = false;
	}
	// If no other keybind grabber triggered
	if (allFalse)
	{
		waitingKeyGrab[1] = true;
		ui.KeyGrab2->setText("En attente d'appui ...");
		ui.KeyGrab1->setDisabled(true);
		ui.KeyGrab3->setDisabled(true);
		ui.KeyGrab4->setDisabled(true);
		ui.KeyGrab5->setDisabled(true);
		ui.KeyGrab6->setDisabled(true);
	}
	else if (waitingKeyGrab[1]) // Else, if this keybind grabber is already waiting reset it
	{
		ui.KeyGrab2->setText("Appuyer pour configurer");
		ui.KeyGrab1->setDisabled(false);
		ui.KeyGrab3->setDisabled(false);
		ui.KeyGrab4->setDisabled(false);
		ui.KeyGrab5->setDisabled(false);
		ui.KeyGrab6->setDisabled(false);
		waitingKeyGrab[1] = false;
	}
}

void SerialKeyboardServer::on_KeyGrab3_clicked()
{
	// Check if other keybind grabber waiting
	bool allFalse = true;
	for (bool b : waitingKeyGrab)
	{
		if (b)
			allFalse = false;
	}
	// If no other keybind grabber triggered
	if (allFalse)
	{
		waitingKeyGrab[2] = true;
		ui.KeyGrab3->setText("En attente d'appui ...");
		ui.KeyGrab1->setDisabled(true);
		ui.KeyGrab2->setDisabled(true);
		ui.KeyGrab4->setDisabled(true);
		ui.KeyGrab5->setDisabled(true);
		ui.KeyGrab6->setDisabled(true);
	}
	else if (waitingKeyGrab[2]) // Else, if this keybind grabber is already waiting reset it
	{
		ui.KeyGrab3->setText("Appuyer pour configurer");
		ui.KeyGrab1->setDisabled(false);
		ui.KeyGrab2->setDisabled(false);
		ui.KeyGrab4->setDisabled(false);
		ui.KeyGrab5->setDisabled(false);
		ui.KeyGrab6->setDisabled(false);
		waitingKeyGrab[2] = false;
	}
}

void SerialKeyboardServer::on_KeyGrab4_clicked()
{
	// Check if other keybind grabber waiting
	bool allFalse = true;
	for (bool b : waitingKeyGrab)
	{
		if (b)
			allFalse = false;
	}
	// If no other keybind grabber triggered
	if (allFalse)
	{
		waitingKeyGrab[3] = true;
		ui.KeyGrab4->setText("En attente d'appui ...");
		ui.KeyGrab1->setDisabled(true);
		ui.KeyGrab2->setDisabled(true);
		ui.KeyGrab3->setDisabled(true);
		ui.KeyGrab5->setDisabled(true);
		ui.KeyGrab6->setDisabled(true);
	}
	else if (waitingKeyGrab[3]) // Else, if this keybind grabber is already waiting reset it
	{
		ui.KeyGrab4->setText("Appuyer pour configurer");
		ui.KeyGrab1->setDisabled(false);
		ui.KeyGrab2->setDisabled(false);
		ui.KeyGrab3->setDisabled(false);
		ui.KeyGrab5->setDisabled(false);
		ui.KeyGrab6->setDisabled(false);
		waitingKeyGrab[3] = false;
	}
}

void SerialKeyboardServer::on_KeyGrab5_clicked()
{
	// Check if other keybind grabber waiting
	bool allFalse = true;
	for (bool b : waitingKeyGrab)
	{
		if (b)
			allFalse = false;
	}
	// If no other keybind grabber triggered
	if (allFalse)
	{
		waitingKeyGrab[4] = true;
		ui.KeyGrab5->setText("En attente d'appui ...");
		ui.KeyGrab1->setDisabled(true);
		ui.KeyGrab2->setDisabled(true);
		ui.KeyGrab3->setDisabled(true);
		ui.KeyGrab4->setDisabled(true);
		ui.KeyGrab6->setDisabled(true);
	}
	else if (waitingKeyGrab[4]) // Else, if this keybind grabber is already waiting reset it
	{
		ui.KeyGrab5->setText("Appuyer pour configurer");
		ui.KeyGrab1->setDisabled(false);
		ui.KeyGrab2->setDisabled(false);
		ui.KeyGrab3->setDisabled(false);
		ui.KeyGrab4->setDisabled(false);
		ui.KeyGrab6->setDisabled(false);
		waitingKeyGrab[4] = false;
	}
}

void SerialKeyboardServer::on_KeyGrab6_clicked()
{
	// Check if other keybind grabber waiting
	bool allFalse = true;
	for (bool b : waitingKeyGrab)
	{
		if (b)
			allFalse = false;
	}
	// If no other keybind grabber triggered
	if (allFalse)
	{
		waitingKeyGrab[5] = true;
		ui.KeyGrab6->setText("En attente d'appui ...");
		ui.KeyGrab1->setDisabled(true);
		ui.KeyGrab2->setDisabled(true);
		ui.KeyGrab3->setDisabled(true);
		ui.KeyGrab4->setDisabled(true);
		ui.KeyGrab5->setDisabled(true);
	}
	else if (waitingKeyGrab[5]) // Else, if this keybind grabber is already waiting reset it
	{
		ui.KeyGrab6->setText("Appuyer pour configurer");
		ui.KeyGrab1->setDisabled(false);
		ui.KeyGrab2->setDisabled(false);
		ui.KeyGrab3->setDisabled(false);
		ui.KeyGrab4->setDisabled(false);
		ui.KeyGrab5->setDisabled(false);
		waitingKeyGrab[5] = false;
	}
}

void SerialKeyboardServer::on_Hold1_stateChanged(int state)
{
	hold[0] = state;
}

void SerialKeyboardServer::on_Hold2_stateChanged(int state)
{
	hold[1] = state;
}

void SerialKeyboardServer::on_Hold3_stateChanged(int state)
{
	hold[2] = state;
}

void SerialKeyboardServer::on_Hold4_stateChanged(int state)
{
	hold[3] = state;
}

void SerialKeyboardServer::on_Hold5_stateChanged(int state)
{
	hold[4] = state;
}

void SerialKeyboardServer::on_Hold6_stateChanged(int state)
{
	hold[5] = state;
}

void SerialKeyboardServer::on_ButtonStart_clicked()
{
	pannel->disconnect();
	ui.labelStatus->setText("Server stopped");
	ui.progressBar->setMaximum(1);
	if (ui.InputPort->text().toLatin1() != "")
	{
		pannel->setPort(ui.InputPort->text().toStdString());
		if (!pannel->connectSerial())
		{
			console->putData("> Failed to open port ");
			console->putData(ui.InputPort->text().toLatin1());
			console->putData("@9600 bauds\n");
		}
		else
		{
			console->putData("> Port ");
			console->putData(ui.InputPort->text().toLatin1());
			console->putData("@9600 bauds successfully openned\n");
			ui.labelStatus->setText("Server started");
			ui.progressBar->setMaximum(0);
		}
	}
	else
	{
		for (int i = 2; i <= 255; i++)
		{
			pannel->setPort("COM"+to_string(i));

			if (!pannel->connectSerial())
			{
				console->putData("> Failed to open port ");
				console->putData(QByteArray::fromStdString("COM" + to_string(i)));
				console->putData("@9600 bauds\n");
			}
			else
			{
				console->putData("> Port ");
				console->putData(QByteArray::fromStdString("COM" + to_string(i)));
				console->putData("@9600 bauds successfully openned\n");
				ui.InputPort->setText(QByteArray::fromStdString("COM" + to_string(i)));
				ui.labelStatus->setText("Server started");
				ui.progressBar->setMaximum(0);
				break;
			}
		}
	}
}

void SerialKeyboardServer::on_ButtonStop_clicked()
{
	pannel->disconnectSerial();
	console->putData("> Port ");
	console->putData(ui.InputPort->text().toLatin1());
	console->putData("@9600 bauds successfully closed\n");
	ui.labelStatus->setText("Server stopped");
	ui.progressBar->setMaximum(1);
}

void SerialKeyboardServer::keyPressEvent(QKeyEvent* evt)
{
	int scancode = evt->nativeScanCode();
	
	if (waitingKeyGrab[0])
	{
		ui.KeyGrab1->setText(evt->text());
		keys[0].setKey(scancode);
	}
	if (waitingKeyGrab[1])
	{
		
		ui.KeyGrab2->setText(evt->text());
		keys[1].setKey(scancode);
	}
	if (waitingKeyGrab[2])
	{
		ui.KeyGrab3->setText(evt->text());
		keys[2].setKey(scancode);
	}
	if (waitingKeyGrab[3])
	{
		ui.KeyGrab4->setText(evt->text());
		keys[3].setKey(scancode);
	}
	if (waitingKeyGrab[4])
	{
		ui.KeyGrab5->setText(evt->text());
		keys[4].setKey(scancode);
	}
	if (waitingKeyGrab[5])
	{
		ui.KeyGrab6->setText(evt->text());
		keys[5].setKey(scancode);
	}

	for (int i = 0; i <= 5; i++)
		waitingKeyGrab[i] = false;

	ui.KeyGrab1->setDisabled(false);
	ui.KeyGrab2->setDisabled(false);
	ui.KeyGrab3->setDisabled(false);
	ui.KeyGrab4->setDisabled(false);
	ui.KeyGrab5->setDisabled(false);
	ui.KeyGrab6->setDisabled(false);

}

void SerialKeyboardServer::serialData_Received(void)
{
	switch (pannel->getSwitched())
	{
		case 1:
			console->putData("> Switch 1 on\n");
			if (hold[0])
				keys[0].hold();
			else
				keys[0].press();
			break;
		case 2:
			console->putData("> Switch 2 on\n");
			if (hold[1])
				keys[1].hold();
			else
				keys[1].press();
			break;
		case 3:
			console->putData("> Switch 3 on\n");
			if (hold[2])
				keys[2].hold();
			else
				keys[2].press();
			break;
		case 4:
			console->putData("> Switch 4 on\n");
			if (hold[3])
				keys[3].hold();
			else
				keys[3].press();
			break;
		case 5:
			console->putData("> Switch 5 on\n");
			if (hold[4])
				keys[4].hold();
			else
				keys[4].press();
			break;
		case 6:
			console->putData("> Switch 6 on\n");
			if (hold[5])
				keys[5].hold();
			else
				keys[5].press();
			break;
		case 7:
			console->putData("> Switch 1 off\n");
			if (hold[0])
				keys[0].release();
			keys[0].press();
			break;
		case 8:
			console->putData("> Switch 2 off\n");
			if (hold[1])
				keys[1].release();
			keys[1].press();
			break;
		case 9:
			console->putData("> Switch 3 off\n");
			if (hold[2])
				keys[2].release();
			keys[2].press();
			break;
		case 10:
			console->putData("> Switch 4 off\n");
			if (hold[3])
				keys[3].release();
			keys[3].press();
			break;
		case 11:
			console->putData("> Switch 5 off\n");
			if (hold[4])
				keys[4].release();
			keys[4].press();
			break;
		case 12:
			console->putData("> Switch 6 off\n");
			if (hold[5])
				keys[5].release();
			keys[5].press();
			break;
	}
}

void SerialKeyboardServer::on_actionSave_configuration_triggered()
{
	ofstream file;

	file.open("settings.cfg");

	file << ui.Name1->text().toStdString() << " :" << ui.KeyGrab1->text().toStdString() << ":" << to_string(keys[0].getKey()) << ":" << to_string(hold[0]) << "\n";
	file << ui.Name2->text().toStdString() << " :" << ui.KeyGrab2->text().toStdString() << ":" << to_string(keys[1].getKey()) << ":" << to_string(hold[1]) << "\n";
	file << ui.Name3->text().toStdString() << " :" << ui.KeyGrab3->text().toStdString() << ":" << to_string(keys[2].getKey()) << ":" << to_string(hold[2]) << "\n";
	file << ui.Name4->text().toStdString() << " :" << ui.KeyGrab4->text().toStdString() << ":" << to_string(keys[3].getKey()) << ":" << to_string(hold[3]) << "\n";
	file << ui.Name5->text().toStdString() << " :" << ui.KeyGrab5->text().toStdString() << ":" << to_string(keys[4].getKey()) << ":" << to_string(hold[4]) << "\n";
	file << ui.Name6->text().toStdString() << " :" << ui.KeyGrab6->text().toStdString() << ":" << to_string(keys[5].getKey()) << ":" << to_string(hold[5]) << "\n";
	file << ui.InputPort->text().toStdString();

	file.close();
	console->putData("> Settings successfully saved\n");
}

void SerialKeyboardServer::on_actionLoad_configuration_triggered()
{
	ifstream file;
	string line;
	char* lineChar;

	QPushButton* keyGrabArray[6]; // Array of the keygrabs, used to simplify the code when using for loop
	QCheckBox* holdChecksArray[6]; // Array of the checkboxes, used to simplify the code when using for loop
	QLineEdit* namesArray[6]; // Array of the names, used to simplify the code when using for loop

	keyGrabArray[0] = ui.KeyGrab1;
	keyGrabArray[1] = ui.KeyGrab2;
	keyGrabArray[2] = ui.KeyGrab3;
	keyGrabArray[3] = ui.KeyGrab4;
	keyGrabArray[4] = ui.KeyGrab5;
	keyGrabArray[5] = ui.KeyGrab6;

	holdChecksArray[0] = ui.Hold1;
	holdChecksArray[1] = ui.Hold2;
	holdChecksArray[2] = ui.Hold3;
	holdChecksArray[3] = ui.Hold4;
	holdChecksArray[4] = ui.Hold5;
	holdChecksArray[5] = ui.Hold6;

	namesArray[0] = ui.Name1;
	namesArray[1] = ui.Name2;
	namesArray[2] = ui.Name3;
	namesArray[3] = ui.Name4;
	namesArray[4] = ui.Name5;
	namesArray[5] = ui.Name6;

	file.open("settings.cfg");
	if (file) {
		for (int i = 0; i < 6; i++)
		{
			getline(file, line); // Read a line of the cfg file("name:text:scancode:holdstate")
			lineChar = strdup(line.c_str()); // Convert it to char* to use strtok
			lineChar = strtok(lineChar, ":"); // Search first token : name
			namesArray[i]->setText(lineChar);
			lineChar = strtok(NULL, ":"); // Search second token : text
			keyGrabArray[i]->setText(lineChar);
			lineChar = strtok(NULL, ":"); // Search third token : scancode
			keys[i].setKey(atoi(lineChar));
			lineChar = strtok(NULL, ":"); // Search fourth token : holdstate
			hold[i] = atoi(lineChar);
			holdChecksArray[i]->setChecked(hold[i]);
		}
		getline(file, line); // Get last line : COM port
		ui.InputPort->setText(QString::fromStdString(line));
		file.close();
		console->putData("> Settings successfully loaded\n");
	}
}

void SerialKeyboardServer::on_actionQuit_triggered()
{
	qApp->quit();
}

void SerialKeyboardServer::on_actionHelp_triggered()
{
	QMessageBox::information(this, "Serial Keyboard Server Help", "Not implemented yet, sorry !");
}

void SerialKeyboardServer::on_actionAbout_triggered()
{
	QMessageBox::about(this, "About Serial Keyboard Server", "Serial Keyboard Server 0.0220\n01/02/2020\n\nDevelopped by : Thomas Tabuteau\nUsing : Qt and Visual Studio\nGitHub : https://github.com/ThomasTab");
}
