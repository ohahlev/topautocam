#include <QtCore>
#include <TreeFrogView>
#include "drivetype.h" 
#include "applicationhelper.h"
#include "bodytypevalidator.h"
#include "drivetypevalidator.h"
#include "makevalidator.h"
#include "newsvalidator.h"
#include "vehiclemodelvalidator.h"

class T_VIEW_EXPORT drivetype_showView : public TActionView
{
  Q_OBJECT
public:
  drivetype_showView() : TActionView() { }
  QString toString();
};

QString drivetype_showView::toString()
{
  responsebody.reserve(1348);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(DriveType, driveType);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing Drive Type</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(driveType.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>Name</dt><dd>");
  responsebody += THttpUtility::htmlEscape(driveType.name());
  responsebody += QStringLiteral("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(driveType.createdAt());
  responsebody += QStringLiteral("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(driveType.updatedAt());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", driveType.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(drivetype_showView)

#include "drivetype_showView.moc"
