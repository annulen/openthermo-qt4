
#include "openthermoextension.h"

#include <QtGui/QAction>
#include <QtGui/QDialog>

#include <avogadro/glwidget.h>
#include <avogadro/molecule.h>

using namespace OpenThermoQt;

namespace Avogadro
{
  OpenThermoExtension::OpenThermoExtension(QObject *parent) : Extension(parent)
                                                              m_molecule(0),
                                                              m_dialog(0),
                                                              m_widget(0)
  {
    QAction *action = new QAction( this );
    action->setText( tr("OpenThermo" ));
    m_actions.append( action );
  }
  
  OpenThermoExtension::~OpenThermoExtension()
  {}
  
  QList<QAction *> OpenThermoExtension::actions() const
  {
    return m_actions;
  }
  
  QString OpenThermoExtension::menuPath(QAction *action) const
  {
    Q_UNUSED(action)
    return tr("&Build");
  }
  
  void OpenThermoExtension::setMolecule(Molecule *molecule)
  {
    if (m_molecule)
      disconnect( m_molecule, 0, 0, 0 );

    m_molecule = molecule;

    if (m_dialog) {
      m_dialog->setMolecule(molecule);
    }
  } 
  
  QUndoCommand* OpenThermoExtension::performAction( QAction *action, GLWidget *widget )
  {
    Q_UNUSED(action)
    QUndoCommand *undo = 0;
    
    if (!m_molecule)
      return 0;

    // Disconnect in case we're attached to a new widget
    if (m_widget) {
      disconnect( m_molecule, 0, 0, 0 );
      if (m_dialog) {
        m_dialog->setMolecule(m_molecule);
      }
    }

    if (widget)
      m_widget = widget;    

    if (!m_dialog) {
      m_dialog = new QDialog(m_widget);
      QVBoxLayout *layout = new QVBoxLayout(dialog);
      dialog->setLayout(layout);
      if (!m_otWidget)
        m_otWidget = new OpenThermoWidget(m_dialog);
      layout->addWidget(m_otWidget);
      dialog->setWindowTitle("OpenThermo");      
    }
    m_dialog->show();
    return undo;
  }

} // end namespace Avogadro

Q_EXPORT_PLUGIN2(openthermoextension, Avogadro::OpenThermoExtensionFactory)
