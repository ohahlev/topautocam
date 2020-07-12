#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"
#include "newsvalidator.h"

class T_VIEW_EXPORT partial_flashView : public TActionView
{
  Q_OBJECT
public:
  partial_flashView() : TActionView() { }
  QString toString();
};

QString partial_flashView::toString()
{
  responsebody.reserve(338);
  tfetch(QString, notice);
  if(notice != NULL) {
  responsebody += QStringLiteral("  <div class=\"row\">\n    <div class=\"col-lg-12\">\n      <div class=\"alert alert-success alert-light alert-dismissible\" role=\"alert\">\n        ");
  tehex(notice);
  responsebody += QStringLiteral("\n      </div>\n    </div>\n  </div>\n  ");
  };

  return responsebody;
}

T_DEFINE_VIEW(partial_flashView)

#include "partial_flashView.moc"
