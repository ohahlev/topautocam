#include <QtCore>
#include <TreeFrogView>
#include "newsgallery.h" 
#include "applicationhelper.h"
#include "newsvalidator.h"

class T_VIEW_EXPORT newsgallery_saveView : public TActionView
{
  Q_OBJECT
public:
  newsgallery_saveView() : TActionView() { }
  QString toString();
};

QString newsgallery_saveView::toString()
{
  responsebody.reserve(1675);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, newsGallery);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Editing News Gallery</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", newsGallery["id"]), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"newsGallery[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(newsGallery["id"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Image<br /><input type=\"text\" name=\"newsGallery[image]\" value=\"");
  responsebody += THttpUtility::htmlEscape(newsGallery["image"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Status<br /><input type=\"text\" name=\"newsGallery[status]\" value=\"");
  responsebody += THttpUtility::htmlEscape(newsGallery["status"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", newsGallery["id"]))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(newsgallery_saveView)

#include "newsgallery_saveView.moc"
