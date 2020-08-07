#include <QtCore>
#include <TreeFrogView>
#include "newsgallery.h" 
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

class T_VIEW_EXPORT newsgallery_showView : public TActionView
{
  Q_OBJECT
public:
  newsgallery_showView() : TActionView() { }
  QString toString();
};

QString newsgallery_showView::toString()
{
  responsebody.reserve(1502);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(NewsGallery, newsGallery);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing News Gallery</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(newsGallery.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>Image</dt><dd>");
  responsebody += THttpUtility::htmlEscape(newsGallery.image());
  responsebody += QStringLiteral("</dd><br />\n<dt>Status</dt><dd>");
  responsebody += THttpUtility::htmlEscape(newsGallery.status());
  responsebody += QStringLiteral("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(newsGallery.createdAt());
  responsebody += QStringLiteral("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(newsGallery.updatedAt());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", newsGallery.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(newsgallery_showView)

#include "newsgallery_showView.moc"
