#include "global.hpp"

#include <QLocale>
#include <QDebug>
#include <QCoreApplication>
#include <QStringList>
#include <QProcess>

namespace OpenThermoQt
{
  QPointer<QTranslator> createTranslator()
  {
    QString translationCode = QLocale::system().name();
    QStringList translationPaths;
	QString translationPath("");
    
    foreach (const QString &variable, QProcess::systemEnvironment()) {
      QStringList split1 = variable.split('=');
      if (split1[0] == "OPENTHERMO_TRANSLATIONS") {
        foreach (const QString &path, split1[1].split(':'))
          translationPaths << path;
      }
    }
	
  #ifdef Q_WS_X11
    defaultPath = INSTALL_PREFIX + "/share/openthermo/i18n/";
  #endif
  #ifdef Q_WS_WIN
    defaultPath = ".";
  #endif
  #ifdef Q_WS_MAC
    defaultPath = "";
  #endif  
    translationPaths << QCoreApplication::applicationDirPath() + defaultPath;    
    QString fileName = "libqperiodictable_" + translationCode + ".qm";
  
    // Load the translations
    QPointer<QTranslator> translator = new QTranslator(0);
    foreach (const QString &translationPath, translationPaths) {
      if (translator->load(fileName, translationPath)) {
        return translator;
      }
    }

    qDebug() << "QPeriodicTable translations not found.";
    delete translator;
    return 0;
}
