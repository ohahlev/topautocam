#include <QtCore>
#include <TreeFrogView>
#include "make.h" 
#include "applicationhelper.h"
#include "makevalidator.h"
#include "newsvalidator.h"

class T_VIEW_EXPORT make_showView : public TActionView
{
  Q_OBJECT
public:
  make_showView() : TActionView() { }
  QString toString();
};

QString make_showView::toString()
{
  responsebody.reserve(1432);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(Make, make);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing Make</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(make.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>Name</dt><dd>");
  responsebody += THttpUtility::htmlEscape(make.name());
  responsebody += QStringLiteral("</dd><br />\n<dt>Logo</dt><dd>");
  responsebody += THttpUtility::htmlEscape(make.logo());
  responsebody += QStringLiteral("</dd><br />\n<dt>Created at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(make.createdAt());
  responsebody += QStringLiteral("</dd><br />\n<dt>Updated at</dt><dd>");
  responsebody += THttpUtility::htmlEscape(make.updatedAt());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", make.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(make_showView)

#include "make_showView.moc"
