#include <SKS_GUI/SKS_GUI_Refactor.h>
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SKS_GUI_Refactor w;
	w.show();
	w.setFixedSize(w.size()); //Désactive le redimensionnement
	return a.exec();
}
