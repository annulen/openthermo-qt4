#ifndef OPENTHERMOEXTENSION_H
#define OPENTHERMOEXTENSION_H

#include <AvogadroWidget/extension.h>
#include "widget.hpp"

namespace Avogadro {

  class OpenThermoExtension : public Extension
  {
    Q_OBJECT
      AVOGADRO_EXTENSION("OpenThermo", tr("OpenThermo"),
                         tr("OpenThermo integration"))

    public:
      //! Constructor
      OpenThermoExtension(QObject *parent=0);
      //! Deconstructor
      virtual ~OpenThermoExtension();

      virtual QList<QAction *> actions() const;
      virtual QString menuPath(QAction *action) const;

      virtual QDockWidget * dockWidget();
      virtual QUndoCommand* performAction(QAction *action, GLWidget *widget);

      virtual void setMolecule(Molecule *molecule);

    private:
      QList<QAction *> m_actions;
      Molecule *m_molecule;
	  QDialog *m_dialog;
	  OpenThermoQt::OpenThermoWidget *m_otWidget;
	  GLWidget *m_glWidget;

    private Q_SLOTS:

  };

  class OpenThermoExtensionFactory : public QObject, public PluginFactory
  {
    Q_OBJECT
    Q_INTERFACES(Avogadro::PluginFactory)
    AVOGADRO_EXTENSION_FACTORY(OpenThermoExtension)
  };

} // end namespace Avogadro

#endif
