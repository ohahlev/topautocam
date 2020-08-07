#include <QtCore>
#include <TreeFrogView>
#include "vehiclemodel.h" 
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

class T_VIEW_EXPORT vehiclemodel_showView : public TActionView
{
  Q_OBJECT
public:
  vehiclemodel_showView() : TActionView() { }
  QString toString();
};

QString vehiclemodel_showView::toString()
{
  responsebody.reserve(1505);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(VehicleModel, vehicleModel);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing Vehicle Model</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicleModel.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>Name</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicleModel.name());
  responsebody += QStringLiteral("</dd><br />\n<dt>Logo</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicleModel.logo());
  responsebody += QStringLiteral("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicleModel.createdAt());
  responsebody += QStringLiteral("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(vehicleModel.updatedAt());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", vehicleModel.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(vehiclemodel_showView)

#include "vehiclemodel_showView.moc"
