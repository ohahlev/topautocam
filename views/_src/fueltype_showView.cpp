#include <QtCore>
#include <TreeFrogView>
#include "fueltype.h" 
#include "applicationhelper.h"
#include "bodytypevalidator.h"
#include "colorvalidator.h"
#include "drivetypevalidator.h"
#include "fueltypevalidator.h"
#include "gradevalidator.h"
#include "makevalidator.h"
#include "newsvalidator.h"
#include "vehiclemodelvalidator.h"

class T_VIEW_EXPORT fueltype_showView : public TActionView
{
  Q_OBJECT
public:
  fueltype_showView() : TActionView() { }
  QString toString();
};

QString fueltype_showView::toString()
{
  responsebody.reserve(1340);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(FuelType, fuelType);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing Fuel Type</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(fuelType.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>Name</dt><dd>");
  responsebody += THttpUtility::htmlEscape(fuelType.name());
  responsebody += QStringLiteral("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(fuelType.createdAt());
  responsebody += QStringLiteral("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(fuelType.updatedAt());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", fuelType.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(fueltype_showView)

#include "fueltype_showView.moc"
