#include <QtCore>
#include <TreeFrogView>
#include "vehicle.h" 
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

class T_VIEW_EXPORT vehicle_showView : public TActionView
{
  Q_OBJECT
public:
  vehicle_showView() : TActionView() { }
  QString toString();
};

QString vehicle_showView::toString()
{
  responsebody.reserve(3472);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(Vehicle, vehicle);
  responsebody += QStringLiteral("<html>\n    <head>\n        <meta charset=\"UTF-8\">\n        <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n    </head>\n    <body>\n        <p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n        <p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n        <h1>Showing Vehicle</h1>\n        <dt>ID</dt>\n        <dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.id());
  responsebody += QStringLiteral("</dd>\n        <br/>\n        <dt>Frame No</dt>\n        <dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.frameNo());
  responsebody += QStringLiteral("</dd>\n        <br/>\n        <dt>Manufacturing Date</dt>\n        <dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.manufacturingDate());
  responsebody += QStringLiteral("</dd>\n        <br/>\n        <dt>Deposit Date</dt>\n        <dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.depositDate());
  responsebody += QStringLiteral("</dd>\n        <br/>\n        <dt>Code</dt>\n        <dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.code());
  responsebody += QStringLiteral("</dd>\n        <br/>\n        <dt>Engine</dt>\n        <dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.engine());
  responsebody += QStringLiteral("</dd>\n        <br/>\n        <dt>Mileage</dt>\n        <dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.mileage());
  responsebody += QStringLiteral("</dd>\n        <br/>\n        <dt>Created at</dt>\n        <dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.createdAt());
  responsebody += QStringLiteral("</dd>\n        <br/>\n        <dt>Updated at</dt>\n        <dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.updatedAt());
  responsebody += QStringLiteral("</dd>\n        <br/>\n        <dt>Make ID</dt>\n        <dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.makeId());
  responsebody += QStringLiteral("</dd>\n        <br/>\n        <dt>Model ID</dt>\n        <dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.modelId());
  responsebody += QStringLiteral("</dd>\n        <br/>\n        <dt>Color ID</dt>\n        <dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.colorId());
  responsebody += QStringLiteral("</dd>\n        <br/>\n        <dt>Grade ID</dt>\n        <dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.gradeId());
  responsebody += QStringLiteral("</dd>\n        <br/>\n        <dt>Drive ID</dt>\n        <dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.driveId());
  responsebody += QStringLiteral("</dd>\n        <br/>\n        <dt>Fuel ID</dt>\n        <dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.fuelId());
  responsebody += QStringLiteral("</dd>\n        <br/>\n        <dt>Body ID</dt>\n        <dd>");
  responsebody += THttpUtility::htmlEscape(vehicle.bodyId());
  responsebody += QStringLiteral("</dd>\n        <br/>\n        ");
  responsebody += QVariant(linkTo("Edit", urla("save", vehicle.id()))).toString();
  responsebody += QStringLiteral("\n        |\n        ");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n    </body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(vehicle_showView)

#include "vehicle_showView.moc"
