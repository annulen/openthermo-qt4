#include <QtGui/QApplication>
#include <QtGui/QMainWindow>
#include <QtCore/QTranslator>

#include "widget.hpp"

using namespace OpenThermoQt;

int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  
  // Load the translations  
  QPointer <QTranslator> otTranslator = createTranslator();
  if (otTranslator)
    qApp->installTranslator(otTranslator);
  
  QMainWindow *window = new QMainWindow();
  OpenThermoWidget *widget = new OpenThermoWidget(window);
  window->setCentralWidget(widget);
  window->show();
  app.exec();
  return 0;
 }
 
