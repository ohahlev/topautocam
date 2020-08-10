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

class T_VIEW_EXPORT publicvehicle_indexView : public TActionView
{
  Q_OBJECT
public:
  publicvehicle_indexView() : TActionView() { }
  QString toString();
};

QString publicvehicle_indexView::toString()
{
  responsebody.reserve(261);
  responsebody += QStringLiteral("<div class=\"container\">\n  <div class=\"row\">\n    <div class=\"col-lg-12\">\n      ");
  responsebody += QVariant(renderPartial("vehicles")).toString();
  responsebody += QStringLiteral("\n    </div>\n  </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(publicvehicle_indexView)

#include "publicvehicle_indexView.moc"
