#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "newsvalidator.h"

class T_VIEW_EXPORT partial_errorView : public TActionView
{
  Q_OBJECT
public:
  partial_errorView() : TActionView() { }
  QString toString();
};

QString partial_errorView::toString()
{
  responsebody.reserve(334);
  tfetch(QString, error);
  if(error != NULL) {
  responsebody += QStringLiteral("  <div class=\"row\">\n    <div class=\"col-lg-12\">\n      <div class=\"alert alert-danger alert-light alert-dismissible\" role=\"alert\">\n        ");
  tehex(error);
  responsebody += QStringLiteral("\n      </div>\n    </div>\n  </div>\n  ");
  };

  return responsebody;
}

T_DEFINE_VIEW(partial_errorView)

#include "partial_errorView.moc"
