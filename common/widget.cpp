#include "widget.hpp"

namespace OpenThermoQt
{
  OpenThermoWidget::OpenThermoWidget( QWidget *parent, Qt::WindowFlags f ) : 
    QWidget( parent, f )
  {
	ui.setupUi(this);
  }
  
  OpenThermoWidget::~OpenThermoWidget()
  {}
  
  void OpenThermoWidget::setMolecule(Molecule *molecule)
  {}
  
  
}
