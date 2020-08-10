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

class T_VIEW_EXPORT vehicle_indexView : public TActionView
{
  Q_OBJECT
public:
  vehicle_indexView() : TActionView() { }
  QString toString();
};

QString vehicle_indexView::toString()
{
  responsebody.reserve(267);
  responsebody += QStringLiteral("<div class=\"container\">\n  <div class=\"row\">\n    <div class=\"col-lg-12\">\n      ");
  responsebody += QVariant(renderPartial("vehicles_admin")).toString();
  responsebody += QStringLiteral("\n    </div>\n  </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(vehicle_indexView)

#include "vehicle_indexView.moc"
