#include <QtGui/QWidget>
#include <AvogadroCore/molecule.h>

namespace OpenThermoQt
{
  class OpenThermoWidget : public QWidget
  {
    Q_OBJECT
    
    public:
      //! Constructor
      explicit OpenThermoWidget( QWidget *parent = 0, Qt::WindowFlags f = 0 );
      //! Deconstructor
      ~OpenThermoWidget();
      
      void setMolecule(Molecule *molecule);
  };
}
