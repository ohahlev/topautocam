#include <QtCore>
#include <TreeFrogView>
#include "newsgallery.h" 
#include "applicationhelper.h"
#include "newsvalidator.h"

class T_VIEW_EXPORT newsgallery_createView : public TActionView
{
  Q_OBJECT
public:
  newsgallery_createView() : TActionView() { }
  QString toString();
};

QString newsgallery_createView::toString()
{
  responsebody.reserve(1274);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, newsGallery);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>New News Gallery</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>Image<br /><input name=\"newsGallery[image]\" value=\"");
  responsebody += THttpUtility::htmlEscape(newsGallery["image"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Status<br /><input name=\"newsGallery[status]\" value=\"");
  responsebody += THttpUtility::htmlEscape(newsGallery["status"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(newsgallery_createView)

#include "newsgallery_createView.moc"
