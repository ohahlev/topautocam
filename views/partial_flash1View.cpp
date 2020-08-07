#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "bodytypevalidator.h"
#include "colorvalidator.h"
#include "drivetypevalidator.h"
#include "fueltypevalidator.h"
#include "gradevalidator.h"
#include "makevalidator.h"
#include "newsvalidator.h"
#include "vehiclemodelvalidator.h"
#include "vehiclevalidator.h"

class T_VIEW_EXPORT partial_flash1View : public TActionView
{
  Q_OBJECT
public:
  partial_flash1View() : TActionView() { }
  QString toString();
};

QString partial_flash1View::toString()
{
  responsebody.reserve(341);
  tfetch(QString, notice1);
  if(notice1 != NULL) {
  responsebody += QStringLiteral("  <div class=\"row\">\n    <div class=\"col-lg-12\">\n      <div class=\"alert alert-success alert-light alert-dismissible\" role=\"alert\">\n        ");
  tehex(notice1);
  responsebody += QStringLiteral("\n      </div>\n    </div>\n  </div>\n  ");
  };

  return responsebody;
}

T_DEFINE_VIEW(partial_flash1View)

#include "partial_flash1View.moc"
