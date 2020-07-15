#include <QtCore>
#include <TreeFrogView>
#include "news.h" 
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

class T_VIEW_EXPORT news_showView : public TActionView
{
  Q_OBJECT
public:
  news_showView() : TActionView() { }
  QString toString();
};

QString news_showView::toString()
{
  responsebody.reserve(1950);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(News, news);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing News</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(news.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>Title</dt><dd>");
  responsebody += THttpUtility::htmlEscape(news.title());
  responsebody += QStringLiteral("</dd><br />\n<dt>Subline</dt><dd>");
  responsebody += THttpUtility::htmlEscape(news.subline());
  responsebody += QStringLiteral("</dd><br />\n<dt>Status</dt><dd>");
  responsebody += THttpUtility::htmlEscape(news.status());
  responsebody += QStringLiteral("</dd><br />\n<dt>Line1</dt><dd>");
  responsebody += THttpUtility::htmlEscape(news.line1());
  responsebody += QStringLiteral("</dd><br />\n<dt>Line2</dt><dd>");
  responsebody += THttpUtility::htmlEscape(news.line2());
  responsebody += QStringLiteral("</dd><br />\n<dt>Line3</dt><dd>");
  responsebody += THttpUtility::htmlEscape(news.line3());
  responsebody += QStringLiteral("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(news.createdAt());
  responsebody += QStringLiteral("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(news.updatedAt());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", news.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(news_showView)

#include "news_showView.moc"
