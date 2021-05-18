#include <SKS_GUI/serialKeyboardServer.h>
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SerialKeyboardServer w;
	w.show();
	w.setFixedSize(w.size()); // Disable resizing
	return a.exec();
}
