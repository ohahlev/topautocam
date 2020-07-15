#include <QtCore>
#include <TreeFrogView>
#include "color.h" 
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

class T_VIEW_EXPORT color_showView : public TActionView
{
  Q_OBJECT
public:
  color_showView() : TActionView() { }
  QString toString();
};

QString color_showView::toString()
{
  responsebody.reserve(1315);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(Color, color);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing Color</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(color.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>Name</dt><dd>");
  responsebody += THttpUtility::htmlEscape(color.name());
  responsebody += QStringLiteral("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(color.createdAt());
  responsebody += QStringLiteral("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(color.updatedAt());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", color.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(color_showView)

#include "color_showView.moc"
